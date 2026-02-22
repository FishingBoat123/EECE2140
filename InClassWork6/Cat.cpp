#include "Cat.h"

int Cat::GetAge() const
{
    return itsAge;
}

int Cat::GetWeight() const
{
    return itsWeight;
}

string Cat::GetName() const
{
    return itsName;
}

void Cat::SetAge(int age) 
{
    if (age > 0)
        itsAge = age;
    else
        cout << "Age must be positive." << endl;
}

void Cat::SetWeight(int weight) 
{
    if (weight > 0)
        itsWeight = weight;
    else
        cout << "Weight must be positive." << endl;
}

void Cat::SetName(const string& name) 
{
    if (!name.empty())
        itsName = name;
    else
        cout << "Name cannot be empty." << endl;
}

Cat::Cat() {} // default constructor

Cat::Cat(int age, int weight, const string& name) // constructor
{
    SetAge(age);
    SetWeight(weight);
    SetName(name);
}

void Cat::meow() 
{
    cout << GetName() << " Meow!" << endl;
}

void Cat::displayInfo()
{
    cout << "Cat Name: " << GetName() << endl;
    cout << "Age: " << GetAge() << " years" << endl;
    cout << "Weight: " << GetWeight() << " kg" << endl;
}
