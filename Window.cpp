#include "Window.h"

//Basic window constructor
Window::Window() 
{
}

Window::~Window() {}
//Window constructor to be used when creating other windows
Window::Window(HINSTANCE hInsantce, int width, int height) :hInstance(hInsantce),width(width),height(height)
{
}

//onDraw to draw the basics of every window including the background and main title
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
//The onCreate and creating the refresh so there is no lag between drawing
void Window::onCreate() {
  EasyGraphics::onCreate();
  setImmediateDrawMode(false);

}
//Empty method to make this class not abstract
void Window::onChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
}

//Create window method to be used by inheriting windows
void Window::createWindow(HINSTANCE hInsantce, int width, int height)
{
  create(hInstance, width, height, 50, false);

}
