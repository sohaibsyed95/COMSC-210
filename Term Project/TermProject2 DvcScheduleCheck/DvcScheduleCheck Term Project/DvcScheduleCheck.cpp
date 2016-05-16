// Term Project 2, DvcScheduleCheck.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

//c++ libraries
#include <iostream>
#include <fstream> //file input/output
#include <map>
#include <iomanip> //formatting output
#include <string>
using namespace std;
//c libraries
#include <cstring> //strcpy
#include <ctime> //clock

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Term project: DvcScheduleCheck.cpp \n";
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

  //variables, including maps strings buffer input, and counter
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int counter = 0;
  map<string, string> dat;
  string term2, section2, course2, line;
  map<string, string>::iterator it;
  map<string, string> output;

  //while the file is good
  while(fin.good())
  {
    //get input from file and insert into string
    getline(fin, line);
    strcpy(buf, line.c_str());
    if(buf[0] == 0)
      continue;

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");

    it = dat.find(term + "-" + section);
    if(it == dat.end())
    {
      dat[term + "-" + section] = course;
    }
    else
    {
      if(it->second != course)
      {
        output[term + "-" + section + "-" + course] = it->first + "-" + it->second;
      }
    }
  }
  //close input file
  fin.close();

  //Use this to stop the timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "The total runtime of the program is " << elapsedSeconds << " seconds." << endl;

  cout << "There are " << output.size() << " duplicate/invalid entries in the database" << endl;
  cout << "They are as follows, along with their duplicate class: " << endl;
  cout << setw(7) << "Term" << setw(16) << "Section" << setw(13) << "Course" << endl;
  cout << "-------------" << setw(10) << "-------" << setw(13) << "------" << endl;
  //begin map iterator loop for output
  for(it = output.begin(); it != output.end(); it++)
  {
    //first is first parameter of the map, output is as follows
    strcpy(buf, it->first.c_str());
    term2 = (token = strtok(buf, "-")); //concatenate term output into term2 string
    section2 = (token = strtok(0, "-")); //concatenate section output into section2 string
    course2 = (token = strtok(0, "-")); //concatenate course output into course2 string
    cout << endl << ++counter << ": " << term2 << ", Section #" << section2 << ",    " << course2;

    //second is second parameter of the map, output is as follows
    strcpy(buf, it->second.c_str());
    term2 = (token = strtok(buf, "-")); //concatenate term output into term2 string
    section2 = (token = strtok(0, "-")); //concatenate section output into section2 string
    course2 = (token = strtok(0, "-")); //concatenate course output into course2 string
    cout << endl << ++counter << ": " << term2 << ", Section #" << section2 << ",    " << course2;
  }
  cout << endl << endl;
  cout << "-----------------------------End of Program--------------------------" << endl;
  cout << "Thank you for using the program. Press [ENTER] to finish." << endl;
  cin.get();
}
