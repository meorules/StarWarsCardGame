#pragma once
#include "Window.h"
#include "CardLibraryWindow.h"
#include "UserMenuWindow.h"

using namespace std;

//Main Menu Window, responsible for login and sign up of users. 

class MainMenuWindow :
    public Window
{
public:
  //Constructors & Destructor
  MainMenuWindow(HINSTANCE hInsantce, int width, int height);
  ~MainMenuWindow();

private:
  //EasyGraphics Methods Used for menu interaction and text entering
  virtual void onDraw();
  virtual void onCreate();
  virtual void onLButtonDown(UINT nFlags, int x, int y);
  virtual void onChar(UINT nChar, UINT nRepCnt, UINT nFlags);

  //an Enum holding the current state of this window to allow for text collection
  enum class currentstate {
    browsing, collectingUsername, collectingPassword
  };

  //The current state of the window
  currentstate currentState;

  //Various text variables required for the menu 
  string outputText;
  string currentusernamefield;
  string currentpasswordfield;

  

};


inline MainMenuWindow::~MainMenuWindow() {

}
