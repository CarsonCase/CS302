#include "Customer.h"

size_t Customer::total_wait_time = 0;

Customer::Customer(): arrival_time(0), time_required(0) {
	time_remaining = 0;
}
Customer::Customer(size_t at, size_t tr): arrival_time(at), time_required(tr) {
	time_remaining = time_required;
}
Customer::Customer(const Customer& other): arrival_time(other.arrival_time), time_required(other.time_required) {
	time_remaining = other.time_remaining;
}

//Assignment operator: only time we change the AT or TR
Customer& Customer::operator=(const Customer& other) {
	arrival_time = other.arrival_time;
	time_required = other.time_required;
	time_remaining = other.time_remaining;

	return *this;
}

bool Customer::operator==(const Customer& other) {
	if (arrival_time == other.arrival_time &&
		time_required == other.time_required &&
		time_remaining == other.time_remaining) {
		return true;
	}
	else { return false; }
}
//Utility Functions
bool Customer::update() {
	time_remaining--;
	if (time_remaining < 0) {
		std::cerr << "Error, Customer has a negative time_remaining";
		throw("Error, Customer has a negative time_remaining");
	}
	if(time_remaining<=0){
		return true;
	}
	else { return false; }
}
size_t Customer::get_arrival_time() const{
	return arrival_time;
}
size_t Customer::get_time_required() const{
	return time_required;
}
size_t Customer::get_time_remaining() const{
	return time_remaining;
}
size_t Customer::get_total_wait_time() {
	return total_wait_time;
}
void Customer::wait(size_t time) {
	total_wait_time += time;
}
//Friend Function. Explained at the top of header file. Maybe a useful, creative idea. Maybe a waste of time
std::istream& operator>>(std::istream& os, Customer& c) {
	size_t at, tr;
	os >> at;
	os >> tr;
	Customer c_new(at, tr);
	c = c_new;

	return os;
}
