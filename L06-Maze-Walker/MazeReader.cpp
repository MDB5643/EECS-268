/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: MazeReader.cpp
/ @since: 10-24-2016
*/

#include "MazeReader.h"
#include <string>
using namespace std;


MazeReader::MazeReader(std::string file) throw(MazeCreationException)
{
	fstream in(file);
	if (in.is_open())
	{
	}
	else
	{
		throw MazeCreationException("Error loading file!");
	}
	in >> rows;
	in >> cols;
	in.ignore();
	in >> startRow;
	in >> startCol;
	in.ignore();

	if (startRow > rows || startCol > cols || rows < 1 || cols < 1)
	{
		throw MazeCreationException("INVALID START POSITION!");
	}

  rows = rows;
	string line;
	int row = 0;
	cout << "Reading... "  << rows << " " << cols << " " << startRow << " " << startCol << endl;

	maze = new char*[rows];
	while (getline(in, line))
	{
		char *nextLine = new char[cols];
		cout << line << endl;

		for (int i = 0;i < cols;i++)
		{

			nextLine[i] = line.c_str()[i];
			// if (row == startRow && nextLine[startCol - 1] == 'W')
			// {
			// 	throw MazeCreationException("Invalid start position!");
			// }

		}
		maze[row] = nextLine;

		row = row + 1;

	}

}

MazeReader::~MazeReader()
{

}

const char* const* MazeReader::getMaze() const
{
	return maze;
}

int MazeReader::getCols() const
{
	return cols;
}

int MazeReader::getRows() const
{
	return rows;
}

int MazeReader::getStartCol() const
{
	return startCol;
}

int MazeReader::getStartRow() const
{
	return startRow;
}
