// Lab 10a, Write, Test, and Apply The HashTable Class Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++
//first c++ libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//then c libraries
#include <cstring>
#include <cassert>

//h file
#include "HashTable.h"
#include "HashTable.h" //for testing ifndef


int main()
{
  // for parsing the inputfile
  AssociativeArray<string, Term> a;
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int n = 0;
  const Term param;
  int duplicates = 0;
  int da = 0;
  cout << "The size of the array currently is: " << a.size() << endl;

  while (fin.good())
  {
    //output .... then implement flush
    if (++n % 10 == 0)cout << '.';
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
  {
    cout << "a[" >> op2[i].term << "] = " << a[op2[i] << endl;
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

}
