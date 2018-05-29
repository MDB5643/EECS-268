/**
* @file Queue.h
* @author Matt Bailey
* @since 10-2-2016
*/

#ifndef QUEUE_H
#define QUEUE_H

#include "QueueInterface.h"


template <typename ItemType>
class Queue: QueueInterface<ItemType>
{

public:

  /*
  pre: queue object is created
  post: private member variables are initialized
  */
  Queue();

  /*
	pre: destructor
	post: deletes instances of stack class
	*/
  ~Queue();

  /*
	pre: queue object has been created
	post: returns true if queue is empty, flase otherwise
	*/
  bool isEmpty() const;

  /*
  pre: value is inputed
  post: adds value to the queue. If queue empty, add to front, if queue not empty, add to back.
  **/
  void enqueue(const ItemType& newEntry) throw (PrecondViolatedExcep);

  /*
  pre: value is inputed and in queue
  post: Removes value from queue
  **/
  void dequeue() throw (PrecondViolatedExcep);

  /*
  pre: assumes value in queue
  post: returns value in front of queue
  **/
  ItemType peekFront() const throw (PrecondViolatedExcep);

  Node<ItemType>* nextNode() const throw (PrecondViolatedExcep);

  ItemType nextValue() const throw (PrecondViolatedExcep);


private:
  Node<ItemType>* m_front;

  Node<ItemType>* m_rear;

  int m_size;

};

#include "Queue.cpp"

#endif
