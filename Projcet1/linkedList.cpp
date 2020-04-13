#include "linkedList.h"
template <class t>
linkedList<t>::linkedList() {
	pFirst = NULL;
	pLast = pFirst;
	count = 0;
}

template <typename t>
linkedList<t>::~linkedList() {
	Node<t>* temp = new Node<t>;
	for (int i = 0; i < count; i++) {
		temp = pLast;
		pLast = pLast->next;
		delete temp;
	}
	count = 0;
}

template <class t>
void linkedList<t>::push(t d) {
	Node<t>* temp = new Node<t>;
	temp->data = d;
	if (count++ == 0) {
		temp->next = NULL;
		pFirst = temp;
		pLast = temp;
	}
	else {
		pFirst->next = temp;
		temp->next = NULL;
		pFirst = temp;
	}
}

template<class t>
int linkedList<t>::getSize() const{
	return count;
}

template <class t>
void linkedList<t>::pop() {
	if (!isEmpty()) {
		Node<t>* temp = new Node<t>;
		temp = pFirst;
		pFirst = pFirst->next;
		delete pFirst;
		count--;
	}
	else { std::string e = "Error. Stack is Full"; throw(e); }
}
template <class t>
bool linkedList<t>::isEmpty() const {
	if (count == 0) {
		return true;
	}
	else {
		return false;
	}
}
template <class t>
void linkedList<t>::serialize(std::ostream& os) const{
	Node<t>* temp = pLast;
	os << "[";
	for (int i = 0; i < count; i++) {
		os << temp->data << ", ";
		temp = temp->next;
	}
	os << "]";
}
template <class T>
std::ostream& operator<<(std::ostream& os, linkedList<T>& l) {
	l.serialize(os);
	return os;
}