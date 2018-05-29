/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: EmptyHeap.h
*/



#ifndef EMPTYHEAP_H
#define EMPTYHEAP_H

#include <exception>

using namespace std;

class EmptyHeap : public exception {
public:
	virtual const char* what() const throw()
	{
		return "The heap is empty!";
	}
};

#endif

//end of file
