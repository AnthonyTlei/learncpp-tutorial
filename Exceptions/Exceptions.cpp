#include "ArrayException.h"
#include "Fraction.h"
#include <iostream>

void testIntArray()
{
	IntArray array;

	try
	{
		int value{ array[5] }; // out of range subscript
	}
	catch (const ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.what() << ")\n";
	}
}

void testFraction()
{
	int numerator{ 0 };
	int denominator{ 1 };

	std::cout << "Enter a numerator: ";
	std::cin >> numerator;
	std::cout << "\n";

	std::cout << "Enter a denominator: ";
	std::cin >> denominator;
	std::cout << "\n";

	try
	{
		Fraction f{ numerator, denominator };
		std::cout << "Your fraction is: " << f << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}

int main()
{

}

