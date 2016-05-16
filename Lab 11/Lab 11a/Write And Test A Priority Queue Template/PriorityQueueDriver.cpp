// LAB 11a: Write And Test A Priority Queue Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++
#include <iostream>
using namespace std;
#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h" // for ifndef testing

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 11a: Write And Test A Priority Queue Template \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  PriorityQueue<int> pqlist(5);

  cout << "**********Size Tester **********" << endl;
  cout << "pq.size() Should be = to 0. its actually equal to " << pqlist.size() << endl;
  cout << "**********End of Size Tester **********" << endl;
  cout << endl << endl;


  cout << "**********Enqueue Function Tester**********" << endl;
  pqlist.enqueue(30);
  pqlist.enqueue(50);
  pqlist.enqueue(70);
  pqlist.enqueue(90);
  pqlist.enqueue(110);
  cout << "The size of pqlist should now be 5" << endl;
  cout << "pqlist.size() is = " << pqlist.size() << endl;
  assert(pqlist.size() == 5);
  cout << "******End of Enqueue Function Tester*******" << endl;
  cout << endl << endl;


  cout << "**********Dequeue Function Tester**********" << endl;
  pqlist.dequeue();
  cout << "pqlist.size() should now be 4, is = " << pqlist.size() << endl;
  assert(pqlist.size() == 4);
  cout << "*******End of Dequeue Function Tester*******" << endl;
  cout << endl << endl;


  cout << "**********Front Function Tester**********" << endl;
  pqlist.front();
  cout << "pqlist should be 70, now is = " << pqlist.front() << endl;
  assert(pqlist.front() == 70);
  cout << "*******End of Front Function Tester******" << endl;
  cout << endl << endl;


  cout << "**********Back Function Tester**********" << endl;
  pqlist.front();
  cout << "Pqlist.back() should be 110, is = " << pqlist.back() << endl;
  assert(pqlist.back() == 110);
  cout << "*******End of Back Function Tester******" << endl;
  cout << endl << endl;


  cout << "**********Copy Constructor Tester**********" << endl;
  PriorityQueue<int> pqlist2 = pqlist;
  cout << "Pqlist2.size() should be 4, is = " << pqlist2.size() << endl;
  cout << "Pqlist2.back is = " << pqlist2.back() << endl;
  assert((pqlist2.size() == 4) && (pqlist2.back() == 110));
  cout << "******End of Copy Constructor Tester*******" << endl;
  cout << endl << endl;


  cout << "**********Operator= Tester**********" << endl;
  PriorityQueue<int> pqlist3;
  pqlist3 = pqlist2;
  cout << "pqlist3.size() should be 4, is = " << pqlist3.size() << endl;
  cout << "pqlist3.back() should be 110, is = " << pqlist3.back() << endl;
  assert((pqlist3.size() == 4) && pqlist3.back() == 110);
  cout << "*******End of operator= Tester******" << endl;
  cout << endl << endl;


  cout << "**********Empty Function Tester**********" << endl;
  cout << "pqlist has objects in it, so it should not be empty" << endl;
  if(pqlist.empty())
    cout << "pqlist.empty = true" << endl;
  else
    cout << "pqlist.empty() = false" << endl;
  assert(!pqlist.empty());
  cout << "*****End of Empty Function Tester********" << endl;
  cout << endl << endl;


  cout << "**********Clear Function Tester**********" << endl;
  pqlist.clear();
  cout << "Pqlist should now be empty, is = " << pqlist.size() << endl;
  assert(pqlist.size() == 0);
  cout << "*******End of Clear Function Tester******" << endl;
  cout << endl << endl;


  cout << "Thanks for using the program." << endl;
  cout << "Press [ENTER] to finish the program." << endl;
  cin.get();
}
