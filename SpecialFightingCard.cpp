#include "SpecialFightingCard.h"

SpecialFightingCard::SpecialFightingCard(string cardId, wchar_t* cardImage,bool good, int force, int melee, int block, int gunnin, string abilityName,string statAffected)
  : FightingCard(cardId, cardImage,good, force, melee, block, gunnin),statAffected(statAffected)
{

  ability = &SpecialAbilities::returnInstance()->returnList()->at(SpecialAbilities::returnInstance()->findAbility(SpecialAbility(abilityName)));
}

SpecialFightingCard::~SpecialFightingCard()
{
}

void SpecialFightingCard::draw(EasyGraphics* canvas, int x, int y, int width, int height) {
  FightingCard::draw(canvas,x,y,width,height);
  wchar_t* specialAbilityNameW = stringToWchar(ability->getName()+": " + ability->returnEffect()+ " " +statAffected);
  canvas->drawText(specialAbilityNameW, x +5, y+ height-23);

}

std::string SpecialFightingCard::getAbilityName()
{
  return ability->getName();
}
