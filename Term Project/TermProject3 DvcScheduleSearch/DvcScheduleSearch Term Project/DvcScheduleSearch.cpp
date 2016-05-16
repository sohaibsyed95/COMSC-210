// Term project 3: DvcScheduleSearch.cpp
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

//c++ libraries
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <map>
#include <string>
using namespace std;
//c libraries
#include <cstring>
#include <ctime>

//function parameter
//this function compares terms in the maps and see which term the class was last offered in
bool termGetter(string, string);

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Term project 3: DvcScheduleSearch.cpp \n";
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
  char buf[100];
  string line, input;
  map<string, string>::iterator it;
  map<string, string> dat;

  while(fin.good())
  {
    //get the input and copy over to buffer
    getline(fin, input);
    strcpy(buf, input.c_str());
    if(buf[0] == 0) continue;

    // parse the line
    const string term(token = strtok(buf, "\t"));
    const string section(token = strtok(NULL, "\t"));
    const string course(token = strtok(NULL, "\t"));
    strcpy(buf, term.c_str());
    const string season(token = strtok(buf, " "));
    const string year((token = strtok(0, " ")) ? token : "");

    //search for courses map
    it = dat.find(course);

    if(it == dat.end())
    {
      dat[course] = term;
    }

    else
    {
      if(termGetter(term, it->second) == true)
      {
        dat[course] = term;
      }
    }
  }
  //close the input file
  fin.close();

  //Use this to stop the timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  cout << "The total runtime of the program is " << elapsedSeconds << " seconds." << endl;

  do
  {
    cout << "Enter the Course you are looking for. 'COMSC-210' is an example of a valid entry";
    cout << "Once done, press X or x to exit the program: ";
    cin >> input;

    if(input != "X" && input != "x")
    {
      it = dat.find(input);

      //output of the course and when it was last offered
      if(it != dat.end())
      {
        cout << it->first << " was last offered in " << it->second << endl;
      }

      //fallback statement in case user entry is not in the database
      else
      {
        cout << input << " has not been offered since the year 2000!" << endl;
      }
    }
  } while(input != "X" && input != "x"); //end do while, user input being X/x
}

//this function compares terms in the maps and see which is most recent one
bool termGetter(string a, string b)
{
  char buf[100];
  char* token;

  //copy from buf to string a
  strcpy(buf, a.c_str());
  const string semesterType(token = strtok(buf, " "));
  const string yearOfCourse((token = strtok(0, " ")) ? token : "");

  //copy from buf to string b
  strcpy(buf, b.c_str());
  const string semesterType2(token = strtok(buf, " "));
  const string yearOfCourse2((token = strtok(0, " ")) ? token : "");

  //if the year the course was offered is equal to each other
  if (yearOfCourse == yearOfCourse2)
  {
    // search if the class was offered in spring fall or summer
    if (semesterType=="Fall" && (semesterType2=="Summer" || semesterType2=="Spring"))
    {
      return true;
    }
    //search for just summer and spring terms
    else if (semesterType=="Summer" && semesterType2=="Spring")
    {
      return true;
    }
    //default to just spring
    else
    {
      return false;
    }
  }
  else
    return yearOfCourse > yearOfCourse2;
}
