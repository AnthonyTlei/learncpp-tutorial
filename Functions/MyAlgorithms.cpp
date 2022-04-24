#include "MyAlgorithms.h"

int MyAlgorithms::fibonacci(int count, int& counter)
{
    ++counter; // Keep track of how many calls to the function were made

	if (count == 0) return 0;
	if (count == 1) return 1;

	return MyAlgorithms::fibonacci(count - 1, counter) + MyAlgorithms::fibonacci(count - 2, counter);
}

int MyAlgorithms::fibonacciOptimized(int count, int& counter)
{
    ++counter;
    // We'll use a static std::vector to cache calculated results
    static std::vector<int> results{ 0, 1 };

    // If we've already seen this count, then use the cache'd result
    if (count < static_cast<int>(std::size(results)))
        return results[count];
    else
    {
        // Otherwise calculate the new result and add it
        results.push_back(fibonacciOptimized(count - 1, counter) + fibonacciOptimized(count - 2, counter));
        return results[count];
    }
}

int MyAlgorithms::factorial(int count, int& counter)
{
    ++counter;
    if (count == 0 || count == 1) return 1;
    return factorial(count - 1, counter) * count;
}

int MyAlgorithms::factorialOptimized(int count, int& counter)
{
    ++counter;

    static std::vector<int> factorials{ 1, 1 };


    if (count < std::size(factorials)) return factorials[count];
     
    factorials.push_back(factorialOptimized((count - 1), counter) * count);
    return factorials[count];
}

int MyAlgorithms::sumDigits(int x)
{
    if (x < 10)
        return x;
    else
        return sumDigits(x / 10) + x % 10;
}

void MyAlgorithms::printBinary(unsigned int x)
{
    if (x > 1) // we only recurse if n > 1, so this is our termination case for n == 0
    {
        printBinary(x / 2);
    }

    std::cout << x % 2;
}

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int MyAlgorithms::iterativeBinarySearch(const int* array, int target, int min, int max)
{
    assert(array); // make sure array exists

    while (min <= max)
    {
        // implement this iteratively
        int midpoint{ std::midpoint(min, max) };
        // Before C++20
        // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

        if (array[midpoint] > target)
        {
            // if array[midpoint] > target, then we know the number must be in the lower half of the array
            // we can use midpoint - 1 as the upper index, since we don't need to retest the midpoint next iteration
            max = midpoint - 1;
        }
        else if (array[midpoint] < target)
        {
            // if array[midpoint] < target, then we know the number must be in the upper half of the array
            // we can use midpoint + 1 as the lower index, since we don't need to retest the midpoint next iteration
            min = midpoint + 1;
        }
        else
        {
            return midpoint;
        }
    }

    return -1;
}

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int MyAlgorithms::recursiveBinarySearch(const int* array, int target, int min, int max)
{
    assert(array); // make sure array exists

    // implement this recursively

    if (min > max)
        return -1;

    int midpoint{ std::midpoint(min, max) };
    // Before C++20
    // int midpoint{ min + ((max-min) / 2) }; // this way of calculating midpoint avoids overflow

    if (array[midpoint] > target)
    {
        return recursiveBinarySearch(array, target, min, midpoint - 1);
    }
    else if (array[midpoint] < target)
    {
        return recursiveBinarySearch(array, target, midpoint + 1, max);
    }
    else
    {
        return midpoint;
    }
}