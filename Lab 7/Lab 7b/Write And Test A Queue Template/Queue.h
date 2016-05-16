#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

template <class T>
class Queue
{
  private:
    struct Node
    {
      T value;
      Node* next;
    };
    Node* start;
    Node* end; // for efficiency
    int siz; // track size

  public:
    Queue();
    ~Queue();
    Queue(const Queue<T>&);
    void push(const T&);
    bool peek(T&) const;
    bool pop(T&);
    void clear();
    Queue<T>& operator=(const Queue<T>&);
    bool empty() const {return 0 == start;}
    int size() const {return siz;}

};

template <class T>
Queue<T>::Queue()
{
  start = 0;
  end = 0;
  siz = 0;
}

template <class T>
Queue<T>::~Queue()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
}

template <class T>
Queue<T>::Queue(const Queue<T>& a)
{
  start = 0;
  end = 0;
  siz = a.siz;
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
}

template <class T>
void Queue<T>::push(const T& parameter)
{
  Node* node = new Node;
  node->value = parameter;
  node->next = 0;
  if (end) end->next = node;
  else start = node;
  end = node;
  ++siz;
}

template <class T>
bool Queue<T>::peek(T& parameter) const
{
  if (0 == start) return false; // failed
  parameter = start->value;
  return true; // success
}

template <class T>
bool Queue<T>::pop(T& parameter)
{
  if (0 == start) return false; // failed
  parameter = start->value;
  Node* p = start->next;
  delete start;
  start = p;
  if (start == 0) end = 0;
  --siz;
  return true; // success
}

template <class T>
void Queue<T>::clear()
{
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }
  end = 0;
  siz = 0;
}

template <class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& a)
{
  if (this == &a) return *this;

  // deallocate existing queue
  while (start)
  {
    Node* p = start->next;
    delete start;
    start = p;
  }

  // build new queue
  end = 0; // data member end pointer
  for (Node* p = a.start; p; p = p->next)
  {
    Node* node = new Node;
    node->value = p->value;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
  }
  siz = a.siz;

  return *this;
}

#endif // QUEUE_H_INCLUDED
