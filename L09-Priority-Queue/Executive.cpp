/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Executive.cpp
*/



#include "Executive.h"


//constructor; it opens the indicated file and calls runSimulation
//requires valid input file
Executive::Executive(const char* fileName)
{
  infile = new ifstream(fileName);
  runSimulation();
}

//runs through the program calling methods from Heap and PriorityQueue
//parses file using getline
//requires Executive to be constructed
void Executive::runSimulation()
{
  cout << "*********************** Simulation Begin ***********************" << endl;
  string line;
  getline(*infile, line);
  //line += '\n';
  cout << "Size of Priority Queue " << line << endl;
  int maxQueue = stoi(line);

  PriorityQueue<Patient> hospitalQueue(maxQueue);
  while (getline(*infile, line))
  {
    // cout << "TEST2" << endl;
    stringstream command(line);
    string C11;
    command >> C11;
    if (C11 == "serve")
    {
      try
    {
      // std::cout << "We are here." << endl;
      cout << "Now Serving: " << hospitalQueue.peekFront() << endl;
      hospitalQueue.dequeue();
    }
    catch (EmptyPriorityQueue& e)
    {
      std::cout << "Priority queue is empty! Moving on!\n";
      e.what();
    }
    }
    else if (C11 == "preview")
    {
      preview(hospitalQueue);
    }

    else
    {
      // if (theHeap.numItemsInHeap >= theHeap.sizeOfArray)
      // cout << "TEST3" << endl;
      //PriorityQueue<Patient> copyQueue = new PriorityQueue<Patient>(*hospitalQueue);
      stringstream nextPatient(line);
      string arrival;
      string name;
      string priorityStr;
      nextPatient >> arrival;
      nextPatient >> name;
      nextPatient >> priorityStr;
      int priority = stoi(priorityStr);
      Patient nextPatientObj(name, priority);
      cout << "New Arrival: " << nextPatientObj << endl;
      hospitalQueue.enqueue(nextPatientObj);
      // std::cout << "TEST." << endl;
    }
  }
  cout << "*********************** Simulation Complete ***********************" << endl;
  cout << "Patients not yet served:" << endl;
  preview(hospitalQueue);
}

//displays formatted preview of upcoming operations to user
//requires a PriorityQueue to be made
void Executive::preview(PriorityQueue<Patient> pq) // NOTE: The Priority Queue is passed by value!!!
{

  cout << "========== Assuming no new arrivals, the current set of patients will be processed as follows ===========" << endl;
  //pq.printQueueAsList();

  while (!pq.isEmpty())
  {
    cout << pq.peekFront() << endl;
    pq.dequeue();
  }

  cout << "============== End of Preview ==============" << endl;
}

//end of file
