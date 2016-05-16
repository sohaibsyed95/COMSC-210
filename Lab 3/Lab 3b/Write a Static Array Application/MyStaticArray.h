// Lab 3b, Write A Static Array Application
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#ifndef STATICARRAY_H
#define STATICARRAY_H

template <class T, int CAPACITY>
class StaticArray
{
  T dummy;
  T values[CAPACITY];
  bool inUse[CAPACITY];

  public:
    StaticArray(){for (int i = 0; i < CAPACITY; i++) inUse[i]=false;}
    T& operator[](int); // lookup key is an index
    T operator[](int) const;
    int size() const; // #of keys "in use", initially zero
    int capacity() const{return CAPACITY;}
    bool containsKey(int) const;
    void deleteKey(int c){(c < 0 || c>= CAPACITY)?dummy:inUse[c] = false;} // set "in use" to false
    vector<int> keys() const; // all "in use" keys
    void clear();
};

template <class T, int CAPACITY>
T StaticArray<T, CAPACITY>::operator[](int key) const
{
  if((key < 0 || key >= CAPACITY) || (inUse[key] == false))
    return dummy;
  return values[key];
}

template <class T, int CAPACITY>
T& StaticArray<T, CAPACITY>::operator[](int key)
{
  if (key < 0 || key >= CAPACITY)
    return dummy;
  inUse[key] = true;
  return values[key];
}

template <class T, int CAPACITY>
int StaticArray<T, CAPACITY>::size() const
{
  int num = 0;
  for(int i = 0; i < CAPACITY; i++)
  {
    if(inUse[i] == true)
      num++;
  }
  return num;
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
    if(inUse[i])
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
}

#endif // STATICARRAY_H
