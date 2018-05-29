//  Subsetted from:
//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/*
/ @author: Matt Bailey
/	@project: Binary Search Tree Lab
/	@file: BinarySearchTree.cpp
/	@since: 11-12-2016
*/

/* @file BinarySearchTree.cpp */

#ifndef _BINARY_SEARCH_TREE_CPP
#define _BINARY_SEARCH_TREE_CPP


#include <iostream>
#include <fstream>

#include "BinarySearchTree.h"


// PRIVATE HELPER METHODS - IMPLEMENT THESE

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::destroyTree(BinaryNode<ItemType>* subTreePtr)
{
}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType,KeyType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr)
{
	if (newNodePtr->getItem() < subTreePtr->getItem())  //going left
	{
		if (subTreePtr->getLeftChildPtr() == nullptr)
		{
			subTreePtr->setLeftChildPtr(newNodePtr);
			return nullptr;
		}
		else
		{
			insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
		}
	}
	else //going right
	{
		if (subTreePtr->getRightChildPtr() == nullptr)
		{
			subTreePtr->setRightChildPtr(newNodePtr);
			return nullptr;
		}
		else
		{
			insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
		}
	}

}

template<typename ItemType, typename KeyType>
BinaryNode<ItemType>* BinarySearchTree<ItemType, KeyType>::findNode(BinaryNode<ItemType>* subTreePtr, const KeyType& target) const
{
	if (subTreePtr == nullptr)
	{
		cout << "NULL POINTER FOUND " << endl;
		return nullptr;
	}
	//cout << " - Comparing " << subTreePtr->getItem() << endl;

	if (subTreePtr->getItem() == target) //item matches the target (pokemon == string)
	{
		cout << "I found the pokemon you were looking for!" << endl;
		return subTreePtr; //return the node
	}

	if (subTreePtr->getItem() < target) //item less than target (pokemon < string, searching as it was sorted with pokemon < pokemon)
	{
		//cout << "Going right from " << subTreePtr->getItem() << endl;
		if (subTreePtr->getRightChildPtr() == nullptr) //if the left child is null, we didnt find it.
		{
			return nullptr; //return nullptr
		}
		return findNode(subTreePtr->getRightChildPtr(), target); //recurse onto the left child (returning whatever the recurse finds, on up the chain)
	}

	//cout << "Going left from " << subTreePtr->getItem() << endl;

	if (subTreePtr->getLeftChildPtr() == nullptr) //nothing right
	{
		return nullptr;
	}

	return findNode(subTreePtr->getLeftChildPtr(), target); //recurse right

}


//////////////////////////////////////////////////////////////
//      PUBLIC METHODS BEGIN HERE
//////////////////////////////////////////////////////////////
template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::BinarySearchTree() : rootPtr(nullptr)
{
}

template<typename ItemType, typename KeyType>
BinarySearchTree<ItemType, KeyType>::~BinarySearchTree()
{
   this->destroyTree(rootPtr); // Call inherited method
}  // end destructor


//////////////////////////////////////////////////////////////
//      Public BinaryTreeInterface Methods Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::add(const ItemType& newData)
{
	if (rootPtr == nullptr)
	{
		rootPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
	}
	else
	{
		BinaryNode<ItemType>* newItem = new BinaryNode<ItemType>(newData, nullptr, nullptr);
		insertInorder(rootPtr, newItem);
	}


	return false;
}

template<typename ItemType, typename KeyType>
ItemType BinarySearchTree<ItemType, KeyType>::getEntry(const KeyType& aKey) const throw(NotFoundException)
{
	BinaryNode<ItemType>* found = findNode(rootPtr, aKey);
	//if (found == nullptr)
	//	throw NotFoundException;
	if (found == nullptr)
	{
		throw NotFoundException();
	}
	else
		//cout << "I found the pokemon you were looking for!" << endl;
		return found->getItem();
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::deleteAndReorder(const KeyType& aKey) throw(NotFoundException)
{
	cout << "Trying to delete " << aKey << endl;
	deleteAndReorderRecursive(rootPtr, aKey);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::deleteAndReorderRecursive(BinaryNode<ItemType>* subTreePtr, const KeyType& target)
{
	cout << "Examining " << subTreePtr->getItem() << endl;
	if (subTreePtr == nullptr)
	{
		cout << "NULL POINTER FOUND " << endl;
		return;
	}
	//cout << " - Comparing " << subTreePtr->getItem() << endl;

	if (subTreePtr->getItem() == target)
	{
		cout << "I think we're deleting the head...";
		if (rootPtr->getLeftChildPtr() != nullptr)
		{
			cout << "Root has a left child, that will be the new root" << endl;
			BinaryNode<ItemType> *holder = rootPtr->getLeftChildPtr(); //get the child that will beocme the new root
			BinaryNode<ItemType> *holderRight = holder->getRightChildPtr(); //hold onto the left childs right children (holder takes roots right children)
			holder->setRightChildPtr(rootPtr->getRightChildPtr()); //holder takes responsibility for root's right children (but keeps its left children)
			rootPtr = holder;
			cout << "Checking to re-add recursively" << endl; //do a recursive add for the holderRight, and all its children
			if (holderRight != nullptr)
			{
				add(holderRight->getItem());
				addToRootRecursive(holderRight);
			}

			return;
		}
		else if (rootPtr->getRightChildPtr() != nullptr)
		{
			cout << "Root has a Right child, that will be the new root" << endl;
			BinaryNode<ItemType> *holder = rootPtr->getRightChildPtr(); //get the child that will beocme the new root
			BinaryNode<ItemType> *holderLeft = holder->getLeftChildPtr(); //hold onto the left childs right children (holder takes roots right children)
			holder->setLeftChildPtr(rootPtr->getLeftChildPtr()); //holder takes responsibility for root's right children (but keeps its left children)
			rootPtr = holder;
			cout << "Checking to re-add recursively" << endl; //do a recursive add for the holderRight, and all its children
			if (holderLeft != nullptr)
			{
				add(holderLeft->getItem());
				addToRootRecursive(holderLeft);
			}


			return;
		}


		return;
	}

	if (subTreePtr->getLeftChildPtr() != nullptr)
	{
		if (subTreePtr->getLeftChildPtr()->getItem() == target)
		{
			cout << "Found as the left child of " << subTreePtr->getItem() << " is " << subTreePtr->getLeftChildPtr()->getItem() << endl;
			BinaryNode<ItemType> *holder = subTreePtr->getLeftChildPtr();
			subTreePtr->setLeftChildPtr(nullptr);

			cout << "Checking to re-add recursively" << endl;
			addToRootRecursive(holder->getLeftChildPtr());

			return;
		}
	}


	if (subTreePtr->getRightChildPtr() != nullptr)
	{
		if (subTreePtr->getRightChildPtr()->getItem() == target)
		{
			cout << "Found as the right child of " << subTreePtr->getItem() << " is " << subTreePtr->getRightChildPtr()->getItem() << endl;
			BinaryNode<ItemType> *holder = subTreePtr->getRightChildPtr();
			subTreePtr->setRightChildPtr(nullptr);

			cout << "Checking to re-add recursively" << endl;
			addToRootRecursive(holder->getRightChildPtr());

			return;
		}
	}

	if (subTreePtr->getItem() < target) //item less than target (pokemon < string, searching as it was sorted with pokemon < pokemon)
	{
		cout << "Going right from " << subTreePtr->getItem() << endl;
		if (subTreePtr->getRightChildPtr() == nullptr) //if the left child is null, we didnt find it.
		{
			return; //return nullptr
		}
		deleteAndReorderRecursive(subTreePtr->getRightChildPtr(), target); //recurse onto the left child (returning whatever the recurse finds, on up the chain)
		return;
	}

	cout << "Going left from " << subTreePtr->getItem() << endl;

	if (subTreePtr->getLeftChildPtr() == nullptr) //nothing right
	{
		return;
	}

	deleteAndReorderRecursive(subTreePtr->getLeftChildPtr(), target); //recurse right
	return;
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::testAdds(BinarySearchTree<ItemType, KeyType> binsearcher)
{
	std::string newmon;
	std::string newind;
	std::string newjapan;
	BinarySearchTree<Pokemon, string> bstCopy;
	bstCopy.addAllFrom(binsearcher);
	cout << "What is the english name of the pokemon you would like to add to the pokedex?" << endl;
	cin >> newmon;
	cout << "What is the pokedex number for this pokemon?" << endl;
	cin >> newind;
	cout << "What is the japanese name of this pokemon?" << endl;
	cin >> newjapan;
	Pokemon *nextPokemon = new Pokemon(newmon, stoi(newind), newjapan);
	binsearcher.add(*nextPokemon);
	// binsearcher.inorderTraverseLazy();
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::testRemoves(BinarySearchTree<ItemType, KeyType> binsearcher)
{
	BinarySearchTree<Pokemon, string> bstCopy;
	bstCopy.addAllFrom(binsearcher);
	cout << "Please type the pokemon english name and I'll try to delete it" << endl;
	string monsaybye;
	cin >> monsaybye;
	binsearcher.deleteAndReorder(monsaybye);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::testWriteToFile(BinarySearchTree<ItemType, KeyType> binsearcher)
{
	cout << "Which method?" << endl;
	cout << "1. Preorder" << endl;
	cout << "2. Inorder" << endl;
	cout << "3. Postorder" << endl;
	int method;
	cin >> method;
	cout << "What file name?" << endl;
	string filename;
	cin >> filename;
	ofstream *outfile = new ofstream(filename);
	binsearcher.writeToFile(outfile, method);
}




template<typename ItemType, typename KeyType>
bool BinarySearchTree<ItemType, KeyType>::contains(const KeyType& aKey) const
{
	return (findNode(rootPtr, aKey) != nullptr);
}

//////////////////////////////////////////////////////////////
//      Public Traversals Section - IMPLEMENT THESE
//////////////////////////////////////////////////////////////

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderTraverse(void visit(ItemType&)) const
{

}


template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderTraverseLazy()
{
	inorderTraverseLazyRecurse(rootPtr);

}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::inorderTraverseLazyRecurse(BinaryNode<ItemType>* subTreePtr)
{
	if (subTreePtr->getLeftChildPtr() != nullptr)
		inorderTraverseLazyRecurse(subTreePtr->getLeftChildPtr());
	cout << subTreePtr->getItem() << endl;
	if (subTreePtr->getRightChildPtr() != nullptr)
		inorderTraverseLazyRecurse(subTreePtr->getRightChildPtr());

}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::writeToFile(ofstream *output, int method)
{
	writeToFileRecursive(output, method, rootPtr);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::writeToFileRecursive(ofstream *output, int method, BinaryNode<ItemType>* subTreePtr)
{
	if (method == 1)
		*output << subTreePtr->getItem() << endl;

	if (subTreePtr->getLeftChildPtr() != nullptr)
		writeToFileRecursive(output, method, subTreePtr->getLeftChildPtr());

	if (method == 2)
		*output << subTreePtr->getItem() << endl;

	if (subTreePtr->getRightChildPtr() != nullptr)
		writeToFileRecursive(output, method, subTreePtr->getRightChildPtr());

	if (method == 3)
		*output << subTreePtr->getItem() << endl;


	{

	}

}



template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::addAllFrom( BinarySearchTree< ItemType, KeyType>otherTree)
{
	rootPtr = new BinaryNode<ItemType>(otherTree.rootPtr->getItem());
	addRecursive(rootPtr, otherTree.rootPtr);
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::addRecursive(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* otherSubTreePtr)
{
	if (otherSubTreePtr->getLeftChildPtr() != nullptr)
	{
		subTreePtr->setLeftChildPtr(new BinaryNode<ItemType>(otherSubTreePtr->getLeftChildPtr()->getItem()));
		addRecursive(subTreePtr->getLeftChildPtr(), otherSubTreePtr->getLeftChildPtr());
	}

	if (otherSubTreePtr->getRightChildPtr() != nullptr)
	{
		subTreePtr->setRightChildPtr(new BinaryNode<ItemType>(otherSubTreePtr->getRightChildPtr()->getItem()));
		addRecursive(subTreePtr->getRightChildPtr(), otherSubTreePtr->getRightChildPtr());
	}
}

template<typename ItemType, typename KeyType>
void BinarySearchTree<ItemType, KeyType>::addToRootRecursive(BinaryNode<ItemType>* otherSubTreePtr)
{
	if (otherSubTreePtr->getLeftChildPtr() != nullptr)
	{
		add(otherSubTreePtr->getLeftChildPtr()->getItem());
		addToRootRecursive(otherSubTreePtr->getLeftChildPtr());
	}

	if (otherSubTreePtr->getRightChildPtr() != nullptr)
	{
		add(otherSubTreePtr->getRightChildPtr()->getItem());
		addToRootRecursive(otherSubTreePtr->getRightChildPtr());
	}
}

#endif
