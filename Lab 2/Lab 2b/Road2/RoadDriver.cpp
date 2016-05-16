// Lab 2b, Writing Templates And Overloading Operators
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
  cout << "Lab 2b, Writing Templates And Overloading Operators \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;


  //DOUBLE ROAD TESTING
  Road<double> road;
  road.WidthOfRoad(5); //feet
  road.LengthOfRoad(5); //miles
  double length = road.ObtainLength(); //in miles
  double width = road.ObtainWidth(); //in feet
  double result = road.asphalt(3);
  assert(length == 5);
  assert(width == 5);
  assert(result == 32998.68);
  cout << "********************DOUBLE ROAD TESTING*******************" << endl;
  cout << "------------------------Object testing road1-----------------------------" << endl;
  cout << "5 miles is expected, " << "actual value is = " << length << " mile"<< endl;
  cout << "5 feet is expected, " << "actual value is = " << width  << " feet" << endl;
  cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998.68 cubic inches" << endl;
  assert(result == 32998.68); //make sure value is true
  cout << "result= " << result << " cubic inches of asphalt" << endl;
  cout << "------------------------End of Object testing road1-----------------------" << endl;

  // object copy testing
  {
    const Road<double> copy = road; // a read-only copy
    length = copy.ObtainLength();
    width = copy.ObtainWidth();
    result = copy.asphalt(3);

    assert(length == 5);
    assert(width == 5);
    assert(result == 32998.68);

    //...confirm that copy's contents match road's
    cout << endl;
    cout << "----------------------Object copy testing road1--------------------------" << endl;
    cout << "5 miles is expected, " << "actual value is = " << length << " mile"<< endl;
    cout << "5 feet is expected " << "actual value is = " << width  << " feet" << endl;
    cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998.68 cubic inches" << endl;
    assert(result == 32998.68); //make sure value is true
    cout << "result= " << result << " cubic inches of asphalt" << endl;
    cout << "----------------------End of Object copy testing road1-------------------" << endl;

  }

  // object assignment testing
  {
    Road<double> copy;
    copy = road;
    length = copy.ObtainLength();
    width = copy.ObtainWidth();
    result = copy.asphalt(3);

    assert(length == 5);
    assert(width == 5);
    assert(result == 32998.68);

    //...confirm that copy's contents match road's
    cout << endl;
    cout << "---------------------Object assignment testing road1-----------------------" << endl;
    cout << "5 miles is expected, " << "actual value is = " << length << " mile"<< endl;
    cout << "5 feet is expected " << "actual value is = " << width  << " feet" << endl;
    cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998.68 cubic inches" << endl;
    assert(result == 32998.68); //make sure value is true
    cout << "result= " << result << " cubic inches of asphalt" << endl;
    cout << "---------------------End of Object assignment testing road1----------------" << endl;

  }

  cout << endl << endl;
  cout << "********************INT ROAD TESTING*******************" << endl;
  Road<int> road2;
  road2.WidthOfRoad(5);
  road2.LengthOfRoad(5);
  int length2 = road2.ObtainLength(); //in miles
  int width2 = road2.ObtainWidth(); //in feet
  int result2 = road2.asphalt(3);
  assert(length2 == 5);
  assert(width2 == 5);
  assert(result2 == 32998);

  cout << "---------------Object testing road2---------------------" << endl;
  cout << "5 miles is expected, " << "actual value is = " << length2 << " mile"<< endl;
  cout << "5 feet is expected " << "actual value is = " << width2  << " feet" << endl;
  cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998 cubic inches" << endl;
  assert(result2 == 32998); //make sure value is true
  cout << "result= " << result2 << " cubic inches of asphalt" << endl;
  cout << "---------------End of Object testing road2---------------" << endl;


  // object copy testing road2
  {
    const Road<int> copy = road2; // a read-only copy
    length2 = copy.ObtainLength();
    width2 = copy.ObtainWidth();
    result2 = copy.asphalt(3);

    assert(length2 == 5);
    assert(width2 == 5);
    assert(result2 == 32998);

    //...confirm that copy's contents match road's
    cout << endl;
    cout << "------------------Object copy testing road2----------------------" << endl;
    cout << "5 miles is expected, " << "actual value is = " << length2 << " mile"<< endl;
    cout << "5 feet is expected " << "actual value is = " << width2  << " feet" << endl;
    cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998 cubic inches" << endl;
    assert(result2 == 32998); //make sure value is true
    cout << "result= " << result << " cubic inches of asphalt" << endl;
    cout << "---------------End of Object copy testing road2---------------" << endl;
  }


  // object assignment testing
  {
    Road<int> copy;
    copy = road2;

    length2 = copy.ObtainLength();
    width2 = copy.ObtainWidth();
    result2 = copy.asphalt(3);

    assert(length2 == 5);
    assert(width2 == 5);
    assert(result2 == 32998);

    //...confirm that copy's contents match road's
    cout << endl;
    cout << "--------------------Object assignment testing road2--------------------" << endl;
    cout << "5 miles is expected, " << "actual value is = " << length2 << " mile"<< endl;
    cout << "5 feet is expected " << "actual value is = " << width2  << " feet" << endl;
    cout << "Asphalt Thickness is: (3 * 0.08333) * (5 * 5280) * 5 = 32998 cubic inches" << endl;
    assert(result2 == 32998); //make sure value is true
    cout << "result= " << result << " cubic inches of asphalt" << endl;
    cout << "-----------------End of Object assignment testing road2--------------" << endl;

  }
  //double object testing
  cout << endl << endl;
  cout << "**************DOUBLE OBJECT OVERLOAD TEST****************" << endl;

  Road<double> road3;
  road3.LengthOfRoad(1);
  road3.WidthOfRoad(1);
  road3.asphalt(3);

  cout << "Check if road3 is less than road: " << endl;
  if(road3 < road)
    cout << "Road3 is less than road." << endl;
  else
    cout << "Road3 is not less than road." << endl;
  cout << endl << endl;

  cout << "**************DOUBLE OPERATOR= TEST****************" << endl;
  if(road == road3)
    cout << "Road1 and road3 are equal" << endl;
  else
    cout << "Road1 and road3 are not equal" << endl;
  assert((road == road3) == false);

  Road<double> road33;
  road33 = road;

  cout << "Checking if copy road33 is equal to road 2" << endl;
  if(road == road33)
    cout << "Copy road33 is equal to road " << endl;
  else
    cout << " are not equal" << endl;

  cout << endl << endl;
  cout << "**************INT OBJECT OVERLOAD TEST****************" << endl;

  Road<int> road4;
  road4.WidthOfRoad(6);
  road4.LengthOfRoad(6);

  cout << "Check if road4 is less than road2." << endl;
  if(road4 < road2)
    cout << "Road4 is less than road2" << endl;
  else
    cout << "Road4 is not less than road2" << endl;
  assert(road2 < road4);
  if(road2 < road4)
    cout << "Road2 is less than road4" << endl;
  else
    cout << "Road2 is not less than road4" << endl;

  cout << endl << endl;
  cout << "**************INT OPERATOR= TEST****************" << endl;

  if(road2 == road4)
    cout << "Road2 and road4 are equal" << endl;
  else
    cout << "Road2 and road4 are not equal" << endl;

  assert(!(road2 == road4));
  Road<int> road22;
  road22 = road2;

  cout << "Check if road2 and copy road 2 are equal" << endl;
  if(road2 == road22)
    cout << "Road2 and road22 copy are the same" << endl;
  else
    cout << "Road2 and road22 are not the same " << endl;
  cout << endl << endl;
  cout << "press enter to finish the program" << endl;
  cin.get();
}
