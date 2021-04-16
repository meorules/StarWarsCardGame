#pragma once
#include "User.h"
#include "listTemplate.h"
class Users
{
public:
  ~Users();
  void addUser(User newUser);
  bool deleteUser(User newUser);
  int findUser(User userName);
  User* returnUser(int index);

  bool checkPassword(int index, string password) const; 

  static Users* returnInstance();
  static void releaseInstance();

private:
  Users();

  listTemplate<User>* userList;
  static Users* instance;

};

