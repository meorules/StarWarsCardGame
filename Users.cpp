#include "Users.h"

Users* Users::instance = nullptr;



Users* Users::returnInstance()
{
  if (instance == nullptr) {
    instance = new Users();
  }
  return instance;
}

void Users::releaseInstance()
{
  delete instance;
}


Users::Users()
{
  userList = new listTemplate<User>();
}

bool Users::deleteUser(User newUser)
{
  return userList->deleteItem(newUser);
}

Users::~Users()
{
}

void Users::addUser(User newUser)
{
  userList->addItem(newUser);
}

int Users::findUser(User userName)
{
  return userList->findItem(userName);
}


User* Users::returnUser(int index)
{
  return &userList->returnList()->at(index);
}

bool Users::checkPassword(int index, string password) const
{
  vector<User>* listOfUsers = userList->returnList();
  return listOfUsers->at(index).checkPassword(password);
}