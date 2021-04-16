#include "Card.h"

Card::Card(string cardId, wchar_t* cardImage,bool good) :cardId(cardId), cardImage(cardImage),good(good),x1(0),x2(0),y1(0),y2(0)
{
}

Card::Card() {

}
Card::~Card()
{
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
    canvas->setPenColour(153831, 3);
    canvas->setBackColour(255);
    canvas->setTextColour(16777215);
  }

  canvas->drawRectangle(x, y, width, height-5,true);
  canvas->drawBitmap(cardImage, x +13, y+16 , int(0.75 * width), int(0.5 * height), 0x00FFFFFF);
  canvas->setFont(width/10, L"Times New Roman Bold");
  wchar_t* cardName = stringToWchar(cardId);
  canvas->drawText(cardName,x+10,y+1);
}

bool Card::operator==(const Card& rhs) const
{
  return this->cardId==rhs.cardId;
}

wchar_t* Card::stringToWchar(string toConvert)
{
  wchar_t* toConvertW = new wchar_t[toConvert.size() + 1];
  MultiByteToWideChar(CP_ACP, 0, toConvert.c_str(), -1, toConvertW, toConvert.size() + 1);
  return toConvertW;
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
