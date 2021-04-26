#pragma once
#include "Window.h"
#include "CardLibrary.h"
#include "MainMenuWindow.h"


//A window to view the card library and see the possible cards which the game has including ones not in a user's collection 

class CardLibraryWindow :
    public Window
{
public:
  //Constructor & Destructor
  CardLibraryWindow(HINSTANCE hInsantce, int width, int height);

  ~CardLibraryWindow();

private:
  //Normal EasyGraphics Methods
  void onDraw();
  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);


};

