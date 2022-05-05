#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

template<typename T>
class DynamicArray
{
	T* m_array;
	int m_length;

public:

	DynamicArray(int length)
		:m_length{length}, m_array{new T[length]}
	{}

	~DynamicArray()
	{
		delete[] m_array;
	}

	DynamicArray(const DynamicArray& arr) = delete;

	DynamicArray(DynamicArray&& arr)
		: m_array(arr.m_array), m_length(arr.m_length)
	{
		arr.m_length = 0;
		arr.m_array = nullptr;
	}

	DynamicArray& operator=(const DynamicArray& arr) = delete;

	DynamicArray& operator=(DynamicArray&& arr)
	{
		if (&arr == this)
			return *this;

		delete[] m_array;

		m_length = arr.m_length;
		m_array = arr.m_array;

		arr.m_array = nullptr;
		arr.m_length = 0;

		return *this;
	}

	int getLength() const { return m_length; }
	T& operator[] (int index) { return m_array[index]; }
	const T& operator[] (int index) const { return m_array[index]; }

};

#endif