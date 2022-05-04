#ifndef FRACTION_H
#define FRACTION_H

#include <stdexcept>
#include <iostream>

class Fraction
{
	int m_numerator{ 0 };
	int m_denominator{ 1 };

public:

	Fraction(int num = 0, int denom = 1) :
		m_numerator{ num }, m_denominator{ denom }
	{
		if (m_denominator == 0)
		{
			throw std::runtime_error("Invalid Denominator");
		}
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& frac);
};

std::ostream& operator<<(std::ostream& out, const Fraction& f1)
{
	out << f1.m_numerator << "/" << f1.m_denominator;
	return out;
}

#endif