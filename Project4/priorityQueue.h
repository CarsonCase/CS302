/*
Priority Queue 
A priority queue made to handle event objects
Uses the queue as a base class to make things easier. Not sure if this is the right implementation but hey
It works. I think

04/02/20
*/

#pragma once
#include "queue.h"
#include "queue.cpp"
#include "simEvent.h"

template <class t> class queue;
template <class t> class priorityQueue;

template <class t> class priorityQueue :
	public queue<t>
{
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, priorityQueue<T>& q);

public:
	void insert(t data);
	void delete_highest_priority();
	t get_highest_priority();

	void serialize(std::ostream& os) const;
};

