/*
/ @author: Matt Bailey
/ @project: interfaces and exceptions
/ @file: Executive.h
/ @since: 9-23-2016
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include "MathTools.h"
#include "NegativeDiscriminant.h"

class Executive
{

public:
  //@pre: called in main to build exec object
  //@post: exec object is built
  Executive();

  //@pre: executive must be built
  //@post: program is running
  void run();

private:


};

#endif
