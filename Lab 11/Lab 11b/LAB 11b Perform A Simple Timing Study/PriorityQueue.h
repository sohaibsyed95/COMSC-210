// LAB 11b:  Perform A Simple Timing Study
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <algorithm>
#include <cassert>

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <class T>
class PriorityQueue
{
  private:
    T* data;
    int capacity, siz, parentIndex, index;
    void doubleCapacity(int);
  public:
    PriorityQueue(int=2);
    ~PriorityQueue() {delete [] data;}
    PriorityQueue(const PriorityQueue<T>&);
    PriorityQueue<T>& operator=(const PriorityQueue<T>&);
    void enqueue(const T&);
    T& front(){return data[0];}
    T& back(){return data[capacity - 1];}
    T& operator[](int a) const {return data[a];}
    T dequeue();
    bool empty() const {return 0 == siz;}
    void clear() {siz = 0;}
    int size() const {return siz;}
};

template <class T>
PriorityQueue<T>::PriorityQueue(int a)
{
  capacity = a;
  siz = 0;
  parentIndex = 0;
  index = 0;
  data = new T[capacity];
}

template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& s)
{
  capacity = s.capacity;
  siz = s.size();
  data = 0;

  if(capacity > 0)
  {
    data = new T[capacity];
    for(int i = 0; i < capacity; i++)
    {
      data[i] = s.data[i];
    }
  }
}

template <class T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& g)
{
  if(this != &g)
  {
    delete [] data; //deallocate data
    capacity = g.capacity;
    siz = g.siz;
    data = 0;
    if(capacity > 0)
    {
      data = new T[capacity];
      for(int i = 0; i < capacity; i++)
      {
        data[i] = g.data[i];
      }
    }
  }
  return *this;
}

template <class T>
void PriorityQueue<T>::enqueue(const T& value)
{
  index = siz;
  if(index >= capacity)
  {
    doubleCapacity(capacity * 2);
  }

  data[index] = value;
  while(true)
  {
    parentIndex = (index + 1) / 2 - 1;
    if(parentIndex < 0)
      break;
    if(data[parentIndex] >= data[index])
      break;
    swap(data[parentIndex], data[index]); //swap index values
    index = parentIndex;
  }
  siz++; //increment size
}

template <class T>
T PriorityQueue<T>::dequeue()
{
  T& dequeuePQ = data[0];
  index = 0;

  while(true)
  {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if(leftChild >= siz)
      break;
    if(leftChild == siz - 1 || data[leftChild] >= data[rightChild])
    {
      data[index] = data[leftChild];
      index = leftChild;
    }
    else
    {
      data[index] = data[rightChild];
      index = rightChild;
    }
  }
  siz--; //decrement size

  if(siz < capacity/4)
  {
    capacity /= 2;
  }
  data[index] = data[siz];

  while(data[parentIndex] < data[index])
  {
    parentIndex = (index + 1)/ 2 - 1;
    if(parentIndex < 0)
      break;
    swap(data[parentIndex], data[index]);
    index = parentIndex;
  }
  return dequeuePQ;
}

template <class T>
void PriorityQueue<T>::doubleCapacity(int b)
{
  T* newPQ = new T[b];
  int index = b > capacity ? capacity : b;
  for(int i = 0; i < index; i++)
  {
    newPQ[i] = data[i];
  }
  delete [] data; //deallocation
  data = newPQ;
  capacity = b;
}

#endif // PRIORITYQUEUE_H
