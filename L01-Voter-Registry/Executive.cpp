/**
* @author Matt Bailey
* @filename Executive.cpp
* @since 9/4/2016
*/

#include "Executive.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <ostream>

//constructor
//requires argv input as parameter

Executive::Executive(char* argv)
{

  //variable initialization

  std::string tempString;
  std::string tempString2;
  int tempNum;

  int count = 0;

  //file and array size input from command line

  std::ifstream inp(argv);

  inp >> size;
  VRR = new VoterRegistration[size];

  //array population

  while (inp >> tempString)
  {

    VRR[count].setFirstName(tempString);

    inp >> tempString;
    VRR[count].setLastName(tempString);

    inp >> tempNum;
    VRR[count].setAge(tempNum);

    inp >> tempString;
    VRR[count].setAff(tempString);


    count++;

  }

}

//destructor

Executive::~Executive()
{
  delete[] VRR;
}

// primary method for execution of the program.
// contains a switch case inside a while loop that calls all other methods in Executive.cpp based on user input
// needs input file to function

void Executive::run()
{

  int choice = 0;
  while (choice != 5)
  {

    std::cout << "1: Query last name" <<std::endl;
    std::cout << "2: Query age range" <<std::endl;
    std::cout << "3: Query affiliations" <<std::endl;
    std::cout << "4: Report number of people with affiliation" <<std::endl;
    std::cout << "5: Quit" <<std::endl;
    std::cin >> choice;

    switch(choice)
    {

      case 1:
      {
        std::string name;
        std::cout << "Enter last name: ";
        std::cin >> name;
        queryLastName(name);
      break;
      }

      case 2:
      {
        int ageMin = 0;
        int ageMax = 0;

        std::cout << "Enter minimum age: ";
        std::cin >> ageMin;

        while(std::cin.fail())
        {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Please enter a correct number: ";  //to ingore non-numerical entries
          std::cin >> ageMin;
        }

        std::cout << "Enter maximum age: ";
        std::cin >> ageMax;

        while(std::cin.fail())
        {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Please enter a correct number: "; //to ignore non-numerical entries
          std::cin >> ageMax;
        }

        queryAgeRange(ageMin, ageMax);

      break;

      }

      case 3:
      {
        std::string affInput;
        std::cout << "Enter affiliation: ";
        std::cin >> affInput;
        queryAffiliation(affInput);
      break;
      }

      case 4:
      {
        std::string affInput;
        std::cout << "Enter affiliation: ";
        std::cin >> affInput;
        querynumAff(affInput);
      break;
      }

      case 5:
      {
        std::cout << "Thanks for checking voter registrations! \n";
        std::cout << "Bye! \n";

        return;
      }

      default:
      {

      }

    }

  }

}
// post: interactive menu will display giving five choices:
// 1. name based search
// 2. age based search
// 3. party affiliation based search
// 4. # voters in particular party Query
// 5. ends program



// pre:
// executive must be constructed
// requires user input std::string& name as parameter

void Executive::queryLastName(const std::string& name)
{
  for(int i = 0; i < size; i++)
  {
    if(VRR[i].getLastName() == name)
    {
      std::cout << "Record: " << VRR[i].getFirstName() << " " << VRR[i].getLastName() <<
      "; age " << VRR[i].getAge() << "; registered as " << VRR[i].getAff() << std::endl;
    }


  }
}

// post: voters with specified last name will be presented to user
// along with their information



// pre:
// executive must be constructed
// requires user input int ageMin (minimum age) and int ageMax (maximum age) as parameters

void Executive::queryAgeRange(const int& ageMin, const int& ageMax)
{
  for(int i = 0; i < size; i++)
  {
    if((VRR[i].getAge() >= ageMin) && (VRR[i].getAge() <= ageMax))
    {
      std::cout << "Record: " << VRR[i].getFirstName() << " " << VRR[i].getLastName() <<
      "; age " << VRR[i].getAge() << "; registered as " << VRR[i].getAff() << std::endl;
    }
  }
}

// post: voters within given age range will be displayed to user
// along w/ info



// pre:
// executive must be constructed
// requires user input std::string affiliation as parameter

void Executive::queryAffiliation(const std::string& affiliation)
{
  for(int i = 0; i < size; i++)
  {
    if(VRR[i].getAff() == affiliation)
    {
      std::cout << "Record: " << VRR[i].getFirstName() << " " << VRR[i].getLastName() <<
      "; age " << VRR[i].getAge() << "; registered as " << VRR[i].getAff() << std::endl;
    }


  }
}

// post: voters with given affiliation will be displayed to user
// along with their info, of course




// pre:
// executive must be constructed
// requires user input std::string affiliation

void Executive::querynumAff(const std::string& affiliation)
{
  int affCount = 0;
  for(int i = 0; i < size; i++)
  {
    if(VRR[i].getAff() == affiliation)
    {
      affCount++;
    }
  }
  std::cout << "The number of people with affiliation " << affiliation << ": " << affCount << std::endl;

}

// post: the number of voters with the given affiliation will be displayed to user
