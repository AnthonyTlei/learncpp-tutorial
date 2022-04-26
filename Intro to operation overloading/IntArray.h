#ifndef INTARRAY_H
#define INTARRAY_H

#include <iostream>
#include <cassert>

class IntArray
{
	int m_size{0};
	int* m_data{nullptr};

public:

	IntArray(int size) :m_size{ size }
	{
		assert(size > 0 && "IntArray length should be a positive integer");

		m_data = new int[m_size] {};
	};

	IntArray(const IntArray& arr) :m_size{ arr.m_size }
	{
		m_data = new int[m_size];

		for (int i = 0; i < m_size; ++i) 
		{
			m_data[i] = arr.m_data[i];
		}
	}

	~IntArray()
	{
		delete[] m_data;
	}

	int& operator[] (int i)
	{
		assert(i >= 0);
		assert(i < m_size);
		return m_data[i];
	}

	IntArray& operator=(const IntArray& arr)
	{
		if (this == &arr) return *this;

		delete[] m_data;

		m_size = arr.m_size;

		m_data = new int[m_size];

		for (int i = 0; i < m_size; ++i)
		{
			m_data[i] = arr.m_data[i];
		}

		return *this;

	}

	friend std::ostream& operator<< (std::ostream& out, IntArray& arr)
	{
		
		for (int i = 0; i < arr.m_size; ++i)
		{
			out << arr[i] << ' ';
		}
		out << '\n';

		return out;
	}

};

#endif