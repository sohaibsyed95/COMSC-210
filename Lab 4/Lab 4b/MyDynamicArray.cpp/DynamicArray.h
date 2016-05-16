#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template <class T>
class DynamicArray
{
  T* data = 0;
  T* values = 0;
  bool* inUse = 0;
  int dummy;
  int cap, index;
  static const int INIT_CAP = 50;
  void capChange(int);

  public:
    DynamicArray(int c = INIT_CAP);
    ~DynamicArray(){delete [] values; delete [] inUse; delete [] data;}
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

template <class T>
T DynamicArray<T>::operator[](int key) const
{
  if((key < 0 || key >= cap) || (inUse[key] == false))
    return dummy;
  return values[key];
}

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

template <class T>
T& DynamicArray<T>::operator[](int key)
{
  if (key < 0)
    return dummy;
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


template <class T>
vector<int> DynamicArray<T>::keys() const // all "in use" keys
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
