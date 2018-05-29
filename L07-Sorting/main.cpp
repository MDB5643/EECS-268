/*
/	@author: Matt Bailey
/	@project: Sorting Algorithm Tests
/	@file: main.cpp
/ @since 8-30-2016
*/

#include <stdlib.h>

#include <iostream>
#include <string>
#include <ctime>
#include <array>

#include "insertionSort.cpp"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "bubbleSort.cpp"
#include "selectionSort.cpp"


int main(int argc, char* argv[])
{

	//commands
  int a_size = std::stoi(argv[1]);
  std::string condition = argv[2];
  std::string Sort = argv[3];

	//initializes array size
  double HeyHeyHeyitstheArray[a_size];

  double netRunTime;
  clock_t mark;
  clock_t start;

  std::cout << endl;

	//output to user
  std::cout << "Array size: " << a_size << std::endl;
  std::cout << "Algorithm: " << Sort << std::endl;
  std::cout << "Order: " << condition << std::endl;

	//condition if statements
  if(condition == "ascending" || condition == "Ascending")
  {

    for(int i; i < a_size; i++)
    {
      HeyHeyHeyitstheArray[i] = 0.001*static_cast<double>(i);
    }

  }

  else if(condition == "descending" || condition == "Descending")
  {

    for(int i; i < a_size; i++)
    {
      HeyHeyHeyitstheArray[i] = 0.001*static_cast<double>(a_size - i - 1);
    }

  }

  else if(condition == "random" || condition == "Random")
  {

    for(int i; i < a_size; i++)
    {
      HeyHeyHeyitstheArray[i] = drand48();
    }

  }

	//sort if statements

  if(Sort == "selection" || Sort == "Selection")
  {
		//timing the sort
      start = clock();
      selectionSort(HeyHeyHeyitstheArray, a_size);
      mark = clock() - start;
  }

  else if(Sort == "quick" || Sort == "Quick")
  {
      start = clock();
      quickSort(HeyHeyHeyitstheArray, 0, a_size-1 );
      mark = clock() - start;
  }

  else if(Sort == "insertion" || Sort == "Insertion")
  {
      start = clock();
      insertionSort(HeyHeyHeyitstheArray, a_size);
      mark = clock() - start;
  }

  else if(Sort == "merge" || Sort == "Merge")
  {
      start = clock();
      mergeSort(HeyHeyHeyitstheArray, a_size);
      mark = clock() - start;
  }

  else if(Sort == "bubble" || Sort == "Bubble")
  {
      start = clock();
      bubbleSort(HeyHeyHeyitstheArray, a_size);
      mark = clock() - start;
  }


  netRunTime = mark/(double)(CLOCKS_PER_SEC);

  std::cout << "Time taken to complete the sort: " << netRunTime << std::endl;

}//end of main
