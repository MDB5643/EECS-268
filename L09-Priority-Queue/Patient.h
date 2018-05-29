/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Patient.h
*/



#ifndef PATIENT_H
#define PATIENT_H


#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Patient
{

private:
	int priority;
	string name;

public:

	Patient();//constructs patient object

	Patient(string name, int priority);

	~Patient();//destructs patient

	inline bool operator<( const Patient& rhs)//operator overload
	{
		return (priority < rhs.priority);
	}

	friend ostream& operator<<(std::ostream& os, const Patient& obj);

};

#endif

//end of file
