// Lab 3a, Write A Static Array Class Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++
#include <iostream>
using namespace std;
#include <vector>
#include <cassert>
#include "StaticArray.h"
#include "StaticArray.h" //testing ifndef

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 3a, Write A Static Array Class Template \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //declare values of the static array
  StaticArray<int, 10> a;
  a[0] = 100;
  a[7] = 7;
  a[9] = 9;
  assert(a[0] == 100);

  //assert one element of the array to test
  assert(a[0] == 100);

  //object assignment testing
  cout << "**********************Object Assignment Testing**********************" << endl;
  cout << "Now testing if a[0] is set to 100. If they are equal, that's great!" << endl;
  if(a[0] == 100)
    cout << "Test Result: They are equal! " << endl;
  else
    cout << "Test Result: They aren't equal..." << endl;
  cout << "******************End of Object Assignment Testing*******************" << endl;
  cout << endl << endl;

  // object copy testing with function from lab writeup
  cout << "**********************Object Copy Testing**********************" << endl;
  const StaticArray<int, 10> copy = a;
  for (int i = 0; i < copy.capacity(); i++)
    cout << "copy[" << i << "] = " << copy[i] << endl;
  cout << "*******************End of Object Copy Testing*******************" << endl;

  cout << endl << endl;
  //Testing Square Bracket Getter
  cout << "******************Now Testing Square Bracket Getter []**********" << endl;
  cout << "Copy[0] is equal to = " << copy[0] << endl;
  cout << "*****************End of Testing Square Bracket Getter []********" << endl;

  cout << endl << endl;

  cout << "*****************Testing the capacity array*********************" << endl;
  cout << "a.CAPACITY Should be 10. It is: " << a.capacity() << endl;
  assert(a.capacity() == 10);
  cout << "*****************End Testing the capacity array*****************" << endl;

  cout << endl << endl;

  cout << "*****************Now testing the size of the array*************" << endl;
  cout << "a.size() should be three. It actually is: " << a.size() << endl;
  assert(a.size() == 3);
  cout << "*****************EndNow testing the size of the array**********" << endl;

  cout << endl << endl;

  cout << "****************Testing the keys function*****************" << endl;
  vector<int> keys = a.keys();
  int count = 0;
  for (int i = 0; i < keys.size(); i++)
  {
    cout << "a[" << keys[i] << "] = " << a[keys[i]] << endl;
    count++;
  }
  assert(count == 3);
  cout << "*****************END of keys testing**********************" << endl;

  cout << endl << endl;

  cout << "******************Testing the containsKey function*********" << endl;
  for(int i = 0; i < a.capacity(); i++)
  {
    if(a.containsKey(i) == true)
    {
       cout << "a[" << i << "] = true" << endl;
    }
  }
  assert((a.containsKey(0) && a.containsKey(7) && a.containsKey(9)) == true);
  cout << "******************End of the containsKey function**********" << endl;

  cout << endl << endl;

  cout << "******************Testing the deleteKey function***********" << endl;
  a.deleteKey(7);
  cout << "A.SIZE() should be two, is now: " << a.size() << endl;
  assert(a.size() == 2);
  cout << "******************End of the deleteKey test****************" << endl;

  cout << endl << endl;

  cout << "******************Testing the clear function***************" << endl;
  a.clear();
  cout << "A.SIZE() should be zero, is now: " << a.size() << endl;
  assert(a.size() == 0);
  cout << "******************End of the clear test********************" << endl;
}
