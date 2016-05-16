// Lab 2a,Writing Overloaded Operators
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;

#include <cassert>
#include "Time.h"
#include "Time.h" // testing ifndef

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 2a,Writing Overloaded Operators \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time;  //declare object
  time.setHours(1);
  time.setMinutes(40);
  time.setSeconds(30);

  Time time2;
  time2.setHours(5);
  time2.setMinutes(40);
  time2.setSeconds(30);

  Time time3;
  time3.setHours(1);
  time3.setMinutes(40);
  time3.setSeconds(30);

  double houras = time.timeInHours();
  double minutos = time.timeInMinutes();
  double segundos = time.timeInSeconds();

  double hours= time2.timeInHours();
  double minutes = time2.timeInMinutes();
  double seconds = time2.timeInSeconds();

  double hou= time3.timeInHours();
  double minu = time3.timeInMinutes();
  double seco = time3.timeInSeconds();

  assert(houras <= 1.675 || houras >= 1.675);
  assert(minutos == 100.5);
  assert(segundos == 6030);
  cout << "------------------------Object testing time---------------------------------" << endl;
  cout << "1.675 hour is expected, " << "actual value is = " << houras << " hour"<< endl;
  cout << "100.5 minutes is expected " << "actual value is = " << minutos  << " minutes" << endl;
  cout << "6030 seconds is expected " << "actual value is = " << segundos << " seconds" << endl;
  cout << "------------------------End of Object testing time---------------------------" << endl;
  cout << "------------------------Object testing time2---------------------------" << endl;
  cout << "Value of hours is " << hours << endl;
  cout << "Value of minutes is " << minutes << endl;
  cout << "Value of seconds is " << seconds << endl;
  cout << "------------------------Object testing time2---------------------------" << endl;
  cout << "Value of hours is " << hou << endl;
  cout << "Value of minutes is " << minu << endl;
  cout << "Value of seconds is " << seco << endl;

  // object copy testing
  {
    const Time copy = time; // a read-only copy
    houras = copy.timeInHours();
    minutos = copy.timeInMinutes();
    segundos = copy.timeInSeconds();

    assert(houras <= 1.675 || houras >= 1.675);
    assert(minutos == 100.5);
    assert(segundos == 6030);

    //...confirm that copy's contents match time's
    cout << endl << endl;
    cout << "------------------------Object copy testing-----------------------------" << endl;
    cout << "1.675 hour is expected, " << "actual value is = " << houras << " hour"<< endl;
    cout << "100.5 minutes is expected " << "actual value is = " << minutos  << " minutes" << endl;
    cout << "6030 seconds is expected " << "actual value is = " << segundos << " seconds" << endl;
    cout << "---------------------End of Object copy testing------------------------" << endl;
  }

  // object assignment testing
  {
    Time copy;
    copy = time;
    houras = copy.timeInHours();
    minutos = copy.timeInMinutes();
    segundos = copy.timeInSeconds();

    //...confirm that copy's contents match time's
    cout << endl << endl;
    cout << "------------------------Object assignment testing-------------------------" << endl;
    cout << "1.675 hour is expected, " << "actual value is = " << houras << " hour"<< endl;
    cout << "100.5 minutes is expected " << "actual value is = " << minutos  << " minutes" << endl;
    cout << "6030 seconds is expected " << "actual value is = " << segundos << " seconds" << endl;
    cout << "---------------------End of Object assignment testing--------------------" << endl;
    cout << endl;
  }
  //testing for less than
  if(time < time2)
    cout << "Time 1 is less than time2" << endl;
  else
    cout << "Time 1 is not less than time 2 " << endl;

  //testing for equals to
  if(time == time3)
    cout << "Time 1 and time3 are equal" << endl;
  else
    cout << "Time 1 and time3 are not equal" << endl;

  assert(time == time3);
  cout << "1.675 hour is expected, " << "actual value is = " << hou << " hour"<< endl;
  cout << "100.5 minutes is expected " << "actual value is = " << minu  << " minutes" << endl;
  cout << "6030 seconds is expected " << "actual value is = " << seco << " seconds" << endl;

  cout << "Press enter to finish" << endl;
  cin.get();
}
