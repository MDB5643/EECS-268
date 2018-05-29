/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: City.h
/ @since: 9-17-2016
*/

#ifndef CITY_H
#define CITY_H

#include <string>

class City
{

public:
  
  City();

  City(std::string name, int pop, int infection);

  void setName( const std::string& name);

  std::string getName() const;

  void setPop(const int& pop);

  int getPop() const;

  void setInfect(const int& infection);

  int getInfect() const;



private:

  std::string name;
  int pop;
  int infection;

};

#endif
