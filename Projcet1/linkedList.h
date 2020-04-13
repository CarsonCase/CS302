#pragma once
#include <iostream>
template <class U> class Node;
template <class U> class linkedList;

/*It's a struct, not a class. Because you get the idea and it's efficient*/
template <class U> struct Node {
	friend class linkedList<U>;
private:
	Node<U>* next;
	U data;
};

template <class U> class linkedList
{
	//print every element
	template <class T>
	friend std::ostream& operator<<(std::ostream& os, linkedList<T>& l);
private:
	Node<U>* pFirst;
	Node<U>* pLast;
	/*I use a count. This is NOT because I am lazy. I promise. I am definetly NOT lazy. And would never*/
	/*submit lazy code. This uses a count variable because it circumnavigates the issues associated with*/
	/*failure in the memory of the device used. I also came up with this myself and definetly did not ask*/
	/*a graduaged CS man named Nick if I would get yelled at for using a count.*/
	int count;
public:
	//Constructor
	linkedList();
	//Destructor
	~linkedList();
	//Push
	void push(const U d);
	//Pop
	void pop();
	//return size
	int getSize() const;
	//return if the list is empty
	bool isEmpty() const;
	//Function to print stuff to screan
	void serialize(std::ostream& os) const;

};

