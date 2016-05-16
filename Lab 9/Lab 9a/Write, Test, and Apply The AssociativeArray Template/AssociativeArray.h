// Lab 9a, Write, Test, and Apply The AssociativeArray Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H
#include <vector>

template <class T, class U>
class AssociativeArray
{
  struct Node
  {
    T value;
    U key;
    bool inUse;
    Node* next;
  };
  Node* start;
  Node* end;
  Node* rem;

  int endTracker;
  T* values;
  T dummy;
  int cap, siz;
  static const int INIT_CAP = 50;

  public:
    AssociativeArray(int c = INIT_CAP);
    ~AssociativeArray();
    AssociativeArray(const AssociativeArray<T, U>&);
    AssociativeArray<T, U>& operator=(const AssociativeArray<T, U>&);
    T& operator[](const U&); // lookup key is an index
    T operator[](const U&) const;
    int size() const {return siz;} // #of keys "in use", initially zero
    int capacity() const{return cap;}
    bool containsKey(U) const;
    void deleteKey(U);
    vector<U> keys() const; // all "in use" keys
    void clear();
};

//destructor function
template <class T, class U>
AssociativeArray<T, U>::~AssociativeArray()
{
  while(start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
}

//operator[] setter
template <class T, class U>
T AssociativeArray<T, U>::operator[](const U& a) const
{
  Node* p;
  for(p = start; p; p = p->next)
  {
    if(p->inUse == true && p->key == a)
    {
      return p->value;
    }
  }
  return dummy;
}

//copy constructor function
template <class T, class U>
AssociativeArray<T, U>::AssociativeArray(const AssociativeArray<T, U>& parameter)
{
  start = end = 0;
  for(Node* p = parameter.start; p; p = p->next)
  {
    //node insertion
    Node* node = new Node;
    //code for copying values from parameter into nodes array
    node->inUse = p->inUse;
    node->value = p->value;
    node->next = 0;
    node->key = p->key;

    if(end)
      end->next = node;
    else
      start = node;

    end = node;
  }
  siz = parameter.size();
  cap = parameter.capacity();
}

template <class T, class U>
T& AssociativeArray<T, U>::operator[](const U& a)
{
  Node* p;
  for(p = start; p; p = p->next)
    if(p->inUse == true && p->key == a)
      return p->value;

  for(p = start; p; p = p->next)
    if(p->inUse == false)
    {
      p->key = a;
      p->inUse = true;
      //increment size
      siz++;
      return p->value;
    }

  Node* node = new Node;
  node->inUse = false;
  node->next = 0;
  if(end)
    end->next = node;
  else
    start = node;
  end = node;

  end->key = a;
  end->inUse = true;  //set inUse to true
  //increment siz
  siz++;
  return end->value;
}

template <class T, class U>
bool AssociativeArray<T, U>::containsKey(U key) const
{
  Node* p;
  bool check = false;

  for (p = start; p; p = p->next)
  {
    if(p->key == key)
    {
      check = true;
      break;
    }
  }
  if(check)
    return p->inUse;
  else
    return false;
}

template <class T, class U>
void AssociativeArray<T, U>::deleteKey(U key)
{

  Node* p;
  for (p = start; p; p = p->next)
    if(p->key == key)
      break;
  if(p->inUse)
    --siz;
  p->inUse = false;
}

template <class T, class U>
void AssociativeArray<T, U>::clear()
{
  Node* p;
  for(p = start; p; p = p->next)
  {
    p->inUse = false;
  }
  siz = 0;
}

template <class T, class U>  //not done
AssociativeArray<T, U>& AssociativeArray<T, U>::operator=(const AssociativeArray<T, U>& a)
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

  start = end = 0;
  for(Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->inUse = p->inUse;
    node->value = p->value;
    node->next = 0;
    node->key = p->key;
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

template <class T, class U>
AssociativeArray<T, U>::AssociativeArray(int c)
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
  endTracker = -1;
  rem = 0;

}

template <class T, class U>
vector<U> AssociativeArray<T, U>::keys() const
{
  vector<U> push;
  for(Node* p = start; p; p = p->next)
  {
    if(p->inUse == true)
    {
      push.push_back(p->key);
    }

  }
  return push;
}

#endif // ASSOCIATIVEARRAY_H
