#include "SpecialAbilities.h"

//Setting the instance to nullptr
SpecialAbilities* SpecialAbilities::instance = nullptr;

//Constructor setting up the list
SpecialAbilities::SpecialAbilities() {
  abilities = new listTemplate<SpecialAbility>;
}
//Destructor
SpecialAbilities::~SpecialAbilities()
{
  for (int i = 0; i < instance->returnList()->size(); i++) {
    instance->abilities->deleteItem(instance->returnList()->at(i));
  }
  delete abilities;
}
//Lazy Initialization and returning of the instance
SpecialAbilities* SpecialAbilities::returnInstance()
{
  if (instance == nullptr) {
    instance = new SpecialAbilities();
    loadAbilities();
  }
  return instance;
}

//Deleting the singleton instance
void SpecialAbilities::releaseInstance()
{
  delete instance;
}

//Returning the special abilities list ( Function overhead)
vector<SpecialAbility>* SpecialAbilities::returnList()
{
  return abilities->returnList();;
}
//Function overhead for finding items
int SpecialAbilities::findAbility(SpecialAbility ability)
{
  return abilities->findItem(ability);
}

//Loading abilities from the text file SpecialAbilities.txt and adding them into the abilities list
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
