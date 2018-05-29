/**
* @author Matt Bailey
* @filename VoterRegistration.cpp
* @since 9/4/2016
*/

#include "VoterRegistration.h"

// constructor
// needs no parameter

VoterRegistration::VoterRegistration()
{
  m_firstname = "";
  m_lastname = "";
  m_age = 0;
  m_affiliation = "";
  m_numaff = 0;
}

//post: variables have been initialized



// pre: VoterRegistration must be constructed

std::string VoterRegistration::getFirstName() const
{
  return m_firstname;
}

// post: voter's first name is returned



// pre: VoterRegistration must be constructed
// requires user input std::string FN (first name) as parameter

void VoterRegistration::setFirstName(const std::string& FN)
{
  m_firstname = FN;
}

// post: voter's firstname is set to parameter


// pre: VoterRegistration must be constructed

std::string  VoterRegistration::getLastName() const
{
  return m_lastname;
}

// post: voter's last name is returned


// pre: VoterRegistration must be constructed
// requires user input std::string LN (last name) as parameter

void VoterRegistration::setLastName(const std::string& LN)
{
  m_lastname = LN;
}

//post: voter's last name is set to parameter


// pre: VoterRegistration must be constructed

std::string VoterRegistration::getAff() const
{
  return m_affiliation;
}

// post: voter's affiliation is returned


// pre: VoterRegistration must be constructed
// requires user input std::string aff as parameter

void VoterRegistration::setAff(const std::string& aff)
{
  m_affiliation = aff;
}

// post: voter's affiliation is set to parameter



// pre: VoterRegistration must be constructed

int VoterRegistration::getAge() const
{
  return m_age;
}

// post: voter's age is returned


// pre: VoterRegistration must be constructed
// requires user input int Age as parameter

void VoterRegistration::setAge(const int& Age)
{
  m_age = Age;
}

// post: voter's age is set to parameter


// pre: VoterRegistration must be constructed

int VoterRegistration::getNumAff() const
{
  return m_numaff;
}

// post: number of voters in given affiliation is returned
