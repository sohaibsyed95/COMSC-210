// LAB 10b: Apply The STL map Template To The Classic Game Of Life Simulation
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

//c++ libraries
#include <iostream>
#include <map>
using namespace std;
//then c libraries
#include <cstdlib>

#include "HashTable.h"

struct cell
{
  int row; // any +/0/- value
  int col; // any +/0/- value
  bool operator<(const cell&) const;
};

map<cell, int> grid;
map<cell, int> grid2;

//Dimensions of the grid with the origin at the center
const int MINROW = -25;
const int MAXROW = 25;
const int MINCOL = -35;
const int MAXCOL = 35;

int neighborCount(int row, int col)
{
  //Count neighboring living cells around cell at row and col
  cell temp;
  int count = 0;
  for (temp.row = row - 1; temp.row <= row + 1; temp.row++)
    for (temp.col = col - 1; temp.col <= col + 1; temp.col++)
      if (temp.row != row || temp.col != col)
        if (grid.find(temp) != grid.end())
          ++count;
  return count;
}

void initialize()
{
  //Output instructions
  cout << "List the coordinates for living cells.\n";
  cout << "Terminate the list with a special pair -1 -1\n";

  //Get input for storing living cells
  cell temp;
  char buf[100];
  while (true)
  {
    cin >> buf; temp.row = atoi(buf);
    cin >> buf; temp.col = atoi(buf);
    if (temp.row == -1 && temp.col == -1) break;
    grid[temp] = 'X';
  }
  cin.ignore();
}

void print()
{
  //Output the grid at the current generation
  cell temp;
  cout << "\nThe current Life configuration is:\n";

  //Nested for loop to print the grid
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      if (grid.find(temp) != grid.end())
        cout << 'X';
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
}

void update()
{
  //Calculate new generation
  cell temp;
  grid2.clear();

  //Nested for loops to traverse the grid
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
    {
      //Process cells based on number of neighbors
      switch (neighborCount(temp.row, temp.col))
      {
        //If 2 neighbors, cell lives (copy old cell to next gen grid)
        case 2:
          if (grid.find(temp) != grid.end()) grid2[temp] = 'X';
          break;
        //Cell with 3 neighbors lives next generation
        case 3:
          grid2[temp] = 'X';
          break;
      } //switch - process cells based on number of neighbors
    } //for - traverse columns of grid
  } //for - traverse rows

  //Update grid
  grid = grid2;
};

bool cell::operator<(const cell& a) const
{
  if((100000 * row + col) < (100000 * a.row + a.col))
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 10b: Apply The STL map Template To The Classic Game Of Life Simulation \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //Prep and output grid for zeroth generation
  initialize();
  print();

  //Game loop cycle
  for (int i = 1; grid.size(); i++)
  {
    //Prompt user for continuing (any normal keyboard character) or quitting (hitting enter)
    cout << "Generation " << i << ". Press ENTER to continue, X-ENTER to quit...\n";
    if (cin.get() > 31) break;

    //Process the grid and output the current generation
    update();
    print();
  }
} //main
