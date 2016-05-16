// LAB 12: Write A Customer Service Simulation
// Programmer: Sohaib Syed
// Editor(s) used: Code::Blocks
// Compiler(s) used: mingw32-g++

//first c++ libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <string>
using namespace std;
//then c libraries
#include <cmath>
#include <cstdlib>
#include <ctime>

struct customer
{
  int arrivalTime, serviceTime, completionTime;
  char ID;
  customer(): serviceTime(0), completionTime(0), ID(' '){}
};

struct serviceEvent
{
  int clockTime, serverNumber;
  bool operator<(const serviceEvent& a) const {return (clockTime > a.clockTime);}
};

int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep);

int main()
{
  // print my name, this assignment's title, and file information
  cout << "LAB 12: Write A Customer Service Simulation \n";
  cout << "Programmer: Sohaib Syed\n";
  cout << "Editor(s) used: Code::Blocks\n";
  cout << "Compiler(s) used: mingw32-g++\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  //call srand only once in a program, as the first statement in main
  srand((float)time(0)); rand();
  ifstream fin;
  fin.open("simulation.txt");
  if(!fin.good()) throw "I/O error";

  //receive the values from input file
  int numServers, maxWaitTime, minServiceInterval, maxServiceInterval, clockTime;
  float avgArrivalRate;
  //as numbers only, one per line, in exact order
  fin >> numServers;
  fin.ignore(1000, 10);
  fin >> avgArrivalRate;
  fin.ignore(1000, 10);
  fin >> maxWaitTime;
  fin.ignore(1000, 10);
  fin >> minServiceInterval;
  fin.ignore(1000, 10);
  fin >> maxServiceInterval;
  fin.ignore(1000, 10);
  fin >> clockTime;
  fin.ignore(1000, 10);

  cout << "number of servers: " << numServers << endl;
  cout << "customer arrival rate: " << avgArrivalRate << " per minute, for 50 minutes" << endl;
  cout << "maximum queue length: " << maxWaitTime << endl;
  cout << "minimum service time: " << minServiceInterval << endl;
  cout << "maximum service time: " << maxServiceInterval << endl;

  //declare queues to be used
  queue<customer> custQueue; //customer queue
  queue<customer> afterServiceDone; //after service finished
  priority_queue<serviceEvent> event; // timing for the event
  customer* servers = new customer[numServers];
  bool* status = new bool[numServers];

  string buf;
  int turnAwayCustomers;
  int n = 0;

  for(int i = 0; i < numServers; i++)
    status[i] = false;

  //clock time loop
  for(int time = 0;; time++)
  {
    //service events schedule
    while(!event.empty() && event.top().clockTime == time)
    {
      //remove top service event
      serviceEvent a = event.top(); event.pop();
      int serverNumber = a.serverNumber;
      servers[serverNumber].completionTime = time;
      afterServiceDone.push(servers[serverNumber]);
      servers[serverNumber].ID = ' ';
      status[serverNumber] = false;
    }

    //new arrivals into the simulation
    if(time < maxWaitTime)
    {
      int randNum = getRandomNumberOfServiceRequests(avgArrivalRate);
      for(int i = 0; i < randNum; i++)
      {
        if(custQueue.size() >= maxWaitTime)
          turnAwayCustomers++;
        else
        {
          customer a;
          a.arrivalTime = time;
          a.ID = (char) ('A' + (n++ % 26));
          custQueue.push(a);
        }
      }
    }

    for(int i = 0; i < numServers; i++)
    {
      //if the server is idle and wait queue not empty
      if(!status[i] && !custQueue.empty())
      {
        customer b = custQueue.front();
        custQueue.pop();
        servers[i] = b;
        b.serviceTime = time;
        status[i] = false;
        int ran = rand() % 6;
        serviceEvent c;
        c.clockTime = time + ran;
        c.serverNumber = i;
        event.push(c);
      }
    }

    //print the outputting info
    cout << "Time: " << time << endl;
    cout << "---------------------------------------" << endl;
    cout << "line    now    serving    wait    queue" << endl;
    cout << "----    ---    -------    ----    -----" << endl;
    for(int i = 0; i < numServers; i++)
    {
      cout << setw(5) << i;
      cout << setw(10) << servers[i].ID;
      if(i == 0)
        cout << setw(15) << servers[i].ID;
      cout << endl;
    }
    cout << "---------------------------------------" << endl;

    //summarize performance
    float sum = 0;
    float sumOfTime = 0;
    float sumOfCount = 0;
    if(time != 0)
    {
      queue<customer> avg = afterServiceDone;
      sumOfCount = avg.size();
      while(!avg.empty())
      {
        sumOfTime += (avg.front().completionTime - avg.front().arrivalTime);
        avg.pop();
      }
      sum = sumOfTime/sumOfCount;
    }
    if(sumOfCount != 0)
      cout << "Average time: " << sum;
    else
      cout << "Average time: 0";
    if(turnAwayCustomers != 0)
      cout << "Turned away per minute: " << (float)turnAwayCustomers/time << endl;
    else
      cout << "Turned away per minute: 0" << endl;
    getline(cin, buf);
    if(buf == "X" || buf == "x")
      break;
    else
      continue;
  }

  delete [] servers;
  delete [] status;
}

// requires cmath and cstdlib (and srand and rand to seed the random number generator)
int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
    (randomValue -= probOfnRequests) > 0.0;
    probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}
