#pragma once
#include <iostream>
#include "Node.h"
#include "Node.cpp"

template <class t> class Node;
template <class t> class NodeStack;

template <class t>
class NodeStack
{
private:
	//Front pointer only as it's a stack and we shouldn't need a back pointer
	Node<t>* head;
	//Added for simplicity. We got RAM for days so I'll sacrafice a little for some simplicity and speed
	size_t count;

	//This is a private helper funcrion for the copy constructor and assignment operator. Takes in any function and does it to every node in opposite order
	void pushList(const NodeStack<t>& other);
public:
	NodeStack();
	NodeStack(const NodeStack& other);
	NodeStack<t>& operator=(NodeStack<t>& rhs);
	~NodeStack();
	void push(const t& data);
	t peek();
	void pop();
	void clear();
	bool isEmpty() const;
	bool isFull() const;
};

