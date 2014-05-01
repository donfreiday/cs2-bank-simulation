// @file SortedList.cpp

#include <cassert>
#include "SortedList.h"

// private //////////////////////////////////////////////////

template<class ItemType>
Node<ItemType>* SortedList<ItemType>::copyChain(const Node<ItemType>* origChainPtr)
{
	Node<ItemType>* copiedChainPtr;
	if (origChainPtr == nullptr)
	{
		copiedChainPtr = nullptr;
		itemCount = 0;
	}
	else
	{
		Node<ItemType>* copiedChainPtr = new Node<ItemType>(origChainPtr->getItem());
		copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
		itemCount++;
	}
	return copiedChainPtr;
}

template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeBefore(const ItemType& anEntry) const
{
	Node<ItemType>* curPtr = headPtr;
	Node<ItemType>* prevPtr = nullptr;
	while (curPtr != nullptr && anEntry > curPtr->getItem())
	{
		prevPtr = curPtr;
		curPtr = curPtr->getNext();
	}
	return prevPtr;
}

template<class ItemType>
Node<ItemType>* SortedList<ItemType>::getNodeAt(int position) const
{
	assert(position >= 1 && position <= itemCount);
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();
	return curPtr;
}

// public ////////////////////////////////////////////////

template<class ItemType>
SortedList<ItemType>::SortedList() : headPtr(nullptr), itemCount(0)
{

}

template<class ItemType>
SortedList<ItemType>::SortedList(const SortedList<ItemType>& aList)
{
	headPtr = copyChain(aList.headPtr);
}

template<class ItemType>
SortedList<ItemType>::~SortedList()
{
	clear();
}

template<class ItemType>
void SortedList<ItemType>::insertSorted(const ItemType& newEntry)
{
	Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
	Node<ItemType>* prevPtr = getNodeBefore(newEntry);
	if (isEmpty() || prevPtr == nullptr) // add at beginning
	{
		newNodePtr->setNext(headPtr);
		headPtr = newNodePtr;
	}
	else
	{
		Node<ItemType>* aftPtr = prevPtr->getNext();
		newNodePtr->setNext(aftPtr);
		prevPtr->setNext(newNodePtr);
	}
	itemCount++;
}

template<class ItemType>
bool SortedList<ItemType>::removeSorted(const ItemType& anEntry)
{
	if (itemCount == 0)
		return false;
	else if (itemCount == 1)
	{
		return remove(1);
	}
	else
	{
		for (int i = 1; i <= itemCount; i++)
		{
			if (getEntry(i) == anEntry)
				return remove(i);
		}
		return false;
	}
}

//stub
template<class ItemType>
int SortedList<ItemType>::getPosition(const ItemType& anEntry) throw(PrecondViolatedExcep)
{
	if (itemCount == 0)
		throw(PrecondViolatedExcep("getPosition(const ItemType& anEntry) called with empty list or invalid position."));
	else
	{
		for (int i = 1; i <= itemCount; i++)
		{
			if (getEntry(i) == anEntry)
				return i;
		}
	}
	throw(PrecondViolatedExcep("getPosition(const ItemType& anEntry): anEntry not in list. "));
}


template<class ItemType>
bool SortedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int SortedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool SortedList<ItemType>::remove(int position)
{
	bool ableToRemove = position >= 1 && position <= itemCount;
	if (ableToRemove)
	{
		Node<ItemType>* curPtr = nullptr;
		if (position == 1)
		{
			curPtr = headPtr;
			headPtr = headPtr->getNext();
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			curPtr = prevPtr->getNext();
			prevPtr->setNext(curPtr->getNext());
		}
		curPtr->setNext(nullptr);
		delete curPtr;
		curPtr = nullptr;
		itemCount--;
	}
	return ableToRemove;
}

template<class ItemType>
void SortedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

template<class ItemType>
ItemType SortedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	if (position >= 1 && position <= itemCount)
		return getNodeAt(position)->getItem();
	else
		throw(PrecondViolatedExcep("getEntry() called with empty list or invalid position."));
}

template<class ItemType>
string SortedList<ItemType>::toString() const
{
	string s = "";
	for (int i = 1; i <= itemCount; i++)
		s += getEntry(i) + "\n";
	return s;
}
