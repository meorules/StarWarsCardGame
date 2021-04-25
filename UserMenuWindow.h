#pragma once
#include "Window.h"
#include "Users.h"
#include "MainMenuWindow.h"
#include "CardBattleWindow.h"
#include "CardDeckWindow.h"
#include "CardLibrary.h"
#include <time.h>
#include <cstdlib>

//Basic user menu meant to hold intermediary functions between the card's collection and actual battles and the main menu. 

class UserMenuWindow :
    public Window
{
public:
  //Constructor and destructor which takes the user signed in and uses it to draw different things
  UserMenuWindow(HINSTANCE hInsantce, int width, int height,User* currentUser);
  ~UserMenuWindow();

private:
  //Normal Easy Graphics methods including on timer to flick through various cards onscreen 
  void onDraw();
  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);
  void onTimer(UINT nIDEvent);

  static const int REDRAW_TIMER_ID = 1;

  //The currently logged in user. 
  User* currentMenuUser;

};

