#pragma once
#include "Window.h"
#include "UserMenuWindow.h"
class CardDeckWindow :
    public Window
{

public:
  CardDeckWindow(HINSTANCE hInsantce, int width, int height, User* currentUser);
  ~CardDeckWindow();


  void onDraw();

private:

  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);

  string outputText;
  User* currentMenuUser;
  Card* selectedCollectionCard;
  Card* selectedDeckCard;
};

