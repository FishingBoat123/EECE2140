#ifndef CAT_H
#define CAT_H

#include <iostream>
using namespace std;

class Cat
{
private:
    int itsAge = 0;
    int itsWeight = 0;
    string itsName = "";

public:
    int GetAge() const;
    int GetWeight() const;
    string GetName() const;

    void SetAge(int age);
    void SetWeight(int weight);
    void SetName(const string& name);

    Cat(); // default constructor
    Cat(int age, int weight, const string& name); // constructor

    void meow();
    void displayInfo();
};

#endif
