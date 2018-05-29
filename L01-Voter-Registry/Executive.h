/**
* @author Matt Bailey
* @filename Executive.h
* @since 9/4/2016
*/

#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include <iostream>
#include <string>
#include "VoterRegistration.h"

class Executive
{
  public:
    Executive(char* argv); // constructor
    ~Executive(); // destructor
    void run(); // handles interacticity and calls private methods


  private:
    VoterRegistration* VRR; // array populated by input file
    int size; // size of VRR
    void queryLastName(const std::string& name); // name search method
    void queryAgeRange(const int& ageMin, const int& ageMax); // age search method
    void queryAffiliation(const std::string& affInput); // affiliation search method
    void querynumAff(const std::string& affInput); // returns # voters in given affiliation

};

#endif
