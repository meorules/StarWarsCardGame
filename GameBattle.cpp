#include "GameBattle.h"

GameBattle::GameBattle(User* user) : userScore(0),opponentScore(0)
{
  currentUser = user;
  opponent = Opponent(user);
  userCardDeckSize = opponentCardDeckSize = 0;
  for (int i = 0; i < 5; i++) {
    userCardDeck[i] = user->returnCardDeck(i)->copyCard();
    opponentCardDeck[i] = opponent.returnCardDeck(i)->copyCard();
    userCardDeckSize++;
    opponentCardDeckSize++;
  }
  userTurn = true;
}

GameBattle::GameBattle() {

}

GameBattle::~GameBattle()
{

}


void GameBattle::applyStatChange(int statToChange, int change, bool isUser)
{
  FightingCard* fC = nullptr;

  if (isUser) {
    //Apply buff or debuff on user cards
    for (int i = 0; i < userCardDeckSize; i++) {
      fC = dynamic_cast<FightingCard*>(userCardDeck[i]);
      if (fC != nullptr) {
        fC->changeStat(change, statToChange);
      }
    }
  }
  else {
    //Apply buff or debuff on opponent cards
    for (int i = 0; i < opponentCardDeckSize; i++) {
      fC = dynamic_cast<FightingCard*>(opponentCardDeck[i]);
      if (fC != nullptr) {
        fC->changeStat(change,statToChange);
      }
    }
  }
}

Card* GameBattle::getOpponentDeck(int index)
{
  return opponentCardDeck[index];
}

Card* GameBattle::getUserDeck(int index)
{
  return userCardDeck[index];
}

void GameBattle::removeCard(Card* toRemove, bool isUser)
{
  if (isUser) {
    int i = 0;
    int j = 0;
    for (i; i < userCardDeckSize; i++) {
      if (userCardDeck[i] == toRemove) {
        break;
      }
    }
    for (j = i; j < userCardDeckSize - 1; j++) {
      userCardDeck[j] = userCardDeck[j + 1];
    }
    userCardDeck[j] = nullptr;
    userCardDeckSize--;
  }
  else {
    int i = 0;
    int j = 0;
    for (i; i < opponentCardDeckSize; i++) {
      if (opponentCardDeck[i] == toRemove) {
        break;
      }
    }
    for (j = i; j < opponentCardDeckSize-1; j++) {
      opponentCardDeck[j] = opponentCardDeck[j + 1];
    }
    opponentCardDeck[j] = nullptr;
    opponentCardDeckSize--;
  }
}

void GameBattle::removeCard(bool isUser)
{
  if (isUser) {
    int j;
    for (j = 0; j < userCardDeckSize - 1; j++) {
      userCardDeck[j] = userCardDeck[j + 1];
    }
    userCardDeck[j] = nullptr;
    userCardDeckSize--;
  }
  else {
    int j;
    for (j = 0; j < opponentCardDeckSize - 1; j++) {
      opponentCardDeck[j] = opponentCardDeck[j + 1];
    }
    opponentCardDeck[j] = nullptr;
    opponentCardDeckSize--;
  }
}

oppAttack GameBattle::opponentAttack()
{
  oppAttack toReturn;
  int ability = findFirstOpponentAbility();
  if (ability != -1 && ability < 5) {
    toReturn.attackingCard = opponentCardDeck[ability];
    toReturn.attackStat = cardStat::ability;
    toReturn.attackType = cardType::ability;
  }
  else {
    toReturn = findBestOpponentStat();
  }
  return toReturn;
}

FightingCard* GameBattle::opponentDefend(cardStat toDefend)
{
  FightingCard* fC = nullptr;
  int maxStat = 0;
  FightingCard* maxCard=nullptr;
  for (int i = 0; i < opponentCardDeckSize; i++) {
    fC = dynamic_cast<FightingCard*>(opponentCardDeck[i]);
    if (fC != nullptr) {
      if (fC->checkStat(static_cast<int>(toDefend)) > maxStat) {
        maxStat = fC->checkStat(static_cast<int>(toDefend));
        maxCard = fC;
      }
    }
  }
  return maxCard;
}

string GameBattle::cardBattle(Card* userCard, cardStat competingStat)
{
  FightingCard* opponentCard = opponentDefend(competingStat);
  FightingCard* userFightingCard = dynamic_cast<FightingCard*>(userCard);
  if (userFightingCard != nullptr && opponentCard !=nullptr) {
    int userStat= userFightingCard->checkStat(static_cast<int>(competingStat));
    int opponentStat = opponentCard->checkStat(static_cast<int>(competingStat));
    string toReturn = "The opponent defended with " + opponentCard->getCardName(); +" who has a value of " + to_string(opponentStat);
      if (userStat > opponentStat) {
        userScore+=3;
        toReturn += ". But you won :)";
      }
      else if (opponentStat > userStat) {
        opponentScore += 3;
        toReturn += " and beat you :(";
      }
      else {
        userScore++;
        opponentScore++;
        toReturn += " and you drew :|";
      }
      removeCard(opponentCard, false);
      removeCard(userFightingCard, true);
      return toReturn;
  }
  else if (userFightingCard != nullptr && opponentCard == nullptr) {
    removeCard(userFightingCard, true);
    removeCard(false);
    userScore+=3;
  }
  
}

int GameBattle::gameEnd()
{
  bool gameResult = false;
  if (userCardDeckSize == 0 && opponentCardDeckSize==0) {
    gameResult = true;
  }
  else if (userCardDeckSize != 0 && opponentCardDeckSize == 0) {
    for (int i = 0; i < userCardDeckSize; i++) {
      removeCard(userCardDeck[i], true);
      userScore++;
    }
    gameResult = true;
  }
  else if(userCardDeckSize == 0 && opponentCardDeckSize != 0){
    for (int i = 0; i < opponentCardDeckSize; i++) {
      removeCard(opponentCardDeck[i], false);
      opponentScore++;
    }
    gameResult = true;
  }
  if (gameResult) {
    if (userScore > opponentScore) {
      return 1;
    }
    else if (userScore < opponentScore) {
      return 2;
    }
    else {
      return 0;
    }
  }
  return -1;
}

int GameBattle::findFirstOpponentAbility()
{
  for (int i = 0; i < opponentCardDeckSize; i++) {
    if (dynamic_cast<AbilityCard*>(opponentCardDeck[i]) != nullptr) {
      return i;
    }
  }
  return -1;
}

oppAttack GameBattle::findBestOpponentStat()
{
  FightingCard* fC = nullptr;
  int maxStat = 0;
  cardStat maxStatType = cardStat::none;
  FightingCard* maxCard = nullptr;
  for (int i = 0; i < opponentCardDeckSize; i++) {
    fC = dynamic_cast<FightingCard*>(opponentCardDeck[i]);
    if (fC != nullptr) {
      for (int j = 0; j < 4; j++) {
        if (fC->checkStat(static_cast<int>(j)) > maxStat) {
          maxStat = fC->checkStat(static_cast<int>(j));
          maxCard = fC;
          maxStatType = static_cast<cardStat>(j);
        }
      }
    }
  }
  oppAttack toReturn;
  toReturn.attackingCard = maxCard;
  toReturn.attackStat = maxStatType;
  toReturn.attackType = cardType::fighting;

  return toReturn;
}
