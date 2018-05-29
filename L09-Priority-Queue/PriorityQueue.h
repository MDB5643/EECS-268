/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: PriorityQueue.h
*/



#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "Heap.h"
#include "EmptyPriorityQueue.h"

template <typename T>
class PriorityQueue
{
private:
	Heap<T>* theHeap = nullptr;

public:
	PriorityQueue(int initialSize);//original constructor

	PriorityQueue(const PriorityQueue<T>& pq); // The copy constructor

	~PriorityQueue(); //destructor, deallocates heap

	void enqueue(T newEntry); //adds item using heap function

	void dequeue() throw();// EmptyPriorityQueue

	bool isEmpty() const;//checks empty status

	T peekFront() const;//reveals front item in queue

	void printQueueAsList();//prints queue. as a list, no less!

};

#endif

//end of file
