#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <cstring>

// Our Storage class for non-pointers
template <typename T>
class Storage
{
private:
	T m_value;
public:
	Storage(T value)
		: m_value{ value }
	{
	}

	~Storage()
	{
	}

	void print() const
	{
		std::cout << m_value << '\n';
	}
};

// Partial-specialization of Storage class for pointers
template <typename T>
class Storage<T*>
{
private:
	T* m_value;
public:
	Storage(T* value)
		: m_value{ new T { *value } } // this copies a single value, not an array
	{
	}

	~Storage()
	{
		delete m_value;
	}

	void print() const
	{
		std::cout << *m_value << '\n';
	}
};

// Full specialization of constructor for type char*
template <>
Storage<char*>::Storage(char* value)
{
	// Figure out how long the string in value is
	int length{ 0 };
	while (value[length] != '\0')
		++length;
	++length; // +1 to account for null terminator

	// Allocate memory to hold the value string
	m_value = new char[length];

	// Copy the actual value string into the m_value memory we just allocated
	for (int count = 0; count < length; ++count)
		m_value[count] = value[count];
}

// Full specialization of destructor for type char*
template<>
Storage<char*>::~Storage()
{
	delete[] m_value;
}

// Full specialization of print function for type char*
// Without this, printing a Storage<char*> would call Storage<T*>::print(), which only prints the first char
template<>
void Storage<char*>::print() const
{
	std::cout << m_value;
}

#endif