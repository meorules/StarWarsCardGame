#pragma once
#include "Card.h"

//A Specialization of the Card but sprouts into a further type of card ( Special Fighting Card) and so it holds common things like stats

class FightingCard :
    public Card
{
public:
  //Constructor & Destructor
  FightingCard(string cardId, string cardImage,bool good ,int force, int melee, int block, int gunnin);
  ~FightingCard();

  //The virtual draw being overridden for normal fighting cards yet still virtual to allow for further polymorphism into Special Fighting Cards
  virtual void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  //Returning a copy of the card
  virtual Card* copyCard();

  //Returning values of stats
  int checkStat(int statToCheck);

  //Changing specific stats ( Used only in card battles) 
  void changeStat(int change,int cardStat);

private:
  //4 Basic stats
  int force;
  int melee;
  int block;
  int gunnin;


};

