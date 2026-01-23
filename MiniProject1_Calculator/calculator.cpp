#include <iostream>
using namespace std;

int main()
{
	double number1 = 0;              
	double number2 = 0;
	int choice = 0;
	bool quit = false;

		do
		{
			double addnum = 0;
			double subnum = 0;
			double mulnum = 0;
			double divnum = 0;
			double modnum = 0;
			
			cout << "Enter your first number: " << endl;
			cin >> number1;

			cout << "Enter your second number: " << endl;
			cin >> number2;

            
			
			cout << "1. Add" << endl;
			cout << "2. Subtract" << endl;
			cout << "3. Multiply" << endl;
			cout << "4. Divide" << endl;
			cout << "5. Modulus (%)" << endl;
			cout << "6. Quit" << endl;
			cin >> choice;

			switch (choice) 
			{
				case 1:
					addnum = number1 + number2;
					cout << number1 << " + " << number2 << " = " << addnum << endl;
					break;
				case 2: 
					subnum = number1 - number2;
					cout << number1 << " - " << number2 << " = " << subnum << endl;
					break;
				case 3: 
					mulnum = number1 * number2;
					cout << number1 << " x " << number2 << " = " << mulnum << endl;
					break;
				case 4:
					divnum = number1 / number2;
					if (number2 == 0) 
					{
					cout << "Error, solution undefined" << endl;
					}
					else
					{
					cout << number1 << " / " << number2 << " = " << divnum << endl;
					}
					break;
				case 5:
					modnum =fmod(number1, number2);
					cout << number1 << " % " << number2 << " = " << modnum << endl;
					break;
				case 6:
					quit = true;
					break;
				default:
					cout << "Invalid option. Please try again" << endl;
					break;
			}

		}
while (!quit);
return 0;
}


