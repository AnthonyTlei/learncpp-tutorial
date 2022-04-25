#include "Stack.h"

void Stack::reset()
{
	m_size = 0;
}

bool Stack::push(int x)
{
	if(m_size == 10) return false;

	m_data[++m_size - 1] = x;
	return true;
}

int Stack::pop()
{
	assert(m_size > 0);
	return m_data[--m_size];
}

void Stack::print() const
{
	std::cout << "( ";
	for (int i = 0; i <= m_size - 1; ++i)
	{
		std::cout << m_data[i] << ' ';
	}
	std::cout << ")\n";
}

const int& Stack::getSize() const
{
	return m_size;
}
