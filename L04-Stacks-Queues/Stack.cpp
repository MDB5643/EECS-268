/**
* @file Stack.cpp
* @author Matt Bailey
* @since 10-2-2016
*/


template <typename ItemType>
Stack<ItemType>::Stack()
{
 //constructor
 m_top = nullptr;
 m_size = 0;

}//end of constructor

template <typename ItemType>
Stack<ItemType>::~Stack()
{
 //destructor
 while(m_top->getNext() != nullptr)
   {
     Node<ItemType>* temp = m_top->getNext();
     delete m_top;
     m_top = temp;

   }

}//end of destructor

template <typename ItemType>
bool Stack<ItemType>::isEmpty() const
{
 //check if stack is empty
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
void Stack<ItemType>::push(const ItemType& newEntry) throw (PrecondViolatedExcep)
{
 //entry added to top of stack
 Node<ItemType>* newNode = new Node<ItemType>();
 newNode->setValue(newEntry);
 if(m_top == nullptr)
   {
     m_top = newNode;
     m_size++;
   }
 else
   {
     newNode->setNext(m_top);
     m_top = newNode;
     m_size++;
   }

}//end of push method

template <typename ItemType>
void Stack<ItemType>::pop() throw(PrecondViolatedExcep)
{
 //pop and delete top of stack
 if(m_size == 0)
   {
     //throw std::runtime_error("");
     throw PrecondViolatedExcep("Pop attempted on empty stack!");
   }
 else
   {
     //stack is not empty, delete top
     Node<ItemType>* temp = m_top->getNext();
     delete m_top;
     m_top = temp;
     m_size--;
   }


}//end of pop method

template <typename ItemType>
ItemType Stack<ItemType>::peek() const throw(PrecondViolatedExcep)
{

 if(m_size == 0)
   {
     throw PrecondViolatedExcep("Peek attempted on empty stack!");
   }
 else
   {
     return(m_top->getValue());
   }


}//end of peek method

template <typename ItemType>
int Stack<ItemType>::size() const
{
 return m_size;
}//end of size method
