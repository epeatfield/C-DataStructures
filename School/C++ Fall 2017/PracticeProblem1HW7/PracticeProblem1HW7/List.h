#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

class List;
class Tester;

class Node
{
public:
	/**
	Constructs a node with a given data value.
	@param element the data to store in this node
	*/
	Node(string element);
private:
	string data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Tester;
};

class List
{
public:
	/**
	Constructs an empty list.
	*/
	List();
	/**
	Adds an element to the front of the list.
	@param element the value to add
	*/
	void push_front(string element);
private:
	Node* first;
	Node* last;
	friend class Tester;
};

#endif#pragma once
