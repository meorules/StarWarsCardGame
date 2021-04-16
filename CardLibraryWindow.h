#pragma once
#include "Window.h"
#include "CardLibrary.h"
#include "MainMenuWindow.h"

class CardLibraryWindow :
    public Window
{
public:
  CardLibraryWindow();
  CardLibraryWindow(HINSTANCE hInsantce, int width, int height);

  ~CardLibraryWindow();

private:
  void onDraw();
  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);


};

