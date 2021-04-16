#include "CardLibraryWindow.h"

CardLibraryWindow::CardLibraryWindow() {

}

CardLibraryWindow::CardLibraryWindow(HINSTANCE hInsantce, int width, int height) : Window(hInsantce,width,height)
{
  createWindow(hInsantce, width, height);
}

CardLibraryWindow::~CardLibraryWindow(){

}

void CardLibraryWindow::onDraw()
{

  drawBitmap(backgroundFile, 0, 0, width, height);
  setTextColour(CYAN);
  //Title
  setFont(28, L"Univers Bold");
  drawText(L"Card Library", 300, 35);
  //25-950 x 100-480
  const int xSpace = 925;
  const int ySpace = 380;

  CardLibrary* instance = CardLibrary::returnInstance();

  vector<Card*> *listOfCards  = instance->returnList();

  const int cardWidth=100;
  const int cardHeight=130;
  int row=0;
  for (int counter = 1; counter < listOfCards->size()+1; counter++) {
    listOfCards->at(counter-1)->draw(this, 25 + (counter%8)*(cardWidth+15), 100 + (row) * (cardHeight) -10, cardWidth, cardHeight);
    if (counter % 8 == 0 && counter !=0) {
      row++;
    }
  }

  //Back to Menu Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(880, 500, 85, 30, true);
  drawText(L"Main Menu", 885, 505);

  Window::onDraw();

}

void CardLibraryWindow::onCreate()
{
  Window::onCreate();
  SetWindowText(getHWND(), L"Card Library");

}

void CardLibraryWindow::onLButtonDown(UINT nFlags, int x, int y)
{
  //Main Menu Button   drawRectangle(880, 500, 85, 30, true);
  if (x > 880 && x < 965 && y>500 && y < 530) {
    MainMenuWindow* main = new MainMenuWindow(hInstance, 600, 400);
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
  else {
   
  }
}

