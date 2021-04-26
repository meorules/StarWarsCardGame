#include "SpecialFightingCard.h"
//Constructor for creating the card and calling on the FightingCard Constructor which in turn calls on the Card Constructor
SpecialFightingCard::SpecialFightingCard(string cardId, string cardImage,bool good, int force, int melee, int block, int gunnin, string abilityName,string statAffected)
  : FightingCard(cardId, cardImage,good, force, melee, block, gunnin),statAffected(statAffected)
{

  ability = &SpecialAbilities::returnInstance()->returnList()->at(SpecialAbilities::returnInstance()->findAbility(SpecialAbility(abilityName)));
}

//Destructor
SpecialFightingCard::~SpecialFightingCard()
{
  delete ability;
}

//Drawing the special fighting card along with all the stats which it affects
void SpecialFightingCard::draw(EasyGraphics* canvas, int x, int y, int width, int height) {
  FightingCard::draw(canvas,x,y,width,height);
  canvas->drawText((ability->getName() + ": " + ability->returnEffect() + " " + statAffected).c_str(), x +5, y+ height-23);
}

//Returning the ability name of the special fighting card for drawing
std::string SpecialFightingCard::getAbilityName()
{
  return ability->getName();
}

//Returning the ability itself of the special fighting card
SpecialAbility* SpecialFightingCard::getAbility()
{
  return ability;
}

//Returning an int which sticks to the values of the cardStat enum used in card battles for the card the ability affects
int SpecialFightingCard::getStatAffected()
{
  if (statAffected == "f") {
    return 0;
  }
  else if (statAffected == "m") {
    return 1;
  }
  else if (statAffected == "b") {
    return 2;
  }
  else if (statAffected == "g") {
    return 3;
  }
}

//Returns a pointer to a new copy of the card 
Card* SpecialFightingCard::copyCard()
{
  return new SpecialFightingCard(*this);
}
