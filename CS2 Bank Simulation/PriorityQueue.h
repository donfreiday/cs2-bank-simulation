// a priority queue implementation using the SortedList
// @file PriorityQueue.h

#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <string>
#include "SortedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class PriorityQueue
{
private:
	SortedList<ItemType>* slistPtr;
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue& pq);
	~PriorityQueue();

	bool isEmpty();
	bool add(const ItemType& newEntry);
	bool remove();
	ItemType peek() const throw(PrecondViolatedExcep);
	std::string toString() const;
};
#include "PriorityQueue.cpp"
#endif