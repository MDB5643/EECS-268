/*
/ @author: Matt Bailey
/ @project: interfaces and exceptions
/ @file: MathTools.h
/ @since: 9-23-2016
*/

#ifndef MATHTOOLS_H
#define MATHTOOLS_H

#include <exception>
#include <cmath>
#include <iostream>
#include "CannotDetermineRoomDimensions.h"
#include "NoIntersection.h"

class MathTools
{
public:
  //@pre: nothing
  //@post: MathTools object created
  MathTools(double, double, double);

  //@pre: a, b, c and roots[] are declared, program is running through Executive.run
  //@post: returns number of roots and what those roots are or throws exception
  int solveQuadratic(double a, double b, double c, double roots[]) const;

  //@pre: d, e, f, roots[][] are declared, user has input option 2
  //@post: returns number of roots found or throws exception
  int intersectLineUnitCircle(double d, double e, double f, double roots[2][2]);

  //@pre: Area, Extra, minRequiredLength, width, length as parameters
  //@post: returns roots and length/width or throws exception
  void roomDimensions(double Area, double Extra, double minRequiredLength, double width, double length) const;

private:

  double a, b, c, a1, b1, c1, x1, x2, determinant, realPart, imaginaryPart;
  double roots[2];
  double xy[2][2];
  double Area;
  double Extra;
  double minRequiredLength;
  double width;
  double length;

};

#endif
