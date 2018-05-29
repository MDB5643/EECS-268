/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: linkedlist.cpp
/ @since: 9-17-2016
*/


#include <iostream>
// #include "LinkedList.h"
#include <string>


template <typename T>
LinkedList<T>::LinkedList()
{
	m_front = nullptr;
	m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* temp = m_front;
	Node<T>* next = nullptr;
	while (temp != nullptr)
	{
		next == temp->getNext();
		delete temp;
		temp == next;
	}

}//end of destructor

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	if (m_length == 0)
	{
		return true;

	}
	else
	{
		return false;
	}

}//end of bool method

template<typename T>
int LinkedList<T>::getLength() const
{
	return m_length;
}//end of size method

template<typename T>
int LinkedList<T>::positionOf(T value) const
{
  if (m_front == nullptr)
  {
    return 0;
  }
  else
  {
    int pos = 1;
    Node<T>* temp = m_front;
    while(temp->getValue != value)
    {
      temp = temp->getNext();
      pos++;
    }
    return pos;
  }


}//end of positionOf mehtod


template<typename T>
void LinkedList<T>::addBack(T value)
{

	Node<T>* newNode = new Node<T>();
	newNode->setValue(value);

	if (m_front == nullptr)
	{
		m_front = newNode;
		m_length++;
	}
	else
	{
		Node<T>* temp = m_front;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext(newNode);
		m_length++;
	}

}//end of addBack method

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* newNode = new Node<T>();
	newNode->setValue(value);

	if (m_front == nullptr)
	{
		m_front = newNode;
		m_length++;
	}
	else
	{
		newNode->setNext(m_front);
		m_front = newNode;
		m_length++;
	}
}//end of addFront method

template <typename T>
bool LinkedList<T>::removeBack()
{

	if (m_front == nullptr)
	{
		return false;
	}

	else if (m_length == 1)
	{
		Node<T>* temp = m_front;
		delete temp;
		m_front = nullptr;
		m_length--;
		return true;
	}

	else
	{
		Node<T>* temp = m_front;
		while(temp->getNext()->getNext() != nullptr)
		{
			temp = temp->getNext();
		}
		Node<T>* temp2 = temp;
		temp2 = temp->getNext();
		delete temp2;
		temp->setNext(nullptr);
	}
}//end of removeBack method

template <typename T>
bool LinkedList<T>::removeFront()
{


	if (m_length == 0)
	{
		return false;

	}

	else if (m_length == 1)
	{
		Node<T>* temp = m_front;
		delete temp;
		m_front = nullptr;
		m_length--;
	}

	else
	{
		Node<T>* temp = m_front;
		m_front = m_front->getNext();
		delete temp;
		m_length--;
		return true;

	}

}//end of removeFront method

template <typename T>
bool LinkedList<T>::removeAt(int position)
{
	if (m_front == nullptr || position > m_length)
	{
		return false;
	}

	else if (position == 1)
	{

		removeFront();
		return true;
	}

	else if(position == m_length)
	{

		removeBack();
		return true;
	}

	else
	{
		Node<T>* temp = m_front;
		int count = 1;

		while (count != position-1)
		{
			temp = temp->getNext();
			count++;
		}
		Node<T>* temp2 = temp->getNext;
		Node<T>* temp3 = temp2->getNext();
		delete temp2;
		temp->setNext(temp3);
		m_length--;
		return true;

	}
}

template <typename T>
bool LinkedList<T>::insert(int position, T value)
{

	if (m_front == nullptr || position > m_length+1)
	{
		return false;
	}
	else
	{
		if(position == 1)
		{
			addFront(value);
			m_length++;
			return true;
		}
		else if(position == m_length + 1)
		{
			addBack(value);
			m_length++;
			return true;
		}
		else
		{
			Node<T>* newNode = new Node<T>();
			Node<T>* temp = m_front;
			int count = 1;
			while(position-1 > count)
			{
				temp = temp->getNext();
				count++;
			}
			Node<T>* temp2 = temp->getNext();
			temp->setNext(newNode);
			newNode->setNext(temp2);
			m_length++;
			return true;
	}

}
}
template <typename T>
void LinkedList<T>::setEntry(int position, T value)
{

	if(position < 1 || position > m_length || m_front == nullptr)
	{
		throw(std::runtime_error("Error! setEntry thrown. Trying to set any entry to a node that does not exist"));
	}
	else
	{
		int count = 1;
		Node<T>* temp = m_front;
		while(position != count)
		{
			temp = temp->getNext();
			count++;
		}
		temp->setValue(value);
	}
}

template <typename T>
T LinkedList<T>::getEntry(int position) const
{
	int count = 0;
	if (position < 1 || position > m_length || m_front ==nullptr)
	{
		throw(std::runtime_error("Error! getEntry thrown. Trying to get an entry of a node that does not exist."));
	}

	else
	{
		count = 1;
		Node<T>* temp = m_front;
		while(position != count)
		{
			temp = temp->getNext();
			count++;
		}
		T answer;
		answer = temp->getValue();
		return answer;
	}

}
