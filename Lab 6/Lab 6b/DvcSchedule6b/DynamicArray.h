#ifndef DYNAMICARRAY_H_INCLUDED
#define DYNAMICARRAY_H_INCLUDED

#include <vector>
template <class T>
class DynamicArray
{
  T* values = 0;
  bool* inUse = 0;
  T dummy;
  int cap, index;
  static const int INIT_CAP = 50;
  void capChange(int);

  public:
    DynamicArray(int c = INIT_CAP);
    ~DynamicArray(){delete [] values; delete [] inUse;}
    DynamicArray(const DynamicArray<T>&);
    DynamicArray<T>& operator=(const DynamicArray<T>&);
    T& operator[](int); // lookup key is an index
    T operator[](int) const;
    int size() const; // #of keys "in use", initially zero
    int capacity() const{return cap;}
    bool containsKey(int) const;
    void deleteKey(int c){(c < 0 || c>= cap)?dummy:inUse[c] = false;} // set "in use" to false
    vector<int> keys() const; // all "in use" keys
    void clear();
};

//size function, determines # of keys in use
template <class T>
int DynamicArray<T>::size() const
{
  int index = 0;
  for(int i = 0; i < cap; i++)
  {
    if(inUse[i] == true)
        index++;
  }
  return index;
}

//operator [] getter
template <class T>
T DynamicArray<T>::operator[](int key) const
{
  if((key < 0 || key >= cap) || (inUse[key] == false))
    return dummy;
  return values[key];
}

//templated copy constructor, allows copies to have their own arrays, avoids conflicting destructors
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& a)
{
  cap = a.cap;
  values = new T[cap];
  inUse = new bool[cap];

  for (int i = 0; i < cap; i++)
  {
    values[i] = a.values[i];
    inUse[i] = a.inUse[i];
  }
}

//operator [] setter
template <class T>
T& DynamicArray<T>::operator[](int key)
{
  if (key < 0)
    return dummy;
  //increase capacity in operator [] setter
  if(key >= cap)
  {
    T* tempValues = new T[key + 1];
    for (int i = 0; i < cap; i++) tempValues[i] = values[i];
    delete [] values;
    values = tempValues;
    bool* tempInUse = new bool[key + 1];
    for (int i = 0; i < cap; i++) tempInUse[i] = inUse[i];
    for (int i = cap; i <= key; i++) tempInUse[i] = false;
    delete [] inUse;
    inUse = tempInUse;
    cap = key + 1;
  }

  inUse[key] = true;
  return values[key];
}

template <class T>
bool DynamicArray<T>::containsKey(int c) const
{
  if(c < 0 || c >= cap)
    return false;
  return inUse[c];
}

// all "in use" keys
template <class T>
vector<int> DynamicArray<T>::keys() const
{
  vector<int> result;
  for(int i = 0; i < cap; i++)
  {
    if(inUse[i])
      result.push_back(i);
  }
  return result;
}

template <class T>
void DynamicArray<T>::clear()
{
  for(int i = 0; i < cap; i++)
  {
    inUse[i] = false;
  }
}

//assignment operator, allows copies to have their own arrays, avoids conflicting destructors
template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& a)
{
  if(&a == this)
    return *this;
  delete [] values;
  delete [] inUse;
  cap = a.cap;
  values = new T[cap];
  inUse = new bool[cap];

  for (int i = 0; i < cap; i++)
  {
    values[i] = a.values[i];
    inUse[i] = a.inUse[i];
  }
  return *this;
}

//default constructor, uses a default parameter
template <class T>
DynamicArray<T>::DynamicArray(int c)
{
  cap = c;
  values = new T[cap];
  inUse = new bool[cap];

  for (int i = 0; i < cap; i++)
    inUse[i] = false;
}


#endif // DYNAMICARRAY_H_INCLUDED
