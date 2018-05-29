/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: PriorityQueue.cpp
*/



#include "PriorityQueue.h"

//PriorityQueue constructor
//requires an initial size for the queue
template<typename T>
PriorityQueue<T>::PriorityQueue(int initialSize)
{
  theHeap = new Heap<T>(initialSize);
}

//
template<typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& pq) // The copy constructor
{
  if (theHeap != nullptr)
  {
    delete[] theHeap;
    theHeap = nullptr;
  }
  //Heap<T> *temp = new Heap<T>(*pq.theHeap);
  theHeap = new Heap<T>(*pq.theHeap);
  //cout << "Made it" << endl;

}

//destructs PriorityQueue, deallocating theHeap
template<typename T>
PriorityQueue<T>::~PriorityQueue()
{

  delete theHeap;

}

//adds item to the queue by using the add function from the heap class
template<typename T>
void PriorityQueue<T>::enqueue(T newEntry)
{
    // Heap<T> theCopyHeap = new Heap<T>(theHeap

    theHeap->add(newEntry);

}

//removes item from queue by using the remove function from the heap class
template<typename T>
void PriorityQueue<T>::dequeue() throw()// EmptyPriorityQueue
{
  if (isEmpty())
  {
    EmptyPriorityQueue broken;
    throw broken;
  }
  theHeap->remove();
}

//checks to see if the queue is empty
template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
  return theHeap->isEmpty();
}

//reveals the front item of the queue
template<typename T>
T PriorityQueue<T>::peekFront() const
{
  if (isEmpty())
  {
    EmptyPriorityQueue broken;
    throw broken;
  }

  return theHeap->peekTop();
}

//calls the printList function from heap
template<typename T>
void PriorityQueue<T>::printQueueAsList()
{
  theHeap->printList();
}

//end of file
