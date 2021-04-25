#include <Windows.h>;
#include <crtdbg.h>
#include "MainMenuWindow.h"
#include "CardLibrary.h"
#include "Users.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int show) {
#ifdef _DEBUG
  _onexit(_CrtDumpMemoryLeaks);
#endif
  CardLibrary::returnInstance();
  Users::returnInstance();
  SpecialAbilities::returnInstance();

  MainMenuWindow* main = new MainMenuWindow(hInstance,600,400);
  main->waitForClose();
  delete main;

  Users::releaseInstance();
  CardLibrary::releaseInstance();
  SpecialAbilities::releaseInstance();

  return 0;
}