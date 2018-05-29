/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: MazeWalker.h
/ @since: 10-24-2016
*/


// #####
// #S1X#
// ##X##
// ##E##
#ifndef MAZEWALKER_H
#define MAZEWALKER_H

class MazeWalker
{

private:

	/**
	*	@returns If the current position is the exit, true is returned. False is returned otherwise.
	*/
	bool isGoalReached() const;

	const char* const* m_maze;
	int** m_visited;
	int m_rows, m_cols;
	int m_curRow, m_curCol;
	int m_startRow, m_startCol;

int m_curStep;

// BELOW ARE REQUIRED METHODS FOR MAZEWALER BUT YOU WILL NEED MORE!
// FOR EXAMPLE, YOU'LL NEED METHOD(S) TO RECUSIVELY TRAVERSE THE MAZE!



public:
	/**
	*	@pre The mazePtr pointer is to a valid maze.
	*	@post A maze walker if created ready to traverse the maze from the start position is the specified order.
	*/
	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols);

	/**
	*
	*	@pre The visited array still exists and has the same dimensions (rows X cols)
	*	@post The visited array is deallocated
	*/
	~MazeWalker();

	/**
	*	@pre The maze is a valid maze.
	*	@post The maze is traversed until the end is reached or all moves are exhausted.
	*	@return true if an exit was reached, false otherwise
	*/
	bool walkMaze();


	/**
	*	@return A const pointer to the visited array. (A pointer that cannot change the array)
	*/
	const int* const* getVisited() const;

	/**
	*	@return number of rows in maze
	*/
	int getVisitedRows() const;

	/**
	*	@return number of cols in maze
	*/
	int getVisitedCols() const;

	/**
	*	@return A const pointer to the maze. (A pointer that cannot change the array)
	*/
	const char* const* getMaze() const;


};

#endif
