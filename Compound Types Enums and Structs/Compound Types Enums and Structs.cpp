#include "Color.h";
#include "Boss.h";
#include "Employee.h"
#include "Company.h"
#include "Pair.h"

#include <iostream>
#include <string>

void printENUM(Color::Color color)
{
    std::cout << "The object is: " << Color::printColor(color) << '\n';

    // Would've resolved into an Implicit conversion to integral
    // However, we overloaded the operator<< in Color.h
    std::cout << "The object is: " << Color::red << '\n';
}

int main()
{
    // Define a few variables of enumerated type Color
    Color::Color apple{ Color::red };   // my apple is red
    Color::Color shirt{ Color::green }; // my shirt is green
    Color::Color cup{ Color::blue };    // my cup is blue

    printENUM(apple);

    // Boss ENUM, not directly accessible (the :: is for the enum not a namespace)
    // This is better than unscoped, as it cannot be compared to other Enums that resolve to same integral value
    Boss omen{ Boss::margit };

    // Function to convert enum class to integer using operator+
    std::cout << +Boss::margit <<'\n';

    // Instantiating an Employee struct
    Employee::Employee malenia;
    malenia.age = 999;
    malenia.id = 0;
    malenia.wage = 1;

    Employee::Employee yoru{ .id{1}, .age{10}, .wage{1000} };

    Employee::printEmployee(malenia);

    Company::Company eldenFactory{ .numberOfEmployees{2}, .CEO{malenia} };

    Company::Company* eldenPtr{ &eldenFactory };
    Employee::Employee ceo = eldenPtr->CEO; // use -> to select member from pointer to object

    Pair::pair<int> p1{ 5, 6 };        // instantiates pair<int> and creates object p1
    std::cout << p1.first << ' ' << p1.second << '\n';

    Pair::pair<double> p2{ 1.2, 3.4 }; // instantiates pair<double> and creates object p2
    std::cout << p2.first << ' ' << p2.second << '\n';

    std::cout << Pair::max(p2) << " is larger\n"; // call to max<double> using template 
}

