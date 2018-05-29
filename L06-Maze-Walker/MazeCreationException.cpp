/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: MazeCreationException.cpp
/ @since: 10-24-2016
*/


#include "MazeCreationException.h"


MazeCreationException::MazeCreationException(const string& message): logic_error("Maze creation exception: " + message)
{
}  // end constructor

// End of implementation file.
