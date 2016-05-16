// LAB 16a: Write A Function For Shortest Route
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;
#include <cstdlib>

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  // TO DO -- write this function

  //set cost=0 and previous index=-1 for all vertices, and mark all as not visited
  for(int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0; //set cost=0
    database[i].prev = -1; //previous index=-1
    database[i].isVisited = false; //mark all as not visited
  }
  //create a queue to store the "to do list"
  queue<int> todoList;

  //mark start vertex as "visited" and push it onto the "to do list"
  database[iStart].isVisited = true;
  todoList.push(iStart);

  //while the "to do list" is not empty
  while(!todoList.empty())
  {
    //peek/pop a vertex from the "to do list"
    int a = todoList.front();
    todoList.pop();

    //for each of that vertex's neighbors
    for(it = database[a].adjacentVertices.begin(); it != database[a].adjacentVertices.end(); it++)
    {
      //if neighbor has not yet been visited
      if(!database[it->first].isVisited)
      {
        //mark neighbor as visited
        database[it->first].isVisited = true;
        //set neighbor's cost to 1+cost of vertex under consideration
        database[it->first].cost = database[a].cost + 1;
        //set neighbor's previous vertex to the vertex under consideration
        database[it->first].prev = a;
        //push neighbor into the "to do list"
        todoList.push(it->first);
      }

      //if neighbor vertex contains the index of the end city
      if(it->first == iEnd)
      {
        //empty the "to do list"
        while(!todoList.empty())
        {
          todoList.pop();
        }
        //exit for-loop
        break;
      }
    }
  }

  //the route's cost equals the end vertex's cost
  result.second = database[iEnd].cost;

  //build a stack of entries, starting from the end vertex, back towards the start
  for(int endVertex = iEnd; endVertex >= 0; endVertex = database[endVertex].prev)
  {
    result.first.push(endVertex);
  }
  return result;
}

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 16a: Write A Function For Shortest Route \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // TO DO -- code to eliminate whitespace
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    cout << "Total edges: " << result.second;
    while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
    cout << endl;
  }
}
