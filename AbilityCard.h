#pragma once
#include "Card.h"
#include "SpecialAbilities.h"
#include "listTemplate.h"

//A type of card ( Gives debuffs and buffs to opponent and user cards during battle.) Uses special abilities like Special Fighting Cards
class AbilityCard :
    public Card
{
public:
  //Constructor && Destructor 
  AbilityCard(string cardId, string cardImage,bool good,string specialAbilityName,bool stats[4]);
  ~AbilityCard();

  //Card Drawing method for this type of card
  void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  //Ability Card Specific Methods
  string getAbilityName();
  SpecialAbility* getAbility();
  bool getStatAffected(int cardStat);

  //Virtual method copy card (returns a deep copy of the card) 
  Card* copyCard();

private:
  //Variables to store ability, the stats affected and how many
  SpecialAbility* ability;
  int noOfStatsAffected;
  bool statsAffected[4];
  const wchar_t* statNames[4] = { L"Force",L"Block",L"Gunnin",L"Melee" };
};

