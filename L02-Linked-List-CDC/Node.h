/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: node.h
/ @since: 9-17-2016
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{

 public:
  /*
    pre: Node object is created
    post: private member variables are initialized
  */
  Node();

  /*
    pre: valid integer is passed into parameter
    post: m_value is set to val
  */
  void setValue(T val);

  /*
    pre: m_value has valid value
    post: value is returned
  */
  T getValue() const;

  /*
    pre: valid Node* is passed into parameter
    post: m_next is set
  */
  void setNext(Node<T>* prev);

  /*
    pre: m_next has a valid value
    post: value is returned
  */
  Node<T>* getNext() const;


 private:
  //the value in the node
  T m_value;

  //the pointer to another node
  Node<T>* m_next;


};
#include "Node.hpp"

#endif
