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

void List::push_front(string element)
{
	Node* new_node = new Node(element);
	if (first == nullptr)
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->next = first;
		first = new_node;
		last->previous = new_node;
	}
}
