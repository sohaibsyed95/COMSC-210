#ifndef LINKEDARRAY_H
#define LINKEDARRAY_H

#include <vector>

template <class T>
class LinkedArray
{
  struct Node
  {
    T value;
    bool inUse;
    Node* next;
  };
  Node* start;
  Node* end;

  T* values;
  bool* inUse;
  T dummy;
  int cap, siz, index;
  static const int INIT_CAP = 50;

  public:
    LinkedArray(int c = INIT_CAP);
    ~LinkedArray();
    LinkedArray(const LinkedArray<T>&);
    LinkedArray<T>& operator=(const LinkedArray<T>&);
    T& operator[](int); // lookup key is an index
    T operator[](int) const;
    int size() const; // #of keys "in use", initially zero
    int capacity() const{return cap;}
    bool containsKey(int) const;
    void deleteKey(int);
    vector<int> keys() const; // all "in use" keys
    void clear();
};

template <class T>
int LinkedArray<T>::size() const
{
  return siz;
}

template <class T>
LinkedArray<T>::~LinkedArray()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
}

template <class T>
T LinkedArray<T>::operator[](int key) const
{
  if(key < 0 || key >= cap)
    return dummy;
  int counter = 0;
  Node* p;
  for (p=start; p; p = p->next, counter++)
    if(counter == key) break;
  return p->value;
}

template <class T>
LinkedArray<T>::LinkedArray(const LinkedArray<T>& a)
{
  int i;
  for(i = 0; i < a.capacity(); i++)
  {
    Node* node = new Node;
    node->inUse = a.containsKey(i);
    node->value = a[i];
    node->next = 0;
    if(end)
      end->next = node;
    else
      start = node;

    end = node;
  }
  siz = a.size();
  cap = a.capacity();
}

template <class T>
T& LinkedArray<T>::operator[](int key)
{
  int counter = 0;
  Node* p = start;
  if (key < 0)
    return dummy;
  if (key >= cap)
  {
    for (int i = cap; i < key + 2; i++)
    {
      //allocate new nodes
      Node* node = new Node;
      node->inUse = false;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      cap = i;
    }
  }

  for (; p; p = p->next, counter++)
  {
    if (counter == key)
      break;
  }
  if (p->inUse == false)
  {
    p->inUse = true;
    siz++;
  }
  return p->value;
}

template <class T>
bool LinkedArray<T>::containsKey(int key) const
{
  int counter = 0;
  Node* p;
  if(key < 0 || key >= cap)
    return false;
  for (p = start; p; p = p->next, counter++)
  {
    if(counter == key)
      break;
  }
  return p->inUse;
}

template <class T>
void LinkedArray<T>::deleteKey(int key)
{
  if(key < 0 || key >= cap)
    return;
  int counter = 0;
  Node* p;
  for (p = start; p; p = p->next, counter++)
    if(counter == key)
      break;
  if(p->inUse)
    --siz;
  p->inUse = false;
}

template <class T>
void LinkedArray<T>::clear()
{
  Node* p;
  for(p = start; p; p = p->next)
  {
    p->inUse = false;
  }
  siz = 0;
}

template <class T> //not done
LinkedArray<T>& LinkedArray<T>::operator=(const LinkedArray<T>& a)
{
  Node* p;

  if(&a == this)
    return *this;

  while(start)
  {
    p = start->next;
    delete start;
    start = p;
  }
  end = 0;

  int i;
  for(i = 0; i < a.capacity(); i++)
  {
    Node* node = new Node;
    node->inUse = a.containsKey(i);
    node->value = a[i];
    node->next = 0;
    if(end)
      end->next = node;
    else
      start = node;

    end = node;
  }
  siz = a.size();
  cap = a.capacity();

  return *this;
}

template <class T>
LinkedArray<T>::LinkedArray(int c)
{
  start = end = 0;
  cap = c;
  siz = 0;

  for(int i = 0; i < cap; i++)
  {
    Node* node = new Node;
    node->inUse = false;
    node->next = 0;
    if(end)
    {
      end->next = node;
    }
    else
    {
      start = node;
    }
    end = node;
  }
}

#endif // LINKEDARRAY_H_INCLUDED
