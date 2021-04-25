#include "Window.h"


Window::Window() 
{
}

Window::~Window() {}

Window::Window(HINSTANCE hInsantce, int width, int height) :hInstance(hInsantce),width(width),height(height)
{
}

void Window::onDraw()
{
  //Menu Title
  drawBitmap(L".\\imageAssets\\StarWarsLogo.bmp", 30, 30, 115, 50, 0x00FFFFFF);
  setTextColour(YELLOW);
  setFont(16, L"Ebrima Bold");
  drawText(L"Trading Card", 150, 30);
  setFont(24, L"Ebrima Bold");
  drawText(L"Game", 170, 45);
  setFont(52, L"Ebrima Bold");
  drawText(L":", 280, 0);


  EasyGraphics::onDraw();
}

void Window::onCreate() {
  EasyGraphics::onCreate();
  setImmediateDrawMode(false);

}

void Window::onChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

void Window::createWindow(HINSTANCE hInsantce, int width, int height)
{
  create(hInstance, width, height, 50, false);

}
