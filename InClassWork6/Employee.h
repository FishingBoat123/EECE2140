#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
using namespace std;

class Employee 
{
private: // excercise 2
    int itsAge = 0;
    int itsYearsOfService = 0;
    double itsSalary = 0;
    int id = 1;

public: // excercise 1
    // excercise 2
    int getAge() const;
    int getYearsOfService() const;
    double getSalary() const;
    int getID() const;
    //excercise 2
    int setAge(int age);
    int setYearsOfService(int yearsOfService);
    double setSalary(double salary);
    int setID(int i);

    //excercise 4
    Employee(); // default constructor
    Employee(int a, int y, double s, int i); // parameterized constructor

    //excercise 3
    void display(); // display

    //excercise 3
    int getSalaryInThousands() const;
};

#endif