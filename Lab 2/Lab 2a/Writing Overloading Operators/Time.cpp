// Lab 2a,Writing Overloaded Operators
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include "Time.h"

void Time::setHours(double hour)
{
  hours = hour;
}

void Time::setMinutes(double minute)
{
  minutes = minute;
}

void Time::setSeconds(double second)
{
  seconds = second;
}

double Time::timeInHours() const
{
  double time = hours + (minutes / 60) + (seconds/3600);
  return time;
}

double Time::timeInMinutes() const
{
  double time = (hours * 60) + minutes + (seconds/60);
  return time;
}

double Time::timeInSeconds() const
{
  double time = hours * 60 * 60 + minutes * 60 + seconds;
  return time;
}

bool operator<(const Time& t, const Time& u)
{
  if(t.timeInSeconds() < u.timeInSeconds())
    return true;
  return false;
}

bool operator==(const Time& e, const Time& f)
{
  double temp = (3600 * e.timeInHours()) + (60 * e.timeInMinutes()) + (e.timeInSeconds());
  double temp2 = (3600 * f.timeInHours()) + (60 * f.timeInMinutes()) + (f.timeInSeconds());
  if(temp == temp2)
    return true;
  return false;
}
