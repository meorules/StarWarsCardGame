#pragma once
#include "User.h"
#include "Card.h"
class Opponent
{
public:
  Opponent(User* user);
  Opponent();
  ~Opponent();


  Card* returnCardDeck(int toReturn);

private:
  gameRecord record;
  Card* cardDeck[5];

};

