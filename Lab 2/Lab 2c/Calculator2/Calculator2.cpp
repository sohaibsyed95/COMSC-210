// Lab 2c, Using Templated Classes
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;

#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
#include <string>
#include <iomanip>

bool testUserEntry(string);

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 2c, Using Templated Classes \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  stack <double> s;
  string userentry;
  cout << "Input a number followed by [ENTER], or if you want to quit press Q or q. " << endl;

  do
  {
    //receive the user entry, determine if entry is decimal digit or not
    getline(cin, userentry);
    if(isdigit(userentry[0]))
      s.push(atof(userentry.c_str()));

    //isdigit checks whether entry is a decimal digit character or not
    if (s.size() < 2 && !isdigit(userentry[0]))
      atof(userentry.c_str());

    //operator test
    else if (userentry[0] == '+' || userentry[0] == '-' || userentry[0] == '/' || userentry[0] == '*')
    {
      double a = s.top();
      s.pop();
      double b = s.top();
      s.pop();

      //switch statement of four possible cases in the calculator: +, -, *, /
      switch (userentry[0])
      {
        case '+': s.push(a + b);
          break;
        case '-': s.push(b - a);
          break;
        case '/': s.push(b / a);
          break;
        case '*': s.push(a * b);
          break;
      }
    }

    //set precision of 10 for results
    cout << setprecision(10);
    cout << "Enter: " << setprecision(10);

    //the copy pop method: inspect the stack contents and make a copy of the stack
    for (stack<double> copy = s; !copy.empty(); copy.pop())
      cout << copy.top() << " ";

  } while (testUserEntry(userentry) == true);
  cout << endl;
  cout << "Thank you for using the program. Press [ENTER] to exit the program" << endl;
  cin.get();
}

bool testUserEntry(string checkUserEntry)
{
  bool result = true;
  if((checkUserEntry == "Q") || (checkUserEntry == "q"))
    result = false;
  return result;
}
