/**
* Assignment 8. STL List and Vector
* Fall 2017
*
* Compare the run times of appending, prepending, removing, getting
* and inserting into lists and vectors.
*
* Author: Emma Peatfield
*		  San Jose State University
*
*/
#include <iostream>
#include <iterator>
#include <list>
#include "SortedList.h"
#include "Node.h"

using namespace std;

/**
* Defaut constructor.
* Reset the global Node counters.
*/
SortedList::SortedList()
{
	Node::reset();
}

/**
* Destructor.
* Reset the global Node counters.
*/
SortedList::~SortedList()
{
	Node::reset();
}

/**
* @return the size of the data list.
*/
int SortedList::size() const { return data.size(); }

/**
* Check that the data is sorted.
* @return true if sorted, false if not.
*/
bool SortedList::check()
{
	if (data.size() == 0) return true;

	list<Node>::iterator it = data.begin();
	list<Node>::iterator prev = it;

	it++;

	// Ensure that each node is greater than the previous node.
	while ((it != data.end()) && (*it >= *prev))
	{
		prev = it;
		it++;
	}

	return it == data.end();  // Good if reached the end.
}

/**
* Insert a new node at the beginning of the data list.
* @param value the new node's value.
*/
void SortedList::prepend(const long value)
{
	Node new_object(value);
	data.push_front(new_object);
}

/**
* Append a new node at the end of the data list.
* @param value the new node's value.
*/
void SortedList::append(const long value)
{
	Node new_object(value);
	data.push_back(new_object);
}

/**
* Remove a node.
* @param index the index of the node to remove.
*/
void SortedList::remove(const int index)
{
	data.erase(position(index));
}

/**
* Insert a new node into the data list at the
* appropriate position to keep the list sorted.
*/
void SortedList::insert(const long value)
{
	
	list<Node>::iterator test = data.begin();
	list<Node>::iterator prev = data.begin();
	if (check())
	{
		Node inserts(value);
		int i = 0;

		while (test != data.end())
		{
			test++;
			Node type = *prev;
			if (value >= type.get_value())
			{
				prev = test;
				
				i++;
			}
			else
			{
				data.insert(position(i), inserts);
				goto finish;
			}
			
		}
	finish:;
	}
	
}

/**
* Return the data node at the indexed position.
* @param the index of the node.
* @return a copy of the data node.
*/
Node SortedList::at(const int index)
{
	list<Node>::iterator t = position(index);
	Node value = *t;
	return value;
}

/**
* Return a forward iterator pointing at the indexed position.
* @param index the index
* @return the iterator.
*/
list<Node>::iterator SortedList::position(const int index)
{
	list<Node>::iterator point = data.begin();
	for (int i = 0; i < index; i++)
		point++;
	return point;
}

/**
* Sort the list
*/
/*void SortedList::sort()
{
	int size1 = size();
	Node type = 0;
	Node type1 = 0;
	list<Node>::iterator it = data.begin();
	list<Node>::iterator temp = data.begin();
	while (it != data.end())
	{
		for (int i = 1; i < size1; i++)
		{
			type = at(i - 1);
			type1 = at(i);
			if (type1.get_value() < type.get_value())
			{
				*temp = type1;
				it++;
				*it = type;
				temp++;
				goto finish;
				}
			}
		it++;
		finish:;
	}
}*/