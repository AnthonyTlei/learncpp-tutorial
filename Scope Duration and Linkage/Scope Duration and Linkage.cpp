#include <iostream>
#include "Constants.h";

void correctComparison()
{
    int smaller{};
    int larger{};
    std::cout << "Enter an integer: ";
    std::cin >> smaller;
    std::cout << "\n";
    std::cout << "Enter a larger integer: ";
    std::cin >> larger;
    std::cout << "\n";

    if (larger < smaller)
    {
        std::cout << "Swapping values...\n";
        int temp = larger;
        larger = smaller;
        smaller = temp;
    }

    std::cout << "The smaller value is: " << smaller <<"\n";
    std::cout << "The larger value is: " << larger << "\n";
}

int generateID()
{
    static int s_itemID{ 0 };
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

// Uses abbreviated function template (C++20) and `auto` return type to make this function work with any type of value
// See 'related content' box below for more info (you don't need to know how these work to use this function)
// consteval is available only in C++20 and above
// This is a helper function that forces other functions to run at compile-time instead of run-time
consteval auto compileTime(auto value)
{
    return value;
}

constexpr int greater(int x, int y) // function is constexpr
{
    return (x > y ? x : y);
}

int main()
{
    correctComparison();

    std::cout << greater(5, 6);              // may or may not execute at compile-time
    std::cout << compileTime(greater(5, 6)); // will execute at compile-time

    int x{ 5 };
    std::cout << greater(x, 6);              // we can still call the constexpr version at runtime if we wish

    std::cout << "\n";

    std::cout << "How many students are in your class? ";
    int students{};
    std::cin >> students;


    if (students > constants::max_class_size)
        std::cout << "There are too many students in this class";
    else
        std::cout << "This class isn't too large";

}

