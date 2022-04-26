#ifndef FIXEDPOINT2_H
#define FIXEDPOINT2_H

#include <math.h>
#include <iostream>

class FixedPoint2
{
	using base_t = std::int_least16_t;
	using decimal_t = std::int_least8_t;

	base_t m_base{};
	decimal_t m_decimal{};

public:

	FixedPoint2(base_t base = 0, decimal_t decimal = 0)
		:m_base{base}, m_decimal{decimal}
	{
		if (base < 0 || decimal < 0)
		{
			if (m_base > 0) m_base = -m_base;

			if (m_decimal > 0) m_decimal = -m_decimal;
		}
	}

	FixedPoint2(double num) : 
		
		m_base{ static_cast<base_t>(std::round(num)) },
		m_decimal{ static_cast<decimal_t>(std::round(num* 100) - m_base * 100) }

		{};

	operator double() const
	{
		return m_base + m_decimal / 100.0;
	}

	friend bool operator==(const FixedPoint2& fp1, const FixedPoint2& fp2)
	{
		return (fp1.m_base == fp2.m_base && fp1.m_decimal == fp2.m_decimal);
	}

	FixedPoint2 operator-() const
	{
		// We need to cast, because the negative sign (-) converts our
		// narrow integers types to int.
		return {
			static_cast<std::int_least16_t>(-m_base),
			static_cast<std::int_least8_t>(-m_decimal)
		};
	}
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& fp)
{
	out << static_cast<double>(fp);
	return out;
}


std::istream& operator >> (std::istream& in, FixedPoint2& fp)
{
	double d{};
	in >> d;
	fp = FixedPoint2{ d };

	return in;
}

FixedPoint2 operator+(const FixedPoint2& fp1, const FixedPoint2& fp2)
{
	return { static_cast<double>(fp1) + static_cast<double>(fp2) };
}

#endif // !FIXEDPOINT2_H
