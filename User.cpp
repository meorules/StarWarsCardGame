#include "User.h"

User::User(string username, string password,int wins,int losses,int draws) : userName(username), password(password),userRecord(gameRecord(wins,losses,draws))
{
  //For now will give 10 random cards to the user. 
  cardCollection = CardLibrary::returnInstance()->generateCardCollection(10);

    for(int i=0;i<5;i++){
      addCardToDeck(cardCollection.returnList()->at(i));
    }
}

//used purely for comparison operations
User::User(string username) : userName(username), password(""), userRecord(gameRecord(0, 0,0))
{
}

User::User(string username, string password, int wins, int losses, int draws, vector<int> cardIndices) : userName(username), password(password), userRecord(gameRecord(wins, losses, draws))
{
  for (int i = 0; i < cardIndices.size(); i++) {
    addCardToCollection(cardIndices.at(i));
  }

  for (int i = 0; i < 5; i++) {
    addCardToDeck(cardCollection.returnList()->at(i));
  }
}

User::~User()
{
}

string User::getName()
{
  return userName;
}


void User::addRandomCard()
{
  if (cardCollection.returnList()->size() != CardLibrary::returnInstance()->returnList()->size()) {
    srand(time(NULL));
    bool added = false;
    while (!added) {
      int newCardIndex = rand() % CardLibrary::returnInstance()->returnList()->size();
      if (checkCardInCollection(CardLibrary::returnInstance()->returnList()->at(newCardIndex)) == -1) {
        cardCollection.addItem(CardLibrary::returnInstance()->returnList()->at(newCardIndex));
        added = true;
      }
      else {
        newCardIndex = rand() % CardLibrary::returnInstance()->returnList()->size();
      }
    }
  }
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
    if (!cardDeck[i] || cardDeck[i]==nullptr) {
      cardDeck[i] = newCard;
      break;
    }
  }
}

void User::addCardToCollection(int index)
{
  Card* cardToAdd = CardLibrary::returnInstance()->returnList()->at(index);
  cardCollection.addItem(cardToAdd);
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

std::vector<Card*>* User::returnCardCollection()
{
  return cardCollection.returnList();
}

bool User::operator==(const User &rhs) const
{
  return this->userName == rhs.userName;
}

