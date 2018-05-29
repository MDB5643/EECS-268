/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: MazeWalker.cpp
/ @since: 10-24-2016
*/

#include "MazeWalker.h"
#include <iostream>
using namespace std;


MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols)
{
	m_maze = mazePtr;
	m_startRow = startRow;
	m_startCol = startCol;
	m_rows = rows;
	m_cols = cols;
	m_visited = new int*[rows];

	//build my mazewalker

	for (int i = 0;i < rows;i++)
	{
		int *nextRow = new int[cols];
		for (int j = 0;j < cols;j++)
		{
			nextRow[j] = 0;
		}
		m_visited[i] = nextRow;
	}
	m_curRow = startRow;
	m_curCol = startCol;
	m_curStep = 1;
	m_visited[startRow][startCol] = 1;

}

//DESTRUCTOOOOOR

MazeWalker::~MazeWalker()
{

}

bool MazeWalker::walkMaze()
{

	//position check
 	std::cout << "Position:  [" << m_curRow << "][" << m_curCol << "]\n";


	//orthogonal movement attempts
	for (int i = 0;i < 4;i++)
	{
		int dx = 0;
		int dy = 0;
		if (i == 0)
		{
			std::cout << "trying to move down" << std::endl;
			dy = 1;
		}
		else if (i == 1)
		{
			std::cout << "trying to move right" << std::endl;
			dx = 1;
		}
		else if (i == 2)
		{
			std::cout << "trying to move up" << std::endl;
			dy = -1;
		}
		else if (i == 3)
		{
			std::cout << "trying to move left" << std::endl;
			dx = -1;
		}

		//row and column tracking
		m_curRow += dy;
		m_curCol += dx;

		//boundary detection
		if ((m_curRow < 0) || (m_curRow >= m_rows) || (m_curCol < 0) || (m_curCol >= m_cols))
		{
			std::cout << "Went out of bounds, backtracking..." << std::endl;
		}
		else if (m_maze[m_curRow][m_curCol] == 'W')
		{
			std::cout << "Hit a wall, backtracking..." << std::endl;
		}

		//exit detection
		else if (m_maze[m_curRow][m_curCol] == 'E')
		{
			std::cout << "I WIN!" << std::endl;
			m_curStep++;
			m_visited[m_curRow][m_curCol] = m_curStep;
			return true;
		}

		//familiar location detection
		else if (m_visited[m_curRow][m_curCol] == 1)
		{
			std::cout << "I think I've been here before... backtracking" << std::endl;
		}

		//unvisited location detection
		else if (m_visited[m_curRow][m_curCol] == 0)
		{
			std::cout << "Found a new place.  Exploring from here..." << std::endl;
			m_curStep++;
			m_visited[m_curRow][m_curCol] = m_curStep;

			//recursion - walkmaze will call itself until E is found
			if (walkMaze() == true)
			{
				std::cout << "This path was part of a solution!  Passing it back" << std::endl;
				return true;
			}
			std::cout << "That path didn't pan out... backtracking" << std::endl;
			m_curStep--;
			m_visited[m_curRow][m_curCol] = 0;
		}

		m_curRow -= dy;
		m_curCol -= dx;

	}

	return false;

}


const int* const* MazeWalker::getVisited() const
{
	return m_visited;
}

/**
*	@return number of rows in maze
*/
int MazeWalker::getVisitedRows() const
{
	return m_rows;
}

/**
*	@return number of cols in maze
*/
int MazeWalker::getVisitedCols() const
{
	return m_cols;
}

/**
*	@return A const pointer to the maze. (A pointer that cannot change the array)
*/
const char* const* MazeWalker::getMaze() const
{
	return m_maze;
}
