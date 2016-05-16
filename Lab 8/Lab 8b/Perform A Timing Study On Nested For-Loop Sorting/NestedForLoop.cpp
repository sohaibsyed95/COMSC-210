// Lab 8b, Perform A Timing Study On Nested For-Loop Sorting
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

//c++ libraries
#include <iostream>
#include <string>
#include <algorithm>  //for swap
using namespace std;

//c libraries
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main()
{
  /*// print my name, this assignment's title, and file information
  cout << "Lab 8b, Perform A Timing Study On Nested For-Loop Sorting \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;*/

  //create the array and fill it with random values
  srand(time(0));
  rand();
  int n = 1000;
  string bigOh = "O(n squared)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;

  for(int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    //provided from email
    double* arr = new double[n];
    for(int i = 0; i < n; i++)
    {
      int j = 0;
      j = rand();
      arr[i] = j;
    }

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();

    //begin of nested for loop
    for(int i = 0; i < n; i++)
    {
      for(int j = i + 1; j < n; j++)
      {
        //swap values of array
        if(arr[j] < arr[i])
          swap(arr[i], arr[j]);
      }
    }

    //end the clock
    clock_t endTime = clock();
    //verify that each number in the array is greater or equal to the number before it
    //starting with the 2nd number. Use assert, like this:
    for (int i = 1; i < n; i++) assert (arr[i - 1] <= arr[i]);

    //deallocate the array
    delete [] arr;

    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
}
