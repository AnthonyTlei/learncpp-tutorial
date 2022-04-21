#include <iostream>  

void multiply()
{
	int numberToMultiply{};
	std::cout << "Enter an integer: ";
	std::cin >> numberToMultiply;
	std::cout << "Double that number is: " << numberToMultiply * 2 << '\n';
	std::cout << "Triple that number is: " << numberToMultiply * 3 << '\n';
}

void add()
{
	int number1{};
	int number2{};

	std::cout << "Enter an integer: ";
	std::cin >> number1;

	std::cout << "Enter another integer: ";
	std::cin >> number2;

	std::cout << number1 << "+" << number2 << "=" << number1 + number2 << '\n';
	std::cout << number1 << "-" << number2 << "=" << number1 - number2 << '\n';
}

int main()
{
	//std::cout << "Enter a number: ";
	//int x{};
	//std::cin >> x;
	//std::cout << "You entered " << x << '\n';

	multiply();
	add();

	return 0;
}