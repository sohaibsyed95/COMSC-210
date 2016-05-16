// LAB 14b: Applying A Data Structure To A Database Program
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++
//c++ libraries
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
//c libraries
#include <cstring>
#include <ctime>
#include "SortableDynamicArray.h"


struct Subject
{
  string codeName;
  int sectionCount;
};

struct duplicateCheck
{
  string section, term;
};

bool operator<(const Subject& a, const Subject& b)
{
  return a.codeName < b.codeName;
}

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 14b: Applying A Data Structure To A Database Program \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // for parsing the input file
  SortableArray<Subject> a;
  SortableArray<duplicateCheck> b[20000];

  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int duplicates = 0;

  //initialize start timer
  clock_t startTime = clock();
  int n = 0;
  int ce = 0;
  // open the input file, requires fstream
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    //output .... then implement flush
    if (++n % 1000 == 0)cout << '.';
    cout.flush();
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str()); //requires cstring
    if (buf[0] == 0)
      continue;

    // parse the line
    //strtok requires cstring
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    int sec = atoi(section.c_str());
    bool check;
    int seed = b[sec].size();
    check = false;
    for(int i = 0; i < seed; i++)
    {
      if(b[sec][i].term == term && b[sec][i].section == section)
      {
        duplicates++;
        check = true;
        break;
      }
    }
    int j;
    if(check) continue;
    seed = b[sec].size();
    for(j = 0; j < seed; j++)
    {
      if(b[sec][seed].term == term)
        break;
    }

    //if the counter is equal to section
    if(j == seed)
    {
      b[sec][seed].section = section;
      b[sec][seed].term = term;
    }
    int k;
    int h = a.size();
    for(k = 0; k < h; k++)
    {
      if (a[k].codeName == subjectCode)
      {
        a[k].sectionCount++;
        break;
      }
    }

    if(k == h)
    {
      Subject re;
      re.codeName = subjectCode;
      re.sectionCount = 1;
      a[h] = re;
    }
  }
  //close file
  fin.close();

  a.sort(a.size());
  cout << endl << endl;
  //Use this to stop the timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  //resulting output from the input file
  for(ce = 0; ce < a.size(); ce++)
  {
    cout << a[ce].codeName << ", " << a[ce].sectionCount << " sections" << endl;
  }
  cout << "There were " << duplicates << " duplicate classes" << endl;
  cout << "The total runtime of the program was " << elapsedSeconds << " seconds." << endl;
  cout << "Press [ENTER] to finish the program " << endl;
  cin.get();
}
