#pragma once
#include "EasyGraphics.h"
#include <string>
#include <cstdlib>

using namespace std;

//A generic card class with the main attributes and method to be inherited into other card types
class Card
{
public:
  //Constructor && Destructor
  Card(string cardId,string cardImageS,bool good);
  Card();
  ~Card();

  //Using operator overriding to allow for comparison of cards by their actual name
  bool operator==(const Card& rhs) const;

  //Virtual methods made for overriding in specific card types
  virtual void draw(EasyGraphics* canvas, int x, int y, int width, int height);
  virtual Card* copyCard() = 0;

  //Generic methods used for every card that do not need to be overridden for specific card types. 
  bool hitTest(int x, int y);

  string getCardName();

private:
  //Card attributes ( The Card ID / Card Name, Card Image filepath,
  //good or bad to determine colour scheme and co-ordinates for their drawing location
  string cardId;
  wchar_t* cardImage;
  bool good;
  int x1, x2, y1, y2;

};

