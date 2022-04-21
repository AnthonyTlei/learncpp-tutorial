#include "Add.h";
#include "Input.h";
#include <iostream>


void printHi()
{
	std::cout << "Hi" << '\n';
}

void printValue(int x)
{
	std::cout << x << '\n';
}

void printDouble(int value) 
{
	std::cout << value << " doubled is: " << value * 2 << '\n';
}

int multiply(int z, int w)
{
	return z * w;
}

int main()
{
	int x{ getValueFromUser() }; 
	int y{ getValueFromUser() }; 

	printHi();
	printValue(x);
	printDouble(y);
	
	printValue(add(x, y));
	printDouble(add(x, multiply(x, y)));

	return 0;
}

