#include <iostream>
using namespace std;

int main() {
    // program that asks user for number of elements in a secret sequence
    int n;
    string message;

    cout << "How many numbers are in the secret sequence?" <<endl;
    cin >> n;
    int code;
    char letter = 'A' + (code - 1);
    message += letter;
    cout << message <<endl;

}