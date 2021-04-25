#pragma once
#include "listTemplate.h"
#include <string>
#include "SpecialAbility.h"
#include <fstream>

using namespace std;

//The 2nd singleton class containing the list of special abilities

class SpecialAbilities
{
public:
  //Destructor along with the return & release instance methods
  ~SpecialAbilities();
  static SpecialAbilities* returnInstance();
  static void releaseInstance();
  
  //Returning the vector list if need be
  vector<SpecialAbility>* returnList();

  //Searching for a specific ability
  int findAbility(SpecialAbility ability);

  //Loading the abilities from a text file, more can be added, changed, removed, etc
  static void loadAbilities();

  private:
    //Private constructor and instance itself along with the list of abilities
    static SpecialAbilities* instance;
    SpecialAbilities();
    listTemplate<SpecialAbility>* abilities;

  };

