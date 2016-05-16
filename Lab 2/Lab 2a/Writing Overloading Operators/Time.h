// Lab 2a,Writing Overloaded Operators
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

bool operator<(const Time&, const Time&);
bool operator==(const Time&, const Time&);

#endif // TIME_H
