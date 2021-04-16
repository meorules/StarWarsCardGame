#include "CardLibrary.h"

CardLibrary* CardLibrary::instance = nullptr;

CardLibrary::CardLibrary() {
  cardDatabase = new listTemplate<Card*>();
}

CardLibrary* CardLibrary::returnInstance()
{

  if (instance == nullptr) {
    instance = new CardLibrary();
    loadCards();
  }
  return instance;
}

void CardLibrary::releaseInstance()
{
  for (int i = 0; i < CardLibrary::returnInstance()->returnList()->size(); i++){
    delete CardLibrary::returnInstance()->returnList()->at(i);
  }
  delete instance;
}

vector<Card*>* CardLibrary::returnList()
{
  return cardDatabase->returnList();;
}

void CardLibrary::loadCards()
{
  if (returnInstance()->cardDatabase->returnList()->size() > 0) {
    //need to save and reload cards per user
    returnInstance()->cardDatabase->returnList()->clear();
  }
  ifstream fin;
  string fileName = ".\\saveData\\Cards.txt";
  fin.open(fileName);

  if (fin) {
    string cardType, cardName, cardImageS, specialAbilityName, statAffected;
    bool good, statsAffected[4];
    int force, melee, block, gunnin;
    fin >> cardType >> cardName >> cardImageS >> good;

    while (!fin.eof()) {
      cardImageS = ".\\imageAssets\\"+ cardImageS + ".bmp";
      wchar_t* cardImageW = Card::stringToWchar(cardImageS);

      Card* current;

      if (cardType == "Fighting") {
        fin >> force >> melee >> block >> gunnin;
        current = new FightingCard(cardName, cardImageW, good, force, melee, block, gunnin);
      }
      else if (cardType == "Ability") {
        fin >> specialAbilityName >> statsAffected[0] >> statsAffected[1] >> statsAffected[2] >> statsAffected[3];
        current = new AbilityCard(cardName, cardImageW, good, specialAbilityName, statsAffected);
      }
      else {
        fin >> force >> melee >> block >> gunnin >> specialAbilityName >> statAffected;
        current = new SpecialFightingCard(cardName, cardImageW, good, force, melee, block, gunnin, specialAbilityName, statAffected);
      }
      instance->cardDatabase->addItem(current);
      fin >> cardType >> cardName >> cardImageS >> good;
    }
  }
  fin.close();
}


CardLibrary::~CardLibrary()
{
}