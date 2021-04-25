#pragma once
#include <string>
#include "listTemplate.h"

using namespace std;

//A singular special ability class, used to store general information about special abilities 

class SpecialAbility
{
public:
  //Constructors and destructor
  SpecialAbility(string name, bool isPositive, int effect);
  SpecialAbility(string name);
  ~SpecialAbility();

  //Overloading == operator to allow for search by name
  bool operator==(const SpecialAbility& rhs) const;

  //Normal methods to return name of ability and effect which a string of the effect the ability has
  string getName();
  string returnEffect();

private:
  string specialAbilityName;
  bool isPositive;
  int effect;
  
};

