// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file LinkedList.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const;
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& aList);
	virtual ~LinkedList();
	bool isEmpty() const;
	int getLength() const;
	bool insert(int position, const ItemType& newEntry);
	bool remove(int position);
	void clear();
	ItemType getEntry(int position) const throw(PrecondViolatedExcep);
	void setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep);
};
#include "LinkedList.cpp"
#endif