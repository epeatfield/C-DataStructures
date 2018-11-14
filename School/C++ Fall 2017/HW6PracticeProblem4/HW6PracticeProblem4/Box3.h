#pragma once
#ifndef BOX3_H
#define BOX3_H

class Box
{
public:
	Box();
	Box(int v);
	Box(const Box& other);
	~Box();
	Box& operator=(const Box& other);
	int value() const;
	void value(int v);
	static int objects();
private:
	int _value;
	static int _objects;
};

#endif
