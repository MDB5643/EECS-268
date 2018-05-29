/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Heap.h
*/



#ifndef HEAP_H
#define HEAP_H

#include "EmptyHeap.h"
#include <iostream>

using namespace std;


template <typename T>
class Heap
{
private:
	int sizeOfArray;
	int numItemsInHeap;
//	int initialSize;
	T* theCompleteBinaryTree = nullptr;

public:

	Heap(int initialSize); //The original constructor

	Heap(const Heap<T>& heap); // The copy constructor

	~Heap(); //destructor

	void add(T& newItem); //makes an addition to the heap based on passed in value

	bool isEmpty() const; //returns T/F based on if heap is empty

	void remove(); //removes item from heap

	void printTree();//display heap to console

	void printList();

	T peekTop(); //view top entry in heap

};

#endif

//end of file
