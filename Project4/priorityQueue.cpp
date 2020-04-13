#include "priorityQueue.h"

template <class t>
void priorityQueue<t>::insert(t data) {
	//If empty or is greater than the rear just push back
	if (queue<t>::empty()||data >= queue<t>::rear->get_data()) {
		//std::cout << "type1\t"<<eventTime<<std::endl;
		queue<t>::push_back(data);
	}
	//If less than the first then make it first
	else if (data <= queue<t>::front->get_data()) {
		//std::cout << "type2\t";
		Node<t>* toInsert = new Node<t>(data, queue<t>::front);
		queue<t>::front = toInsert;
		queue<t>::size++;
	}
	//If it's in the middle somewhere
	else {
		//std::cout << "type3\t";
		Node<t>* temp = queue<t>::front;
		//Used to iterate until it's time to insert
		while (data > temp->get_data()) {
			temp = temp->get_next_node();
		}
		Node<t>* toInsert = new Node<t>(data, temp->get_next_node());
		temp->set_next_node(toInsert);
		queue<t>::size++;
	}
}

template <class t>
void priorityQueue<t>::delete_highest_priority() {
	//Highest prioroty is always in front so just pop
	queue<t>::pop_front();
}

template <class t>
t priorityQueue<t>::get_highest_priority() {
	return queue<t>::front->get_data();
}

template <class t>
void priorityQueue<t>::serialize(std::ostream& os) const {
	Node<t>* temp = queue<t>::front;
	os << "[";
	for(int i=0; i< queue<t>::size; i++) {
		t data = temp->get_data();
		data.serialize(os);
		temp = temp->get_next_node();
	}
	os << "]";
}

template <class t>
std::ostream& operator<<(std::ostream& os, priorityQueue<t>& q) {
	q.serialize(os);
	return os;
}
