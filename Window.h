#pragma once
#include "EasyGraphics.h"
#include "CardLibrary.h"
#include "Users.h"
#include <string>

//Basic window which all windows inherit from full of virtual functions and different variables used by all windows 

class Window : public EasyGraphics
{
public:
  //Constructors and destructor
  Window();
  Window(HINSTANCE hInsantce, int width, int height);
  ~Window();


protected:
  //Various easygraphics methods overridden by various inheriting classes
  virtual void onDraw();
  virtual void onCreate();
  virtual void onLButtonDown(UINT nFlags, int x, int y) = 0;
  virtual void onChar(UINT nChar, UINT nRepCnt, UINT nFlags);

  //Required to create the windows
  HINSTANCE hInstance;

  void createWindow(HINSTANCE hInsantce, int width, int height);

  int width, height;
  //Keeping the background constant throughout all the windows. 
  const wchar_t* backgroundFile = L".\\imageAssets\\background.bmp";  
};

