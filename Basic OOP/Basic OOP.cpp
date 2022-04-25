#include "IntPair.h"
#include "Stack.h"
#include "Calc.h"
#include "Timer.h"
#include "Point2d.h"

#include <iostream>

void intPairTest()
{
	IntPair p1;
	p1.set(2, 1); // set p1 values to (1, 1)

	IntPair p2{ 2, 1}; // initialize p2 values to (2, 2)

	p1.print();
	p2.print();

	if (p1.isEqual(p2))
	{
		std::cout << "pair 1 and pair 2 are equal\n";
	}
	else
	{
		std::cout << "pair 1 and pair 2 are not equal\n";
	}

	const IntPair p3{ 3,3 }; // Since p3 is const, it can only call const member functions
	
	std::cout << IntPair::getCount() << '\n';

	p1.reset(); // Reset as a method
	p1.print();

	p1.set(4, 4);
	reset(p1); // Reset as a friend function
	p1.print();
}

void testStack()
{
	Stack stack;
	stack.reset();

	stack.print();

	for (int i = 1; i <= 10; ++i)
	{
		stack.push(i);
	}

	stack.print();

	if (!stack.push(11)) std::cout << "Data is full!\n";
	
	int x = stack.pop();
	stack.print();

	stack.push(x);
	stack.print();

	for (int i = 0; i < 10; ++i)
	{
		stack.pop();
		stack.print();
	}

	int y = stack.getSize();
	std::cout << y << "\n";

	//stack.pop(); //This will cause an assert abort
	
}

void calcTest()
{
	Calc calc{};
	calc.add(5).sub(3).mult(4);

	std::cout << calc.getValue() << '\n';
}

void point2dTest()
{
	Point2d first{};
	Point2d second{ 3.0, 4.0 };
	first.print();
	second.print();
	std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';
	std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

}


int main()
{
	Timer t;

	//intPairTest();
	//testStack();
	//calcTest();
	point2dTest();

	std::cout << "Time elapsed: " << t.elapsed() << " seconds\n";
}
