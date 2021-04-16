#include "SpecialAbilities.h"

SpecialAbilities* SpecialAbilities::instance = nullptr;

SpecialAbilities::SpecialAbilities() {
  abilities = new listTemplate<SpecialAbility>;
}

SpecialAbilities::~SpecialAbilities()
{
}

SpecialAbilities* SpecialAbilities::returnInstance()
{
  if (instance == nullptr) {
    instance = new SpecialAbilities();
    loadAbilities();
  }
  return instance;
}

void SpecialAbilities::releaseInstance()
{
  delete instance;
}

vector<SpecialAbility>* SpecialAbilities::returnList()
{
  return abilities->returnList();;
}

int SpecialAbilities::findAbility(SpecialAbility ability)
{
  return abilities->findItem(ability);
}

void SpecialAbilities::loadAbilities()
{
  ifstream fin;
  fin.open(L".\\saveData\\SpecialAbilities.txt");

  if (fin) {
    string name;
    bool isPositive;
    int effect;

    fin >> name >> isPositive >> effect;
    while (!fin.eof()) {
      SpecialAbilities::returnInstance()->abilities->addItem(SpecialAbility(name, isPositive, effect));
      fin >> name >> isPositive >> effect;
    }
    fin.close();
  }
}
