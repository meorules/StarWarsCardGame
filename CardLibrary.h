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

//The first singleton class responsible for holding all possible cards in the game. It holds all the cards which exist and is accessed in many places. 

class CardLibrary
{
public:
  //Destructor only as constructor is private but all methods are public
  ~CardLibrary();
  //Returning the instance
  static CardLibrary* returnInstance();
  // Deleting the instance
  static void releaseInstance();

  //Returning the list inside the instance
  vector<Card*>* returnList();

  //Loading up cards from Cards.txt and adding them to the library ( list of cards) inside the instance 
  static void loadCards();

  //Generating Card Collections for new users
  vector<Card*> generateCardCollection(int size);

  //Looking for specific cards inside the library and returning their index
  int findCardIndex(Card* itemToFind) { return cardDatabase->findItem(itemToFind); }

private:
  //Private constructor and instance along with the list inside the instance 
  static CardLibrary* instance;
  CardLibrary();
  listTemplate<Card*>* cardDatabase;


};

