#include "Users.h"
//Setting up instance as null
Users* Users::instance = nullptr;

//Loading users from the text file and adding them to the user database along with their cards to their collections
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

//Saving the users back into the text file ( new users and old ones) and adding any new cards to their collection
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

//Returning the singleton instance
Users* Users::returnInstance()
{
  if (instance == nullptr) {
    instance = new Users();
    loadUsers();
  }
  return instance;
}

//Deleting the instance
void Users::releaseInstance()
{
  saveUsers();
  delete instance;
}

//Creating the list
Users::Users()
{
  userList = new listTemplate<User>();
}
//Function overhead for deleting users
bool Users::deleteUser(User newUser)
{
  return userList->deleteItem(newUser);
}
//On Deletion of the users they must be saved
Users::~Users()
{
  for (int i = 0; i < instance->userList->returnList()->size(); i++) {
    instance->deleteUser(instance->userList->returnList()->at(i));
  }
}
//Function overhead for adding users
void Users::addUser(User newUser)
{
  userList->addItem(newUser);
}
//Function overhead for finding users
int Users::findUser(User userName)
{
  return userList->findItem(userName);
}

//Function overhead for returning users at position index in the database
User* Users::returnUser(int index)
{
  return &userList->returnList()->at(index);
}
//Checking password of user using their index (Function overhead for checking it on the specific object)
bool Users::checkPassword(int index, string password) const
{
  vector<User>* listOfUsers = userList->returnList();
  return listOfUsers->at(index).checkPassword(password);
  delete listOfUsers;
}