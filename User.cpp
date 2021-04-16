#include "User.h"

User::User(string username, string password,int wins,int losses) : userName(username), password(password),userRecord(gameRecord(wins,losses))
{
  //For now will give 10 random cards to the user. 
  vector<Card*>* cardLibrary = CardLibrary::returnInstance()->returnList();
  
  

  for (int i = 0; i < cardLibrary->size(); i++)
    cardOrder.push_back(i);

  shuffle(cardOrder.begin(), cardOrder.end(), random_device());

  for (int i = 0; i < 10; i < i++) {
    cardCollection.addItem(cardLibrary->at(cardOrder.at(i)));
    if (i < 5) {
      addCardToDeck(cardCollection.returnList()->at(i));
    }
  }


}

//used purely for comparison operations
User::User(string username) : userName(username), password(""), userRecord(gameRecord(0, 0))
{
}

User::~User()
{
}

string User::getName()
{
  return userName;
}


bool User::checkPassword(string currentPassword) {
  if (this->password == currentPassword) {
    return true;
  }
  else {
    return false;
  }
}

void User::addCardToDeck(Card* newCard)
{
  for (int i = 0; i < 5; i++) {
    if (!cardDeck[i]) {
      cardDeck[i] = newCard;
      break;
    }
  }
}

Card* User::returnCardDeck(int index)
{
  return cardDeck[index];
}

int User::checkCardInDeck(Card* cardToCheck)
{
  for (int i = 0; i < 5; i++) {
    if (cardDeck[i]==cardToCheck) {
      return i;
    }
  }
  return -1;
}

int User::checkCardInCollection(Card* cardToCheck)
{
  return cardCollection.findItem(cardToCheck);
}

void User::replaceCardinDeck(int toReplace, Card* newCard)
{
  cardDeck[toReplace] = newCard;
}

int User::getWins()
{
  return userRecord.wins;
}

int User::getLosses()
{
  return userRecord.losses;
}

std::vector<Card*>* User::returnCardCollection()
{
  return cardCollection.returnList();
}

bool User::operator==(const User &rhs) const
{
  return this->userName == rhs.userName;
}

