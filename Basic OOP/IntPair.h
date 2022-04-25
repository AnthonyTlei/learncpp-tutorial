#ifndef INTPAIR_H
#define INTPAIR_H

#include<iostream>

class IntPair
{
	int m_first{ 0 };
	int m_second{ 0 };

	// A static member is associated with the Class itself not instances of the class
	// A static non-const member should be initialized outside of the class
	// Static members are not subject to access modifiers 
	// Static members should be defined in the .cpp file to not get redefined with every inclusion of the header
	// A static member should be accessed using the class name and not the instances of the class
	//	Ex: IntPair::m_count and NOT p3.m_count
	static int m_count;
	
public:
	
	IntPair();
	IntPair(int f, int s);

	void set(int f, int s);
	void print() const;

	bool isEqual (const IntPair& pair) const;

	// Static methods have no "this" pointer
	// Static methods can only access static members
	static int getCount();
	static void incrementCount();

	void reset();

	// A different reset using a friend function which can access the private members of IntPair
	// Defined outside IntPair class
	// Multiple classes can use a single friend function
	// Classes can be made "friendly" too
	// Methods can be made "friendly" too but we would have to write the full definition and not just a declaration
	friend void reset(IntPair& intPair);
};

#endif