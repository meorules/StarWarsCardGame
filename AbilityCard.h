#pragma once
#include "Card.h"
#include "SpecialAbilities.h"
#include "listTemplate.h"

class AbilityCard :
    public Card
{
public:
  AbilityCard(string cardId, string cardImage,bool good,string specialAbilityName,bool stats[4]);
  ~AbilityCard();
  void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  string getAbilityName();

  SpecialAbility* getAbility();

  bool getStatAffected(int cardStat);

  Card* copyCard();

private:
  SpecialAbility* ability;
  int noOfStatsAffected;
  bool statsAffected[4]= { L"Force",L"Block",L"Gunnin",L"Melee" };
};

