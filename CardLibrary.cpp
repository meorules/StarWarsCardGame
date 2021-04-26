#include "CardLibrary.h"
//Setting instance to nullptr
CardLibrary* CardLibrary::instance = nullptr;
//Private Constructor 
CardLibrary::CardLibrary() {
  cardDatabase = new listTemplate<Card*>();
}
//Deleting the stuff inside the instance before deleting the instance itself
CardLibrary::~CardLibrary()
{
}

//Lazy Initialization and loading of cards
CardLibrary* CardLibrary::returnInstance()
{

  if (instance == nullptr) {
    instance = new CardLibrary();
    loadCards();
  }
  return instance;
}

//Deleting the singleton as soon as it is no longer needed
void CardLibrary::releaseInstance()
{
  for (int i = 0; i < CardLibrary::returnInstance()->returnList()->size(); i++){
    delete CardLibrary::returnInstance()->returnList()->at(i);
  }
  delete instance;
}
//Returning the list of cards
vector<Card*>* CardLibrary::returnList()
{
  return cardDatabase->returnList();;
}
//Loading in the cards from the text file and adding them to the library
void CardLibrary::loadCards()
{
  ifstream fin;
  string fileName = ".\\saveData\\Cards.txt";
  fin.open(fileName);

  if (fin) {
    string cardType, cardName, cardImageS, specialAbilityName, statAffected;
    bool good, statsAffected[4];
    int force, melee, block, gunnin;
    fin >> cardType >> cardName >> cardImageS >> good;

    while (!fin.eof()) {

      Card* current;

      if (cardType == "Fighting") {
        fin >> force >> melee >> block >> gunnin;
        current = new FightingCard(cardName, cardImageS, good, force, melee, block, gunnin);
      }
      else if (cardType == "Ability") {
        fin >> specialAbilityName >> statsAffected[0] >> statsAffected[1] >> statsAffected[2] >> statsAffected[3];
        current = new AbilityCard(cardName, cardImageS, good, specialAbilityName, statsAffected);
      }
      else {
        fin >> force >> melee >> block >> gunnin >> specialAbilityName >> statAffected;
        current = new SpecialFightingCard(cardName, cardImageS, good, force, melee, block, gunnin, specialAbilityName, statAffected);
      }
      instance->cardDatabase->addItem(current);
      fin >> cardType >> cardName >> cardImageS >> good;
    }
  }
  fin.close();
}

//Generating the randomized card collection to be sent back to users or opponents when generating collections for new users
std::vector<Card*> CardLibrary::generateCardCollection(int size)
{
  vector<Card*> cardCollection;
  vector <int> cardOrder;

  for (int i = 0; i < returnInstance()->cardDatabase->returnList()->size(); i++)
    cardOrder.push_back(i);

  shuffle(cardOrder.begin(), cardOrder.end(), random_device());

  for (int i = 0; i < size; i < i++) {
    cardCollection.push_back(returnInstance()->cardDatabase->returnList()->at(cardOrder.at(i)));
  }

  return cardCollection;
}

