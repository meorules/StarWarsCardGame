#include "GameBattle.h"
//Game battle class constructor which takes in the user and uses it to create the opponent, copy their decks and set the user's turn to true
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
//GameBattle empty constructor used for conversion and use in creating the gamebattle then setting it to new using the other constructor
GameBattle::GameBattle() {

}
//GameBattle destructor 
GameBattle::~GameBattle()
{
  
}

//Function overhead for applying stat changes
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

//Returning the card from the deck in the index specified for the opponent
Card* GameBattle::getOpponentDeck(int index)
{
  return opponentCardDeck[index];
}

//Returning the card from the deck in the index specified for the user
Card* GameBattle::getUserDeck(int index)
{
  return userCardDeck[index];
}

//Removing the card passed and then the bool determines whether to remove it from the user's or opponent's deck
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

//Removing the first available card and the bool determines whether from the user's or opponent's deck
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

//The opponent attack which is returned to the card battle window for action and text proccessing, it finds the best option for the AI
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

//The Opponent defend which finds the best card to defend with based on the stat passed and passes that card back
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

//The card battle class which takes the user's card along with their chosen attack stat and then appropriately calls the opponent defend class
//And returns the required string text for the window
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
//The game end method which checks the current state of the battle and returns an int to confirm what is happening and whether
// the battle is continuing or whether the user has lost, won or drawn
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

//Looks through the opponent's deck to find an ability card and if it does not returns -1
int GameBattle::findFirstOpponentAbility()
{
  for (int i = 0; i < opponentCardDeckSize; i++) {
    if (dynamic_cast<AbilityCard*>(opponentCardDeck[i]) != nullptr) {
      return i;
    }
  }
  return -1;
}

//Looks through the opponent's cards to find the highes stat amongst all the cards they have and returns both that card, its type and the stat
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
