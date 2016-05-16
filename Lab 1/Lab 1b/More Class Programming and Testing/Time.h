// Lab 1b, More Class Programming and Testing
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#ifndef TIME_H
#define TIME_H

class Time
{
  private:
    double hours;
    double minutes;
    double seconds;

  public:
    void setHours(double hour);
    void setMinutes(double minute);
    void setSeconds(double second);
    double timeInHours() const;
    double timeInMinutes() const;
    double timeInSeconds() const;
};

#endif // TIME_H_INCLUDED
