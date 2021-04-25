#pragma once
#include <vector>
#include <string>
//Template class used for managing basic vector needs which I found to be more useful than standard vector uses
using namespace std;

//Start of the template class
template <class listType> 
class listTemplate 
{
public:
  //Basic constructors and destructor including one which takes a vector to start with 
  listTemplate();
  listTemplate(vector<listType> typeList);
  ~listTemplate();

  //Basic methods used in vector management
  int findItem(listType itemToFind);
  bool deleteItem (listType username);
  void addItem(listType newItem);

  //Returning the vector itself if need be
  vector<listType>* returnList();

private:
  //The vector itself
  vector <listType> list;

};

//Normal constructor
template <class listType>
listTemplate<listType>::listTemplate(vector<listType> typeList)
{
  list = typeList;
}

template<class listType>
inline listTemplate<listType>::listTemplate()
{
}

template<class listType>
inline listTemplate<listType>::~listTemplate()
{
}

//Using operator overloading to make the equal for a specific data type return what I am searching for
template<class listType>
inline int listTemplate<listType>::findItem(listType itemToFind)
{
  for (int counter = 0; counter < list.size(); counter++) {
    bool check = list.at(counter) == itemToFind;
    if (check) {
      return counter;
    }
  }
  
  return -1;
}

template<class listType>
inline vector<listType>* listTemplate<listType>::returnList()
{
  return &list;
}

//Deleting items (Although not used) 
template<class listType>
inline bool listTemplate<listType>::deleteItem(listType username)
{
  int found = findItem(username);
  if (found != -1) {
    list.erase(found+list.begin());
    return true;
  }
  return false;
}

//Adding items if they don't already exist making sure each item added is unique
template<class listType>
inline void listTemplate<listType>::addItem(listType newItem)
{
  if (findItem(newItem) == -1) {
    list.push_back(newItem);
  }
}
