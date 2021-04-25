#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "CardLibrary.h"
#include <stdlib.h>
#include <time.h>

struct gameRecord {
  int wins;
  int losses;
  int draws;
  gameRecord(int w,int l,int d) : wins(w),losses(l),draws(d){}

  gameRecord(){
    losses = wins = 0;
  }
};

using namespace std;
class User
{

  friend class Users;

public:
  User(string username, string password,int wins,int losses,int draws);
  User(string username, string password, int wins, int losses,int draws,vector<int> cardIndices);
  User(string username);
  ~User();

  bool checkPassword(string currentPassword);
  string getName();

  void addRandomCard();
  void addCardToDeck(Card* newCard);
  Card* returnCardDeck(int index);
  int checkCardInDeck(Card* cardToCheck);
  int checkCardInCollection(Card* cardToCheck);
  void replaceCardinDeck(int toReplace, Card* newCard);

  int getWins() {return userRecord.wins;}
  int getLosses() {return userRecord.losses;}
  int getDraws(){ return userRecord.draws;}

  void addWin() { userRecord.wins++; }
  void addLoss() { userRecord.losses++; }
  void addDraw() { userRecord.draws++; }

  vector<Card*>* returnCardCollection();

  bool operator==(const User& rhs) const;

private:
  void addCardToCollection(int index);
  string userName;
  string password;
  gameRecord userRecord;
  listTemplate<Card*> cardCollection;
  Card* cardDeck[5];

};

