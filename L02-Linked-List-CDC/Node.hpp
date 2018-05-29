/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: node.hpp
/ @since: 9-17-2016
*/

#include "Node.h"

template <typename T>
Node<T>::Node()
{
  m_next = nullptr;
}

template <typename T>
void Node<T>::setValue(T value)
{
  m_value = value;
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
