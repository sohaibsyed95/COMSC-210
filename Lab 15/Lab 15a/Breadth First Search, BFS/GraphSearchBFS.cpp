#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Vertex
{
  string name;

  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  queue<int> searchOrder; // return this queue of indices
  queue<int> todoList; //create another queue to store the "to do list"
  list<int>::iterator it;
  //initialize each vertex in database: set to "not visited"
  for(int i = 0; i < database.size(); i++)
    database[i].isVisited = false;
  if(iOriginVertex < 0 || iOriginVertex >= database.size())
    return searchOrder;

  //mark starting vertex as "visited"
  database[iOriginVertex].isVisited = true;

  //push start vertex's index onto the result queue
  searchOrder.push(iOriginVertex);

  //push start vertex's index onto the "to do list"
  todoList.push(iOriginVertex);

  //while the "to do list" is not empty
  while(!todoList.empty())
  {
    //peek/pop a vertex from the "to do list"
    int a = todoList.front(); //set result = to int a
    todoList.pop();
    //for each of that vertex's "neighbors"
    for(it = database[a].adjacentVertices.begin(); it != database[a].adjacentVertices.end(); it++)
    {
      //if neighbor has not yet been visited
      if(!database[*it].isVisited)
      {
        //mark neighbor as visited
        database[*it].isVisited = true;

        //push neighbor onto the result queue
        todoList.push(*it);

        //push neighbor onto the "to do list"
        searchOrder.push(*it);
      }

    }
  }
  return searchOrder;
}

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 15a: Breadth First Search, BFS \n";
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
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
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
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
        break;

    // TO DO -- skip the next code blocks if no matching city is found

    // BFS result
    cout << "BFS";
    queue<int> q = doBreadthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }
    cout << endl;
  }
}
