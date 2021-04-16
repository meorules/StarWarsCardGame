#pragma once
#include "listTemplate.h"
#include <string>
#include "SpecialAbility.h"
#include <fstream>

using namespace std;

class SpecialAbilities
{
public:
  ~SpecialAbilities();
  static SpecialAbilities* returnInstance();
  static void releaseInstance();

  vector<SpecialAbility>* returnList();

  int findAbility(SpecialAbility ability);

  static void loadAbilities();

  private:
    static SpecialAbilities* instance;
    SpecialAbilities();
    listTemplate<SpecialAbility>* abilities;

    

  };

