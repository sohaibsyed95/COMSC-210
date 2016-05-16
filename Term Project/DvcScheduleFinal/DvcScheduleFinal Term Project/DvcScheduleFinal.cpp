// Term project 1: DvcScheduleFinal.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <iomanip>
#include <string>
using namespace std;
#include <cstring>
#include <ctime>

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Term project: DvcScheduleFinal.cpp \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  //initialize start timer
  clock_t startTime = clock();

  //variables, including maps
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  map< string, map<string, int> >::iterator it;
  map<string, int>::iterator it2;
  map<string, map<string, int> > parse;

  while(fin.good())
  {
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if(buf[0] == 0) continue;

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    parse[subjectCode][course]++;
  }

  //Use this to stop the timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "------------------Subject----------------" << endl;
  for(it = parse.begin(); it != parse.end(); it++)
  {
    cout << endl;
    //first is an iterator to the first element in the container.
    //second is an iterator to the past-the-end element in the container.
    cout << "Subject:" << it->first << ", ";
    cout << it->second.size() << " sections " << endl;

    for(it2 = it->second.begin(); it2 != it->second.end(); it2++)
    {
      cout << "Course: " << it2->first << '-' << "Number of courses: " << it2->second << endl;
    }
  }
  cout << endl << endl;
  cout << "The total runtime of the program is " << elapsedSeconds << " seconds." << endl;
  cout << "-----------------------------End of Program--------------------------" << endl;
  cout << "Thank you for using the program. Press [ENTER] to finish." << endl;
  cin.get();
  //less than 83 lines of code
}
