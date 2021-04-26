#include "User.h"
//Constructor to create a user and generate their card collection and card deck
User::User(string username, string password,int wins,int losses,int draws) : userName(username), password(password),userRecord(gameRecord(wins,losses,draws))
{
  //For now will give 10 random cards to the user. 
  cardCollection = CardLibrary::returnInstance()->generateCardCollection(10);

    for(int i=0;i<5;i++){
      addCardToDeck(cardCollection.returnList()->at(i));
    }
}

//Constructor of user used purely for comparison operations
User::User(string username) : userName(username), password(""), userRecord(gameRecord(0, 0,0))
{
}

// Creates a user and adds cards to their collection from reading the text file
User::User(string username, string password, int wins, int losses, int draws, vector<int> cardIndices) : userName(username), password(password), userRecord(gameRecord(wins, losses, draws))
{
  for (int i = 0; i < cardIndices.size(); i++) {
    addCardToCollection(cardIndices.at(i));
  }

  for (int i = 0; i < 5; i++) {
    addCardToDeck(cardCollection.returnList()->at(i));
  }
}
//User destructor
User::~User()
{
}
//Returns user name
string User::getName()
{
  return userName;
}

//Adds a random card not in the user's collection to it , used as the reward of wins
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

//Method to check password of a user from the passed in string and return true or false based on if the string matches the password
bool User::checkPassword(string currentPassword) {
  if (this->password == currentPassword) {
    return true;
  }
  else {
    return false;
  }
}

//Adds the passed in card to the next available slot in the card deck
void User::addCardToDeck(Card* newCard)
{
  for (int i = 0; i < 5; i++) {
    if (!cardDeck[i] || cardDeck[i]==nullptr) {
      cardDeck[i] = newCard;
      break;
    }
  }
}

//Adds the card from the index passed in to the collection the user owns
void User::addCardToCollection(int index)
{
  Card* cardToAdd = CardLibrary::returnInstance()->returnList()->at(index);
  cardCollection.addItem(cardToAdd);
}

//Returns the card from the index specified inside the card deck
Card* User::returnCardDeck(int index)
{
  return cardDeck[index];
}

//Checks whether the card passed is already in the deck
int User::checkCardInDeck(Card* cardToCheck)
{
  for (int i = 0; i < 5; i++) {
    if (cardDeck[i]==cardToCheck) {
      return i;
    }
  }
  return -1;
}

//Checks whether the card passed is already in the user's collection
int User::checkCardInCollection(Card* cardToCheck)
{
  return cardCollection.findItem(cardToCheck);
}

//Replaces the space of the index passed with the card passed
void User::replaceCardinDeck(int toReplace, Card* newCard)
{
  cardDeck[toReplace] = newCard;
}

//Returning the entire card collection of a user
std::vector<Card*>* User::returnCardCollection()
{
  return cardCollection.returnList();
}

//== Operator overloading for username checking and use in searching
bool User::operator==(const User &rhs) const
{
  return this->userName == rhs.userName;
}

