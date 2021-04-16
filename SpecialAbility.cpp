#include "SpecialAbility.h"

SpecialAbility::SpecialAbility(string name, bool isPositive, int effect) : specialAbilityName(name), isPositive(isPositive), effect(effect)
{
  
}

SpecialAbility::SpecialAbility(string name) : specialAbilityName(name),isPositive(false),effect(19)
{

}

SpecialAbility::~SpecialAbility()
{
}

bool SpecialAbility::operator==(const SpecialAbility& rhs) const
{
  return this->specialAbilityName == rhs.specialAbilityName;
}

string SpecialAbility::getName()
{
  return specialAbilityName;
}

string SpecialAbility::returnEffect()
{
  if (isPositive) {
    return "+" + to_string(effect);
  }
  else {
    return "-" + to_string(effect);
  }
}

