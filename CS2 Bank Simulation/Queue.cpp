// LinkedList based queue class
// @file Queue.cpp
#include "Queue.h"

template<class ItemType>Queue<ItemType>::Queue()
{ 
	listPtr = new LinkedList<ItemType>(); 
}

template<class ItemType>
Queue<ItemType>::Queue(const Queue& aQueue) : listPtr(new LinkedList<ItemType>(*aQueue.listPtr))
{
}

template<class ItemType>
Queue<ItemType>::~Queue()
{
	delete listPtr;
	listPtr = nullptr;
}

template<class ItemType>
bool Queue<ItemType>::isEmpty() const
{
	return listPtr->isEmpty();
}

template<class ItemType>
bool Queue<ItemType>::enqueue(const ItemType& newEntry)
{
	return listPtr->insert(listPtr->getLength() + 1, newEntry);
}

template<class ItemType>
bool Queue<ItemType>::dequeue()
{
	return listPtr->remove(1);
}

template<class ItemType>
ItemType Queue<ItemType>::peekFront() const throw(PrecondViolatedExcep)
{
	if (isEmpty())
		throw(PrecondViolatedExcep("peekFront() called with an empty Queue."));
	return listPtr->getEntry(1);
}

template<class ItemType>
string Queue<ItemType>::toString() const
{
	string s = "";
	for (int i = 1; i <= listPtr->getLength(); i++)
		s += listPtr->getEntry(i) + "\n";
	return s;
}