
#include "MainMenuWindow.h"


MainMenuWindow::MainMenuWindow(HINSTANCE hInsantce, int width, int height) : Window(hInsantce, width, height)
{
  createWindow(hInstance, width, height);
  currentState = currentstate::browsing;
}

void MainMenuWindow::onDraw() {

  drawBitmap(backgroundFile, 0, 0, 600, 400);
  setTextColour(CYAN);

  setFont(28, L"Ebrima Bold");
  drawText(L"Main Menu", 300, 35);

  //Output Text
  setFont(12, L"Times New Roman Bold");
  drawText(outputText.c_str(), 75, 300);

  //Username Label & Box
  setTextColour(YELLOW);
  drawRectangle(125, 200, 200, 20, false);
  drawText(L"Username:", 50, 200);
  setTextColour(WHITE);
  drawText(currentusernamefield.c_str(), 126, 201);

  //Password Label & Box
  setTextColour(YELLOW);
  drawRectangle(125, 230, 200, 20, false);
  drawText(L"Password:", 55, 230);
  setTextColour(WHITE);
  drawText(currentpasswordfield.c_str(), 126, 231);

  //Sign Up Button
  setFont(12, L"News Gothic Bold");
  setBackColour(DARK_BLUE);
  setTextColour(WHITE);

  drawRectangle(370, 185, 60, 30, true);
  drawText(L"Sign-up", 372, 190);

  //Add Login logic
  drawRectangle(370, 225, 60, 30, true);
  drawText(L"Login", 380, 230);

  //Add Card Library Logic
  drawRectangle(450, 205, 100, 40, true);
  drawText(L"Card Library", 455, 215);

  //Basic onDraw() 
  Window::onDraw();
}

void MainMenuWindow::onCreate()
{
  Window::onCreate();
  outputText = "Please enter a username and password to create an account or login";  
  SetWindowText(getHWND(), L"Main Menu");

}

void MainMenuWindow::onLButtonDown(UINT nFlags, int x, int y)
{
  //Collecting Username
  if (x > 125 && x < 325 && y>200 && y < 220) {
    currentState = currentstate::collectingUsername;
  }
  //Collecting Password
  else if (x > 125 && x < 325 && y>230 && y < 250) {
    currentState = currentstate::collectingPassword;
  }
  //Sign up Button  drawRectangle(370, 185, 60, 30, true);
  else if (x>370 && x<430 && y>185 && y<215) {
    if (!((currentusernamefield == "" || currentusernamefield == " ") || (currentpasswordfield == "" || currentpasswordfield == " ") )) {
      int found = Users::returnInstance()->findUser(User(currentusernamefield));
      if (found == -1) {
        Users::returnInstance()->addUser(*(new User(currentusernamefield, currentpasswordfield, 0, 0, 0)));
        currentusernamefield = "";
        currentpasswordfield = "";
      }
      else {
        outputText = "Username is already taken";
      }
    }
    else {
      outputText = "Username and/or Password cannot be empty";
    }
  }
  //Login Button  drawRectangle(370, 225, 60, 30, true);
  //NEEDS TO BE WORKED ON 
  else if (x > 370 && x < 430 && y>225 && y < 255) {
    int found= Users::returnInstance()->findUser(User(currentusernamefield));
    if (found!=-1) {
      if (Users::returnInstance()->checkPassword(found, currentpasswordfield) == true) {
        UserMenuWindow* main = new UserMenuWindow(hInstance, 600, 400, Users::returnInstance()->returnUser(found));
        DestroyWindow(getHWND());
        main->waitForClose();
        delete main;
      }
      else {
        outputText = "Password is incorrect";
      }
    }
    else {
      outputText = "Username not found";
    }
  }
  // Card Library Button drawRectangle(450, 205, 100, 40, true);
  else if (x > 450 && x < 550 && y>205 && y < 245) {
    CardLibraryWindow* main = new CardLibraryWindow(hInstance, 1000, 600);
    DestroyWindow(getHWND());
    main->waitForClose();
    delete main;
  }
  //Default 
  else{
    currentState = currentstate::browsing;
  }
  onDraw();
}

void MainMenuWindow::onChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{

  string character = string(1, char(nChar));

  if (currentState == currentstate::collectingUsername) {
    if (nChar == 8) {
      currentusernamefield = currentusernamefield.substr(0, currentusernamefield.length() - 1);
    }
    else {
      if (currentusernamefield.length() < 25) {
        currentusernamefield = currentusernamefield + character;
      }
      else {
        outputText = "The username field has exceeded the limit of 24 characters";
      }
    }
  }
  else if (currentState == currentstate::collectingPassword) {
    if (nChar == 8) {
      currentpasswordfield = currentpasswordfield.substr(0, currentpasswordfield.length() - 1);
    }
    else {
      if (currentpasswordfield.length() < 25) {
        currentpasswordfield = currentpasswordfield + character;
      }
      else {
        outputText = "The password field has exceeded the limit of 24 characters";
      }
    }
  }

  if (currentusernamefield.length() < 25 && currentpasswordfield.length() < 25) {
    outputText = "Please enter a username and password to create an account or login";
  }

  onDraw();
}
