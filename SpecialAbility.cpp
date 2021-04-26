#include "SpecialAbility.h"
//Special Ability Constructor 
SpecialAbility::SpecialAbility(string name, bool isPositive, int effect) : specialAbilityName(name), isPositive(isPositive), effect(effect)
{
  
}
//Special Ability Constructor purely for comparison purposes ( Just the name is set)
SpecialAbility::SpecialAbility(string name) : specialAbilityName(name),isPositive(false),effect(19)
{

}
//Destructor
SpecialAbility::~SpecialAbility()
{
}
//== Operator to be used in comparison operations to compare by name rather than the whole object
bool SpecialAbility::operator==(const SpecialAbility& rhs) const
{
  return this->specialAbilityName == rhs.specialAbilityName;
}
//Returning the special ability name
string SpecialAbility::getName()
{
  return specialAbilityName;
}

//Returns a string of the amount the stats are changed along with the + or - representing the positive or negative change
string SpecialAbility::returnEffect()
{
  if (isPositive) {
    return "+" + to_string(effect);
  }
  else {
    return "-" + to_string(effect);
  }
}

