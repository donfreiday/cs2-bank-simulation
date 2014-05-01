// LinkedList based queue class
// @file Queue.h

#ifndef _QUEUE_H
#define _QUEUE_H

#include "QueueInterface.h"
#include "LinkedList.h"
#include "PrecondViolatedExcep.h"

template<class ItemType>
class Queue : public QueueInterface<ItemType>
{
private:
	LinkedList<ItemType>* listPtr;
public:
	Queue();
	Queue(const Queue& aQueue);
	~Queue();
	bool isEmpty() const;
	bool enqueue(const ItemType& newEntry);
	bool dequeue();
	ItemType peekFront() const throw(PrecondViolatedExcep);
	string toString() const;
};
#include "Queue.cpp"
#endif
