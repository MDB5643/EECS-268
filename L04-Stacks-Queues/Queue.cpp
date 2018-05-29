/**
* @file Queue.cpp
* @author Matt Bailey
* @since 10-2-2016
*/


#include "Node.cpp"

template <typename ItemType>
Queue<ItemType>::Queue()
{
  //constructor
  m_front = nullptr;
  m_size = 1;

}//end of constructor

template <typename ItemType>
Queue<ItemType>::~Queue()
{
  //destructor
  while(m_front->getNext() != nullptr)
    {
      Node<ItemType>* temp = m_front->getNext();
      delete m_front;
      m_front = temp;

    }

}//end of destructor

template <typename ItemType>
bool Queue<ItemType>::isEmpty() const
{
  //checks to see if stack is empty
  if (m_size == 0)
    {
      return true;
    }
  else
    {
      return false;
    }

}//end of isEmpty method


template <typename ItemType>
void Queue<ItemType>::enqueue(const ItemType& newEntry) throw(PrecondViolatedExcep)
{
  Node<ItemType>* newNode = new Node<ItemType>;
  newNode->setValue(newEntry);

  if(newNode == nullptr)
  {
    throw PrecondViolatedExcep("Heap memory is full.");
  }
  else if(m_front == nullptr)
  {
    m_front = newNode;
  }
  else
  {
    Node<ItemType>* temp = m_front;
		while (temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		  temp->setNext(newNode);

      m_size++;
  }


}//end of enqueue method

template <typename ItemType>
void Queue<ItemType>::dequeue() throw(PrecondViolatedExcep)
{
  Node<ItemType>* temp = m_front;
  if (m_size == 0)
  {
    throw PrecondViolatedExcep("Tried to delete an empty queue.");
  }
  else
  {
    //Node<T>* temp = m_front;
    temp = m_front->getNext();
    delete m_front;
    m_front = temp;
    m_size--;
  }

}//end of dequeue method

template <typename ItemType>
ItemType Queue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
  if(m_size == 0)
    {
      throw PrecondViolatedExcep("Peek attempted on empty stack.");
    }
  else
    {
      return(m_front->getValue());
    }

}//end of peekFront method
