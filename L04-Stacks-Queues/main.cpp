/**
* @file main.cpp
* @author Matt Bailey
* @since 10-2-2016
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <sstream>
#include "Stack.h"
#include "Queue.h"
#include "PrecondViolatedExcep.h"
#include <cstring>


//input file
//std::ifstream filename(argv);

int main(int argc, char* argv[])
{

  Stack<std::string>* elevator = new Stack<std::string>();

  Queue<std::string>* line = new Queue<std::string>();

  std::string name;
  std::string command;
  std::string num;
  std::string ename;
  std::string lname;
  std::string item;
  int dropnum;
  int elevatornum = 0;

  //Lab2 input file
  //std::ifstream inp(argv);

  std::string NewFile = argv[1];
  std::ifstream inp(NewFile);


  while (std::getline(inp, item))
  {
    std::stringstream sstr(item);

    while (getline(sstr, command, ' '))
    {
      if (command == "WAIT")
      {
        getline(sstr, name, ' ');
        line->enqueue(name);
      }
      else if (command == "DROP_OFF")
      {
        getline(sstr, num, ' ');
        dropnum = stoi(num);
        try
        {
        for (int i = 0; i < dropnum; i++)
        {
          elevatornum--;
          elevator->pop();
          // elevatornum--;
        }
        }
        catch(PrecondViolatedExcep)
        {
          std::cout << "Pop attempted on empty stack!\n";
        }

      }
      else if (command == "INSPECTION")
      {
        std::cout << "Elevator status:\n";
        if (elevator->isEmpty())
        {
          std::cout << "Elevator is empty.\n";
          try
          {
            lname = line->peekFront();
            std::cout << lname << " will be the next person to enter on the elevator.\n";
          }
          catch(PrecondViolatedExcep)
          {
            std::cout << "Line is empty too.\n";
          }
        }
        else
        {
          std::cout << "Elevator is not empty.\n";
        try
        {
          ename = elevator->peek();
        }
        catch(PrecondViolatedExcep)
        {
          std::cout << "Peek attempted on empty stack.\n";
        }
        try
        {
          lname = line->peekFront();
        }
        catch(PrecondViolatedExcep)
        {
          std::cout << "Line is empty.\n";
        }
          std::cout << ename << " will be next person to exit the elevator.\n";
          std::cout << lname << " will be next person to enter the elevator. \n";
        }
      }
      else if (command == "PICK_UP")
      {
        // if (!(line->isEmpty())
        // {
        try
        {
        while (elevatornum < 7 && line->isEmpty() != true)
        {

            elevatornum++;
            elevator->push(line->peekFront());
            line->dequeue();
          }
        }
        catch(PrecondViolatedExcep)
        {
          std::cout << "Line is empty.\n";
        }
        // }
      }
    }
  }



  inp.close();
  return 0;



}//end of main
