/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Patient.cpp
*/



#include "Patient.h"

//constructs patient object, sets priority
Patient::Patient()
{
  priority = -1;
}


Patient::Patient(string name, int priority)
{
  this->name = name;
  this->priority = priority;
}

//destructs patient
Patient::~Patient()
{

}

//operator overload for ostream
ostream& operator<<(std::ostream& os, const Patient& obj)
{
	os << obj.name << " with priority " << obj.priority;
	return os;
}

//end of file
