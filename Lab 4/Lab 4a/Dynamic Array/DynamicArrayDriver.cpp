#include <iostream>
using namespace std;
#include <vector>
#include <cassert>
#include "DynamicArray.h"
#include "DynamicArray.h" //testing ifndef

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
  DynamicArray<int> a;
  DynamicArray<int> b(100);

  cout << "****************Constructor Testing***********************" << endl;
  for(int i = 0; i < a.capacity(); i++)
    if(a.containsKey(i) == false)
      cout << "a[" << i << "] = false" << endl;
  cout << "****************END OF Constructor Testing***********************" << endl;
  cout << endl << endl;
  cout << "****************[] Testing***********************" << endl;
  for(int i = 0; i < a.capacity(); i++)
  a[0] = 10;
  a[1] = 69;
  a[3] = 7;
  a[4] = 8;
  for(int i = 0; i < a.capacity(); i++)
    if(a.containsKey(i) == true)
      cout << "a[" << i << "] = " << a[i] << endl;
  cout << "****************END OF [] Testing***********************" << endl;
  cout << endl << endl;
    //object assignment testing
  cout << "**********************Object Assignment Testing**********************" << endl;
  cout << "Now testing if a[0] is set to 100." << endl;
  if(a[0] == 100)
    cout << "Test Result: They are equal! " << endl;
  else
    cout << "Test Result: They aren't equal..." << endl;
  cout << "******************End of Object Assignment Testing*******************" << endl;
  cout << endl << endl;

  assert(a.containsKey(0) == true);
  // object copy testing with function from lab writeup
  cout << "**********************Object Copy Testing**********************" << endl;
  const DynamicArray<int> copy = a;
  for (int i = 0; i < copy.capacity(); i++)
    cout << "copy[" << i << "] = " << copy[i] << endl;
  cout << "*******************End of Object Copy Testing*******************" << endl;
  cout << endl << endl;

  cout << "******************Operator [] getter*******************" << endl;
  cout << "copy[0] is " << copy[0] << endl;
  cout << "****************** END OF Operator [] getter*******************" << endl;
  cout << endl << endl;

  cout << "*****************Testing the capacity array*********************" << endl;
  cout << "a.CAPACITY Should be 50. It is: " << a.capacity() << endl;
  assert(a.capacity() == 50);
  cout << "*****************End Testing the capacity array*****************" << endl;

  cout << endl << endl;

  cout << "*****************Now testing the size of the array*************" << endl;
  cout << "a.size() should be four. It actually is: " << a.size() << endl;
  assert(a.size() == 4);
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
  assert(count == 4);
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
  assert((a.containsKey(0) && a.containsKey(1) && a.containsKey(3) && a.containsKey(4)) == true);
  cout << "******************End of the containsKey function**********" << endl;

  cout << endl << endl;

  cout << "******************Testing the deleteKey function***********" << endl;
  a.deleteKey(4);
  cout << "A.SIZE() should be three, is now: " << a.size() << endl;
  assert(a.size() == 3);
  cout << "******************End of the deleteKey test****************" << endl;

  cout << endl << endl;

  cout << "******************Testing the clear function***************" << endl;
  a.clear();
  cout << "A.SIZE() should be zero, is now: " << a.size() << endl;
  assert(a.size() == 0);
  cout << "******************End of the clear test********************" << endl;
  cout << endl << endl;

  cout << "******************Testing OPERATOR=***************" << endl;
  cout << "B.capacity is " << b.capacity() << endl;
  cout << "B.size is " << b.size() << endl;
  b = a;
  cout << "B.capacity now is " << b.capacity() << endl;
  cout << "B.size now is " << b.size() << endl;
  for(int i = 0; i < b.capacity(); i++)
    if(b.containsKey(i) == true)
      cout << "b[" << i << "] = " << b[i] << endl;
  cout << "******************End of operator=********************" << endl;
  cout << endl << endl;

  cout << "******************Testing expandibility***************" << endl;
  cout << "a[60] is wild, it is: " << a[60] << endl;
  a[60] = 699;
  cout << "new value of a[60] is: " << a[60] << endl;
  cout << "a.capacity now is: " << a.capacity() << endl;
  cout << "a.size now is: " << a.size() << endl;
  cout << "******************END OF Testing expandibility***************" << endl;

}
