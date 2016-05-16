// Lab 1b, More Class Programming and Testing
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
  cout << "Lab 1b, More Class Programming and Testing \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Time time;  //declare object

  time.setHours(1);
  time.setMinutes(40);
  time.setSeconds(30);

  double houras = time.timeInHours();
  double minutos = time.timeInMinutes();
  double segundos = time.timeInSeconds();

  assert(houras <= 1.675 || houras >= 1.675);
  assert(minutos == 100.5);
  assert(segundos == 6030);
  cout << "------------------------Object testing---------------------------------" << endl;
  cout << "1.675 hour is expected, " << "actual value is = " << houras << " hour"<< endl;
  cout << "100.5 minutes is expected " << "actual value is = " << minutos  << " minutes" << endl;
  cout << "6030 seconds is expected " << "actual value is = " << segundos << " seconds" << endl;
  cout << "------------------------End of Object testing---------------------------" << endl;

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
  cout << "press enter to finish" << endl;
  cin.get();
}
