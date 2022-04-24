#ifndef FIXEDARRAY_H
#define FIXEDARRAY_H

#include <iostream>

namespace FixedArray
{
	// param: int* a is equivalent to int a[] as its passed by address
	void passArray(int* a, int size);

	void printArray(int* a, int size);

	// My attempt at selection sort
	void sortArray(int* a, int size);

	// My Attempt at descending selection sort
	void sortArrayDesc(int* a, int size);

	// My Attempt at bubble sort 
	void bubbleSort(int* a, int size);

	void optimizedBubbleSort(int* a, int size);

	// My attempt at find()
	int* find(int* begin, int* end, int value);


	struct FixedArray5
	{
		int data[5]{};
	};

	/* Note 
	
	If we created the function as to take the WHOLE struct instead of the data member,
	the array "data" will not decay into a pointer
	
	*/
}

#endif