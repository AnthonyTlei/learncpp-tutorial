#include "FixedArray.h";

namespace FixedArray 
{

	// In C++ Arrays are not passed by value, the actual array is passed by address (pointer)
	void passArray(int* a, int size) // prime is the actual array
	{

		for(int i=0; i < size; ++i)
		{
			int temp{};
			std::cout << "Enter number " << i+1 << ": ";
			std::cin >> temp;
			std::cout << '\n';

			if (std::cin.fail()) // has a previous extraction failed or overflowed?
			{
				std::cout << "Invalid number!\n";
				// yep, so let's handle the failure
				std::cin.clear(); // put us back in 'normal' operation mode
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
				break;
			}

			a[i] = temp;

		}
	}

	void printArray(int* a, int size)
	{
		for (int i{ 0 }; i < size; ++i)
		{
			std::cout << a[i] << ' ';
		}
		std::cout << '\n';
	}

	void sortArray(int* a, int size)
	{
		std::cout << "Sorting the Array ...\n";
		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = i+1; j < size; ++j)
			{
				if (a[j] < a[i]) 
				{
					std::swap(a[j], a[i]);
				}
			}
		}
	}

	void sortArrayDesc(int* a, int size)
	{
		std::cout << "Sorting the Array (Descending) ...\n";
		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				if (a[j] > a[i])
				{
					std::swap(a[j], a[i]);
				}
			}
		}
	}

	void bubbleSort(int* a, int size)
	{
		std::cout << "Sorting the Array ...\n";
		for (int i = 0; i < size-1; ++i)
		{
			for (int j = 0; j < size-1; ++j)
			{
				if (a[j] > a[j + 1]) std::swap(a[j], a[j + 1]);
			}
		}

		if (a[0] > a[1]) std::swap(a[0], a[1]);
		
	}

	void optimizedBubbleSort(int* a, int size)
	{
		std::cout << "Sorting the Array ...\n";
		for (int iteration{ 0 }; iteration < size - 1; ++iteration)
		{
			// Account for the fact that the last element is already sorted with each subsequent iteration
			// so our array "ends" one element sooner
			int endOfArrayIndex{ size - iteration };

			bool swapped{ false }; // Keep track of whether any elements were swapped this iteration

			// Search through all elements up to the end of the array - 1
			// The last element has no pair to compare against
			for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
			{
				// If the current element is larger than the element after it
				if (a[currentIndex] > a[currentIndex + 1])
				{
					// Swap them
					std::swap(a[currentIndex], a[currentIndex + 1]);
					swapped = true;
				}
			}

			// If we haven't swapped any elements this iteration, we're done early
			if (!swapped)
			{
				// iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
				std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
				break;
			}
		}
	}

	int* find(int* begin, int* end, int value)
	{
		while (begin < end)
		{
			if (*begin == value) return begin;
			++begin;
		}
		return begin;
	}


}
