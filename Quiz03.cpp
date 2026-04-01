#include <iostream>
#include <sstream>
#include <stdexcept>
using namespace std;

// ─────────────────────────────────────────────
// Block 1: Library inclusions and namespace
// Imports I/O, string stream parsing, and
// exception handling. Declares std namespace.
// ─────────────────────────────────────────────

// Block 2: Class definition and private members
// Declares the ArrayProcessor class. Private
// members store array size, the dynamic array
// pointer, even count, and the max value.
class ArrayProcessor {

private:
    int  arrSize;
    int* arr;
    int  countEven;
    int  arrMax;

public:

    // Block 3: Constructor
    // Initialises all private members to zero/
    // null via this-> to make default state explicit.
    ArrayProcessor() {
        this->arrSize   = 0;
        this->arr       = nullptr;
        this->countEven = 0;
        this->arrMax    = 0;
    }

    // Block 4: Destructor
    // Frees the heap-allocated array with delete[]
    // and nullifies the pointer to prevent dangling references.
    ~ArrayProcessor() {
        delete[] this->arr;
        this->arr = nullptr;
    }

    // Block 5: Getters
    // Returns the value of each private member
    // to allow read-only access from outside the class.
    int  getArrSize()   const { return this->arrSize;   }
    int* getArr()       const { return this->arr;       }
    int  getCountEven() const { return this->countEven; }
    int  getArrMax()    const { return this->arrMax;    }

    // Block 6: Setters
    // Validates and assigns each private member.
    // setArrSize throws if size <= 0 (edge case guard).
    // setArr safely replaces the existing array pointer.
    void setArrSize(int size) {
        if (size <= 0) {
            throw invalid_argument("Error: please input a valid array size (must be > 0).");
        }
        this->arrSize = size;
    }

    void setArr(int* newArr) {
        delete[] this->arr;
        this->arr = newArr;
    }

    void setCountEven(int c) { this->countEven = c; }
    void setArrMax(int m)    { this->arrMax    = m; }

    // ══════════════════════════════════════════
    //  setArray()
    // ══════════════════════════════════════════
    void setArray() {

        // Block 7: Array size input and validation
        // Reads the desired array size from the user.
        // Passes it through setArrSize() which throws
        // on invalid input, printing the error and aborting.
        int size = 0;
        cout << "Enter the size of the array: ";
        cin  >> size;
        cin.ignore();

        try {
            setArrSize(size);
        } catch (const invalid_argument& e) {
            cout << e.what() << "\n";
            return;
        }

        // Block 8: Dynamic memory allocation
        // Allocates an integer array of arrSize elements
        // on the heap and assigns it to the arr pointer.
        this->arr = new int[this->arrSize];

        cout << "Enter " << this->arrSize << " integer value(s).\n"
             << "  Tip: you may enter all values at once on any prompt\n"
             << "  (e.g. 1 2 3  or  [1, 2, 3]) and the rest will autofill.\n\n";

        // Block 10: Per-index prompt loop with lookahead buffer
        // Prompts for each index individually. Each line the user
        // types is stripped of brackets/commas and fed into a
        // string stream. If the line holds multiple tokens, they
        // are drained into a buffer so subsequent prompts can
        // consume them without requiring further user input.
        istringstream pending;   // holds any leftover tokens from a multi-value line
        int filled = 0;

        while (filled < this->arrSize) {
            int token;

            // Try to pull the next value from the lookahead buffer first
            if (pending >> token) {
                *(this->arr + filled) = token;
                filled++;
                continue;
            }

            // Buffer empty — show the prompt and read a new line
            cout << "  arr[" << filled << "]: ";
            string line;
            getline(cin, line);

            // Block 11: Bracket and comma stripping
            // Replaces '[', ']', and ',' with spaces so the
            // string stream tokenises cleanly for any input style.
            for (char& c : line) {
                if (c == '[' || c == ']' || c == ',') c = ' ';
            }

            // Reload the buffer with the cleaned line
            pending.clear();
            pending.str(line);

            // Block 12: Excess value detection and reporting
            // After filling all remaining slots from this line,
            // any leftover tokens are out-of-scope. They are
            // collected into a string and reported to the user.
            int needed = this->arrSize - filled;
            int loaded = 0;
            while (loaded < needed && pending >> token) {
                *(this->arr + filled + loaded) = token;
                loaded++;
            }
            filled += loaded;

            // Check for surplus tokens
            if (filled == this->arrSize && pending >> token) {
                string extras = to_string(token);
                while (pending >> token) extras += ", " + to_string(token);
                cout << "Warning: values exceed array size — out-of-scope values removed: "
                     << extras << "\n";
            }
        }
    }

    // ══════════════════════════════════════════
    //  displayArray()
    // ══════════════════════════════════════════
    void displayArray() const {

        // Block 14: Empty array guard
        // Exits early with a message if the array
        // pointer is null or arrSize is zero.
        if (this->arr == nullptr || this->arrSize == 0) {
            cout << "Array is empty.\n";
            return;
        }

        // Block 15: All-zero detection
        // Scans each element via pointer arithmetic.
        // If every value is 0, prints a notice that
        // the array contains no meaningful data.
        bool allZero = true;
        for (int i = 0; i < this->arrSize; i++) {
            if (*(this->arr + i) != 0) { allZero = false; break; }
        }
        if (allZero) {
            cout << "Note: all array values are 0 — the array is effectively empty.\n";
        }

        // Block 16: Array printing with pointer arithmetic
        // Sets a local pointer to the start of arr, then
        // iterates using *(ptr + i) to print each element
        // in [value], format. Nullifies the pointer after use.
        int* ptr = this->arr;

        cout << "Data: ";
        for (int i = 0; i < this->arrSize; i++) {
            cout << "[" << *(ptr + i) << "]";
            if (i < this->arrSize - 1) cout << ", ";
        }
        cout << "\n";

        ptr = nullptr;
    }

    // ══════════════════════════════════════════
    //  reverseArray()
    // ══════════════════════════════════════════
    void reverseArray() {

        // Block 17: Empty array guard
        // Returns immediately if the array is null or empty.
        if (this->arr == nullptr || this->arrSize == 0) return;

        // Block 18: In-place swap via pointer arithmetic
        // Iterates only through the first half of the array.
        // For each index i, a front pointer and back pointer
        // are set using arithmetic, then their values are
        // swapped via a temp variable. Half-length iteration
        // prevents double-swapping back to the original order.
        for (int i = 0; i < this->arrSize / 2; i++) {
            int  indexBack = this->arrSize - 1 - i;
            int* pFront    = this->arr + i;
            int* pBack     = this->arr + indexBack;

            int tmp = *pFront;
            *pFront = *pBack;
            *pBack  = tmp;
        }
    }

    // ══════════════════════════════════════════
    //  findMax()
    // ══════════════════════════════════════════
    void findMax() {

        // Block 19: Empty array guard
        // Exits early with a message if no data exists.
        if (this->arr == nullptr || this->arrSize == 0) {
            cout << "Array is empty — cannot determine max.\n";
            return;
        }

        // Block 20: Max search via pointer arithmetic
        // Seeds arrMax from the first element (not 0) so
        // negative-only arrays are handled correctly.
        // Iterates from index 1, updating arrMax whenever
        // a larger or equal value is found via *(arr + i).
        // Prints the final max value.
        this->arrMax = *(this->arr);

        for (int i = 1; i < this->arrSize; i++) {
            if (*(this->arr + i) >= this->arrMax) {
                this->arrMax = *(this->arr + i);
            }
        }

        cout << "Max value: " << this->arrMax << "\n";
    }

    // ══════════════════════════════════════════
    //  countEvenNumbers()
    // ══════════════════════════════════════════
    void countEvenNumbers() {

        // Block 21: Empty array guard
        // Exits early with a message if no data exists.
        if (this->arr == nullptr || this->arrSize == 0) {
            cout << "Array is empty — no even values to count.\n";
            return;
        }

        // Block 22: Even value counting via pointer arithmetic
        // Initialises a local counter, then iterates the array
        // using *(arr + i) to check divisibility by 2.
        // Increments the counter for each even value, stores
        // the result in countEven, and prints it.
        int counterEven = 0;

        for (int i = 0; i < this->arrSize; i++) {
            if (*(this->arr + i) % 2 == 0) {
                counterEven++;
            }
        }

        this->countEven = counterEven;
        cout << "Number of even values: " << this->countEven << "\n";
    }
};


// ─────────────────────────────────────────────
// Block 23: main function
// Entry point of the program. Creates an
// ArrayProcessor object, calls setArray() to
// populate it, then sequentially calls display,
// reverse, display again, findMax, and
// countEvenNumbers. Guards against an aborted
// setArray() call before proceeding.
// ─────────────────────────────────────────────
int main() {

    ArrayProcessor a1;

    a1.setArray();

    if (a1.getArrSize() == 0) {
        cout << "No valid array was created. Exiting.\n";
        return 1;
    }

    cout << "\n--- Original Array ---\n";
    a1.displayArray();

    cout << "\n--- Reversed Array ---\n";
    a1.reverseArray();
    a1.displayArray();

    cout << "\n--- Statistics -------\n";
    a1.findMax();
    a1.countEvenNumbers();

    cout << "\nDone.\n";
    return 0;
}