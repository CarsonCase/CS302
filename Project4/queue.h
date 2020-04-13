/*
Linked list implementation of a queue! <templated>
A normal queue. Doesn't do anything particularly special

Uses the Node class as a dependency
04/01/2020
*/
#pragma once
#include "Node.h"
#include "Node.cpp"
#include <iostream>
template <class t> class Node;

template <class t> class queue;

template <class t>
class queue
{
	template <class U>
	friend std::ostream& operator<<(std::ostream& os, const queue<U>& q);
protected:
	Node<t>* front;
	Node<t>* rear;
	size_t size;

public:
	queue<t>();
	~queue<t>();
	//I am not including all the utility constructors and overloads. Because I am only using one. If I ever need them I'll add them
	void push_back(t data);
	t peek_front();
	void pop_front();
	size_t get_size();
	bool empty();

	void serialize(std::ostream& os) const;
};

