#pragma once
#include "Window.h"
#include "UserMenuWindow.h"
#include "listTemplate.h"
#include "GameBattle.h"
#include <functional>
#include <string>

using namespace std;
using namespace std::placeholders;

class CardBattleWindow :
    public Window
{
public:
  CardBattleWindow(HINSTANCE hInsantce, int width, int height, User* currentUser);
  ~CardBattleWindow();


  void onDraw();

private:
  void onCreate();
  void onLButtonDown(UINT nFlags, int x, int y);
  void resetSelected();

  void opponentAttackChoices();
  
  string outputText;
  GameBattle battle;
  cardType selectedUserCardType;
  User* currentMenuUser;
  Card* selectedUserCard;
  cardStat userSelectedStat;

  FightingCard* fC =nullptr;
  SpecialFightingCard* sFC = nullptr;
  AbilityCard* aC = nullptr;

  const int cardWidth = 120;
  const int cardHeight = 150;

  oppAttack attack;

  int gameEndState;
};

