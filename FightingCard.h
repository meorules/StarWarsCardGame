#pragma once
#include "Card.h"

class FightingCard :
    public Card
{
public:
  FightingCard(string cardId, string cardImage,bool good ,int force, int melee, int block, int gunnin);
  ~FightingCard();
  virtual void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  virtual Card* copyCard();

  int checkStat(int statToCheck);

  void changeStat(int change,int cardStat);

private:
  int force;
  int melee;
  int block;
  int gunnin;


};

