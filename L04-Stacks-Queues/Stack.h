/**
* @file Stack.h
* @author Matt Bailey
* @since 10-03-2016
*
*/

/**
*implements all methods from the StackInterface class
*put precondition, postcondition, return, and throw comments in this class
*use Node class form lab3 as building blocks for stack, but need teplated version
*/

#ifndef STACK_H
#define STACK_H

#include "StackInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"



template <typename ItemType>
class Stack: public StackInterface<ItemType>
{
 public:
 /*
 pre: Stack object is created
 post: private member variables are initialized
 */
 Stack();

 /*
 pre: Destructor
 post: Deletes instances of stack class
 */
 ~Stack();

 /*
 pre: Stack object has been created
 post: Returns true if stack is empty, flase otherwise
 */
 bool isEmpty() const;

 /*
 pre: value is inputed
 post:adds value to the top of the Stack
 **/
 void push(const  ItemType& newEntry) throw (PrecondViolatedExcep);

 /*
 pre: Assumes stack is not empty
 post: Entry added to top of stack
 **/
 void pop() throw (PrecondViolatedExcep);

 /*
 pre: assumes the stack is not empty
 post: top of the stack is removed, throws PreconditionViolationException
 *when a pop is attempted on an empty stack. Does not return a value in this case.
 **/
 ItemType peek() const throw (PrecondViolatedExcep);

 /*
 pre: stack created
 post: returns the size of the stack
 **/
 int size() const;


 private:
   //isnatce of node class, pointer
   Node<ItemType>* m_top;

   //size of Stack
   int m_size;


};

#include "Stack.cpp"

#endif
