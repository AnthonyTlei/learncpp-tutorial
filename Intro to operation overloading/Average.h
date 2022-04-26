#ifndef AVERAGE_H
#define AVERAGE_H

#include <cstdint>
#include <iostream>

class Average
{
	using sum_t = std::int_least32_t;
	using nums_t = std::int_least8_t;

	sum_t m_sum{};
	nums_t m_nums{};

public:

	Average() : m_sum{ 0 }, m_nums{ 0 }{};

	friend std::ostream& operator<<(std::ostream& out, const Average& avg)
	{
		out << static_cast<double>(avg.m_sum) / avg.m_nums << '\n';
		return out;
	}

	Average& operator+=(int x)
	{
		m_sum += x;
		++m_nums;
		return *this;
	}
};


#endif