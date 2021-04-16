#include "FightingCard.h"

FightingCard::FightingCard(string cardId, wchar_t* cardImage,bool good, int force, int melee, int block, int gunnin) :
  Card(cardId, cardImage,good), force(force), melee(melee), block(block), gunnin(gunnin)
{

}

FightingCard::~FightingCard()
{
}

void FightingCard::draw(EasyGraphics* canvas, int x, int y, int width, int height) {
  Card::draw(canvas,x,y,width,height);


  canvas->setFont(width / 10 -1, L"Times New Roman Bold");

  string forceS = "F: " + to_string(force);

  wchar_t* forceW = stringToWchar(forceS);

  string blockS = "B: " + to_string(block);

  wchar_t* blockW = stringToWchar(blockS);

  string gunninS = to_string(gunnin) + " :G";

  wchar_t* gunninW = stringToWchar(gunninS);

  string meleeS = to_string(melee) + " :M";

  wchar_t* meleeW = stringToWchar(meleeS);

  canvas->drawText(forceW, x+5, y+ 0.5*height+15);
  canvas->drawText(gunninW, x+width/2+10, y+0.5*height+15);
  canvas->drawText(blockW, x+5, y+ 0.5 * height+30);
  canvas->drawText(meleeW, x+width / 2 + 10, y+ 0.5 * height+30);
}

void FightingCard::changeStat(int change, int cardStat)
{
  switch (cardStat) {
  case 0:
    force + change;
    break;
  case 1:
    melee + change;
    break;
  case 2: 
    block + change;
    break;
  case 3:
    gunnin + change;
  }
}

