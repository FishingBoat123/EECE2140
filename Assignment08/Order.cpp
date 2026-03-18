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
    void display()
    {
        cout << "$" << minCharge;
    }

};
double Order::minCharge = 4.75;

int main()
{
    Order o1;
    o1.display();
}