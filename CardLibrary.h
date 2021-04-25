#pragma once
#include "listTemplate.h"
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>

#include "Card.h"

#include "AbilityCard.h"
#include "SpecialFightingCard.h"
#include "FightingCard.h"

using namespace std;

class CardLibrary
{
public:
  ~CardLibrary();
  static CardLibrary* returnInstance();
  static void releaseInstance();

  vector<Card*>* returnList();

  static void loadCards();

  vector<Card*> generateCardCollection(int size);

  int findCardIndex(Card* itemToFind) { return cardDatabase->findItem(itemToFind); }

private:
  static CardLibrary* instance;
  CardLibrary();
  listTemplate<Card*>* cardDatabase;


};

