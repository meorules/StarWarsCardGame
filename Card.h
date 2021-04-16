#pragma once
#include "EasyGraphics.h"
#include <string>
#include <cstdlib>


using namespace std;
class Card
{
public:
  Card(string cardId,wchar_t* cardImage,bool good);
  Card();
  ~Card();

  bool operator==(const Card& rhs) const;

  virtual void draw(EasyGraphics* canvas, int x, int y, int width, int height);

  static wchar_t* stringToWchar(string toConvert);

  bool hitTest(int x, int y);

  string getCardName();
protected:
  int x1, x2, y1, y2;

private:
  string cardId;
  wchar_t* cardImage;
  bool good;

};

