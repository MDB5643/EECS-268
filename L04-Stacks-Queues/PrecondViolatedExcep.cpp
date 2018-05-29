/**
* @file PrecondViolatedExcep.cpp
* @author Matt Bailey
* @since 10-2-2016
*/
#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message): logic_error("Precondition Violated Exception: " + message)
{
}  // end constructor

// End of implementation file.
