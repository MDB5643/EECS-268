/**
* @author Matt Bailey
* @filename main.cpp
* @since 9/4/2016
*/

#include <iostream>
#include <string>
#include "Executive.h"

//pre: nothing but the void
// and header files :)

int main(int argc, char* argv[])
{
  Executive exec(argv[1]); // contruct Executive using input file
  exec.run(); // runs the main program
  return 0;
}

//post: program will run as intended until user-prompted exit.
