#ifndef INTARRAY_H
#define INTARRAY_H

#include <cassert>
#include <iostream>
#include <initializer_list>

class IntArray
{
	int m_length{};
	int* m_data{};

public:

	IntArray() = default;

	IntArray(int length) : 
		m_length{length}
	{
		assert( length >= 0 );

		if (length > 0)
			m_data = new int[length];
	}

	IntArray(std::initializer_list<int> list) // allow IntArray to be initialized via list initialization
		: IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}


	~IntArray()
	{
		// we don't need to set m_data to null or m_length to 0 here, 
		// since the object will be destroyed immediately after this function anyway
		delete[] m_data;
	}

	void erase()
	{
		m_length = 0;
		// We need to make sure we set m_data to nullptr here, otherwise it will
		// be left pointing at deallocated memory!
		m_data = nullptr;
	}

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}


	IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

	IntArray& operator=(std::initializer_list<int> list)
	{
		// If the new list is a different size, reallocate it
		int length{ static_cast<int>(list.size()) };
		if (length != m_length)
		{
			delete[] m_data;
			m_length = length;
			m_data = new int[length] {};
		}

		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}

		return *this;
	}

	int getLength() const
	{
		return m_length;
	}

	void reallocate(int newLength)
	{
		// First we delete any existing elements
		erase();

		// If our array is going to be empty now, return here
		if (newLength <= 0)
			return;

		// Then we have to allocate new elements
		m_data = new int[newLength];
		m_length = newLength;
	}

	void resize(int length)
	{
		if (length == m_length) return;

		if (length <= 0) 
		{
			erase();
			return;
		}

		int* data{ new int[length] };

		if (m_length > 0)
		{
			int elementsToCopy{ (length > m_length) ? m_length : length };

			for (int i = 0; i < elementsToCopy; ++i)
			{
				data[i] = m_data[i];
			}

		}

		delete[] m_data;

		m_data = data;
		m_length = length;

	}

	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length);

		// First create a new array one element larger than the old array
		int* data{ new int[m_length + 1] };

		// Copy all of the elements up to the index
		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		// Insert our new element into the new array
		data[index] = value;

		// Copy all of the values after the inserted element
		for (int after{ index }; after < m_length; ++after)
			data[after + 1] = m_data[after];

		// Finally, delete the old array, and use the new array instead
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void remove(int index)
	{
		assert(index >= 0 && index < m_length);

		// First create a new array one element smaller than the old array
		int* data{ new int[m_length - 1] };

		// Copy all of the elements up to the index
		for (int before{ 0 }; before < index; ++before)
			data[before] = m_data[before];

		// Copy all of the values after the removed element
		for (int after{ index+1 }; after < m_length; ++after)
			data[after - 1] = m_data[after];

		// Finally, delete the old array, and use the new array instead
		delete[] m_data;
		m_data = data;
		--m_length;
			
	}

	// A couple of additional functions just for convenience
	void insertAtBeginning(int value) { insertBefore(value, 0); }
	void insertAtEnd(int value) { insertBefore(value, m_length); }

};

#endif