#include "FightingCard.h"

//Constructor of the Fighting Card which gets called by Special FIghting Card and itself calls Card
FightingCard::FightingCard(string cardId, string cardImage,bool good, int force, int melee, int block, int gunnin) :
  Card(cardId, cardImage,good), force(force), melee(melee), block(block), gunnin(gunnin)
{

}
//Destructor empty due to no attributes requiring clearing
FightingCard::~FightingCard()
{
}

//Drawing the attributes of the Fighting Card 
void FightingCard::draw(EasyGraphics* canvas, int x, int y, int width, int height) {
  Card::draw(canvas,x,y,width,height);


  canvas->setFont(width / 10 -1, L"Times New Roman Bold");

  canvas->drawText(("F: " + to_string(force)).c_str(), x+5, y+ 0.5*height+15);
  canvas->drawText((to_string(gunnin) + " :G").c_str(), x+width/2+10, y+0.5*height+15);
  canvas->drawText(("B: " + to_string(block)).c_str(), x+5, y+ 0.5 * height+30);
  canvas->drawText((to_string(melee) + " :M").c_str(), x+width / 2 + 10, y+ 0.5 * height+30);
}

//Returning a pointer to the copy of a card
Card* FightingCard::copyCard()
{
  return new FightingCard(*this);

}

//Returning the specific stat of a card based on the int passed and the enum defined in the game battle class
int FightingCard::checkStat(int statToCheck)
{
  switch (statToCheck) {
  case 0:
    return force;
    break;
  case 1:
    return melee;
    break;
  case 2:
    return block;
    break;
  case 3:
    return gunnin;
    break;
  }
}

//Commiting an addition operation on the passed stat which needs to be changed
void FightingCard::changeStat(int change, int cardStat)
{
  switch (cardStat) {
  case 0:
    force = min(force + change,99);
    break;
  case 1:
    melee = min(melee + change, 99);
    break;
  case 2: 
    block = min(block + change, 99);
    break;
  case 3:
    gunnin = min(gunnin + change, 99);
    break;
  }
}

