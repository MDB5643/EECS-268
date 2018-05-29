/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Executive.h
*/



#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <ostream>
#include <string>

#include "PriorityQueue.h"
#include "Patient.h"

using namespace std;

class Executive
{
private:
	ifstream *infile;

public:
	Executive(const char* fileName); // constructor; it opens the indicated file and calls runSimulation.

	void runSimulation(); //runs simulation of user interaction

	void preview(PriorityQueue<Patient> pq); // NOTE: The Priority Queue is passed by value!!!


};

#endif
// #include "Executive.cpp"

//end of file
