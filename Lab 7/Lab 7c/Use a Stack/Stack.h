// Lab 7c, Use a Stack
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <string>
using namespace std;

template <class T>

class Stack
{
  private:
    static const int INIT_CAP = 100;
    int cap; // capacity
    T* values;
    int siz; // track size

  public:
    Stack(int=INIT_CAP); // prototype with default initial capacity
    ~Stack(){delete [] values;} // inline
    Stack(const Stack<T>&); //copy constructor
    bool empty() const {return 0 == siz;} // inline
    int size() const {return siz;} // inline
    void clear() {siz = 0;} // inline
    void push(const T& parameter);
    bool peek(T& parameter) const;
    T peek() const{return values[siz];}
    bool pop(T&);
    void clearStack();
    Stack<T>& operator=(const Stack<T>&);

};

template <class T>
Stack<T>::Stack(const Stack<T>& a)
{
  cap = a.cap;
  siz = a.siz;
  values = new T[cap];
  for (int i = 0; i < cap; i++)
    values[i] = a.values[i];
}

template <class T>
Stack<T>::Stack(int init_cap) // function
{
  cap = init_cap;
  values = new T[cap];
  siz = 0; // initally empty
}

template <class T>
void Stack<T>::push(const T& parameter)
{
  int i;
  if (++siz > cap)
  {
    int cap2 = cap * 2;
    T* temp = new T[cap2];
    for(i = 0; i < siz; i++)
      temp[i] = values[i];
    delete [] values;
    values = temp;
    cap = cap2;
  }
  values[siz - 1] = parameter;
}

template <class T>
bool Stack<T>::peek(T& parameter) const
{
  if (0 == siz) return false; // failed
  parameter = values[siz - 1];
  return true; // success
}

template <class T>
bool Stack<T>::pop(T& parameter)
{
  int i;
  if (0 == siz) return false; // failed
  parameter = values[--siz];

  if (siz > 2 && siz < cap / 4)
  {
    //halve the capacity
    T* temp = new T[cap/2];
    for(i = 0; i <= siz; i++)
      temp[i] = values[i];

    delete values;
    values = temp;
  }
  return true; // success
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& c)
{
  int i;
  if(this == &c)
    return *this;

  delete [] values;
  cap = c.cap;
  siz = c.siz;

  values = new T[cap];
  for(i = 0; i < cap; i++)
    values[i] = c.values[i];

  return *this;
}

#endif // STACK_H_INCLUDED
