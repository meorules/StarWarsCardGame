#pragma once
#include "FightingCard.h"
#include "SpecialAbilities.h"
#include <vector>

//A type of Card, the lowermost level inherits from Fighting Card && Card 

class SpecialFightingCard :
    public FightingCard
{
public:
  //Constructor & Destructor
  SpecialFightingCard(string cardId, string cardImage,bool good, int force, int melee, int block, int gunnin, string abilityName,string statAffected);
  ~SpecialFightingCard();
  //Normal draw method to draw specifics of this card
  void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  //returning the ability name and itself
  string getAbilityName();

  SpecialAbility* getAbility();
  //Getting an int representing the stat affected
  int getStatAffected();
  //Returning a copy of the card
  virtual Card* copyCard();

private:
  //Member variables including the ability itself and the stat it affects
  SpecialAbility* ability;
  string statAffected;

};

