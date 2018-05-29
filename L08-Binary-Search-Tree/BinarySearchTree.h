//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 16-4.

/** Link-based implementation of the ADT binary search tree.
 @file BinarySearchTree.h */



#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"
#include "NotFoundException.h"

template<typename ItemType, typename KeyType>
class BinarySearchTree
{
private:
   BinaryNode<ItemType>* rootPtr;

   // Recursively deletes all nodes from the tree.
   void destroyTree(BinaryNode<ItemType>* subTreePtr);

   // Recursively finds where the given node should be placed and
   // inserts it in a leaf at that point.
   BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);

   // Returns a pointer to the node containing the given value,
   // or nullptr if not found.
   BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const KeyType& target) const;

   void deleteAndReorderRecursive(BinaryNode<ItemType>* treePtr, const KeyType& target);

public:
   //------------------------------------------------------------
   // Constructor and Destructor Section.
   //------------------------------------------------------------
   BinarySearchTree();
   virtual ~BinarySearchTree();

   //------------------------------------------------------------
   // Public Methods Section.
   //------------------------------------------------------------
   bool add(const ItemType& newEntry);
   ItemType getEntry(const KeyType& aKey) const throw(NotFoundException);
   bool contains(const KeyType& aKey) const;

   void addAllFrom( BinarySearchTree<ItemType, KeyType>otherTree);
   void addRecursive(BinaryNode<ItemType>* , BinaryNode<ItemType>* );
   void addToRootRecursive(BinaryNode<ItemType>*);

   void testAdds(BinarySearchTree<ItemType, KeyType>);
   void testRemoves(BinarySearchTree<ItemType, KeyType>);
   void testWriteToFile(BinarySearchTree<ItemType, KeyType>);

   void deleteAndReorder(const KeyType& aKey) throw(NotFoundException);

   //------------------------------------------------------------
   // Public Traversals Section.
   //------------------------------------------------------------
   void inorderTraverse(void visit(ItemType&)) const;

   void inorderTraverseLazy();
   void inorderTraverseLazyRecurse(BinaryNode<ItemType>* subTreePtr);

   void writeToFile(ofstream *output, int method);
   void writeToFileRecursive(ofstream *output, int method, BinaryNode<ItemType>* subTreePtr);



}; // end BinarySearchTree

#include "BinarySearchTree.cpp"

#endif
