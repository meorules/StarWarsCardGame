#pragma once
#include "Opponent.h"

enum class cardStat {
  force, melee, block, gunnin,ability, none
};

enum class cardType {
  fighting, special, ability,none
};

struct oppAttack {
  Card* attackingCard;
  cardType attackType;
  cardStat attackStat;
};

class GameBattle
{
public:
  GameBattle(User* user);
  GameBattle();
  ~GameBattle();

  friend class CardBattleWindow;

  void applyStatChange(int statToChange, int change, bool isUser);
  
  Card* getOpponentDeck(int index);

  Card* getUserDeck(int index);

  inline int getUserDeckSize() { return userCardDeckSize; }

  void removeCard(Card* toRemove,bool isUser);

  void removeCard(bool isUser);

  oppAttack opponentAttack();

  string cardBattle(Card* userCard, cardStat competingStat);

  int gameEnd();

private:
  Opponent opponent;
  User* currentUser;
  int userScore;
  int opponentScore;

  Card* userCardDeck[5];
  Card* opponentCardDeck[5];
  int userCardDeckSize;
  int opponentCardDeckSize;

  bool userTurn;

  FightingCard* opponentDefend(cardStat toDefend);
  int findFirstOpponentAbility();
  oppAttack findBestOpponentStat();
};

