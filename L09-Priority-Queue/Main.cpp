/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Main.cpp
*/


#include <iostream>

#include "Patient.cpp"
#include "PriorityQueue.cpp"
#include "Heap.cpp"
#include "Executive.cpp"

using namespace std;

//program begins here
//main reads in a file, creates an executive, which calls runSimulation
//has a default setting that reads in the default.sim file in the project folder
//otherwise reads in file specified on command line

int main(int argc, char* argv[])
{
	Executive *exe; //create executive
	if (argc != 2)
	{
		cout << "Wrong number of args, using default file" << endl;
		exe = new Executive("default.txt");
	}
	else
	{
		exe = new Executive(argv[1]);
	}

}

//end of file
