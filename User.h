#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "CardLibrary.h"
#include <random>
#include <algorithm>
#include <set>

struct gameRecord {
  int wins;
  int losses;
  gameRecord(int w,int l) : wins(w),losses(l){}
};

using namespace std;
class User
{
public:
  User(string username, string password,int wins,int losses);
  User(string username);
  ~User();

  bool checkPassword(string currentPassword);
  string getName();

  void addCardToDeck(Card* newCard);
  Card* returnCardDeck(int index);
  int checkCardInDeck(Card* cardToCheck);
  int checkCardInCollection(Card* cardToCheck);
  void replaceCardinDeck(int toReplace, Card* newCard);

  int getWins();
  int getLosses();


  vector<Card*>* returnCardCollection();

  bool operator==(const User& rhs) const;

private:
  string userName;
  string password;
  gameRecord userRecord;
  listTemplate<Card*> cardCollection;
  Card* cardDeck[5];
  vector<int> cardOrder;

};

