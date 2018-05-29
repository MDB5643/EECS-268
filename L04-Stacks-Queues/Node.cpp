/**
 * @file Node.cpp
 * @author Matt Bailey
 * @since 10-2-2016
 */

#include "Node.h"

template <typename ItemType>
Node<ItemType>::Node()
{

  m_next = nullptr;

}

template <typename ItemType>
void Node<ItemType>::setValue(ItemType value)
{
  m_value = value;

}

template <typename ItemType>
ItemType Node<ItemType>::getValue() const
{
  return m_value;

}

template <typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* prev)
{
  m_next = prev;

}

template <typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
  return m_next;

}
