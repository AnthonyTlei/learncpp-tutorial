#include "FixedArray.h"

#include <iostream>
#include <string_view>
#include <algorithm>
#include <array>
#include <vector>


bool verifyCin()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

void fixedArrayTest()
{
    FixedArray::FixedArray5 myArray;
    FixedArray::printArray(myArray.data, 5);
    FixedArray::passArray(myArray.data, 5); // This will change the actual array
    FixedArray::printArray(myArray.data, 5);

    std::cout << "The array has: " << std::size(myArray.data) << " elements\n";

    FixedArray::sortArray(myArray.data, 5);
    FixedArray::printArray(myArray.data, 5);

    FixedArray::sortArrayDesc(myArray.data, 5);
    FixedArray::printArray(myArray.data, 5);

    //FixedArray::bubbleSort(myArray.data, 5);
    //FixedArray::printArray(myArray.data, 5);

    FixedArray::optimizedBubbleSort(myArray.data, 5);
    FixedArray::printArray(myArray.data, 5);
}

void stringViewTest()
{
    std::string_view text{ "hello" }; // view the text "hello", which is stored in the binary
    std::string_view str{ text }; // view of the same "hello" (not a copy)
    std::string_view more{ str }; // view of the same "hello" (not a copy)

    // Ignore the first character.
    str.remove_prefix(1);

    std::cout << str << '\n';

    // Ignore the last 2 characters.
    str.remove_suffix(2);

    std::cout << str << '\n';

    std::cout << text << ' ' << str << ' ' << more << '\n';
}

void arraysAndPointers()
{
    int array[5]{ 9, 7, 5, 3, 1 };

    // Deferencing an array returns the first element (element 0)
    std::cout << *array; // will print 9!

    char name[]{ "Jason" }; // C-style string (also an array)
    std::cout << *name << '\n'; // will print 'J'
}

void findTest()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ FixedArray::find(std::begin(arr), std::end(arr), 4) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }
}

template<typename T>
void printArray(T* a, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << a[i] << ' ';
    }
    std::cout << '\n';
}

void dynamicArrayExercise()
{
    int count{};
    std::cout << "How many names do u need? ";
    std::cin >> count;
    std::cout << '\n';

    if (!verifyCin())
    {
        std::cout << "Invalid input!\n";
        return;
    }

    std::string* list{ new std::string[count]{} };

    for (int i = 0; i < count; ++i)
    {
        std::string name{};
        std::cout << "Enter name " << i+1 << ": ";
        std::cin >> name;
        if (!verifyCin()) 
        {
            std::cout << "Invalid input!\n";
            return;
        }

        list[i] = name;
    }

    std::sort(list, list+count);
    printArray(list, count);

    // don't forget to use array delete
    delete[] list;
    // we don't need to set names to nullptr/0 here because it's going to go out
    // of scope immediately after this anyway.
}

// printArray is a template function
template <typename T, std::size_t size> // parameterize the element type and size
void printArray(const std::array<T, size>& myArray)
{
    for (auto element : myArray)
        std::cout << element << ' ';
    std::cout << '\n';
}


int main()
{
    
    
    
}

