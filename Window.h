#pragma once
#include "EasyGraphics.h"
#include "CardLibrary.h"
#include "Users.h"
#include <string>

class Window : public EasyGraphics
{

public:
  Window();
  ~Window();
  Window(HINSTANCE hInsantce, int width, int height);


protected:
  virtual void onDraw();
  virtual void onCreate();
  virtual void onLButtonDown(UINT nFlags, int x, int y) = 0;
  virtual void onChar(UINT nChar, UINT nRepCnt, UINT nFlags);

  HINSTANCE hInstance;

  void createWindow(HINSTANCE hInsantce, int width, int height);

  int width, height;

  const wchar_t* backgroundFile = L".\\imageAssets\\background.bmp";

private:
  
};

