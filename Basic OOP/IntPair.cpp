#include "IntPair.h"

// Definition of m_count
int IntPair::m_count{0};

IntPair::IntPair():m_first{0}, m_second{0}
{
	IntPair::incrementCount();
}

IntPair::IntPair(int f, int s) : m_first{ f }, m_second{ s }
{
	IntPair::incrementCount();
}

void IntPair::set(int f, int s)
{
	m_first = f;
	m_second = s;
}

void IntPair::print() const
{
	std::cout << "Pair(" << m_first << ", " << m_second << ")\n";
}

bool IntPair::isEqual(const IntPair& pair) const
{
	if (m_first == pair.m_first && m_second == pair.m_second) return true;
	return false;
}

int IntPair::getCount()
{
	return m_count;
}

void IntPair::incrementCount()
{
	++m_count;
}

void IntPair::reset()
{
	*this = IntPair();
}

void reset(IntPair& intPair)
{
	intPair.m_first = 0;
	intPair.m_second = 0;
	IntPair::m_count = 0;
}
