#ifndef MYALGORITHMS_H
#define MYALGORITHMS_H

#include <iostream>
#include <vector>
#include <cassert>
#include <numeric> // for std::midpoint

namespace MyAlgorithms
{
	int fibonacci(int count, int& counter);
	int fibonacciOptimized(int count, int& counter);
	int factorial(int count, int& counter);
	int factorialOptimized(int count, int& counter);
	int sumDigits(int x);
	void printBinary(unsigned int x);
	int iterativeBinarySearch(const int* array, int target, int min, int max);
	int recursiveBinarySearch(const int* array, int target, int min, int max);
}

#endif