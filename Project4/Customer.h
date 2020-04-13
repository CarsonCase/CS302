/*
Customer Object for use in bank simulation
Like several other things in this I would probably rather keep something this simple as a struct,
but I'm not exactly sure how I will implement this whole thing yet. So I am just going to add a lot of
functionality here so I can get creative when tyring to put the project together. 

04/04/2020
*/

#pragma once
#include "simEvent.h"
#include <iostream>
class Customer
{
	//May delete this. Or forget to
	//If not the point is to overload << to be able to read a text file line directly into constructing a customer
	friend std::istream& operator>>(std::istream& os, Customer& c);

private:
	//Upon creation these will never change. Would make them const but it causes problems for assignment operator
	size_t arrival_time;
	size_t time_required;
	//This will change
	size_t time_remaining;

	static size_t total_wait_time;		//Exactly what it sound like. Increase each tic for every customer in line but NOT upon update at a teller

public:
	//Constructors
	Customer();
	Customer(size_t at, size_t tr);
	Customer(const Customer& other);

	//Assignment operator: only time we change the AT or TR
	Customer& operator=(const Customer& other);
	//comparisson operator
	bool operator==(const Customer& other);
	//Utility Functions
	//UPDATE: Decreases the time left for customer by 1 and returns true if time is 0 meaning customer is done
	bool update();
	size_t get_arrival_time() const;
	size_t get_time_required() const;
	size_t get_time_remaining() const;
	static size_t get_total_wait_time();
	static void wait(size_t time);
};

