// Lab 2b, Writing Templates And Overloading Operators
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#ifndef ROAD_H_INCLUDED
#define ROAD_H_INCLUDED

template <class T>
class Road
{
  private:
    T width;
    T length;
  public:
    void WidthOfRoad(T feet);
    void LengthOfRoad(T miles);
    T ObtainWidth() const;
    T ObtainLength() const;
    T asphalt(T) const;
};

template <class T>
void Road<T>::WidthOfRoad(T feet)
{
  width = feet;
}

template <class T>
void Road<T>::LengthOfRoad(T miles)
{
  length = miles;
}

template <class T>
T Road<T>::ObtainWidth() const
{
  return width;
}

template <class T>
T Road<T>::ObtainLength() const
{
  return length;
}

template <class T>
T Road<T>::asphalt(T thickness) const
{
  T cubicFeet;
  cubicFeet = (thickness * .08333) *(length * 5280) * width;
  return cubicFeet;
}

template <class T>
bool operator<(const T& a, const T& b)
{
  if(a.ObtainLength() < b.ObtainLength())
    return true;
  if(a.ObtainLength() > b.ObtainLength())
    return false;
  if(a.ObtainWidth() < b.ObtainWidth())
    return true;
  if(a.ObtainWidth() < b.ObtainWidth())
    return false;
  return false;
}

template <class T>
bool operator==(const T& c, const T& d)
{
  if(c.ObtainLength() == d.ObtainLength())
    return true;
  if(c.ObtainWidth() == d.ObtainWidth())
    return true;
  if(c.ObtainLength() != d.ObtainLength())
    return false;
  if(c.ObtainWidth() != d.ObtainWidth())
    return false;
  return false;
}

#endif // ROAD_H
