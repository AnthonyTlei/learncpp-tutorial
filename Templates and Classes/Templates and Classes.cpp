#include "Storage.h"
#include "Pair.h"
#include <iostream>

void testStorage()
{
	// Declare a non-pointer Storage to show it works
	Storage<int> myint{ 5 };
	myint.print();

	// Declare a pointer Storage to show it works
	int x{ 7 };
	Storage<int*> myintptr(&x);

	// If myintptr did a pointer assignment on x,
	// then changing x will change myintptr too
	x = 9;
	myintptr.print();

	// Dynamically allocate a temporary string
	char* name{ new char[40]{ "Alex" } };

	// Store the name
	Storage< char*> myname(name);

	// Delete the temporary string
	delete[] name;

	// Print out our name to prove we made a copy
	myname.print();
}

void testPair()
{
	Pair1<int> p1{ 5, 8 };
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2{ 2.3, 4.5 };
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> p3{ 5, 6.7 };
	std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

	const Pair<double, int> p4{ 2.3, 4 };
	std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

	StringValuePair<int> svp{ "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
}

int main()
{
	testPair();
}
