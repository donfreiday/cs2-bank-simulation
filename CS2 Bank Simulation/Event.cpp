// @file Event.cpp

#include <iostream>
#include <sstream>
#include "Event.h"

Event::Event(char type, int time, int length, std::string name)
{
	eventType = type;
	eventTime = time;
	eventLength = length;
	eventName = name;
}

Event::Event(const Event& anEvent)
{
	eventType = anEvent.type();
	eventTime = anEvent.time();
	eventLength = anEvent.length();
	eventName = anEvent.name();
}

char Event::type() const
{
	return eventType;
}

int Event::time() const
{
	return eventTime;
}

int Event::length() const
{
	return eventLength;
}

std::string Event::name() const
{
	return eventName;
}

std::string Event::toString() const
{
	std::stringstream ss;
	ss << eventType << " | " << eventTime << " | " << eventLength << " | " << eventName;
	return ss.str();
}

// priority determined by time
bool Event::operator > (const Event& rhs) const
{
	return eventTime > rhs.time();
}
bool Event::operator < (const Event& rhs) const
{
	return eventTime < rhs.time();
}
bool Event::operator==(const Event& rhs) const
{
	return eventTime == rhs.time() && eventType == rhs.type() && eventLength == rhs.length() && eventName==rhs.name();
}