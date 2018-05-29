/**
* @file Node.h
* @author Matt Bailey
* @since 10-2-2016
*/
#ifndef NODE_H
#define NODE_H

template <typename ItemType>
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
 void setValue(ItemType value);

 /*
   pre: m_value has valid value
   post: value is returned
 */
 ItemType getValue() const;

 /*
   pre: valid Node* is passed into parameter
   post: m_next is set
 */
 void setNext(Node<ItemType>* prev);

 /*
   pre: m_next has a valid value
   post: value is returned
 */
 Node<ItemType>* getNext() const;


private:
 //the value in the node
 ItemType m_value;

 //the pointer to another node
 Node<ItemType>* m_next;


};

#endif
