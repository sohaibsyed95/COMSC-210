// Lab 1a, Class Program and Testing
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;
#include <cassert>

#include "Road.h"
#include "Road.h" // testing ifndef

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 1a, Class Programming and Testing \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Road road;
  road.WidthOfRoad(5); //feet
  road.LengthOfRoad(5); //miles

  int length = road.ObtainLength(); //in miles
  int width = road.ObtainWidth(); //in feet
  int result = road.asphalt(3);

  assert(length == 5);
  assert(width == 5);
  assert(result == 32998);
  cout << "------------------------Object testing---------------------------------" << endl;
  cout << "5 miles is expected, " << "actual value is = " << length << " mile"<< endl;
  cout << "5 feet is expected " << "actual value is = " << width  << " feet" << endl;
  cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998 cubic inches" << endl;
  assert(result == 32998); //make sure value is true
  cout << "result= " << result << " cubic inches of asphalt" << endl;
  cout << "------------------------End of Object testing---------------------------" << endl;

  // object copy testing
  {
    const Road copy = road; // a read-only copy
    length = copy.ObtainLength();
    width = copy.ObtainWidth();
    result = copy.asphalt(3);

    assert(length == 5);
    assert(width == 5);
    assert(result == 32998);

    //...confirm that copy's contents match road's
    cout << endl << endl;
    cout << "------------------------Object copy testing---------------------------------" << endl;
    cout << "5 miles is expected, " << "actual value is = " << length << " mile"<< endl;
    cout << "5 feet is expected " << "actual value is = " << width  << " feet" << endl;
    cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998 cubic inches" << endl;
    assert(result == 32998); //make sure value is true
    cout << "result= " << result << " cubic inches of asphalt" << endl;
    cout << "------------------------End of Object copy testing--------------------------" << endl;

  }

  // object assignment testing
  {
    Road copy;
    copy = road;
    length = copy.ObtainLength();
    width = copy.ObtainWidth();
    result = copy.asphalt(3);

    assert(length == 5);
    assert(width == 5);
    assert(result == 32998);

    //...confirm that copy's contents match road's
    cout << endl << endl;
    cout << "------------------------Object assignment testing-----------------------------" << endl;
    cout << "5 miles is expected, " << "actual value is = " << length << " mile"<< endl;
    cout << "5 feet is expected " << "actual value is = " << width  << " feet" << endl;
    cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998 cubic inches" << endl;
    assert(result == 32998); //make sure value is true
    cout << "result= " << result << " cubic inches of asphalt" << endl;
    cout << "------------------------End of Object assignment testing--------------------" << endl;

  }
  cout << "press enter to finish" << endl;
  cin.get();
}
