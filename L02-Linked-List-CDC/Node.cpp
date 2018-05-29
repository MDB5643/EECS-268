/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: node.cpp
/ @since: 9-17-2016
*/

#include "Node.h"


template <typename T>
Node<T>::Node()
{
  //m_value = 0;
  m_next = nullptr;

}

template <typename T>
void Node<T>::setValue(T val)
{
  m_value = val;

}

template <typename T>
T Node<T>::getValue() const
{
  return m_value;

}

template <typename T>
void Node<T>::setNext(Node<T>* prev)
{
  m_next = prev;

}

template <typename T>
Node<T>* Node<T>::getNext() const
{
  return m_next;

}
