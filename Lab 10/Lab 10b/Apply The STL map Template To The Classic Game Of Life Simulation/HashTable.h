// Lab 10a, Write, Test, and Apply The HashTable Class Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <list>
#include <algorithm>
#include <vector>
using namespace std;

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<class T, class U, int CAPACITY>
class HashTable
{
  struct Node
  {
    T value;
    U key;
    //to support STL find, add this to Node
    void operator=(const T& v){value = v;}
    bool operator==(const Node& n) const {return key == n.key;}
  };
    int siz;
    static const int INIT_CAP = 50;
    T dummy;  //dummy variable
    list<Node> data[CAPACITY];
    int(*hashCode)(const U&); // as data member, "hashCode"

  public:
    HashTable(int(*)(const U&));// constructor prototype
    ~HashTable();
    int getWrappedIndex(const U&) const;
    T& operator[](const U&); // lookup key is an index
    T operator[](const U&) const;
    bool containsKey(const U&) const;
    void deleteKey(U);
    vector<U> keys() const; // all "in use" keys
    void clear();
    int capacity() const { return 0.8 * CAPACITY;} // rule of thumb
    int size() const {return siz;}

};

//constructor
template<class T, class U, int CAPACITY>
HashTable<T, U, CAPACITY>::HashTable(int(*a)(const U&))
{
  siz = 0;  //set siz equal to zero
  hashCode = a;
}

//destructor
template<class T, class U, int CAPACITY>
HashTable<T, U, CAPACITY>::~HashTable()
{
  int wrapppedIndexxx = 0;
  typename list<Node>::iterator it; // an uninitialized mutating pointer to a Node in a list [a local variable]
  for(it = data[wrapppedIndexxx].begin(); it != data[wrapppedIndexxx].end(); it++)
  {
    data[wrapppedIndexxx].erase(it);
  }
}

template<class T, class U, int CAPACITY>
int HashTable<T, U, CAPACITY>::getWrappedIndex(const U& key) const
{
  // the wrapped index, in the range 0 to N-1 [a local variable]
  int wrapppedIndexxx = hashCode(key) % CAPACITY;
  if(wrapppedIndexxx < 0)
  {
    wrapppedIndexxx = wrapppedIndexxx + CAPACITY;
  }
  return wrapppedIndexxx;
}

template<class T, class U, int CAPACITY>
bool HashTable<T, U, CAPACITY>::containsKey(const U& key) const
{
  int wrapppedIndexxx = getWrappedIndex(key);// the wrapped index, in the range 0 to N-1 [a local variable]
  typename list<Node>::const_iterator it; // an uninitialized read-only pointer to a Node in a list [a local variable]
  Node p;
  p.key = key; // if any (usually so), of type U
  it = find(data[wrapppedIndexxx].begin(), data[wrapppedIndexxx].end(), p);
  if(it == data[wrapppedIndexxx].end())
  {
      return false;
  }
  else
    return true;
}

template<class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::deleteKey(U key)
{
  int wrapppedIndexxx = getWrappedIndex(key);// the wrapped index, in the range 0 to N-1 [a local variable]
  typename list<Node>::iterator it; // an uninitialized mutating pointer to a Node in a list [a local variable]
  for(it = data[wrapppedIndexxx].begin(); it != data[wrapppedIndexxx].end(); it++)
  {
    if(it != key.end())
    {
      data[wrapppedIndexxx].erase(it);
    }
  }
  siz--;
}

template<class T, class U, int CAPACITY>
vector<U> HashTable<T, U, CAPACITY>::keys() const
{
  vector<U> f;
  int wrapppedIndexxx = 0;// the wrapped index, in the range 0 to N-1 [a local variable]
  typename list<Node>::const_iterator it; // an uninitialized read-only pointer to a Node in a list [a local variable]
  for(it = data[wrapppedIndexxx].begin(); it != data[wrapppedIndexxx].end(); it++)
  {
    f.push_back(it->key);
  }
  return f;
}

template<class T, class U, int CAPACITY>
void HashTable<T, U, CAPACITY>::clear()
{
  int wrapppedIndexxx = 0;// the wrapped index, in the range 0 to N-1 [a local variable]
  for(wrapppedIndexxx = 0; wrapppedIndexxx < CAPACITY; wrapppedIndexxx++)
  {
    data[wrapppedIndexxx].clear();
  }
  siz = 0;
}

template<class T, class U, int CAPACITY>
T& HashTable<T, U, CAPACITY>::operator[](const U& key)
{
  int wrapppedIndexxx = getWrappedIndex(key);// the wrapped index, in the range 0 to N-1 [a local variable]
  typename list<Node>::iterator it; // an uninitialized mutating pointer to a Node in a list [a local variable]
  Node p;
  p.key = key; // if any (usually so), of type U
  it = find(data[wrapppedIndexxx].begin(), data[wrapppedIndexxx].end(), p);

  if(it == data[wrapppedIndexxx].end())
  {
    siz++;
    data[wrapppedIndexxx].push_back(p);
    return data[wrapppedIndexxx].back().value;
  }
  else
  {
    return it->value;
  }
}

template<class T, class U, int CAPACITY>
T HashTable<T, U, CAPACITY>::operator[](const U& d) const
{
  int wrapppedIndexxx = getWrappedIndex(d); // the wrapped index, in the range 0 to N-1 [a local variable]
  typename list<Node>::iterator it; // an uninitialized mutating pointer to a Node in a list [a local variable]
  Node p;
  p.key = d; // if any (usually so), of type U
  it = find(data[wrapppedIndexxx].begin(), data[wrapppedIndexxx].end(), p);

  if(it == data[wrapppedIndexxx].end())
  {
    return dummy;
  }
  else
  {
    return it->value;
  }
}

#endif // HASHTABLE_H
