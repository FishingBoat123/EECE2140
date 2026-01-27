#include <iostream>
#include <cmath>
using namespace std;    

int main()
{
    double number1 = 0;
    double number2 = 0;
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter the second number: ";
    cin >> number2; 
    
    double answer = 0;
    answer = pow(number1, number2) + pow(number2, number1);
    cout << "the first number to the power of the second number plus the second number to the power of the first number is: " << answer << endl;

    return 0;
}