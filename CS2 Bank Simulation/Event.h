// @file Event.h

#include <string>

class Event
{
private:
	char eventType;
	int eventTime;
	int eventLength;
	std::string eventName;
public:
	Event(char type, int time, int length, std::string name);
	Event(const Event& anEvent);
	char type() const;
	int time() const;
	int length() const;
	std::string  name() const;
	bool operator > (const Event& rhs) const;
	bool operator < (const Event& rhs) const;
	bool operator == (const Event& rhs) const;
	std::string toString() const;
};