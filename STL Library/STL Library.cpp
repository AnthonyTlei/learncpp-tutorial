#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm> // std::min_element and std::max_element   
#include <numeric> // std::iota

void testIteratorsWithVector()
{
    std::vector<int> vect;
    for (int count = 0; count < 6; ++count)
        vect.push_back(count);

    std::vector<int>::const_iterator it; // declare a read-only iterator
    it = vect.cbegin(); // assign it to the start of the vector
    while (it != vect.cend()) // while it hasn't reached the end
    {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';

}

void testIteratorsWithList()
{
    std::list<int> li;
    for (int count = 0; count < 6; ++count)
        li.push_back(count);

    std::list<int>::const_iterator it; // declare an iterator
    it = li.cbegin(); // assign it to the start of the list
    while (it != li.cend()) // while it hasn't reach the end
    {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

void testIteratorsWithSet()
{
    std::set<int> myset;
    myset.insert(7);
    myset.insert(2);
    myset.insert(-6);
    myset.insert(8);
    myset.insert(1);
    myset.insert(-4);

    std::set<int>::const_iterator it; // declare an iterator
    it = myset.cbegin(); // assign it to the start of the set
    while (it != myset.cend()) // while it hasn't reach the end
    {
        std::cout << *it << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

void testIteratorsWithMap()
{
    std::map<int, std::string> mymap;
    mymap.insert(std::make_pair(4, "apple"));
    mymap.insert(std::make_pair(2, "orange"));
    mymap.insert(std::make_pair(1, "banana"));
    mymap.insert(std::make_pair(3, "grapes"));
    mymap.insert(std::make_pair(6, "mango"));
    mymap.insert(std::make_pair(5, "peach"));

    auto it{ mymap.cbegin() }; // declare a const iterator and assign to start of vector
    while (it != mymap.cend()) // while it hasn't reach the end
    {
        std::cout << it->first << "=" << it->second << " "; // print the value of the element it points to
        ++it; // and iterate to the next element
    }

    std::cout << '\n';
}

void testAlgorithms()
{
    std::list<int> li(6);
    // Fill li with numbers starting at 0.
    std::iota(li.begin(), li.end(), 0);

    for (int i : li) // for loop with iterators
        std::cout << i << ' ';
    std::cout << '\n';

    std::cout << *std::min_element(li.begin(), li.end()) << ' '
        << *std::max_element(li.begin(), li.end()) << '\n';

    // Find the value 3 in the list
    auto it{ std::find(li.begin(), li.end(), 3) };
    if (it == li.end())
    {
        std::cout << "3 was not found\n";
    }
    else
    {
        // Insert 8 right before 3.
        li.insert(it, 8);

        for (int i : li) // for loop with iterators
            std::cout << i << ' ';

        std::cout << '\n';
    }

    std::vector<int> vect{ 7, -3, 6, 2, -5, 0, 4 };

    // sort the vector
    std::sort(vect.begin(), vect.end());

    for (int i : vect)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    // reverse the vector
    std::reverse(vect.begin(), vect.end());

    for (int i : vect)
    {
        std::cout << i << ' ';
    }

    std::cout << '\n';

    
}

int main()
{
    testIteratorsWithVector();
    testIteratorsWithList();
    testIteratorsWithSet();
    testIteratorsWithMap();
    testAlgorithms();
}
