/*
Node Class <templated>
For use in linked lists

Normally I would love to use a struct to keep this nice and simple.
But since I am needing to prove myself as a prim and proper coder I will write it as a class. Maybe I'll understand
one day when I'm older and wiser.

This is something I really should just save somewhere I write it so many times. So this will likely be
copy and pasted many times from here on out.
Hey, you know what. Just for fun. Let's put time stamps on my code from now on. Starting here in this project. It's
good practice right? Also it'll make it fun to look back on one day.

04/01/2020 
(plus it's april fools :p)
*/
#pragma once
template <class t>
class Node
{
	template<class U> friend class queue;
private:
	Node<t>* next;
	t data;
public:
	Node<t>();
	Node<t>(t d, Node<t>* n = nullptr);
	Node<t>(const Node<t> &other);
	Node<t> operator=(const Node<t>& rhs);
	bool operator==(const Node<t>& other);
	Node<t>* get_next_node() const;
	t get_data() const;
	void set_next_node(Node<t>* n);
	void set_data(t d);
};

