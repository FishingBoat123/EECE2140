#include <iostream>
using namespace std;

int main()
{
    double number1 = 0;
    double number2 = 0;
    double number3 = 0;
    cout << "Enter number for a: ";
    cin >> number1;
    cout << "Enter number for b: ";
    cin >> number2;
    cout << "Enter number for c: ";
    cin >> number3;

    if (floor(number1 * number2) == floor(number3))
    {
        cout << "True" << endl;
        return 0;
    }
    else
    {
        cout << "False" << endl;
        return 0;
    }
}