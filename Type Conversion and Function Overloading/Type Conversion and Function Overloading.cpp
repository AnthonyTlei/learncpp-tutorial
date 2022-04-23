#include <iostream>

void printInt(int x)
{
    std::cout << x <<'\n';
}

void printFloating(double x)
{
    std::cout << x << '\n';
}

void integralPromotionTest()
{
    printInt(2);

    short s{ 3 }; // there is no short literal suffix, so we'll use a variable for this one
    printInt(s); // numeric promotion of short to int

    printInt('a'); // numeric promotion of char to int
    printInt(true); // numeric promotion of bool to int
}

void floatingPromotionTest()
{
    printFloating(3.5f); // float 3.5
    printFloating(3.5); // double 3.5
}

/* Function overloading example */
int add(int x, int y) // integer version
{
    return x + y;
}

double add(double x, double y) // floating point version
{
    return x + y;
}

/* Template Example */
template <typename T> // this is the template parameter declaration
T max(T x, T y) // this is the function template definition for max<T>
{
    return (x > y) ? x : y;
}

template <typename T, typename U> // We're using two template type parameters named T and U
auto max(T x, U y) // x can resolve to type T, and y can resolve to type U
{
    return (x > y) ? x : y; // uh oh, we have a narrowing conversion problem here
}

/* The above function can be abbreviated in C++20 to:

auto max(auto x, auto y)
{
    return (x > y) ? x : y;
}

*/

int main()
{
    std::cout << max(2, 3.2) << std::endl;
}