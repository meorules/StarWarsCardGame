#pragma once
#include <vector>
#include <string>

using namespace std;

template <class listType> 
class listTemplate 
{
public:
  listTemplate();
  listTemplate(vector<listType> typeList);
  ~listTemplate();

  int findItem(listType itemToFind);
  bool deleteItem (listType username);
  void addItem(listType newItem);

  vector<listType>* returnList();

private:
  vector <listType> list;

};

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

//USE OPERATOR OVERLOADING TO GET THE EQUAL OPERATOR TO EQUAL WHAT I AM SEARCHING FOR
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

template<class listType>
inline void listTemplate<listType>::addItem(listType newItem)
{
  if (findItem(newItem) == -1) {
    list.push_back(newItem);
  }
}
