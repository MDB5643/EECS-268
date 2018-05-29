/**
/ @author: Matt Bailey
/ @project: infection outbreak
/ @file: medicalexecutive.cpp
/ @since: 9-17-2016
*/

#include "MedicalExecutive.h"
#include "City.h"
#include "LinkedList.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <ostream>
#include <sstream>


MedicalExecutive::MedicalExecutive(std::string fileName)
{
  std::ifstream inputFile("input.txt");
  if (!inputFile.is_open())
  {
    std::cout<<"File could not be opened." << std::endl;
  }

  // LinkedList<City>* CDClist;
  // LinkedList<City>* m_quarantinelist;
  std::string line;

  while(inputFile)
  {
    std::string cityName, line;
    std::string pop;
    std::string infection;
    std::getline(inputFile, line);
    std::istringstream ss(line);
    std::getline(ss , cityName , ',');
    std::getline(ss , pop , ',');
    std::getline(ss , infection , ',');
    std::cout << line << "\n";

    if(cityName != "")
    {
      City myCity(cityName , std::stoi(pop) , std::stoi(infection));
      addToCityList(myCity);
    }
  }
}

void MedicalExecutive::addToCityList(City newCity) //will cause seg fault
{
  int LinkedListSize = CDClist->getLength();
  std::cout << LinkedListSize << std::endl; //prints a HUGE number. Why??
  //
  // CDClist->addFront(newCity);
  //
  // if(LinkedListSize == 0)
  // {
  //   CDClist->addFront(newCity);
  //   LinkedListSize++;
  // }
  //
  // for(int i = 1; 1 < LinkedListSize; i++)
  // {
  //   if(newCity.getPop() >= CDClist->getEntry(i).getPop())
  //   {
  //     CDClist->insert(i, newCity);
  //   }
  // }
 }

void MedicalExecutive::run()
{
  int choice = 0;
  while (choice != 6)
  {

    std::cout << "Make a selection:\n";
    std::cout << "1) Increase infection level of all cities\n";
    std::cout << "2) Increase infection level of specific city\n";
    std::cout << "3) Print status of specific city\n";
    std::cout << "4) Create quarantine log\n";
    std::cout << "5) Print all cities above an infection level\n";
    std::cout << "6) Exit\n";
    std::cin >> choice;


    switch(choice)
    {
      case 1:
      {
        for (int position = 1; position < m_length+1; position++)
        {
          City tempcity = CDClist->getEntry(position);
          tempcity.setInfect(tempcity.getInfect()+1);
          CDClist->getEntry(position) = tempcity;
        }
        std::cout << "You've increased the infection level of all cities by 1.\n";
        break;
      }
      case 2:
      {
        std::string cityinput;
        std::cout << "Which city would you like to infect?\n";
        std::cin >> cityinput;
        for (int position = 1; position < m_length+1; position++)
        {
          if(CDClist->getEntry(position).getName() == cityinput)
          {
            City tempcity = CDClist->getEntry(position);
            tempcity.setInfect(tempcity.getInfect() + 1);
            CDClist->getEntry(position) = tempcity;
          }
          else if (position == m_length+1)
          {
            std::cout << "I'm sorry, " << cityinput << " is not a city in this list. \n";
          }
        }
        break;
      }
      case 3:
      {
        std::string cityinput;
        std::cout << "For which city would you like to check the status?\n";
        std::cin >> cityinput;
        for (int position = 1; position < m_length+1; position++)
        {
          if(CDClist->getEntry(position).getName() == cityinput)
          {
            std::cout << CDClist->getEntry(position).getName() << ":\nPopulation: " << CDClist->getEntry(position).getPop() << "\n Infection level: " << CDClist->getEntry(position).getInfect() << "\n";
          }
          else if (position == m_length)
          {
          std::cout << "I'm sorry, " << cityinput << " is not a city in this list.\n";
          }
      }
        break;
      }
      case 4:
      {
        std::cout << "The following cities are quarantined: \n";
        for (int position = 1; position < m_length+1; position++)
        {
          if(CDClist->getEntry(position).getInfect() == 4)
          {
            std::cout << CDClist->getEntry(position).getName() << "\n";
           }
         }
         break;
       }
       case 5:
       {
         int infinput = 0;
         std::cout << "Print all cities above what infection level?";
         std::cin >> infinput;
         for  (int position = 1; position < m_length+1; position++)
         {
           if(CDClist->getEntry(position).getInfect() > infinput)
           {
             std::cout << CDClist->getEntry(position).getName();
           }
         }
         break;
       }

       default:
       {

       }
     }
}

   std::cout << "Thanks for using our system to monitor the downfall of society. Bye!\n";
   return;
}
