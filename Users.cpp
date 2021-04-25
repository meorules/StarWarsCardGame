#include "Users.h"

Users* Users::instance = nullptr;

void Users::loadUsers()
{
  ifstream fin;
  string fileName = ".\\saveData\\Users.txt";
  fin.open(fileName);

  if (fin) {
    string name, password;
    int wins, losses, draws;
    string cardNumber;
    vector <int> cardCollection;
    User* currentUser;

    while (!fin.eof()) {
      fin >> name >> password >> wins >> losses >> draws >> cardNumber;
      while (cardNumber != "/") {
        cardCollection.push_back(stoi(cardNumber));
        fin >> cardNumber;
      }
      currentUser = new User(name, password, wins, losses, draws, cardCollection);
      instance->userList->addItem(*currentUser);
      cardCollection.clear();
    }
  }
}

void Users::saveUsers()
{
  ofstream fout;
  string fileName = ".\\saveData\\Users.txt";
  fout.open(fileName);

  if (fout) {
    for (int j = 0; j < instance->userList->returnList()->size(); j++) {
      User* currentUser = instance->returnUser(j);
      int cardNumber;
      fout << currentUser->userName<< " " << currentUser->password << " "<< currentUser->getWins() <<" " << currentUser->getLosses() <<" " << currentUser->getDraws();
      for (int i = 0; i < currentUser->cardCollection.returnList()->size(); i++) {
        cardNumber = CardLibrary::returnInstance()->findCardIndex(currentUser->cardCollection.returnList()->at(i));
        fout << " "<< cardNumber;
      }
      fout << " /";
      if (j != instance->userList->returnList()->size() - 1) {
        fout << endl;
      }
    }
  }

}

Users* Users::returnInstance()
{
  if (instance == nullptr) {
    instance = new Users();
    loadUsers();
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
  saveUsers();
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