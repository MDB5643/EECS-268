/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: MazeReader.h
/ @since: 10-24-2016
*/

#include <iostream>
#include <string>
#include <fstream>

#include "MazeCreationException.h"

using namespace std;

#ifndef MAZEREADER_H
#define MAZEREADER_H

class MazeReader
{
private:
	/**
	*	@pre the file is properly formatted
	*	@post the characters representing the maze are stores
	*/
	void readMaze();
	int rows;
	int cols;
	int startRow;
	int startCol;
	char **maze;

public:
	/**
	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
	*	@throws MazeCreationExecption
	*
	*/


	MazeReader(std::string file) throw(MazeCreationException);

	/**
	*	@post The maze is deallocated.
	*/
	~MazeReader();

	/**
	*	@pre the file was formatting and read in correctly
	*	@return Returns pointer to the maze
	*/
	const char* const* getMaze() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of columns listed in the file
	*/
	int getCols() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of rows listed in the file
	*/
	int getRows() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting column
	*/
	int getStartCol() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting row
	*/
	int getStartRow() const;



};

#endif
