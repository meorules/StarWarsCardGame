#pragma once
#include "Window.h"
#include "Users.h"
#include "MainMenuWindow.h"
#include "CardBattleWindow.h"
#include "CardDeckWindow.h"
#include "CardLibrary.h"
#include <time.h>
#include <cstdlib>

class UserMenuWindow :
    public Window
{
public:
  UserMenuWindow(HINSTANCE hInsantce, int width, int height,User* currentUser);
  ~UserMenuWindow();


  void onDraw();

private:

  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);
  void onTimer(UINT nIDEvent);

  static const int REDRAW_TIMER_ID = 1;
  User* currentMenuUser;

};

