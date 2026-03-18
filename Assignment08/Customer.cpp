#include <iostream>
using namespace std;

class Customer
{
    private:
    int customerID;
    string lastName;
    string firstName;
    double creditLimit;

    public:

    Customer(){};
    Customer(int customerID, string lastName, string firstName, double creditLimit) : customerID(customerID), lastName(lastName), firstName(firstName) {setCreditLimit(creditLimit);};
    
    void setCustomerID(int customerID){this->customerID = customerID;}
    void setLastName(string lastName){this->lastName = lastName;}
    void setFirstName(string firstName){this->firstName = firstName;}
    void setCreditLimit(double creditLimit)
    {
        if (creditLimit <= 10000 && creditLimit >= 0)
        {
            this->creditLimit = creditLimit;
        }
        else
        {
            cout << "\nError, credit limit cannot be a negative number or exceed 10,000" << endl;
        }
    }

    int getCustomerID(){return customerID;}
    string getLastName(){return lastName;}
    string getFirstName(){return firstName;}
    double getCreditLimit(){return creditLimit;}



    void display()
    {
        cout << "\n===== Customer Data =====";
        cout << "\nCustomer ID: " << getCustomerID();
        cout << "\nLast Name: " << getLastName();
        cout << "\nFirst Name: " << getFirstName();
        cout << "\nCredit Limit: " << getCreditLimit();
    }
};

int main()
{
    Customer c1(10001, "Smith", "John", 90000);
    c1.display();
}