#pragma once
#include <string>
#include "listTemplate.h"

using namespace std;

class SpecialAbility
{
public:
  SpecialAbility(string name, bool isPositive, int effect);
  SpecialAbility(string name);
  ~SpecialAbility();

  bool operator==(const SpecialAbility& rhs) const;

  string getName();
  string returnEffect();

private:
  string specialAbilityName;
  bool isPositive;
  int effect;
  
};

