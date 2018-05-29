/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: medicalexecutive.h
/ @since: 9-17-2016
*/

#ifndef MEDICALEXECUTIVE_H
#define MEDICALEXECUTIVE_H
#include <iostream>
#include "City.h"
#include "LinkedList.h"
#include "Node.h"

class MedicalExecutive
{
public:
  MedicalExecutive(std::string fileName);

  void run();

private:
  int position;
  int m_length;
  LinkedList<City>* CDClist;
  LinkedList<City>* m_quarantinelist;
  std::string fileName;
  std::string line;
  void addToCityList(City);
};

#endif
