#include "UserMenuWindow.h"

UserMenuWindow::UserMenuWindow(HINSTANCE hInsantce, int width, int height, User* currentUser) : Window(hInsantce, width, height),currentMenuUser(currentUser)
{
  createWindow(hInsantce, width, height);
}

UserMenuWindow::~UserMenuWindow()
{
}

void UserMenuWindow::onDraw()
{

  drawBitmap(backgroundFile, 0, 0, width, height);
  setTextColour(CYAN);
  //Title
  setFont(28, L"Ebrima Bold");
  drawText(L"User Main Menu", 300, 35);

  //Currently Signed in as
  setFont(12, L"Times New Roman Bold");
  string userNameText = "Currently Signed in as " + currentMenuUser->getName();
  drawText(userNameText.c_str(), 10, 305);

  //Current User Record
  setFont(18, L"Ebrima Bold");
  drawText(L"Current Record", 10, 90);
  setFont(14, L"Ebrima Bold");
  drawText(L"Wins: ", 10, 120);
  drawText(L"Losses: ", 10, 150);
  drawText(L"Draws: ", 10, 180);
  drawText(to_string(currentMenuUser->getWins()).c_str(), 100, 120);
  drawText(to_string(currentMenuUser->getLosses()).c_str(), 100, 150);
  drawText(to_string(currentMenuUser->getDraws()).c_str(), 100, 180);




  int deckrandCard = rand() % 5;

  Card* deckcardtoDraw = currentMenuUser->returnCardDeck(deckrandCard);

  deckcardtoDraw->draw(this,370,85,100,130);

  //Change Card Deck Menu Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(350, 230, 140, 50, true);
  drawText(L"Check & Change", 355, 235);
  drawText(L"Current User Deck", 355, 255);

  vector<Card*>* cardLibrary = CardLibrary::returnInstance()->returnList();

  int randCard = rand() % 24;

  Card* cardtoDraw = cardLibrary->at(randCard);

  cardtoDraw->draw(this, 220, 85, 100, 130);

  //Card Battle Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(200, 230, 140, 50, true);
  drawText(L"Play a Game", 205, 235);
  drawText(L"Against the AI", 205, 255);

  

  //Back to Menu Button 
  setPenColour(16777215, 3);
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);
  drawRectangle(475, 300, 85, 30, true);
  drawText(L"Sign Out", 480, 305);

  Window::onDraw();
}

void UserMenuWindow::onCreate()
{
  Window::onCreate();
  SetWindowText(getHWND(), L"User Main Menu");
  setTimer(REDRAW_TIMER_ID, 3000);
  srand(time(NULL));
}

void UserMenuWindow::onLButtonDown(UINT nFlags, int x, int y)
{
  //Main Menu Button   drawRectangle(475,300 , 85, 30, true);
  if (x > 475 && x < 560 && y>300 && y < 330) {
    MainMenuWindow* main = new MainMenuWindow(hInstance, 600, 400);
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
  //Change Card Deck Menu Button   drawRectangle(350, 230, 140, 50, true);
  else if (x > 350 && x < 490 && y>230 && y < 280) {
    CardDeckWindow* main = new CardDeckWindow(hInstance, 1000, 800,currentMenuUser);
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
  //Card Battle Button     drawRectangle(200, 230, 140, 50, true);
  else if (x > 200 && x < 340 && y>230 && y < 280) {
    CardBattleWindow* main = new CardBattleWindow(hInstance, 1200, 800, currentMenuUser);
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
}

void UserMenuWindow::onTimer(UINT nIDEvent)
{
  if (nIDEvent == REDRAW_TIMER_ID)
    onDraw();
}
