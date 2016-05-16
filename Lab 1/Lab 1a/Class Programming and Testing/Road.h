// Lab 1a, Class Program and Testing
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#ifndef ROAD_H
#define ROAD_H

class Road
{
  private:
    int width;
    int length;
  public:
    void WidthOfRoad(int feet);
    void LengthOfRoad(int miles);
    int ObtainWidth() const;
    int ObtainLength() const;
    int asphalt(int thickness) const;
};
#endif // ROAD_H
