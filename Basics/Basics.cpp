#include <iostream>  

void multiply()
{
	int numberToMultiply{};
	std::cout << "Enter an integer: ";
	std::cin >> numberToMultiply;
	std::cout << "Double that number is: " << numberToMultiply * 2 << '\n';
	std::cout << "Triple that number is: " << numberToMultiply * 3 << '\n';
}

int main()
{
	//std::cout << "Enter a number: ";
	//int x{};
	//std::cin >> x;
	//std::cout << "You entered " << x << '\n';

	multiply();

	return 0;
}