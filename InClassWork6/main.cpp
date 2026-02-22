#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
    // //excercise 2
    // Employee emp;
    // emp.setAge(30);
    // emp.setYearsOfService(5);
    // emp.setSalary(75000.0);

    // cout << "Age: " << emp.getAge() << endl;
    // cout << "Years of Service: " << emp.getYearsOfService() << endl;
    // cout << "Salary: " << emp.getSalary() << endl;

    // //excercise 3
    // Employee e1;
    // e1.setID(1);
    // e1.setAge(30);
    // e1.setYearsOfService(5);
    // e1.setSalary(75000.00);

    // Employee e2;
    // e2.setID(2);
    // e2.setAge(42);
    // e2.setYearsOfService(15);
    // e2.setSalary(95000.00);

    // e1.display();
    // e2.display();

    // //excercise 4
    // Employee e1;
    // e1.setSalary(75000.00);

    // Employee e2;
    // e2.setSalary(75499.00);

    // Employee e3;
    // e3.setSalary(75500.00);

    // cout << e1.getSalaryInThousands() << endl;
    // cout << e2.getSalaryInThousands() << endl;
    // cout << e3.getSalaryInThousands() << endl;

    //excercise 5
    Employee e1;
    e1.setAge(30);
    e1.setYearsOfService(5);
    e1.setSalary(75000.00);
    e1.setID(1);

    Employee e2(30, 5, 75000.00, 2);
    
    cout << e1.getAge() << endl; // output: 30
    cout << e2.getAge() << endl; // output: 30

    e1.display();
    e2.display();
}