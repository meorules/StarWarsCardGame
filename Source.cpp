#include <Windows.h>;
#include <crtdbg.h>
#include "MainMenuWindow.h"
#include "CardLibrary.h"
#include "Users.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int show) {
  //Checking Memory Leaks and dumping them on Exit of the application 
#ifdef _DEBUG
  _onexit(_CrtDumpMemoryLeaks);
#endif
  //Returning the singleton instances in the order in which they depend on each other
  SpecialAbilities::returnInstance();
  CardLibrary::returnInstance();
  Users::returnInstance();

  //Calling and creating the main menu window which leads to all other windows
  MainMenuWindow* main = new MainMenuWindow(hInstance,600,400);
  main->waitForClose();
  delete main;

  //Releasing the various singletons in the order they depend on each other
  Users::releaseInstance();
  CardLibrary::releaseInstance();
  SpecialAbilities::releaseInstance();

  return 0;
}