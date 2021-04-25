#include "SpecialFightingCard.h"

SpecialFightingCard::SpecialFightingCard(string cardId, string cardImage,bool good, int force, int melee, int block, int gunnin, string abilityName,string statAffected)
  : FightingCard(cardId, cardImage,good, force, melee, block, gunnin),statAffected(statAffected)
{

  ability = &SpecialAbilities::returnInstance()->returnList()->at(SpecialAbilities::returnInstance()->findAbility(SpecialAbility(abilityName)));
}

SpecialFightingCard::~SpecialFightingCard()
{
}

void SpecialFightingCard::draw(EasyGraphics* canvas, int x, int y, int width, int height) {
  FightingCard::draw(canvas,x,y,width,height);
  canvas->drawText((ability->getName() + ": " + ability->returnEffect() + " " + statAffected).c_str(), x +5, y+ height-23);
}

std::string SpecialFightingCard::getAbilityName()
{
  return ability->getName();
}

SpecialAbility* SpecialFightingCard::getAbility()
{
  return ability;
}

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

Card* SpecialFightingCard::copyCard()
{
  return new SpecialFightingCard(*this);
}
