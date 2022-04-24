#include "MyAlgorithms.h"

#include <iostream>
#include <array>
#include <string_view>
#include <functional>

void testFibonnaci()
{
    int counter{ 0 };
    int number{ 0 };

    std::cout << "Enter numbers to print: ";
    std::cin >> number;

    std::cout << "Fibonacci sequence (-Memoization): \n";
    for (int i = 0; i < number; ++i)
    {
        std::cout << MyAlgorithms::fibonacci(i, counter) << ' ';
    }
    std::cout << '\n';
    std::cout << "Function calls: " << counter << '\n';

    counter = 0;

    std::cout << "Fibonacci sequence (+Memoization): \n";
    for (int i = 0; i < number; ++i)
    {
        std::cout << MyAlgorithms::fibonacciOptimized(i, counter) << ' ';
    }
    std::cout << '\n';
    std::cout << "Function calls: " << counter << '\n';
}

void testFactorial()
{
    int number{ 0 };
    int counter{ 0 };

    std::cout << "Enter numbers to print: ";
    std::cin >> number;

    std::cout << "Factorial sequence (-Memoization): \n";
    for (int i = 0; i < number; ++i)
    {
        std::cout << MyAlgorithms::factorial(i, counter) << ' ';
    }
    std::cout << '\n';
    std::cout << "Function calls: " << counter << '\n';

    counter = 0;

    std::cout << "Factorial sequence (+Memoization): \n";
    for (int i = 0; i < number; ++i)
    {
        std::cout << MyAlgorithms::factorialOptimized(i, counter) << ' ';
    }
    std::cout << '\n';
    std::cout << "Function calls: " << counter << '\n';

}

void testSumDigits()
{
    int number{ 0 };

    std::cout << "Enter int to sum digits: ";
    std::cin >> number;

    std::cout << MyAlgorithms::sumDigits(number) << '\n';
}

void testToBinary()
{
    int x{};
    std::cout << "Enter a decimal number: ";
    std::cin >> x;
    std::cout << '\n';

    MyAlgorithms::printBinary(x);
}

void repeat(int repetitions, const std::function<void(int)>& fn)
{
    for (int i{ 0 }; i < repetitions; ++i)
    {
        fn(i);
    }
}


int main(int argc, char* argv[])
{
    //testFibonnaci();
    //testFactorial();
    //testSumDigits();
    //testToBinary();

    std::cout << "There are " << argc << " arguments:\n";

    // Loop through each argument and print its number and value
    for (int count{ 0 }; count < argc; ++count)
    {
        std::cout << count << ' ' << argv[count] << '\n';
    }


    // Lambdas
    repeat(3, [](int i) {
        std::cout << i << '\n';
        });


    // Capture clause (lambdas dont have access to all surrounding variables by default, so we capture them)

    std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    // Capture @search                                vvvvvv
    auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
      return (str.find(search) != std::string_view::npos);
    }) };

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
    // use "=" to capture all variables mentioned in the lambda

}

