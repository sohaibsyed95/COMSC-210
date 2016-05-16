#include <vector>
#include <algorithm>
#include <iostream>

#ifndef SORTABLESTATICARRAY_H
#define SORTABLESTATICARRAY_H

template <class T, int CAPACITY>
class StaticArray
{
  T dummy;
  T values[CAPACITY];
  int siz;
  bool inUse[CAPACITY];

  public:
    StaticArray();
    T& operator[](int); // lookup key is an index
    T operator[](int) const;
    int size() const{return siz;} // #of keys "in use", initially zero
    int capacity() const{return CAPACITY;}
    bool containsKey(int) const;
    void deleteKey(int c){(c < 0 || c>= CAPACITY)?dummy:inUse[c] = false;} // set "in use" to false
    vector<int> keys() const; // all "in use" keys
    void clear();
    void sort();
};

//constructor function
template <class T, int CAPACITY>
StaticArray<T, CAPACITY>::StaticArray()
{
  for(int i = 0; i < CAPACITY; i++)
  {
    inUse[i] = false;
  }
  siz = 0;
}

//getter operator [] function
template <class T, int CAPACITY>
T StaticArray<T, CAPACITY>::operator[](int key) const
{
  if((key < 0 || key >= CAPACITY) || (inUse[key] == false))
    return dummy;
  return values[key];
}

//setter operator[] function
template <class T, int CAPACITY>
T& StaticArray<T, CAPACITY>::operator[](int key)
{
  if (key < 0 || key >= CAPACITY)
    return dummy;
  if(!inUse[key])
    siz++;
  inUse[key] = true;
  return values[key];
}

template <class T, int CAPACITY>
bool StaticArray<T, CAPACITY>::containsKey(int c) const
{
  if(c < 0 || c >= CAPACITY)
    return false;
  return inUse[c];
}


template <class T, int CAPACITY>
vector<int> StaticArray<T, CAPACITY>::keys() const // all "in use" keys
{
  vector<int> result;
  for(int i = 0; i < CAPACITY; i++)
  {
    if(inUse[i] == true)
      result.push_back(i);
  }
  return result;
}

template <class T, int CAPACITY>
void StaticArray<T, CAPACITY>::clear()
{
  for(int i = 0; i < CAPACITY; i++)
  {
    inUse[i] = false;
  }
  siz = 0;
}

template <class T, int CAPACITY>
void StaticArray<T, CAPACITY>::sort()
{
  int n = CAPACITY;//set n to capacity
  for (int i = 0; i < n; i++) // stop at n
  {
    if (!inUse[i]) continue; // in case of holes
    for (int j = i + 1; j < n; j++)
    {
      if (!inUse[j]) continue; // in case of holes
      if (values[j] < values[i]) swap(values[i], values[j]);
    }
  }
}

#endif // SORTABLESTATICARRAY_H
