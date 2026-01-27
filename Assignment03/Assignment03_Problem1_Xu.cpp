#include <iostream>
using namespace std;

// int main() 
//{
//     double a = 9.2;
//     double answer = 0;

//     answer = a*a*a*a; // a to the power of 4
//     cout << a << "^4 = " << answer << endl;

//     return 0;
// }

// int main() 
// {
//     double x = 0;
//     double y = 0;
//     cout << "Enter number for x: ";
//     cin >> x;
//     cout << "Enter number for y: ";
//     cin >> y;

//     double answer = 0;
//     answer = sqrt(5*x-3*x*y);
//     cout << "The square root of 5x-3xy is: " << answer << endl;

//     return 0;
// }

// int main()
// {
//     double a = 0;
//     double b = 0;
//     cout << "Enter number for a: ";
//     cin >> a;
//     cout << "Enter number for b: ";
//     cin >> b;

//     double answer = 0;
//     answer = cbrt(a+b);
//     cout << "The cube root of a + b is: " << answer << endl;
    
//     return 0;
// }

// int main()
// {
//     double b = 0;
//     double a = 0;
//     double c = 0;
//     cout << "Enter number for a: ";
//     cin >> a;
//     cout << "Enter number for b: ";
//     cin >> b;
//     cout << "Enter number for c: ";
//     cin >> c;

//     double answer = 0;
//     answer = (-b + sqrt(b*b - 4*a*c)) / (2*a);
//     cout << "The solution to (-b+sqrt(b*b-4*a*c))/(2a) is: " << answer << endl;
    
//     return 0;
// }

int main()
{
    double x = 0;
    double y = 0;
    cout << "Enter number for x: ";
    cin >> x;
    cout << "Enter number for y: ";
    cin >> y;

    double answer = 0;
    answer = abs(3*x*x-2*y);
    cout << "The absolute value of 3x^2-2y is: " << answer << endl;
    
    return 0;
}