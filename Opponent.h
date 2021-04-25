#pragma once
#include "User.h"
#include "Card.h"

//Opponent class used to create an AI with a smaller card collection than a standard user 

class Opponent
{
public:
  Opponent(User* user);
  Opponent() {}
  ~Opponent() {}


  Card* returnCardDeck(int toReturn);

private:
  // Need to display record in battle window
  gameRecord record;
  //To store the array of pointer to cards for an opponent's deck
  Card* cardDeck[5];

};

inline Opponent::Opponent(User* user) : record(user->getLosses(), user->getWins(), user->getDraws())
{
  vector<Card*> cardCollection = CardLibrary::returnInstance()->generateCardCollection(5);

  for (int i = 0; i < 5; i < i++) {
    cardDeck[i] = cardCollection.at(i);
  }
}

inline  Card* Opponent::returnCardDeck(int toReturn)
{
  return cardDeck[toReturn];
}
