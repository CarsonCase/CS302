#include "NodeStack.h"

//Constructor
template <class t>
NodeStack<t>::NodeStack() {
	head = NULL;
	count = 0;
}

//pushes every node of this list to another
template <class t>
void NodeStack<t>::pushList(const NodeStack<t>& other) {
	/*This was a massive pain but I got it to work with nested for loops. It's a janky implementation as 
	it has to itterate through the whole list each time. But it works and I can't even remember why I 
	chose this method at this point. I'm just glad it works. Notice all my debugging console logs*/

	Node<t>* temp = other.head;
	//std::cout << "COUNT: " << other.count << std::endl;
	for (int i = other.count; i > 0; i--) {
		//std::cout << "Iteration of list: " << i << std::endl;
		for (int j = i; j > 1; j--) {
			//std::cout << "Moving down the chain: " << j << std::endl;
			temp = temp->next;
		}
	//std::cout << "pushing " << temp->data << " to the copied stack" << std::endl;
	push(temp->data);
	temp = other.head;
	}
}
//Copy Constructor
template <class t>
NodeStack<t>::NodeStack(const NodeStack<t>& other) {
	//Just calls pushLoop on other
	pushList(other);
}

//Assignment Operator
template <class t>
NodeStack<t>& NodeStack<t>::operator=(NodeStack<t>& rhs) {
	//Clears the list then calls pushloop on ourself
	clear();
	pushList(rhs);
	return *this;
}

//Destructor
template <class t>
NodeStack<t>::~NodeStack() {
	Node<t>* temp = new Node<t>;
	for (int i = 0; i < count; i++) {
		temp = head;
		head = head->next;
		delete temp;
	}
	count = 0;
}

//push function
template <class t>
void NodeStack<t>::push(const t& data) {
	Node<t>* temp = new Node<t>;
	temp->data = data;
	if (count <= 0) {
		head = temp;
		head->next = NULL;
	}
	else {
		temp->next = head;
		head = temp;
	}
	count++;
}

//peek function
template <class t>
t NodeStack<t>::peek() {
	if (count <= 0) {
		throw 0;
	}
	else {
		return head->data;
	}
}

//pop
template <class t>
void NodeStack<t>::pop() {
	Node<t>* temp = head;
	head = head->next;
	delete temp;
	count--;
}

//clear
template <class t>
void NodeStack<t>::clear() {
	for (int i = 0; i < count; i++) {
		pop();
	}
}

//is Empty
template <class t>
bool NodeStack<t>::isEmpty() const {
	if (count <= 0) {
		return true;
	}else{
		return false;
	}
}
//Returns false always. Could be fancy and add in some memory allocation stuff later
template <class t>
bool NodeStack<t>::isFull() const {
	return false;
}