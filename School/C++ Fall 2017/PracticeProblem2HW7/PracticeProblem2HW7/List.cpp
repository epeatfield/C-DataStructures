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

void List::pop_front()
{
	Node* removed = first;
	if (last == first)
	{
		first = nullptr;
		last = nullptr;
	}
	else
	{
		first = first->next;
		first->previous = nullptr;
		last->next = nullptr;
	}
	delete removed;

}

// We aren't showing you the implementation of List::push_front
