//Dependancies
#include "simEvent.h"


//Constructors
simEvent::simEvent() {
	timestamp = 0;
	event_name = "";
}
simEvent::simEvent(size_t time, std::string name) {
	timestamp = time;
	event_name = name;
}

//Get functions
size_t simEvent::get_time() {
	return timestamp;
}
std::string simEvent::get_event_name() {
	return event_name;
}

//Set functions
void simEvent::set_time(size_t time) {
	timestamp = time;
}
void simEvent::set_event_name(std::string name) {
	event_name = name;
}

bool simEvent::operator<=(const simEvent& e) {
	if (timestamp <= e.timestamp) { return true; }
	else { return false; }
}
bool simEvent::operator>(const simEvent& e) {
	if (timestamp > e.timestamp) { return true; }
	else { return false; }
}
bool simEvent::operator>=(const simEvent& e) {
	if (timestamp >= e.timestamp) { return true; }
	else { return false; }
}

//Serialize
void simEvent::serialize(std::ostream& os) {
	os << event_name << ":\t" << timestamp << "\n";
}