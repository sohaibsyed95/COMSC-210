#include <iostream>
using namespace std;
#include <vector>
#include <cassert>
#include "Queue.h"
#include "Queue.h" //testing ifndef

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 7a, Write And Apply A Stack Template \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //variable and Stack of floats created
  Queue<int> s;
  int temp;

  cout << "*********Testing constructor.*********" << endl;
  cout << "s.size() should be 0, is actually " << s.size() << endl;
  assert(s.size() == 0);
  cout << "*********End of Testing constructor.*********" << endl;
  cout << endl << endl;

  cout << "******************Testing push function*******************" << endl;
  s.push(2);
  s.push(4);
  s.push(5);
  s.push(7);
  cout << "4 is expected for size of stack, it actually is: " << s.size() << endl;
  cout << "******************End of Testing push function*******************" << endl;
  cout << endl << endl;
  assert(s.size() == 4);


  cout << "******************Testing peek function*******************" << endl;
  cout << "2 is expected peek value on the stack " << endl;
  s.peek(temp);
  cout << "whats actually on the stack is: " << temp << endl;
  cout << "******************End of Testing peek function*******************" << endl;
  cout << endl << endl;
  assert(temp == 2);

  cout << "******************Testing pop function*******************" << endl;
  cout << "4 is new expected value " << endl;
  s.pop(temp);
  s.peek(temp);
  cout << "whats actually on the stack is: " << temp << endl;
  cout << "******************End of Testing pop function*******************" << endl;
  cout << endl << endl;
  assert(temp == 4);

  cout << "**********************Object Assignment Testing**********************" << endl;
  cout << "Now testing if copy is equal to original stack." << endl;
  const Queue<int> copy = s;
  int x;
  copy.peek(x);
  s.peek(temp);
  if(temp == x)
    cout << "Test Result: They are equal! " << endl;
  else
    cout << "Test Result: They aren't equal..." << endl;
  cout << "******************End of Object Assignment Testing*******************" << endl;
  cout << endl << endl;
  assert(temp == x);

  cout << "*****************Operator= testing****************" << endl;
  Queue<int> t;
  t = s;
  t.peek(temp);
  cout << "4 is expected peek value of the new stack. " << endl;
  cout << temp << " is the actual value" << endl;
  cout << "*****************End of Operator= testing****************" << endl;
  assert(temp == 4);
  cout << endl << endl;

  cout << "*****************Size testing****************" << endl;
  cout << "3 is expected size of s." << endl;
  cout << s.size() << " is the actual value" << endl;
  cout << "*****************End of Size testing****************" << endl;
  assert(s.size() == 3);
  cout << endl << endl;

  cout << "*****************Clear testing****************" << endl;
  s.clear();
  cout << "Size should be 0." << endl;
  cout << s.size() << " is the actual size" << endl;
  cout << "*****************End of Clear testing****************" << endl;
  assert(s.size() == 0);

  cout << "*****************Empty testing****************" << endl;
  s.empty();
  if(s.empty() == true)
    cout << "Stack is empty" << endl;
  else
    cout << "Stack isn't empty" << endl;
  cout << "*****************Empty testing****************" << endl;
  assert(s.empty() == true);
  cout << endl << endl;

  cout << "Press [ENTER] to finish the program." << endl;
  cin.get();
}
