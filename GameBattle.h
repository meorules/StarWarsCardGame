#pragma once
#include "Opponent.h"

//Card Stat Enum exists in this class for use in communication to the card class and other classes. 
enum class cardStat {
  force, melee, block, gunnin,ability, none
};

//Card Type to help differentiate between possible user and opponent (AI) actions
enum class cardType {
  fighting, special, ability,none
};

//Opponent attack structure to store all data surrounding opponent attacks 
struct oppAttack {
  Card* attackingCard;
  cardType attackType;
  cardStat attackStat;
};

//Game Battle class meant to handle all gamebattles and interfaces with the card battle window class

class GameBattle
{
public:
  //Constructor & Destructor
  GameBattle(User* user);
  GameBattle();
  ~GameBattle();

  //Friends with the card battle window class to allow for access into private data members
  friend class CardBattleWindow;

  
private:
  //Method to allow for applying stat changes to specific cards and whether they are user or opponent cards
  void applyStatChange(int statToChange, int change, bool isUser);

  //Retrieving opponent cards by index 
  Card* getOpponentDeck(int index);

  //Retrieving user cards by index 
  Card* getUserDeck(int index);

  //Holding user deck size which is used to return the actual amount of cards left in the user deck 
  inline int getUserDeckSize() { return userCardDeckSize; }

  //Methods to remove cards from user and opponent decks and the second purely removing cards in order of index
  void removeCard(Card* toRemove, bool isUser);

  void removeCard(bool isUser);

  //The main opponent attack method which returns the possible structure containing the details of the card type and stat which will be used
  //Used for decision making in the CardBattleWindow class 
  oppAttack opponentAttack();

  //Commencing a straight head to head card battle starting from the user's selected card and selected stat also handles opponent defence
  string cardBattle(Card* userCard, cardStat competingStat);

  //Int keeping track of the game's current state ( Set to -1 when running and otherwise when ending)
  int gameEnd();

  //Opponent and user variables and scores
  Opponent opponent;
  User* currentUser;
  int userScore;
  int opponentScore;

  //Copies of the decks of opponents and users as to not affect original cards outside of this
  Card* userCardDeck[5];
  Card* opponentCardDeck[5];
  int userCardDeckSize;
  int opponentCardDeckSize;

  //A variable to store whether it's the user's turn to attack or defend
  bool userTurn;

  //A method used in the card battle to find the best opponent defensive stat
  FightingCard* opponentDefend(cardStat toDefend);
  //A method to find the first ability card of an opponent to use in an attack
  int findFirstOpponentAbility();
  //A method to find the highest possible stat available in the opponent's deck
  oppAttack findBestOpponentStat();
};

