// Lab 7c, Use a Stack
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

//c++ libraries first
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//then c libraries and source file
#include <cstring>
#include "Stack.h"

struct Symbol
{
  int line;
  char symbol;
};

int main()
{
  // print my name, this assignment's title, and file information
  cout << "Lab 7c, Use a Stack \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //declare needed variables
  Stack<Symbol> s;
  Symbol a, b;
  //Symbol b;
  bool quote = false;
  bool starSlash = false;
  bool starSlash2 = false;
  bool testing = true;

  //create input vars
  ifstream fin;
  string file, tr;
  int i;
  int lineCount = 0;
  cout << "Enter filename (H, CPP, JAVA, HTML, or JS): ";
  getline(cin, file);
  fin.open(file.c_str());
  if(!fin.good()) throw "I/O error";

  //start testing while assuming file is good
  while(fin.good())
  {
    //get the input from the file
    getline(fin, tr);
    i = tr.length();

    if(quote)
      break;
    quote = false;
    lineCount++; //increment line counter

    for(int j = 0; j < i; j++)
    {
      //assign object to the next valid position character of the string with the at() function
      a.symbol = tr.at(j); //Value with the position of a character within the string

      //single line comment - double slash test
      if(tr[j] == '/')
      {
        if(j + 1 < i && tr[j + 1] == '/')
          break;
      }

      //slash star test
      if(tr[j] == '/')
      {
        if(j + 1 < i && tr[j + 1] == '*') //if first / successful
        a.line = lineCount;
        s.push(a);
        s.peek(b);
        starSlash = true;
      }

      //star slash - multi line comment test
      if(starSlash)
      {
        //if it finds closing *
        if(tr[j] == '*')
        {
          //then finds closing / in next position of the string
          if(tr[j + 1] == '/')
          {
            if(s.empty())
            {
              testing = false;
            }
            else
            {
              s.pop(a);
              starSlash = false;
              continue;
            }
          }
        }
      }

      //continue if starSlash is valid
      if(starSlash)
        continue;

      //testing for quotes
      if('\"' == tr[j])
      {
        if(!quote)
          quote = true;
        else
          quote = false;
      }
      if(quote)
        continue;


      //testing for first entry opening bracket, function, or parentheses
      if(tr[j] == '{' || tr[j] == '[' || tr[j] == '(')
      {
        a.line = lineCount;
        s.push(a);
      }

      //testing for either a closing bracket, function, or parentheses
      if(tr[j] == '}' || tr[j] == ']' || tr[j] == ')')
      {
        if(s.empty() || (tr[j] == '*' && tr[j + 1]))
        {
          //closing curly bracket output
          if(tr[j] == '}')
          {
            cout << "Closing bracket found: line #" << lineCount << "from the file " << file << ". However no opening curly brace\n";
          }

          //closing square bracket output
          if(tr[j] == ']')
          {
            cout << "Closing square bracket found: line #" << lineCount << "from the file " << file << ". However no opening square brace\n";
          }

          //closing parenthesis output
          if(tr[j] == ')')
          {
            cout << "Closing parenthesis found: line #" << lineCount << "from the file " << file << ". However no opening parenthesis\n";
          }

          if(tr[j] == '*' && tr[j + 1] == '/')
          {
            cout << "Closing multi-line comment found: line #" << lineCount << "from the file " << file << ". However no opening multi-line comment\n";
            starSlash2 = true;
          }

          testing = false;
          break;
        }

        else
        {
          //peek the b object
          s.peek(b);
        }
        if((a.symbol == '}' && b.symbol == '{') || (a.symbol == ']' || b.symbol == '[') || (a.symbol == ')' || b.symbol == '('))
        {
          s.pop(a);
          continue;
        }
      }

    }

    if(!testing)
    {
      break;
    }
  }
  //close file once done using it
  fin.close();

  if(!starSlash2)
  {
    if(testing && s.empty() && !starSlash)
    {
      cout << "No mismatches found by my preprocessor in" << file << endl;
    }

    //test single line comment code
    if(starSlash)
    {
      cout << "An opening / was found, line #" << lineCount << ". No closing / found \n";
    }
    //check if the object is empty or not and if opening star slash is not valid
    if((s.empty()) && (!starSlash))
    {
      //peek a object
      s.peek(a);

      //opening bracket but no closing bracket
      if(a.symbol == '{')
      {
        cout << "An opening { was found, line #" << lineCount << ". No closing } was found \n";
      }

      //opening square bracket but no closing bracket
      else if(a.symbol == '[')
      {
        cout << "An opening [ was found, line #" << lineCount << ". No closing ] was found \n";
      }

      //opening parenthesis but no closing parenthesis
      else if(a.symbol == '(')
      {
        cout << "An opening ( was found, line #" << lineCount << ". No closing ) was found \n";
      }

      //opening comment
      else
      {
        cout << "An opening / was found, line #" << lineCount << ". No closing / was found \n";
      }
    }
  }

  s.empty();
  cout << "Thank you for using the program. Press [ENTER] to finish.\n";
  cin.get();

}
