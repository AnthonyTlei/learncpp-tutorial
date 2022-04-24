#ifndef EMPLOYEE_H
#define EMPLOYEE_H

namespace Employee 
{

    struct Employee
    {
        int id{ 0 };
        int age{ 0 };
        double wage{ 0 };
    };

    void printEmployee(const Employee& employee) // note pass by reference here
    {
        std::cout << "ID:   " << employee.id << '\n';
        std::cout << "Age:  " << employee.age << '\n';
        std::cout << "Wage: " << employee.wage << '\n';
    }

    Employee getDefaultEmployee()
    {
        // We already specified the type at the function declaration
        // so we don't need to do so here again
        // We can use empty curly braces to value-initialize all members
        return { }; // return an unnamed Employee
    }
}

#endif
