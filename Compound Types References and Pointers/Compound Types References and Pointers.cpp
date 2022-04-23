#include <iostream>
#include <string>
#include <typeinfo>

void printByValue(std::string val) // The function parameter is a copy of str
{
    std::cout << val << '\n'; // print the value via the copy
}

void printByReference(const std::string& ref) // The function parameter is a reference that binds to str
{
    std::cout << ref << '\n'; // print the value via the reference
}

void printByAddress(const std::string* ptr) // The function parameter is a pointer that holds the address of str
{
    std::cout << *ptr << '\n'; // print the value via the dereferenced pointer
}


void addOne(int& y) // y is bound to the actual object x
{
    ++y; // this modifies the actual object x
}

void printMemoryAddress(const int& x)
{
    // Pointer to an integer (made const because x is const)
    const int* xPtr = &x;
    std::cout << "Variable has address: " << xPtr << " with value: " << *xPtr << '\n';
    // xPtr == *(&x) print the value at the memory address of variable x 
}

// Function to increment a variable by passing its pointer (the pointer is passed by ref)
void incrementByOne(int* ptr)
{
    ++* ptr;
}

void printType()
{
    int x{ 4 };
    std::cout << typeid(&x).name() << '\n'; // print the type of &x
}

void nullify(int*& ptr2)
{
    ptr2 = nullptr; // Make the function parameter a null pointer
}

// Takes two std::string objects, returns the one that comes first alphabetically (by ref)
const std::string& firstAlphabetical(const std::string& a, const std::string& b)
{
    return (a < b) ? a : b; // We can use operator< on std::string to determine which comes first alphabetically
}

int main()
{
    std::string x{ "Hello, world!" }; // x is a std::string
    const std::string y{ "Hello, world!" }; // x is a std::string
    int counter{ 0 };

    for (size_t i = 0; i < 5; i++)
    {
        addOne(counter);
        std::cout << counter << ' ';
    }
    std::cout << '\n';

    printMemoryAddress(counter);

    int* counterPtr = &counter;
    incrementByOne(counterPtr);
    printMemoryAddress(counter);

    printType();


}
