/*
/		@project: EECS 268 Lab 09 - Priority Queue with Heap
/		@author: Matt Bailey
/		@since: 12/6/2016
/		@filename: Heap.cpp
*/



#include "Heap.h"

//constructor for the heap
template <typename T>
Heap<T>::Heap(int initialSize)
{
  theCompleteBinaryTree = new T[initialSize];
  numItemsInHeap = 0;
  sizeOfArray = initialSize;
}

template <typename T>
Heap<T>::Heap(const Heap<T>& heap) // The copy constructor
{
  if (theCompleteBinaryTree != nullptr)
  {
    delete[] theCompleteBinaryTree;
    theCompleteBinaryTree = nullptr;
  }
  // if (heap.numItemsInHeap >= heap.sizeOfArray)
  // {
  //   sizeOfArray = heap.sizeOfArray*2;
  // }

  numItemsInHeap = heap.numItemsInHeap;
  theCompleteBinaryTree = new T[heap.sizeOfArray];
  for (int i = 0;i < numItemsInHeap;i++)
  {
    theCompleteBinaryTree[i] = heap.theCompleteBinaryTree[i];
  }
  //  parent   child1 child2    child1-1 child1-2  child2-1 child2-2  child-1-1-1(7)

}

//heap destructor
template <typename T>
Heap<T>::~Heap()
{

  delete[] theCompleteBinaryTree;

}


//adds an item to the heap
//requires heap to be constructed
template <typename T>
void Heap<T>::add(T& newItem)
{
  if (numItemsInHeap >= sizeOfArray)
  {
    std::cout << "The queue has been maxed out. A new, larger queue is being made.\n";
    sizeOfArray = 2*sizeOfArray;
    T* newarr = new T[sizeOfArray];
    for (int i = 0; i < numItemsInHeap; i++)
    {
      newarr[i] = theCompleteBinaryTree[i];
    }
    delete[] theCompleteBinaryTree;
    theCompleteBinaryTree = newarr;
  }
    //cout << "Inserting to index " << numItemsInHeap << endl;
    //Heap<T> theCopyHeap = new Heap<T>(theHeap);
    theCompleteBinaryTree[numItemsInHeap] = newItem;
    numItemsInHeap++;
    // 0 1 2 3 4 5 6 7 8
    int placedIndex = numItemsInHeap - 1;
    if (placedIndex <= 0)
    {
      //cout << "No need to bubble" << endl;
      return;
    }

    while (theCompleteBinaryTree[(placedIndex - 1) / 2] < theCompleteBinaryTree[placedIndex])
    {
      //cout << "Bubbling index " << (placedIndex - 1) / 2 << " against index " << placedIndex << endl;
      T temp = theCompleteBinaryTree[(placedIndex - 1) / 2];
      theCompleteBinaryTree[(placedIndex - 1) / 2] = theCompleteBinaryTree[placedIndex];
      theCompleteBinaryTree[placedIndex] = temp;
      placedIndex = (placedIndex - 1) / 2;
    }

}

//checks heap to determine if it is empty
template <typename T>
bool Heap<T>::isEmpty() const
{
  return (numItemsInHeap == 0);
}

//
template <typename T>
void Heap<T>::remove()
{
  if (isEmpty())
  {
    EmptyHeap broken;
    throw broken;
  }


  numItemsInHeap--;
  theCompleteBinaryTree[0] = theCompleteBinaryTree[numItemsInHeap];
  int bubbleDown = 0;
  int child1Index = 1;
  int child2Index = 2;
  while(child1Index < numItemsInHeap)
  {
    //printTree();

    int biggestIndex = bubbleDown;
    if (theCompleteBinaryTree[biggestIndex] < theCompleteBinaryTree[child1Index])
      biggestIndex = child1Index;

    if (child2Index < numItemsInHeap && theCompleteBinaryTree[biggestIndex] < theCompleteBinaryTree[child2Index])
      biggestIndex = child2Index;

    if (biggestIndex != bubbleDown)
    {
      //cout << "Swapping index " << biggestIndex << "(" << theCompleteBinaryTree[biggestIndex]
      //	 << ") with index " << bubbleDown << "(" << theCompleteBinaryTree[bubbleDown] << ")" << endl;
      T temp = theCompleteBinaryTree[bubbleDown];
      theCompleteBinaryTree[bubbleDown] = theCompleteBinaryTree[biggestIndex];
      theCompleteBinaryTree[biggestIndex] = temp;
      bubbleDown = biggestIndex;
      child1Index = bubbleDown * 2 + 1;
      child2Index = bubbleDown * 2 + 2;
    }
    else
    {
      //cout << "Bigger than both children" << endl;
      break;
    }
  }
  //printTree();

}

//prints tree to the user
template <typename T>
void Heap<T>::printTree()
{
  int pow = 0;
  int step = 0;
  for (int i = 0;i < numItemsInHeap;i++)
  {

    if (pow == step)
    {
      std::cout << endl;
      for (int i = 0;i < numItemsInHeap - pow * 2;i++)
      {
        cout << " ";
      }
      if (pow == 0)
        pow = 1;
      else
        pow = pow * 2;
      step = 0;
    }
    cout << theCompleteBinaryTree[i] << " ";
    step++;

  }
}

//lists heap
template <typename T>
void Heap<T>::printList()
{
  cout << " -- Listing Heap -- " << endl;
  for (int i = 0;i < numItemsInHeap;i++)
  {
    cout << theCompleteBinaryTree[i] << endl;
  }
  cout << " -- End List -- " << endl;
}

//reveals the top item in the heap
template <typename T>
T Heap<T>::peekTop() //const throw()// EmptyHeap
{
  if (isEmpty())
  {
    EmptyHeap broken;
    throw broken;
  }
  return theCompleteBinaryTree[0];
}

//end of file
