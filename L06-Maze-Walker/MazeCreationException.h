/*
/ @author: Matt Bailey
/ @project: Recursion maze
/ @file: MazeCreationException.h
/ @since: 10-24-2016
*/


#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class MazeCreationException : public logic_error
{
public:
   MazeCreationException(const string& message = "");
}; // end MazeCreationException#endif
#endif
