#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <array>
#include <assert.h>

// My attempt at the stack class
class Stack
{
	std::array<int, 10> m_data {};
	int m_size{0};

public:
	void reset();
	bool push(int x);
	int pop();
	void print() const;
	// The const-ness of a member function is part of its signature and thus can be overloaded
	const int& getSize() const; // A const member function cannot return non const reference to other members
};

#endif