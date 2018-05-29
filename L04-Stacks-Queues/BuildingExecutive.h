/**
* @file main.cpp
* @author Matt Bailey
* @since 10-2-2016
*/

#ifndef BUILDINGEXECUTIVE_H
#define BUILDINGEXECUTIVE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <sstream>
#include "Stack.h"
#include "Queue.h"
#include "PrecondViolatedExcep.h"
#include <cstring>

class BuildingExecutive
{
public:
  BuildingExecutive(char*);

  ~BuildingExecutive();

  void run() const;

private:

  std::string name;
  std::string command;
  std::string num;
  std::string ename;
  std::string lname;
  std::string item;
  int dropnum;

};

#endif
