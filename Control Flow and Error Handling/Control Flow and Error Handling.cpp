#include "Calculator.h";

#include <iostream>
#include <string>
#include <limits> // for std::numeric_limits
#include <random>
#include <chrono>

namespace Random // capital R to avoid conflicts with functions named random()
{
    // We created a namespace because we should only seed PRNG Once!
    std::mt19937 mt{ std::random_device{}() };
    std::mt19937 mt2{ static_cast<unsigned int>(
    std::chrono::steady_clock::now().time_since_epoch().count()
    )}; 

    int get1(int min, int max)
    {
        std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
        return die(mt); // and then generate a random number from our global generator
    }

    int get2(int min, int max)
    {
        std::uniform_int_distribution die{ min, max }; // we can create a distribution in any function that needs it
        return die(mt2); // and then generate a random number from our global generator
    }
}

void printDigitName(int x)
{
    // we use break or return to prevent overflow
    switch (x) 
    {
    case 1:
        std::cout << "One";
        break;
    case 2: 
        std::cout << "Two"; 
        break; 
    case 3:
        std::cout << "Three";
        break;
    default:
        std::cout << "Unknown";
        break; 
    }
}

void printChar(char x)
{
    switch (x)
    {
    case 'a':
        std::cout << "Letter A";
        break;
    case 'b':
        std::cout << "Letter B";
        break;
    case 'c':
        std::cout << "Letter C";
        break;
    default:
        std::cout << "Unknown";
        break;
    }
}

/* // The following does not work as type string does not evaluate to an integral type
*  // The same goes for using char x[] instead of string
* 
void printString(std::string x)
{
    switch (x)
    {
    case 'a':
        std::cout << "Letter A";
        break;
    case 'b':
        std::cout << "Letter B";
        break;
    case 'c':
        std::cout << "Letter C";
        break;
    default:
        std::cout << "Unknown";
        break;
    }
}
*/

void fallThroughExample(int x)
{
    switch (x)
    {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]]; // intentional fallthrough -- note the semicolon to indicate the null statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed if x = 2
        break;
    }
}

// Example of case labels stacking, better than chained if-statements 
bool isVowel(char c)
{
    switch (c)
    {
    case 'a': // if c is 'a'
    case 'e': // or if c is 'e'
    case 'i': // or if c is 'i'
    case 'o': // or if c is 'o'
    case 'u': // or if c is 'u'
    case 'A': // or if c is 'A'
    case 'E': // or if c is 'E'
    case 'I': // or if c is 'I'
    case 'O': // or if c is 'O'
    case 'U': // or if c is 'U'
        return true;
    default:
        return false;
    }
}

int calculate(int x, int y, char operation)
{
    switch (operation)
    {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    case '%':
        return x % y;
    default:
        std::cerr << "Invalid Operation\n";
        return -1;
    }
}

void countWithLoop()
{
    int count{ 1 };
    while (count <= 50)
    {
        // print the number (pad numbers under 10 with a leading 0 for formatting purposes)
        if (count < 10)
        {
            std::cout << '0';
        }

        std::cout << count << ' ';

        // if the loop variable is divisible by 10, print a newline
        if (count % 10 == 0)
        {
            std::cout << '\n';
        }

        // increment the loop counter
        ++count;
    }
}

void triangleShape1()
{
    int outer{ 1 };
    while (outer <= 5)
    {
        // loop between 1 and outer
        int inner{ 1 };
        while (inner <= outer)
        {
            std::cout << inner << ' ';
            ++inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    }
}

void triangleShape2()
{
    int outer{ 5 };
    while (outer >= 1)
    {
        int inner{ outer };
        while (inner >= 1)
        {
            std::cout << inner << ' ';
            --inner;
        }

        std::cout << '\n';
        --outer;
    }
}

// My attempt at the question
void triangleShape3()
{
    int i = 1;
    while (i <= 5)
    {
        int j = 5 - i;
        while (j >= 1)
        {
            std::cout << "  ";
            --j;
        }

        int k = i;
        while (k >= 1)
        {
            std::cout << k << ' ';
            --k;
        }

        std::cout << '\n';
        ++i;
    }
}

// Better solution for triangleShape3
void triangleShape4()
{
    int i = 1;
    while (i <= 5)
    {
        int j = 5;
        while (j >= 1)
        {
            if (i < j)
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << j << ' ';
            }

            --j;
        }

        std::cout << '\n';
        ++i;
    }
}

// My Attemp at the question
void printAlphabet1()
{
    int counter = 97;
    while (counter <= 122)
    {
        std::cout << static_cast<char>(counter) << " ASCII: " << counter << '\n';
        ++counter;
    }
}

void printAlphabet2()
{
    char myChar{ 'a' };
    while (myChar <= 'z')
    {
        std::cout << myChar << ' ' << static_cast<int>(myChar) << '\n';
        ++myChar;
    }
}

int pow(int base, int exponent)
{
    int total{ 1 };

    for (int count{ 0 }; count < exponent; ++count)
        total *= base;

    return total;
}

int sumTo(int value)
{
    int total{ 0 };
    for (int count{ 1 }; count <= value; ++count)
        total += count;

    return total;
}

int main()
{
    //double x{ getDouble() };
    //char operation{ getOperator() };
    //double y{ getDouble() };

    //printResult(x, operation, y);
    
    for (int i = 1; i <= 100; ++i)
    {
        std::cout << Random::get1(1, 10) << '\t';
        if (i % 10 == 0) std::cout << '\n';
    }

    return 0;
}