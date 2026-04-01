#include <iostream>
#include <limits>
using namespace std;

class ArrayHandler {
private:
    int arr[7];
    int input;
    int counter;
    static int totalArrays;

public:
    // Constructor
    ArrayHandler() : input(0), counter(0) {
        for (int i = 0; i < 7; i++) arr[i] = 0;
        totalArrays++;
    }

    // --- Setters ---
    void setInput(int val)         { input = val; }
    void setElement(int i, int val){ if (i >= 0 && i < 7) arr[i] = val; }
    void setCounter(int val)       { counter = val; }

    // --- Getters (const) ---
    int getInput()              const { return input; }
    int getElement(int i)       const { return (i >= 0 && i < 7) ? arr[i] : -1; }
    int getCounter()            const { return counter; }
    static int getTotalArrays()       { return totalArrays; }

    // --- Core Methods ---

    // Fills the array with validated user input
    void setArray() {
        cout << "\nEnter 7 integer values:\n";
        for (int i = 0; i < 7; i++) {
            cout << "  Value [" << i << "]: ";

            // Edge case: wrong data type
            while (!(cin >> input)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "  Error: invalid input. Integers only. Re-enter value [" << i << "]: ";
            }
            arr[i] = input;
            counter++;
        }

        // Edge case: oversized input — consume and report any extra values on the line
        // (catches cases like "1 2 3 4 5 6 7 8 9" pasted at once)
        if (cin.peek() != '\n' && cin.peek() != EOF) {
            cout << "\n  Warning: extra values detected beyond index 6. Rejected values: ";
            int extra;
            int extraIndex = 7;
            while (cin.peek() != '\n' && cin.peek() != EOF && cin >> extra) {
                cout << extra << " (index " << extraIndex++ << ")  ";
            }
            cout << "\n  Only the first 7 values have been stored.\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Prints all elements in order
    void displayArray() const {
        cout << "\nArray contents:\n  [ ";
        for (int i = 0; i < 7; i++) {
            cout << arr[i];
            if (i < 6) cout << ", ";
        }
        cout << " ]\n";
    }

    // Reverses the array in-place using a temp variable (swap up to index < 4)
    void reverseArray() {
        int temp;
        for (int i = 0; i < 4; i++) {
            int newPos = 6 - i;   // mirror index (7 - 1 - i, matching pseudocode intent)
            temp        = arr[i];
            arr[i]      = arr[newPos];
            arr[newPos] = temp;
        }
    }

};

// Static member definition
int ArrayHandler::totalArrays = 0;

// ---------------------------------------------------------------
int main() {
    char again = 'y';

    while (again == 'y' || again == 'Y') {
        ArrayHandler handler;

        cout << "=== Array Handler (Array #" << ArrayHandler::getTotalArrays() << ") ===";
        handler.setArray();

        cout << "\nOriginal:";
        handler.displayArray();

        handler.reverseArray();
        cout << "Reversed:";
        handler.displayArray();

        cout << "\nTotal arrays created this session: "
        << ArrayHandler::getTotalArrays() << "\n";

        cout << "\nCreate another array? (y/n): ";
        cin >> again;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }


    return 0;
}