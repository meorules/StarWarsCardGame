#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "CardLibrary.h"
#include <stdlib.h>
#include <time.h>
//A struct to store wins, losses and draws of a user, also used in opponent
struct gameRecord {
  int wins;
  int losses;
  int draws;
  //Basic constructor to set variables quickly
  gameRecord(int w,int l,int d) : wins(w),losses(l),draws(d){}
  
  //Basic constructor to set variables to 0
  gameRecord(){
    losses = wins = draws = 0;
  }
};

using namespace std;
class User
{
  //Making Users a friend class to allow for easier access as it is a list of this type
  friend class Users;

public:
  //Various constructors used in sign up or during the loading of users from the text file along with the destructor
  User(string username, string password,int wins,int losses,int draws);
  User(string username, string password, int wins, int losses,int draws,vector<int> cardIndices);
  User(string username);
  ~User();

  //Checking password for sign in purposes by passing in attempts rather than checking it from outside
  bool checkPassword(string currentPassword);

  //Getting a user's name for drawing 
  string getName();

  //Adding a random card on win conditions
  void addRandomCard();

  //User Card Deck & Card Collection operations
  void addCardToDeck(Card* newCard);
  Card* returnCardDeck(int index);
  int checkCardInDeck(Card* cardToCheck);
  int checkCardInCollection(Card* cardToCheck);
  void replaceCardinDeck(int toReplace, Card* newCard);

  //Using gamerecord portion of users to set or retrieve them
  int getWins() {return userRecord.wins;}
  int getLosses() {return userRecord.losses;}
  int getDraws(){ return userRecord.draws;}

  void addWin() { userRecord.wins++; }
  void addLoss() { userRecord.losses++; }
  void addDraw() { userRecord.draws++; }

  //Returning the user's full collection 
  vector<Card*>* returnCardCollection();

  //Overloading the == equal operator to making finding items using the template easier
  bool operator==(const User& rhs) const;

private:
  //method used only inside this class and variables which should not be accessible otherwise ( or sometimes from getters)
  void addCardToCollection(int index);
  string userName;
  string password;
  gameRecord userRecord;
  listTemplate<Card*> cardCollection;
  Card* cardDeck[5];

};

