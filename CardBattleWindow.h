#pragma once
#include "Window.h"
#include "UserMenuWindow.h"
#include "listTemplate.h"

enum cardStat {
  nothing,force,melee,block,gunnin,specialability
};

enum cardType {
  none,fighting,special,ability
};
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
  void applyStatChange(bool isUser, cardStat, int change);

  string outputText;


  Card opponentDeck[5];
  User* opponent;
  Card* selectedAICard;
  int opponentScore;


  Card userDeck[5];
  cardType selectedUserCardType;
  User* currentMenuUser;
  Card* selectedUserCard;
  cardStat userSelectedStat;
  int userScore;


  FightingCard* fC =nullptr;
  SpecialFightingCard* sFC = nullptr;
  AbilityCard* aC = nullptr;

  const int cardWidth = 120;
  const int cardHeight = 150;
};

