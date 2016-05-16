#include <iostream>
#include <string>
#include <cstring>
using namespace std;
#include <fstream>
#include <cassert>
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{
  // problem setup goes here
  // programmer customizations go here
  int n = 7000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  char buf[1000];
  char* token;
  const char* const tab = "\t";
  string bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  // for timing fast operations, use REPS up to 100th of the starting n

  cout << "Press [ENTER] to begin the program" << endl;
  cin.get();

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for(int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    ifstream fin;
    fin.open("dvc-schedule.txt");
    if(!fin.good()) throw "I/O error";

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    //do something
    int i = 0;
    while(fin.good())
    {
      if(++i == n) break;
      string oneLine;
      getline(fin, oneLine);
      strcpy(buf, oneLine.c_str());
      if(buf[0] == 0)
        continue;

      // parse the line, code from labs 5a, 5b, 6b
      const string term(token = strtok(buf, tab));
      const string section(token = strtok(0, tab));
      const string course((token = strtok(0, tab)) ? token : "");
      const string instructor((token = strtok(0, tab)) ? token : "");
      const string whenWhere((token = strtok(0, tab)) ? token : "");
      if (course.find('-') == string::npos) continue; // invalid line
      const string subjectCode(course.begin(), course.begin() + course.find('-'));
    }

    fin.close();
    //end the clock
    clock_t endTime = clock();

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
