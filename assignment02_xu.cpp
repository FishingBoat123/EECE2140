#include <iostream>
using namespace std;

int main() {
// program that asks user for number of elements in a secret sequence
int n;
int choice = 0;
bool quit = false;
string message;

do {
    cout << "1: Run decoder" << endl;
    cout << "2: Help" << endl;
    cout << "3: Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
        
    switch (choice) {
        case 1: 
            cout << "How many numbers are in the secret sequence?" <<endl;
            cin >> n;
            // error message for invalid input
            // if (n <= 0) {
            //         cerr << "Invalid input. Number of elements cannot be negative." << endl;
            //         return 1;
            //     }
            while (n <= 0) {
                cout << "Please enter a positive, non-zero integer for code length: ";
                cin >> n;
            }
                // loop to get each code from user
            for (int i = 0; i < n; i++) {
                int code;
                cout << "Enter a code " << (i + 1) << ": ";
                cin >> code;
                // Convert code to corresponding letter (1=A, 2=B, ..., 26=Z)
                if (1 <= code and code <= 26) {
                    char letter = 'A' + (code - 1); // Convert number to letter
                    message += letter; // Append letter to message
                }
                else {
                message += '?';
                }
            }
            cout << "The secret message is: " << message << endl;
            break;
        
        case 2:
            cout << "Help:" << endl;
            cout << "This program decodes a message based on numerical codes." << endl;
            cout << "You will be prompted to enter the number of elements in the secret sequence." << endl;
            cout << "Then, enter each code" << endl;
            cout << "If an invalid code is entered, it will be represented by '?' in the message." << endl;
            break;

        case 3:
            quit = true;
            break;
            
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
    }
}
while (!quit);
return 0;
}


   