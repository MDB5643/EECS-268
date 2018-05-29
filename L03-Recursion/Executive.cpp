/*
/ @author: Matt Bailey
/ @project: interfaces and exceptions
/ @file: Executive.cpp
/ @since: 9-23-2016
*/

#include "Executive.h"
#include "CannotDetermineRoomDimensions.h"
#include "MathTools.h"

Executive::Executive()
{
  double a = 0;
  double b = 0;
  double c = 0;
  double roots[2];
  double xy[2][2];

  MathTools* MT = new MathTools(a, b, c);
}

void Executive::run()
{
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;
  double roots[2];
  double roots2[2][2];
  double Area;
  double minRequiredLength;
  double Extra;
  double length = 0;
  double width = 0;
  MathTools* MT = new MathTools(a, b, c);

  int choice;




  while (choice != 4)
  {
    try
    {
    std::cout << "Welcome to the mathbot program! Please choose from the following operations:\n";
    std::cout << "1. Enter A, B, and C for a quadratic equation to be solved.\n";
    std::cout << "2. Enter the d, e, and f parameters for a line to be intersected with a unit circle.\n";
    std::cout << "3. Enter area, extra, and minRequiredLength for a ballroom.\n";
    std::cout << "4. Quit.\n";
    std::cin >> choice;

    if (choice == 1)
    {
      std::cout << "Enter coefficients a, b and c: \n";
      std::cin >> a >> b >> c;
      MT->solveQuadratic(a, b, c, roots);
    }

    else if (choice == 3)
    {
      std::cout << "Enter area, extra, and minRequiredLength: \n" ;
      std::cin >> Area >> Extra >> minRequiredLength;
      MT->roomDimensions(Area, Extra, minRequiredLength, length, width);
    }

    else if (choice == 2)
    {
      std::cout << "Enter d, e, and f: \n";
      std::cin >> d >> e >> f;
      MT->intersectLineUnitCircle(d, e, f, roots2);
    }

  }
  catch(NegativeDiscriminant& e)
  {

  }
  catch(CannotDetermineRoomDimensions& e)
  {

  }
  catch(NoIntersection& e)
  {

  }

}
std::cout << "Thank you for using my program! Have a nice day! \n";
}
