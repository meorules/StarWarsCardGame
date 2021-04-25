#include "Opponent.h"

Opponent::Opponent(User* user) : record(user->getLosses(),user->getWins(),user->getDraws())
{
  vector<Card*> cardCollection = CardLibrary::returnInstance()->generateCardCollection(5);

  for (int i = 0; i < 5; i < i++) {
    cardDeck[i] = cardCollection.at(i);
  }
}

Opponent::Opponent()
{

}

Opponent::~Opponent()
{

}

Card* Opponent::returnCardDeck(int toReturn)
{
  return cardDeck[toReturn];
}
