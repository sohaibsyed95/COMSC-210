// LAB 14b: Applying A Data Structure To A Database Program
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++
#include <vector>
using namespace std;

#ifndef SORTABLEDYNAMICARRAY_H
#define SORTABLEDYNAMICARRAY_H

template<class T>
class SortableArray
{
  private:
    T* data;
    T dummy;
    bool* inUse;
    static const int INIT_CAP = 50;
    int CAPACITY, siz;

  public:
    SortableArray(int a = INIT_CAP); //constructor
    SortableArray(const SortableArray<T>&);//copy constructor
    ~SortableArray(); //destructor
    SortableArray<T>& operator=(const SortableArray<T>&);
    T& operator[](int); //operator bracket SETTER version
    T operator[](int) const; //operator bracket GETTER version
    int bsearch(int, const T&) const;
    void quickSort(int, int);//sort function from lecture notes
    void clear();
    int capacity() const {return CAPACITY;}
    bool containsKey(int) const;
    int size() const;
    vector<int> keys() const;
    void deleteKey(int);
    void sort(int);
};

//constructor code
template <class T>
SortableArray<T>::SortableArray(int a)
{
  siz = 0;
  CAPACITY = 0;
  inUse = new bool[CAPACITY];
  data = new T[CAPACITY];
  for(int i = 0; i < CAPACITY; i++)
  {
    inUse[i] = false; //set inuse values to false
  }
}

//destructor code
template <class T>
SortableArray<T>::~SortableArray()
{
  delete [] inUse;
  delete [] data;
}

//operator bracket SETTER version
template <class T>
T& SortableArray<T>::operator [](int a)
{
  if(a < 0)
    return dummy; //return dummy if the key is <0
  if(a >= CAPACITY)
  {
    //create new data object, allocate and copy
    T* next = new T[a + 1]; //create new T object
    for(int i = 0; i < CAPACITY; i++)
    {
      next[i] = data[i];
    }
    delete [] data; //deallocate data
    data = next;


    //create new inuse object, allocate and copy
    bool* next2 = new bool[a + 1];
    for(int i = 0; i < CAPACITY; i++)
    {
      next2[i] = inUse[i];
    }
    //set all inuse to false
    for(int i = 0; i < CAPACITY; i++)
    {
      inUse[i] = false;
    }
    delete [] inUse; //deallocate inUse
    inUse = next2;

    CAPACITY = a + 1;
    inUse[a] = true;
    return data[a];
  }
  if(!inUse[a])
  {
    siz++;
  }
  inUse[a] = true;
  return data[a];
}

//operator bracket GETTER version
template <class T>
T SortableArray<T>::operator[](int b) const
{
  if((b < 0 || b >= CAPACITY) || inUse[b] == false)
  {
    return dummy;
  }
  return data[b];
}

template <class T>
SortableArray<T>::SortableArray(const SortableArray<T>& g)
{
  CAPACITY = g.CAPACITY;
  siz = g.siz;
  data = new T[CAPACITY]; //create new t object
  inUse = new bool[CAPACITY]; //create new inUse object
  for(int i = 0; i < CAPACITY; i++)
  {
    data[i] = g.data[i];//copy data values into g
    inUse[i] = g.inUse[i]; //copy inUse values into g
  }
}

template <class T>
SortableArray<T>& SortableArray<T>::operator=(const SortableArray<T>& c)
{
  if(&c == this)
  {
    return *this;//return a self reference
  }
  delete [] inUse; //deallocate inUse
  delete [] data; //deallocate data

  CAPACITY = c.CAPACITY;
  siz = c.siz;
  data = new T[CAPACITY];
  for(int i = 0; i < CAPACITY; i++)
  {
    data[i] = c.data[i]; //copy values from data to c
    inUse[i] = c.inUse[i]; //copy inUse values from inUse to c
  }
  return *this; //return a self reference
}

template <class T>
void SortableArray<T>::deleteKey(int d)
{
  (d < 0 || d >= CAPACITY) ? dummy : inUse[d] = false;
  --siz; //decrement siz
}

//containsKey function
template <class T>
bool SortableArray<T>::containsKey(int e) const
{
  if(e < 0 || e >= CAPACITY)
    return false;
  return inUse[e];
}

//keys function
template <class T>
vector<int> SortableArray<T>::keys() const
{
  vector<int> count; //create a vector of ints
  for(int i = 0; i < CAPACITY; i++)
  {
    if(inUse[i] == true)
    {
      count.push_back(i); //push back the count vector, from lecture notes
    }
  }
  return count;
}

//clear function
template <class T>
void SortableArray<T>::clear()
{
  for(int i = 0; i < CAPACITY; i++)
  {
    inUse[i] = false; //set all inUse values to false
  }
  siz = 0; //set size = to 0
}

//size function
template <class T>
int SortableArray<T>::size() const
{
  int siz2 = 0;
  for(int i = 0; i < CAPACITY; i++)
  {
    if(inUse[i] == true)
    {
      siz2++;
    }
  }
  return siz2;
}

template <class T>
void SortableArray<T>::sort(int e)
{
  quickSort(0, e);
}

//sort function
template <class T>
void SortableArray<T>::quickSort(int s, int e)
{
  int pivot = (s + e - 1) / 2; // right-side heavy
  int left = s; // index of left-most element
  int right = e - 1; // index of right-most element
  if( s >= e)
    return;
  while (true)
  {
    while(left < pivot)
      if (data[pivot] < data[left]) break; else ++left;
    while(pivot < right)
      if (data[right] < data[pivot]) break; else --right;
    if (left == right) // balanced and apivot is in the right place
    {
      quickSort(s, pivot);
      quickSort(pivot + 1, e);
      break; // done with this cycle
    }
    else if (left == pivot) // swap w/pivot
    {
      swap(data[pivot], data[right]);
      pivot = right;
      ++left;
    }
    else if (pivot == right) // swap w/pivot
    {
      swap(data[pivot], data[left]);
      pivot = left;
      --right;
    }
    else // swap around the pivot
    {
      swap(data[left], data[right]);
      ++left;
      --right;
    }
  }
}

//bsearch function, should return the index of the found value as it appears in the sorted array
template <class T>
int SortableArray<T>::bsearch(int e, const T& dat) const
{
  int s = 0, result = -1;
  while(true)
  {
    int m = (s + e - 1) / 2; // the middle element
    if (dat == data[m]) // got lucky -- matches middle element
      return m; // return index of found element
    else if (s == e - 1) // 1-element array
      return -1; // only element in array did not match
    else if (dat < data[m]) // look between s and m-1
    {
      if (s == m) return -1; // but that range is empty, no match
      else {e = m; continue;} // look in s to m-1
    }
    else // look between m+1 and e-1
    {
      if (m == e - 1) return -1; // but that range is empty, no match
      else {s = m + 1; continue;} // look in m-1 to e
    }
  }
  return result; //return the result
}
#endif // SORTABLEDYNAMICARRAY_H_INCLUDED
