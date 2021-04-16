#pragma once
#include "Window.h"
#include "CardLibraryWindow.h"
#include "UserMenuWindow.h"

using namespace std;

class MainMenuWindow :
    public Window
{
public:
  MainMenuWindow(HINSTANCE hInsantce, int width, int height);
  MainMenuWindow();
  ~MainMenuWindow();

private:
  virtual void onDraw();
  virtual void onCreate();
  virtual void onLButtonDown(UINT nFlags, int x, int y);
  virtual void onChar(UINT nChar, UINT nRepCnt, UINT nFlags);


  enum currentState {
    browsing, collectingUsername, collectingPassword
  };

  currentState currentState;


  string outputText;
  string currentusernamefield;
  string currentpasswordfield;

  

};

inline MainMenuWindow::MainMenuWindow() {
}

inline MainMenuWindow::~MainMenuWindow() {

}
