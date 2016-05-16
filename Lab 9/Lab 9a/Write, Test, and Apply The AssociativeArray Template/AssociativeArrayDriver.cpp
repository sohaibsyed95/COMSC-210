// Lab 9a, Write, Test, and Apply The AssociativeArray Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include <vector>
#include <cstring>

#include "AssociativeArray.h"
#include "AssociativeArray.h" //test ifndef

struct Term
{
  string term, section;
};

bool operator==(const Term&, const Term&);

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 9a, Write, Test, and Apply The AssociativeArray Template \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  // for parsing the inputfile
  AssociativeArray<string, Term> a;
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0;
  const Term param;
  int da = 0;

  ifstream fin;
  fin.open("dvc-schedule.txt");
  if(!fin.good()) throw "I/O error";
  cout << "The size of the array currently is: " << a.size() << endl;

  while (fin.good())
  {
    //output .... then implement flush
    if (++n % 10 == 0)
      cout << '.';
    cout.flush();
    if(n == 100)
        break;
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

    Term termsec = {term, section};
    a[termsec] = course;
  }
  //done parsing the file, now we can close it
  fin.close();

  cout << "*********Object Copy Constructor Testing**********" << endl;
  const AssociativeArray<string, Term> copy = a;
  cout << "A.size() = " << a.size() << endl;
  cout << "Copy of a = " << copy.size() << ". Should be the same as a.size." << endl;
  cout << "A.size() = " << a.size() << endl;
  cout << "# of added nodes: " << da << endl;
  cout << "*********End of Object Copy Constructor Testing**********" << endl;
  cout << endl << endl;

  cout << "*********Operator= Testing************" << endl;
  AssociativeArray<string, Term> c;
  c = a;
  cout << "a.size() is = " << a.size() << endl;
  cout << "c.size() is = " << c.size() << endl;
  cout << "*********End of Operator= Testing************" << endl;
  cout << endl << endl;

  cout << "******Operator[] getter testing******" << endl;
  vector<Term> op2;
  op2 = a.keys();
  for(int i = 0; i < op2.size(); i++)
  {//
    cout << "a[" << op2[i].term << "] = " << a[op2[i]] << endl;
  }
  cout << "******End of Operator[] getter testing******" << endl;
  cout << endl << endl;

  cout << "******Deletekey() testing******" << endl;
  cout << "c.size = " << c.size() << endl;
  c.clear();
  cout << "After clearing, c.size() now is = " << c.size() << endl;
  cout << "******End of Deletekey() testing******" << endl;

  fin.open("dvc-schedule.txt");
  if(!fin.good()) throw "I/O error";
  da = 0;
  n = 0;

  while (fin.good())
  {
    //output .... then implement flush
    if (++n % 10 == 0)cout << '.';
    cout.flush();
    if(n == 100)
      break;
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

    Term termsec = {term, section};
    c[termsec] = course;
    if(a[termsec] == c[termsec])
      a.deleteKey(termsec);
    da++;
  }
  //done parsing the file, now we can close it
  fin.close();

  cout << "*********Testing Removal of elements********" << endl;
  cout << "The size is now = " << a.size() << endl;
  cout << "This many elements were removed: " << da << endl;
  cout << "There were " << a.size() << " Duplicates" << endl;
  cout << "Thanks for using the program. Press [ENTER] to finish" << endl;
  cin.get();
}

bool operator==(const Term& diff, const Term& integ)
{
  //if terms don't match, return false
  if(diff.term != integ.term)
    return false;
  //if sections don't match, return false
  if(diff.section != integ.section)
    return false;
  return true;
}
