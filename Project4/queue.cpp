#include "queue.h"
//constructor/destructors
template <class t>
queue<t>::queue<t>() {
	front = nullptr;
	rear = front;
	size = 0;
}

template <class t>
queue<t>::~queue<t>() {
	Node<t>* temp = front, * current = NULL;
	if (rear) { rear->next = nullptr; }
	while (temp) {
		current = temp;
		temp = temp->next;
		delete current;
	}
	front = rear = nullptr;
}

//Utility Functions

template <class t>
void queue<t>::push_back(t data) {
	Node<t>* temp = new Node<t>(data);
	if (front == nullptr) {
		front = rear = temp;
		rear->next = front;
		front->next = rear;
	}
	else {
		rear->next = temp;
		rear = temp;
	}
	size++;
}

template <class t>
t queue<t>::peek_front() {
	if (empty()) {
		std::cerr << "empty queue, cannot peek" << std::endl;
		throw("empty queue, cannot peek");
	}
	else {return front->get_data();}
}

template <class t>
void queue<t>::pop_front() {
	if (empty()) {
		std::cerr << "empty queue, cannot peek" << std::endl;
		throw("empty queue, cannot pop_front");
	}
	else {
		if (front == rear) {
			front = rear = nullptr;
		}
		else {
			front = front->next;
			delete rear->next;
		}
		size--;
	}
}

template <class t>
size_t queue<t>::get_size() {
	return size;
}

template <class t>
bool queue<t>::empty() {
	if (size <= 0) {
		return true;
	}
	else { return false; }
}

template <class t>
void queue<t>::serialize(std::ostream& os) const{
	Node<t>* temp = front;
	os << "[";
	for (int i = 0; i < size; i++) {
		os << temp->data << ", ";
		temp = temp->next;
	}
	os << "]";
}


template <class U>
std::ostream& operator<<(std::ostream& os, const queue<U>& q) {
	q.serialize(os);
	return os;
}

