/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: EmptyPriorityQueue.h
*/



#ifndef EMPTYPRIORITYQUEUE_H
#define EMPTYPRIORITYQUEUE_H

#include <exception>

//custom exception inheriting from exception

using namespace std;

class EmptyPriorityQueue : public exception {
public:
	virtual const char* what() const throw()
	{
		return "The priority queue is empty!";
	}
};

#endif

//end of file
