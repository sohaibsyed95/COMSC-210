// Lab 5b, Using A Data Structure As A Data Member
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "DynamicArray.h"

struct Course
{
  string coursename;
  int sectionCountCourse = 0;
};

struct Subject
{
  string codeName;
  int sectionCount;
  DynamicArray<Course> dynCourse;
};


int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 5b, Using A Data Structure As A Data Member \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // for parsing the input file
  DynamicArray<Subject> a(1000);
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  string b;
  int size = 0;
  int duplicates = 0;
  int i = 0;
  int j = 0;

  cout << "press [ENTER]" << endl;
  cin.get();

  // open the input file
  ifstream fin;
  ofstream fout;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  //initialize start timer
  clock_t startTime = clock();
  int n = 0;

  // read the input file
  while (fin.good())
  {
    //output .... then implement flush
    if (++n % 1000 == 0)cout << '.';
    cout.flush();
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0)
      continue;
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    if(b.find('|' + term + section + '|') != string::npos)
    {
      duplicates++;
      continue;
    }
    b = '|' + term + section + '|' + b;

    for(i = 0; i < size; i++)
    {
      if(a[i].codeName == subjectCode)
        break;
    }

    if(size == i)
    {
      a[i].codeName = subjectCode;
      a[i].sectionCount = 1;
      size++;
    }
    else
    {
      a[i].sectionCount++;
    }

    bool findSubject = false;
    bool findCourse = false;
    int i;
    for(i = 0; i < a.size(); i++)
    {
      if(a[i].codeName == subjectCode)
      {
        findSubject = true;
        break;
      }
    }
    if(findSubject == true)
    {
      for(j = 0; j < a[i].dynCourse.size(); j++)
      {
        if(a[i].dynCourse[j].coursename == course)
        {
          findCourse = true;
          break;
        }
      }
      if(findCourse == true)
      {
        a[i].dynCourse[j].sectionCountCourse++;
      }
      if(findCourse == false)
      {
        if(j == a[i].dynCourse.size())
        {
          Course x;
          x.coursename = course;
          x.sectionCountCourse = 1;
          a[i].dynCourse[a[i].dynCourse.size()] = x;
        }
      }
    }

    if(i == a.size()) //no match check
    {
      Subject y;
      y.codeName = subjectCode;
      Course z;
      z.coursename = course;
      z.sectionCountCourse = 1;
      y.dynCourse[0] = z;
      a[a.size()] = y;
    }


  }//close file
  fin.close();

  //Use this to stop the timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  //code for sorting the array
  Subject c;
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      if(a[i].codeName < a[j].codeName)
      {
        c = a[i];
        a[i] = a [j];
        a[j] = c;
      }
    }
  }
  //resulting output from the input file
  cout << "There were " << duplicates << " duplicate classes" << endl;
  cout << "The total runtime of the program is " << elapsedSeconds << " seconds." << endl;
  for(int i = 0; i < a.size(); i++)
  {
    cout << a[i].codeName << " " << a[i].dynCourse.size() << " course(s)" << endl;
    for(int j = 0; j < a[i].dynCourse.size(); j++)
    {
      cout << "    " << a[i].dynCourse[j].coursename << " " << a[i].dynCourse[j].sectionCountCourse << " section(s)" << endl;
    }
  }

  cout << "Press [ENTER] to finish the program " << endl;
  cin.get();

  fout.open("DvcSchedule.xls");
  if(!fout.good()) throw "I/O error";
  fout << "Section Name" << '\t' << "Section count" << endl;
  for(int i = 0; i < a.size(); i++)
  {
    fout << endl << a[i].codeName << "\t" << a[i].dynCourse.size() << "course(s)" << endl;
    for(int j = 0; j < a[i].dynCourse.size(); j++)
    {
      fout << a[i].dynCourse[j].coursename << '\t' << a[i].dynCourse[j].sectionCountCourse << endl;
    }
  }
  fout.close();

}
