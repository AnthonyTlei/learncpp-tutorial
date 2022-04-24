#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <string_view> // C++17 (Return string literals efficiently)

namespace Color
{
    // Define a new unscoped enumeration named Color
    enum Color
    {
        // Here are the enumerators
        // These symbolic constants define all the possible values this type can hold
        // Each enumerator is separated by a comma, not a semicolon
        red, // assigned to 0
        green, // assigned to 1
        blue, // assigned to 2 
        // trailing comma optional but recommended
    }; // the enum definition must end with a semicolon



    // Teach std::cout how to print a Color
    // Consider this magic for now since we haven't explained any of the concepts it uses yet
    // std::ostream is the type of std::cout
    // The return type and parameter type are references (to prevent copies from being made)!
    std::ostream& operator<<(std::ostream& out, Color color)
    {
        switch (color)
        {
        case red: out << "red";  break;
        case green:   out << "green";    break;
        case blue:  out << "blue";   break;
        default:    out << "???";    break;
        }

        return out;
    }


    std::string_view printColor(Color color)
    {
        switch (color)
        {
        case Color::red:
            return "red";
        case Color::green:
            return "green";
        case Color::blue:
            return "blue";
        default:
            return "Invalid";
        }
    }

}


#endif