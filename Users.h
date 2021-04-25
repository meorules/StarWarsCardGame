#pragma once
#include "User.h"
#include "listTemplate.h"
#include <fstream>

//The 3rd and final singleton class meant to store all users of the game and includes loading and saving user data into Users.txt

class Users
{
public:
  ~Users();
  //Various methods as overheads for using template methods
  void addUser(User newUser);
  int findUser(User userName);
  User* returnUser(int index);

  //Checking password by user index rather than calling it on users themselves
  bool checkPassword(int index, string password) const; 

  //Normal singleton methods
  static Users* returnInstance();
  static void releaseInstance();

private:
  //Private constructor and various functions only used in this class and member variables should only be accessed from here. 
  Users();
  bool deleteUser(User newUser);
  listTemplate<User>* userList;
  static Users* instance;
  static void loadUsers();
  static void saveUsers();
};

