#ifndef CENT_H
#define CENT_h

#include <iostream>

class Cents
{
private:
	int m_cents{};

public:
	Cents(int cents) : m_cents{ cents } { }

	// add Cents + Cents using a friend function
	friend Cents operator+(const Cents& c1, const Cents& c2);
	// subtract Cents - Cents using a friend function
	friend Cents operator-(const Cents& c1, const Cents& c2);

	friend std::istream& operator>> (std::istream& in, Cents& cents);

	// Overload -Cents as a member function (Unary operator -)
	Cents operator-() const;

	// Prefix increment operator
	Cents& operator++();
	// Postfix increment operator
	Cents operator++(int);

	friend bool operator!= (const Cents& c1, const Cents& c2);
	friend bool operator<= (const Cents& c1, const Cents& c2);


	int getCents() const { return m_cents; }

	// Overloaded int cast (to convert cent to int)
	operator int() const { return m_cents; }
};

// note: this function is not a member function!
Cents operator+(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator+(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents{ c1.m_cents + c2.m_cents };
}

// note: this function is not a member function!
Cents operator-(const Cents& c1, const Cents& c2)
{
	// use the Cents constructor and operator-(int, int)
	// we can access m_cents directly because this is a friend function
	return Cents(c1.m_cents - c2.m_cents);
}

// note: this function is a member function!
Cents Cents::operator-() const
{
	return -m_cents; // since return type is a Cents, this does an implicit conversion from int to Cents using the Cents(int) constructor
}

// We overloaded << as a normal function, not a method nor a friend 
// If this definition was i  another file (ex: Cents.cpp), we would need to declare its prototype in the header
std::ostream& operator<< (std::ostream& out, const Cents& cents)
{
	// Using the public interface of Cents to access the values 
	out << "Cents(" << cents.getCents() << ')'; // actual output done here

	return out; // return std::ostream so we can chain calls to operator<<
}

std::istream& operator>> (std::istream& in, Cents& cents)
{
	// Since operator>> is a friend of the Cent class, we can access Cent's members directly.
	// note that parameter cents must be non-const so we can modify the class members with the input values
	in >> cents.m_cents;
	

	return in;
}

bool operator!= (const Cents& c1, const Cents& c2)
{
	return (c1.getCents() != c2.getCents());
}

bool operator<= (const Cents& c1, const Cents& c2)
{
	return c1.m_cents <= c2.m_cents;
}

Cents& Cents::operator++()
{
	if (m_cents == 99) m_cents = 0; // Wrap 
	else
	{
		++m_cents;
	}
	return *this;
}

// int parameter means this is postfix operator++
Cents Cents::operator++(int)
{
	// Create a temporary variable with our current cent
	Cents temp{ *this };

	// Use prefix operator to increment this cent
	++(*this); // apply operator

	// return temporary result
	return temp; // return saved state
}


#endif