// Lab 3b, Write A Static Array Application
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;
#include <cstdlib>
#include <vector>

#include "MyStaticArray.h"
int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 1a, Class Programming and Testing \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //declare buffers and needed integer values
  char buf[100];
  char buff[100];
  int num1, num2;
  int track = 0;
  //create the StaticArray Object
  StaticArray<int, 100> a;
  while(a.size() <= a.capacity())
  {
    cout << "Input an index and a value [Q to quit]: ";
    cin >> buf;
    if(buf[0] == 'Q' || buf[0] == 'q')
    {
      //check the number of values stored in the array and what they are
      cout << "I stored this many values: " << a.size() <<  endl;
      cout << "The values are: " << endl;
      for(int i = 0; i < 100; i++)
      {
        if(a.containsKey(i) == true)
        {
          cout << i  << " " << a[i] << "" << endl;
          track++;
        }
      }

      while(true)
      {
        //ask user to enter an index they can search from they array
        //and see if that index is found or not
        cout << "Input an index for me to look up [Q to quit]:";
        cin >> buf;
        if(buf[0] == 'Q' || buf[0] == 'q')
            return 0;
        num1 = atoi(buf);

        //if found
        if(a.containsKey(num1) == true)
            cout << "Found it -- the value stored at " << buf << " is " << a[num1] << endl;
        else //not found
            cout << "I didn't find it" << endl;
      }
    }
   // cin the second char buf and convert both entries in buf to integer values
    cin >> buff;
    num1 = atoi(buf);
    num2 = atoi(buff);
    a[num1] = num2;
  }

}
