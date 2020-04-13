#include "Node.h"

//Constructors
template <class t>
Node<t>::Node<t>() {
	next = nullptr;
}
template <class t>
Node<t>::Node<t>(t d, Node<t>* n) {
	next = n;
	data = d;
}
template <class t>
Node<t>::Node<t>(const Node<t>& other) {
	next = other.next;
	data = other.data;
}
template <class t>
Node<t> Node<t>::operator=(const Node<t>& rhs) {
	next = rhs.next;
	data = rhs.data;
}
template <class t>
bool Node<t>::operator==(const Node<t>& other) {
	if (data == other.data) {
		return true;
	}
	else { return false; }
}

//Get Functions
template <class t>
Node<t>* Node<t>::get_next_node() const{
	return next;
}
template <class t>
t Node<t>::get_data() const{
	return data;
}

//Set Functions
template <class t>
void Node<t>::set_next_node(Node<t>* n) {
	next = n;
}
template <class t>
void Node<t>::set_data(t d) {
	data = d;
}