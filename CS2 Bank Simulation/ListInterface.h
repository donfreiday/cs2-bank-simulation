// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file ListInterface.h

#ifndef _LIST_INTERFACE_H
#define _LIST_INTERFACE_H

#include "PrecondViolatedExcep.h"

template<class ItemType>
class ListInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual int getLength() const = 0;
	virtual bool insert(int newPosition, const ItemType& newEntry) = 0;
	virtual bool remove(int position) = 0;
	virtual void clear() = 0;
	virtual ItemType getEntry(int position) const throw(PrecondViolatedExcep) = 0;
	virtual void setEntry(int position, const ItemType& newEntry) = 0;
};
#endif