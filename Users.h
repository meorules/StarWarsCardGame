#pragma once
#include "User.h"
#include "listTemplate.h"
#include <fstream>

class Users
{
public:
  ~Users();
  void addUser(User newUser);
  int findUser(User userName);
  User* returnUser(int index);

  bool checkPassword(int index, string password) const; 

  static Users* returnInstance();
  static void releaseInstance();

private:
  Users();
  bool deleteUser(User newUser);
  listTemplate<User>* userList;
  static Users* instance;
  static void loadUsers();
  static void saveUsers();
};

