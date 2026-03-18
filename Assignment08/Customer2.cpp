#include <iostream>
#include <string>
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

    int const getCustomerID(){return customerID;}
    string const getLastName(){return lastName;}
    string const getFirstName(){return firstName;}
    double const getCreditLimit(){return creditLimit;}



    void display()
    {
        cout << "\n===== Customer Data =====";
        cout << "\nCustomer ID: " << getCustomerID();
        cout << "\nLast Name: " << getLastName();
        cout << "\nFirst Name: " << getFirstName();
        cout << "\nCredit Limit: " << getCreditLimit() << endl;
    }
};

int main()
{
    Customer customers[5];

    for(int i = 0; i < 5; i++)
    {
        int customerID;
        string lastName;
        string firstName;
        double creditLimit;

        cout << "\n===== Customer Info Input. " << "Customer: " << i+1 << " =====";
        cout << "\nCustomer ID: ";
        cin >> customerID;
        cout << "Last Name: ";
        cin >> lastName;
        cout << "First Name: ";
        cin >> firstName;
        cout << "Credit Limit: ";
        cin >> creditLimit;
        
        customers[i].setCustomerID(customerID);
        customers[i].setLastName(lastName);
        customers[i].setFirstName(firstName);
        customers[i].setCreditLimit(creditLimit);
    }

    for (int i = 0; i < 5; i++)
    {
        customers[i].display();
    }
}