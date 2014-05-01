// Donald J Freiday
// page 383-388 - Bank queue simulation
// @file main.cpp

#include <iostream>
#include <fstream>
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"

// Globals, ugh
int g_tellersAvailable;
int g_currentTime = 0;
int g_numCustomers = 0;
float g_totalWaitTime = 0;

void simulate(string dataFile);
void processArrival(Event& arrivalEvent, PriorityQueue<Event>& eventListPQueue, Queue<Event>& bankQueue);
void processDeparture(Event& departureEvent, PriorityQueue<Event>& eventListPQueue, Queue<Event>& bankQueue);

int main()
{
	std::cout << "\n                            Bank Simulator 2015 \n\n";
	string filename = "";
	while (true)
	{
		g_currentTime = 0;
		g_numCustomers = 0;
		g_totalWaitTime = 0;

		std::cout << "--------------------------------------------------------------------------------\n"
			<< "Filename (q to quit): ";
		std::cin >> filename;
		
		if (filename == "Q" || filename == "q")
			return 0;

		std::cout << "Number of tellers: ";
		std::cin >> g_tellersAvailable;

		simulate(filename);
	}
	return 0;
}

void simulate(string dataFile)
{
	PriorityQueue<Event> eventListPQueue;
	Queue<Event> bankQueue;

	// Read data file
	ifstream file;
	file.open(dataFile);
	if (!file.is_open())
	{
		std::cout << "Failed to open file " << dataFile << ", aborting simulation. \n";
		return;
	}
	while (!file.eof())
	{
		int arrivalTime, transactionLength;
		string name;
		file >> arrivalTime;
		file >> transactionLength;
		file >> name;
		Event newArrivalEvent('a', arrivalTime, transactionLength, name);
		eventListPQueue.add(newArrivalEvent);
		g_numCustomers++;
	}
	file.close();

	std::cout << std::endl << g_currentTime << " : The bank opens.\n";

	// Event loop
	while (!eventListPQueue.isEmpty())
	{
		Event newEvent(eventListPQueue.peek());
		g_currentTime = newEvent.time();

		if (newEvent.type() == 'a') // arrival
		{
			processArrival(newEvent, eventListPQueue, bankQueue);
		}
		else // departure
			processDeparture(newEvent, eventListPQueue, bankQueue);
	}

	std::cout << "\n  Average wait time: " << g_totalWaitTime / g_numCustomers << " minutes. \n\n";
}

void processArrival(Event& arrivalEvent, PriorityQueue<Event>& eventListPQueue, Queue<Event>& bankQueue)
{
	eventListPQueue.remove();
	if (bankQueue.isEmpty() && g_tellersAvailable > 0)
	{
		int departureTime = g_currentTime + arrivalEvent.length();
		std::cout << g_currentTime << " : " << arrivalEvent.name() << " arrives and is served immediately. \n";
		Event newDepartureEvent('d', departureTime, 0, arrivalEvent.name()); // departures are of length 0
		eventListPQueue.add(newDepartureEvent);
		g_tellersAvailable--;
	}
	else
	{
		std::cout << g_currentTime << " : " << arrivalEvent.name() << " arrives and gets in line. \n";
		bankQueue.enqueue(arrivalEvent);
	}
}

void processDeparture(Event& departureEvent, PriorityQueue<Event>& eventListPQueue, Queue<Event>& bankQueue)
{
	std::cout << g_currentTime << " : " << eventListPQueue.peek().name() << " leaves." << std::endl;
	eventListPQueue.remove();
	if (!bankQueue.isEmpty())
	{
		Event customer(bankQueue.peekFront());
		int waitTime = g_currentTime - customer.time();
		g_totalWaitTime += waitTime;
		bankQueue.dequeue();
		int departureTime = g_currentTime + customer.length();
		std::cout << g_currentTime << " : " << customer.name() << " is served after waiting " << waitTime << " minutes.\n";
		Event newDepartureEvent('d', departureTime, 0, customer.name()); // departures are of length 0
		eventListPQueue.add(newDepartureEvent);
	}
	else
		g_tellersAvailable++;
}