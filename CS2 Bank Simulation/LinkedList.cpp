// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file LinkedList.cpp

#include <cassert>
#include "LinkedList.h"

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
	assert(position >= 1 && position <= itemCount);
	Node<ItemType>* curPtr = headPtr;
	for (int skip = 1; skip < position; skip++)
		curPtr = curPtr->getNext();
	return curPtr;
}

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(nullptr), itemCount(0)
{

}

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
	itemCount = aList.itemCount;
	Node<ItemType>* origChainPtr = aList.headPtr;
	if (origChainPtr == nullptr)
		headPtr = nullptr;
	else
	{
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());
		Node<ItemType>* newChainPtr = headPtr;

		while (origChainPtr->getNext() != nullptr)
		{
			origChainPtr = origChainPtr->getNext();
			ItemType nextItem = origChainPtr->getItem();
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
			newChainPtr->setNext(newNodePtr);
			newChainPtr = newChainPtr->getNext();
		}
		newChainPtr->setNext(nullptr);
	}
}

template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
	clear();
}

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
	return itemCount;
}

template<class ItemType>
bool LinkedList<ItemType>::insert(int position, const ItemType& newEntry)
{
	bool ableToInsert = (position >= 1 && position <= itemCount + 1);

	if (ableToInsert)
	{
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		if (position == 1)
		{
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
		}
		else
		{
			Node<ItemType>* prevPtr = getNodeAt(position - 1);
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
		}
		itemCount++;
	}
	return ableToInsert;
}

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
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
void LinkedList<ItemType>::clear()
{
	while (!isEmpty())
		remove(1);
}

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
	if (position >= 1 && position <= itemCount)
		return getNodeAt(position)->getItem();
	else
		throw(PrecondViolatedExcep("getEntry() called with empty list or invalid position."));
}

template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry) throw(PrecondViolatedExcep)
{
	if (position >= 1 && position <= itemCount)
		getNodeAt(position)->setItem(newEntry);
	else
		throw(PrecondViolatedExcep("setEntry() called with empty list or invalid position."));
}
