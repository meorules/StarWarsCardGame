#pragma once
#include "Window.h"
#include "UserMenuWindow.h"


//A class to allow users to see their current deck of five cards and switch between cards in their deck and cards in their collection

class CardDeckWindow :
    public Window
{
public:
  //Constructor & Destructor
  CardDeckWindow(HINSTANCE hInsantce, int width, int height, User* currentUser);
  ~CardDeckWindow();

  //Window Draw Method

private:
  //Easygraphics methods
  void onDraw();
  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);

  //Text & selected menu options
  string outputText;
  User* currentMenuUser;
  Card* selectedCollectionCard;
  Card* selectedDeckCard;
};

