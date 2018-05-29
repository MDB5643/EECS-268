/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: City.cpp
/ @since: 9-17-2016
*/

#include "City.h"

City::City()
{
  name = "";
  pop = 0;
  infection = 0;
}

City::City(std::string newname, int newpop, int newinfection)
{

  name = newname;
  pop = newpop;
  infection = newinfection;
  setName(newname);
  setPop(newpop);
  setInfect(newinfection);

}

void City::setName(const std::string& newname)
{
  name = newname;
}

std::string City::getName() const
{
  return name;
}

void City::setPop(const int& newpop)
{
  pop = newpop;
}

int City::getPop() const
{
  return pop;
}

void City::setInfect(const int& newinfection)
{
  infection = newinfection;
}

int City::getInfect() const
{
  return infection;
}
