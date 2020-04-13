#pragma once
#include <iostream>
template <class t>
class Node
{
	template <class U> friend class NodeStack;
private:
	Node();
	Node<t>* next;
	t data;
};

