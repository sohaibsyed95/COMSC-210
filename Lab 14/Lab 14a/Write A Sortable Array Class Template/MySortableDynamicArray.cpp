// LAB 14a: Write A Sortable Array Class Template
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <iostream>
using namespace std;
#include <cstdlib>

#include "SortableDynamicArray.h"
int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 14a: Write A Sortable Array Class Template \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //declare buffers and needed integer values
  char buf[100];
  char buff[100];
  int num2;
  int userentry, userentry2;
  int track = 0;

  //create the StaticArray Object
  SortableArray<int> a;
  vector<int> keys = a.keys();
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
        {
          cout << "How many values do you want to sort: " << endl;
          cin >> buf;
          userentry = atoi(buf);
          a.sort(userentry);
          cout << "Sorted values: " << endl;
          for (int i = 0; i < a.size(); i++)
          {
            if(a.containsKey(i) == true)
              cout << i << " " << a[i] << " " << endl;
          }
          while(true)
          {
            int entry;
            cout << "Enter a value for me to search for [Q/q to quit]:";
            cin >> buf;
            if(buf[0] == 'Q' || buf[0] == 'q')
              break;
            entry = atoi(buf);
            int index = a.bsearch(userentry, entry);
            if(index == -1)
            {
              cout << "Not in the array" << endl;
            }
            else
            {
              cout << entry << " " << "is at the index " << index << endl;
            }
          }
          cout << "Thanks for using the program. Press [ENTER] to finish." << endl;
          cin.get();
          return 0;
        }

        userentry2 = atoi(buf);

        //if found
        if(a.containsKey(userentry2) == true)
            cout << "Found it -- the value stored at " << buf << " is " << a[userentry2] << endl;
        else //not found
            cout << "I didn't find it" << endl;
      }
    }

   // cin the second char buf and convert both entries in buf to integer values
    cin >> buff;
    userentry2 = atoi(buf);
    num2 = atoi(buff);
    a[userentry2] = num2;
  }
}
