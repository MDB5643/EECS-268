/**
* @author Matt Bailey
* @filename VoterRegistration.h
* @since 9/4/2016
*/

#ifndef VOTERREGISTRATION_H
#define VOTERREGISTRATION_H
#include <string>

class VoterRegistration
{
public:
  VoterRegistration(); // constructor
  std::string getFirstName() const; // method to return voter's first name
  void setFirstName(const std::string& firstname); // method to set voter's first name

  std::string getLastName() const; // method to return voter's last name
  void setLastName(const std::string& lastname); // method to set voter's last name

  int getAge() const; // method for returning voter's age
  void setAge(const int& age); // method for setting voter's age

  std::string getAff() const; // method for returing voter's affiliation
  void setAff(const std::string& affiliation); // method for setting voter's affiliation

  int getNumAff() const; // method for returning number of voters in affiliation
  //void setNumAff(const int&); unused method



private:

  //variables to be initialized in constructor

  std::string m_firstname;
  std::string m_lastname;
  int m_age;
  std::string m_affiliation;
  int m_numaff;

};

#endif
