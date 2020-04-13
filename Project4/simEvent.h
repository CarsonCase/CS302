/*
Event Class
The simEvent is a way to keep track of what happens when. I would rather implement something as simple as this with
a struct. But the assignment called for a class so I am implementing proper get/set functions and constructors

04/01/2020
*/

#pragma once
#include <iostream>
class simEvent
{
private:
	size_t timestamp;
	std::string event_name;

public:
	simEvent();
	simEvent(size_t time, std::string name);
	size_t get_time();
	std::string get_event_name();
	void set_time(size_t time);
	void set_event_name(std::string name);

	//Overloads
	bool operator<=(const simEvent& e);
	bool operator>(const simEvent& e);
	bool operator>=(const simEvent& e);

	//Serialize
	void serialize(std::ostream& os);
};

