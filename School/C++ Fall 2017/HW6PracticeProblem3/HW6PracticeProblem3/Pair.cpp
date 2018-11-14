#include <iostream>
using namespace std;

/**
Implement the constructor to initialize two Box values,
and do the right thing in the "big 3".
*/

#include "Pair.h"

Pair::Pair(int v1, int v2) :
	first(new Box(v1)), second(new Box(v2))
{}

Pair::Pair(const Pair& other) :
	first(other.first), second(other.second)
{
}

Pair& Pair::operator=(const Pair& other)
{
	first = other.first;
	second = other.second;
	return *this;
}


Pair::~Pair()
{
	first->~Box();
	second->~Box();
}
