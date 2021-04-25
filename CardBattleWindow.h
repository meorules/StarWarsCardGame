#pragma once
#include "Window.h"
#include "UserMenuWindow.h"
#include "listTemplate.h"
#include "GameBattle.h"
#include <functional>
#include <string>

using namespace std;

//The main window in which a battle would take place. Handles a lot of battle activity including the storage of the game battle class

class CardBattleWindow :
    public Window
{
public:
  //Constructor & Destructor
  CardBattleWindow(HINSTANCE hInsantce, int width, int height, User* currentUser);
  ~CardBattleWindow();

private:
  //Draw method for the window
  void onDraw();

  //Normal Easygraphics methods
  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);

  //Resetting Selected Menu Options
  void resetSelected();
  //Making opponent attack after user turn
  void opponentAttackChoices();
  
  //Window variables text values, and selected options
  string outputText;
  GameBattle battle;
  cardType selectedUserCardType;
  User* currentMenuUser;
  Card* selectedUserCard;
  cardStat userSelectedStat;

  //Used for runtime type information conversion 
  FightingCard* fC =nullptr;
  SpecialFightingCard* sFC = nullptr;
  AbilityCard* aC = nullptr;

  //const information for card drawing
  const int cardWidth = 120;
  const int cardHeight = 150;

  //Opponent attack to determine how the use should react
  oppAttack attack;

  //Game end / win conditions
  int gameEndState;
};

