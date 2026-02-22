#include "Employee.h"

//excercise 2
int Employee::getAge() const {
    return itsAge;
}

int Employee::getYearsOfService() const {
    return itsYearsOfService;
}

double Employee::getSalary() const {
    return itsSalary;
}

int Employee::getID() const {
    return id;
}

int Employee::setAge(int age) {
    if (age > 0)
        itsAge = age;
    else 
        cout << "Age must be positive." << endl;
}

int Employee::setYearsOfService(int yearsOfService) {
    if (yearsOfService >= 0)
        itsYearsOfService = yearsOfService;
    else
        cout << "Years of service must be non-negative." << endl;
}

double Employee::setSalary(double salary) {
    if (salary >= 0)
        itsSalary = salary;
    else
        cout << "Salary must be non-negative." << endl;
}

int Employee::setID(int i) {
    if (i > 0)
        id = i;
    else
        cout << "ID must be positive." << endl;
}

//excercise 2
Employee::Employee() {} // default constructor

//excercise 5
Employee::Employee(int a, int y, double s, int i) { // parameterized constructor
    setAge(a);
    setYearsOfService(y);
    setSalary(s);
    setID(i);
}

//excercise 3
void Employee::display() // display
{
    cout << "\nEmployee " << getID() << ":" << endl;
    cout << "Age: " << getAge() << " years" << endl;
    cout << "Years of Service: " << getYearsOfService() << " years" << endl;
    cout << "Salary: $" << getSalary() << endl;
}
 //excercise 4
int Employee::getSalaryInThousands() const {
    return static_cast<int>((getSalary() + 500) / 1000); // rounding
}
