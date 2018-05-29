/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: main.cpp
/ @since: 10-24-2016
*/

#include <iostream>
#include "MazeReader.h"
#include "MazeWalker.h"
#include "MazeCreationException.h"


using namespace std;

int main(int argc, char* argv[])
{

	char* filename = new char[32];

	//check for existence of file
	if (argc != 2)
	{
		cout << "Wrong number of arguments; please type a filename" << endl;
		cin >> filename;
	}

	//read in file
	else
	{
		char next = ' ';
		int i = 0;
		while(next != '\0')
		{
			next = argv[1][i];
			filename[i] = next;
			i++;
		}
	}
	cout << "Opening " << filename << endl;

	try
	{

	//begin primary functions of program
	//instantiate mazereader
	MazeReader *mr = new MazeReader(filename);

	//instantiate mazewalker
	MazeWalker *guy = new MazeWalker(mr->getMaze(), mr->getStartRow(), mr->getStartCol(), mr->getRows(), mr->getCols());
	cout << "Here goes nothing!" << endl;

	//walk the maze

	bool foundOpening = guy->walkMaze();
	const int *const* path = guy->getVisited();

	//populate an array based on walkMaze return

	for (int i = 0;i < guy->getVisitedRows();i++)
	{
		for (int j = 0;j < guy->getVisitedCols();j++)
		{
			printf("%2d ", path[i][j]);
		}
		cout << endl;
	}

	//if there's no way out, use this:

	if (foundOpening == false)
	{
		cout << "I quit, there's no way out.\n";
	}
	}

	//catch my exception

	catch(MazeCreationException& e)
	{
		std::cout << "Invalid starting position!\n";
	}

	// char ch;
	// cin >> ch;
	return 0;
}
