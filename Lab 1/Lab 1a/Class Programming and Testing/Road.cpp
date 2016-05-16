// Lab 1a, Class Program and Testing
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include "Road.h"

void Road::WidthOfRoad(int feet)
{
  width = feet;
}

void Road::LengthOfRoad(int miles)
{
  length = miles;
}

int Road::ObtainWidth() const
{
  return width;
}

int Road::ObtainLength() const
{
  return length;
}

int Road::asphalt(int thickness) const
{
  /*//conversion process, 5280 ft = 1 mile, 1 inch = 0.0833 feet
  const int FeetInAMile = 5280;
  const double FeetInAnInch = 0.0833;

  //formula for calculating cubic feet = length * width * height
  int cubicFeet = (thickness * FeetInAnInch) * (length * FeetInAMile) * width;
  return cubicFeet;
  */
  int cubicFeet;
  cubicFeet = (thickness * .08333) *(length * 5280) * width;
  return cubicFeet;
}
