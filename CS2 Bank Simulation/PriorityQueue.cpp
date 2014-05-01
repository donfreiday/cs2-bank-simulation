// @file PriorityQueue.cpp

#include "PriorityQueue.h"

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue()
{
	slistPtr = new SortedList<ItemType>();
}

template<class ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue& pq)
{
	slistPtr = new SortedList<ItemType>(*pq.slistPtr);
}

template<class ItemType>
PriorityQueue<ItemType>::~PriorityQueue()
{
	delete slistPtr;
	slistPtr = nullptr;
}

template<class ItemType>
bool PriorityQueue<ItemType>::isEmpty()
{
	return slistPtr->isEmpty();
}

template<class ItemType>
bool PriorityQueue<ItemType>::add(const ItemType& newEntry)
{
	slistPtr->insertSorted(newEntry);
	return true;
}

template<class ItemType>
bool PriorityQueue<ItemType>::remove()
{
	return slistPtr->remove(1);	// highest priority is at beginning of list
}

template<class ItemType>
ItemType PriorityQueue<ItemType>::peek() const throw(PrecondViolatedExcep)
{
	if (slistPtr->isEmpty())
		throw(PrecondViolatedExcep("peek() called with empty list."));
	return slistPtr->getEntry(1); 	// highest priority is at beginning of list
}

template<class ItemType>
std::string PriorityQueue<ItemType>::toString() const
{
	string s = "";
	for (int i = 1; i <= slistPtr->getLength(); i++)
		s += slistPtr->getEntry(i).toString() + "\n";
	return s;
}