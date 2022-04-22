#include <iostream>

bool isEven(int number)
{
    return (number % 2) == 0;
}

void prefixOperatorTest()
{
    int x{ 5 };
    int y = ++x; 
    std::cout << x << ' ' << y;
}

void postfixOperatorTest()
{
    int x{ 5 };
    int y = x++; 
    std::cout << x << ' ' << y;
}

void prefixAndPostfixTest()
{
    int x{ 5 };
    int y{ 5 };
    std::cout << x << ' ' << y << '\n';
    std::cout << ++x << ' ' << --y << '\n'; // prefix
    std::cout << x << ' ' << y << '\n';
    std::cout << x++ << ' ' << y-- << '\n'; // postfix
    std::cout << x << ' ' << y << '\n';
}

// epsilon is an absolute value
bool isAlmostEqual(double a, double b, double epsilon)
{
    // if the distance between a and b is less than epsilon, then a and b are "close enough"
    return std::abs(a - b) <= epsilon;
}

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqual(double a, double b, double epsilon)
{
    return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * epsilon));
}

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff{ std::abs(a - b) };
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
}

int main()
{
    int x = 3;
    if (isEven(x)) std::cout << x << " is even\n";
    else std::cout << x << " is not even\n";
}

