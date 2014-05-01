// @file SortedList.h
// link based implementation of a sorted list

#ifndef _SORTED_LIST_H
#define _SORTED_LIST_H

#include "SortedListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class SortedList : public SortedListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;

	Node<ItemType>* getNodeBefore(const ItemType& anEntry) const;
	Node<ItemType>* getNodeAt(int position) const;
	Node<ItemType>* copyChain(const Node<ItemType>* origChainPtr);
public:
	SortedList();
	SortedList(const SortedList<ItemType>& aList);
	virtual ~SortedList();
	void insertSorted(const ItemType& newEntry);
	bool removeSorted(const ItemType& anEntry);
	int getPosition(const ItemType& anEntry) throw(PrecondViolatedExcep);
	bool isEmpty() const;
	int getLength() const;
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
	string toString() const;
};
#include "SortedList.cpp"
#endif