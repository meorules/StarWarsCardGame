#pragma once
#include "FightingCard.h"
#include "SpecialAbilities.h"
#include <vector>

class SpecialFightingCard :
    public FightingCard
{
public:

  SpecialFightingCard(string cardId, wchar_t* cardImage,bool good, int force, int melee, int block, int gunnin, string abilityName,string statAffected);
  ~SpecialFightingCard();

  void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  string getAbilityName();

private:
  SpecialAbility* ability;
  string statAffected;

};

