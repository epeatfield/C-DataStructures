#include <string>
#include "List.h"

using namespace std;

Node::Node(string element)
{
	data = element;
	previous = nullptr;
	next = nullptr;
}

List::List()
{
	first = nullptr;
	last = nullptr;
}

Iterator List::begin()
{
	Iterator iter;
	iter.container = this;
	iter.position = first; // Points to first element
	return iter;
}

// Implement the following three member functions

/**
Tests whether this iterator is past the end of the list.
*/
bool Iterator::past_end() const
{
	bool flag;
	if (position == nullptr)
	{
		flag = true;
	}
	else flag = false;
	return flag;
}

/**
Yields the element to which the iterator points.
This member function should not be called if the iterator
is past the end of the list.
*/
string Iterator::get() const
{
	return position->data;
}

/*
Moves the iterator to the next element of the list or
past the end.
This member function should not be called if the iterator
is already past the end of the list.
*/
void Iterator::next()
{
	position = position->next;
	return;
}

// We aren't showing you the implementation of List::push_front
