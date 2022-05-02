#include "Shape.h"
#include <iostream>

int main()
{
	std::vector<Shape*> v{
		  new Circle{Point{1, 2, 3}, 7},
		  new Triangle{Point{1, 2, 3}, Point{4, 5, 6}, Point{7, 8, 9}},
		  new Circle{Point{4, 5, 6}, 3}
	};

	for (const auto* element : v) // element will be a Shape*
		std::cout << *element << '\n';

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n';

	for (const auto* element : v)
		delete element;
}

