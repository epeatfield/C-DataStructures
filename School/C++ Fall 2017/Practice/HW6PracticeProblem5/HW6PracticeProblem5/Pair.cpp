#include <iostream>
using namespace std;

/**
In this implementation of the Pair class, you will NOT COPY
Box objects. Instead, when copying Pair objects, copy the pointers
and increment the refcount of the box whose pointer you copied,
so that the refcount always tells you how many pointers point
to it. If the refcount goes to zero, delete the Box object.

Note that the Pair(int v1, int v2) constructor also shares
the Box object if v1 equals v2.
*/

#include "Pair.h"

Pair::Pair(int v1, int v2)
{
	first = new Box(v1);
	if (v1 == v2)
		second = first;
	else
		second = new Box(v2);
	first->refcount++;
	second->refcount++;
}

Pair::Pair(const Pair& other) : first(other.first),
second(other.second)
{
	first->refcount++;
	second->refcount++;
	//first->Box::objects();
	//second->Box::objects();
}

Pair& Pair::operator=(const Pair& other)
{
	first = other.first;
	second = other.second;
	return *this;
}


Pair::~Pair()
{
	//first->refcount--;
	//second->refcount--;
	if (first->refcount = 0)
		delete first;
	if (second->refcount = 0)
		delete second;
}
