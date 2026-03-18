#include <iostream>
using namespace std;

class Dog
{
    private:
    string name;
    string breed;
    int age;
    static double licenseFee;

    public:
    Dog(){}

    void setName(string name){this->name = name;}
    void setBreed(string breed){this->breed = breed;}
    void setAge(int age){this->age = age;}

    void display()
    {
        cout << "\n===== Dog Information =====";
        cout << "\nName: " << name;
        cout << "\nBreed: " << breed;
        cout << "\nAge: " << age;
        cout << "\nLicense Fee: $" << licenseFee;
    }
    
};

double Dog::licenseFee = 10.25;

int main()
{
    Dog d1;
    d1.setName("Bill");
    d1.setBreed("dog Breed");
    d1.setAge(11);

    d1.display();
}