#include "Card.h"

Card::Card(string cardId, string cardImageS,bool good) :cardId(cardId), good(good),x1(0),x2(0),y1(0),y2(0)
{
  cardImageS = ".\\imageAssets\\" + cardImageS + ".bmp";
  cardImage = new wchar_t[cardImageS.size() + 1];
  MultiByteToWideChar(CP_ACP, 0, cardImageS.c_str(), -1, cardImage, cardImageS.size() + 1);
}

Card::Card() {

}
Card::~Card()
{
  delete cardImage;
}


void Card::draw(EasyGraphics* canvas,int x, int y, int width, int height)
{
  x1 = x;
  x2 = x + width;
  y1 = y;
  y2 = y + height;

  if (good) {
      canvas->setBackColour(16711820);
      canvas->setTextColour(16777215);
      canvas->setPenColour(EasyGraphics::BLUE, 3);
  }
  else {
    canvas->setPenColour(9204991, 3);
    canvas->setBackColour(255);
    canvas->setTextColour(16777215);
  }

  canvas->drawRectangle(x, y, width, height-5,true);
  canvas->drawBitmap(cardImage, x +13, y+16 , int(0.75 * width), int(0.5 * height), 0x00FFFFFF);
  canvas->setFont(width/10, L"Times New Roman Bold");
  canvas->drawText(cardId.c_str(),x+10,y+1);
}

bool Card::operator==(const Card& rhs) const
{
  return this->cardId==rhs.cardId;
}

bool Card::hitTest(int x, int y)
{
  if (x > x1 && x<x2 && y>y1 && y < y2) {
    return true;
  }
  else {
    return false;
  }
}

std::string Card::getCardName()
{
  return cardId;
}
