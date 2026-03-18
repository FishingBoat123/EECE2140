#include <iostream>
using namespace std;

class Order
{
    private:
    int tableNumber;
    string serverName;
    int numberPatrons;
    static double minCharge;

    public:
    Order (){}
    Order(int tableNumber, string serverName, int numberPatrons) : tableNumber(tableNumber), serverName(serverName), numberPatrons(numberPatrons) {}

    double charge(int numberPatrons)
    {
        double charge;
        charge = minCharge * numberPatrons;
        return charge;
    }

    void display()
    {
        cout << "Table Number: " << tableNumber;
        cout << "\nServer Name: " << serverName;
        cout << "\nNumber of Patrons: " << numberPatrons;
        cout << "\nCharge: $" << charge(numberPatrons) << endl;
        cout << "$" << minCharge;
    }

};
double Order::minCharge = 4.75;

int main()
{
    Order o1(10, "Smith", 5);
    o1.display();
}