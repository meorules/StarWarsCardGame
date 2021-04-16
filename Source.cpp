#include <Windows.h>;
#include <crtdbg.h>
#include "MainMenuWindow.h"
#include "CardLibrary.h"
#include "Users.h"
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int show) {
#ifdef _DEBUG
  _onexit(_CrtDumpMemoryLeaks);
#endif
  Users* usersdatabase = Users::returnInstance();
  User admin = User("", "", 0, 0);
  Users::returnInstance()->addUser(admin);
  SpecialAbilities::returnInstance();
  CardLibrary* cardDatabase = CardLibrary::returnInstance();
  

  MainMenuWindow* main = new MainMenuWindow(hInstance,600,400);
  
  main->waitForClose();
  delete main;


  Users::releaseInstance();

  CardLibrary::releaseInstance();

  return 0;
}