// Donald J Freiday
// CISC 125 : Computer Science 2
// LinkedList
// @file Node.h : Node class specification

#ifndef _NODE_H
#define _NODE_H

template<class ItemType>
class Node
{
private:
	ItemType item;
	Node<ItemType>* next;
public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& anItem);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;
}; // end Node

#include "Node.cpp"
#endif