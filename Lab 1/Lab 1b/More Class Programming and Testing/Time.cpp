// Lab 1b, More Class Programming and Testing
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
