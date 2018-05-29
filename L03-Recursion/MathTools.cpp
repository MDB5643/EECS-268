/*
/ @author: Matt Bailey
/ @project: interfaces and exceptions
/ @file: MathTools.cpp
/ @since: 9-23-2016
*/

#include "MathTools.h"
#include "NegativeDiscriminant.h"
#include "CannotDetermineRoomDimensions.h"


MathTools::MathTools(double a, double b, double c)
{
  a1 = a;
  b1 = b;
  c1 = c;
}

int MathTools::solveQuadratic(double a, double b, double c, double roots[]) const
{

    double determinant = b*b - 4*a*c;
    double roota = 0;
    double rootb = 0;
    double realPart = 0;
    double imaginaryPart = 0;

        if(determinant > 0)
        {
          roota = (-b + sqrt(determinant))/(2*a);
          rootb = (-b - sqrt(determinant))/(2*a);
          std::cout << "Roots are real and different.\n";
          std::cout << "The roots are " << roota << " and " << rootb << std::endl;
          roots[0] = roota;
          roots[1] = rootb;
          return 2;
        }

        else if(determinant== 0)
        {
            roota = (-b + sqrt(determinant)) / (2*a);
            std::cout << "Roots are real and same." << std::endl;
            roots[0] = roota;
            std::cout << "The roots are both " << roota << std::endl;
            return 1;
         }

         else if (determinant < 0)
         {
           throw(NegativeDiscriminant());
         }

        else
        {
          realPart = -b/(2*a);
          imaginaryPart = sqrt(-determinant)/(2*a);
          roots[0] = roota;
          roots[1] = rootb;
            std::cout << "Roots are complex and different."  << std::endl;
            std::cout << "The roots are " << realPart << "+" << imaginaryPart << "i \n";
            std::cout << "and " << realPart << "-" << imaginaryPart << "i \n";
        }

    return 0;
}

void MathTools::roomDimensions(double Area, double Extra, double minRequiredLength, double width, double length) const
    {
      double roots[]={};
      try
      {
        int n = solveQuadratic(1.0 , Extra , (0.0 - Area), roots);
        if (n==1)
        {
          length = roots[0];
          width = length + Extra;
        }
        else
        {
          if(roots[0] > roots[1])
          {
            length = roots[0];
          }
          else
          {
            length = roots[1];
          }
          width = length + Extra;
        }
      }
      catch(NegativeDiscriminant& e)
      {
        throw(CannotDetermineRoomDimensions());
      }
      if (length < minRequiredLength)
      {
        throw(CannotDetermineRoomDimensions());
      }
      else
      {
      std::cout << "The length is: " << length << std::endl;
      std::cout << "The width is: " << width << std::endl;
      }
    }

int MathTools::intersectLineUnitCircle(double d, double e, double f, double [2][2] )
 {   double d1 = (d*d)*(e*e);
   double d2 = 2*e*f;
   double d3 = (f*f) - (d*d);
   double myArr[2];
   try
   {
     int n = solveQuadratic(d1, d2, d3, myArr);
     if (n == 1)
     {
       xy[0][1] = myArr[0];
       xy[0][0] = (f-(e*myArr[0]))/d;
       return 1;
     }
     else
     {
       for(int i = 0; i < 2; i++)
       {
         xy[i][1] = myArr[i];
         double myNum = 0 - (f + (e*myArr[i]));
         xy[i][0] = myNum/d;
       }
       return 2;
     }
   }
   catch(NoIntersection& e)
   {
    throw(NoIntersection());
   }
 }
