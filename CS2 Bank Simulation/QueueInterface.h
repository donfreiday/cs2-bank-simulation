// @file QueueInterface.h

#ifndef _QUEUE_INTERFACE_H
#define _QUEUE_INTERFACE_H

template<class ItemType>
class QueueInterface
{
public:
	virtual bool isEmpty() const = 0;
	virtual bool enqueue(const ItemType& newEntry) = 0;
	virtual bool dequeue() = 0;
	virtual ItemType peekFront() const = 0;
};
#endif