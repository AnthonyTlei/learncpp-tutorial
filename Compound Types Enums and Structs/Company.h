#ifndef COMPANY_H
#define COMPANY_H

#include "Employee.h";

namespace Company 
{

    struct Company
    {
        int numberOfEmployees{};
        Employee::Employee CEO{}; // Employee is a struct within the Company struct
    };

}

#endif
