#include "Resource.h"
#include "AutoPtr.h"
#include "DynamicArray.h"

#include <iostream>
#include <utility> // for std::move
#include <vector>
#include <memory> // for make_unique/shared and unique/shared_ptr

template<class T>
void myswap(T& a, T& b)
{
	T tmp{ std::move(a) }; // invokes move constructor
	a = std::move(b); // invokes move assignment
	b = std::move(tmp); // invokes move assignment
}

AutoPtr<Resource> generateResource()
{
	AutoPtr<Resource> res(new Resource);
	return res; // this return value will invoke the move constructor
}

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int>& arr)
{
	DynamicArray<int> dbl(arr.getLength());
	for (int i = 0; i < arr.getLength(); ++i)
		dbl[i] = arr[i] * 2;

	return dbl;
}

void testAutoPtr()
{
	AutoPtr<Resource> mainres;
	mainres = generateResource(); // this assignment will invoke the move assignment
}

void testDynamicArray()
{
	DynamicArray<int> arr(1000000);

	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i;

	arr = cloneArrayAndDouble(arr);
}

void testSTDMove()
{
	std::vector<std::string> v;
	std::string str = "Knock";

	std::cout << "Copying str\n";
	v.push_back(str); // calls l-value version of push_back, which copies str into the array element

	std::cout << "str: " << str << '\n';
	std::cout << "vector: " << v[0] << '\n';

	std::cout << "\nMoving str\n";

	v.push_back(std::move(str)); // calls r-value version of push_back, which moves str into the array element

	std::cout << "str: " << str << '\n';
	std::cout << "vector:" << v[0] << ' ' << v[1] << '\n';
}

void testUniquePointer()
{
	auto ptr{ std::make_unique<Resource>() };

	useResource(ptr.get()); // note: get() used here to get a pointer to the Resource

	std::cout << "Ending program\n";
}

void testSharedPointer()
{
	// allocate a Resource object and have it owned by std::shared_ptr
	std::shared_ptr<Resource> ptr1{ std::make_shared<Resource>()};

	// New block to demonstrare lifecycle of resources owned by shared ptrs
	{
		std::shared_ptr<Resource> ptr2{ ptr1 }; // make another std::shared_ptr pointing to the same thing
		// Note that we created ptr2 from ptr1 and not res (to 'link' them together)

		std::cout << "Killing one shared pointer\n";
	} // ptr2 goes out of scope here, but nothing happens

	std::cout << "Killing another shared pointer\n";

}

void testWeakPointer()
{
	auto ptr1{ std::make_shared<WeakResource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it
}

int main()
{
	
}
