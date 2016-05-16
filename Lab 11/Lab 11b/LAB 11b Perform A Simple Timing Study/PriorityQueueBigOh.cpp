// LAB LAB 11b:  Perform A Simple Timing Study
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
#include <string>
using namespace std;
#include <cassert>
#include <cmath>
#include <ctime>

#include "PriorityQueue.h"
#include "PriorityQueue.h" // for ifndef testing

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 11b:  Perform A Simple Timing Study \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // problem setup goes here
  // programmer customizations go here
  PriorityQueue<int> a(2);
  int n = 50000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  int elapsedTimeTicksNorm = 0;
  string bigOh = "O(log n)";
  const int reps = (n/100);
  double expectedTimeTicks = 0;
  for(int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    for(int i = n; i > 1; --i)
    {
      a.enqueue(i);
    }
    assert(a.size() == n - 1);

    clock_t startTime = clock();
    int reps2;
    for(reps2 = 0; reps2 < reps; reps2++)
    {
      for(int i = n + 1; i < n + reps2; i++)
      {
        a.enqueue(i);
      }
    }
    clock_t endTime = clock();

    int m = a.size();
    for(int i = m; i >0; i--)
    {
      a.dequeue();
      assert(a.front() >= a[1] || a.front() >= a[2]);
    }

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
  cout << "Press [ENTER]" << endl;
  cin.get();

  n = 50000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  elapsedTimeTicksNorm = 0;
  const int repsreps = n/100;
  expectedTimeTicks = 0;
  for(int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    for(int i = n; i > 1; i--)
    {
      a.enqueue(i);
    }
    int temp = a.size();
    assert(a.size() == n - 1);

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    int reps3;
    for(reps3 = 0; reps3 < repsreps; reps3++)
    {
      for(int i = 0; i < temp; i++, --temp)
      {
        a.dequeue();
      }
    }
    // stop the timer
    clock_t endTime = clock();
    assert(a.front() >= a[1] || a.front() >= a[2]);

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
