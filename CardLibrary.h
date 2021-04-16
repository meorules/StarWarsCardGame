#pragma once
#include "listTemplate.h"
#include <string>
#include <iostream>
#include <fstream>

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


private:
  static CardLibrary* instance;
  CardLibrary();
  listTemplate<Card*>* cardDatabase;


};

