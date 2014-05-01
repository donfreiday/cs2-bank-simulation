// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file PrecondViolatedExcep.h

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
	PrecondViolatedExcep(const string& message = "");
};
#endif