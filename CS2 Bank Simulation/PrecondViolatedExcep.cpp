// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file PrecondViolatedExcep.cpp

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message) :
logic_error("Precondition Violated Exception: " + message)
{

}