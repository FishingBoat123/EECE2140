#include <iostream>
#include <fstream> //copilot
#include <vector> //copilot
#include <string> //copilot
#include <cmath>      
#include <cctype>     // tolower (copilot)

using namespace std;

using Matrix = vector<vector<int>>; // copilot used to help set up matrix type and understand how this works

// clamp an integer x to the range [lo, hi].
static int clampInt(int x, int lo, int hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}

// clamp an integer to the range [0, 255] for pixel values.
static int clamp255(int x) {
    return clampInt(x, 0, 255);
}

// clamp edge handling for indexing:
// if r < 0 -> 0, if r >= rows -> rows-1, same for c.
// copilot was used for this part to understand how to handle edge cases when applying the mean filter, and to ensure it doesnt go out of bounds when accessing pixel values near the edges of the image.
static int getClamped(const Matrix& img, int r, int c) 
{
    int rows = (int)img.size();
    int cols = rows ? (int)img[0].size() : 0;
    r = clampInt(r, 0, rows - 1);
    c = clampInt(c, 0, cols - 1);
    return img[r][c];
}

// read a matrix from a text file. format: first line "rows cols", then rows*cols integers.
static bool readMatrix(const string& filename, Matrix& img) 
{
    ifstream in(filename);
    if (!in.is_open()) return false;

    int rows, cols;
    if (!(in >> rows >> cols)) return false;
    if (rows <= 0 || cols <= 0) return false;

    img.assign(rows, vector<int>(cols, 0));
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int v;
            if (!(in >> v)) return false;
            img[r][c] = clamp255(v);
        }
    }
    return true;
}

// write a matrix to a text file in the same format as readMatrix.
static bool writeMatrix(const string& filename, const Matrix& img) 
{
    ofstream out(filename); //copilot uses out instead of cout here. this is to write to a file, not to the console. this is something I missed.

    int rows = (int)img.size();
    int cols = rows ? (int)img[0].size() : 0;

    out << rows << " " << cols << "\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            out << img[r][c];
            if (c + 1 < cols) out << " ";
        }
        out << endl;
    }
    return true;
}

// apply a 3x3 mean filter to the image, using clamped edge handling.
static Matrix meanFilter3x3_clampEdges(const Matrix& img) 
{
    int rows = (int)img.size();
    int cols = rows ? (int)img[0].size() : 0;

    Matrix out(rows, vector<int>(cols, 0));

    // works for any rows/cols >= 1
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            int sum = 0;
            for (int dr = -1; dr <= 1; dr++) {
                for (int dc = -1; dc <= 1; dc++) {
                    sum += getClamped(img, r + dr, c + dc);
                }
            }
            int avg = (int)lround(sum / 9.0); // round to nearest int
            out[r][c] = clamp255(avg);
        }
    }
    return out;
}

// print usage instructions for the program.
static void printUsage(const string& prog) {
    cout << "Usage: " << endl;
    cout << "  " << prog << " <input.txt> <output.txt> mean [iterations]" << endl;
    cout << endl << "Example: " << endl;
    cout << "  " << prog << " tests/noisy.txt out.txt mean 2" << endl;
}


// convert a string to lowercase for case-insensitive filter name comparison.
static string toLower(string s) {
    for (char& ch : s) ch = (char)tolower((unsigned char)ch);
    return s;
}


// main function: parse arguments, read input, apply filter, write output.
int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage(argv[0]);
        return 1;
    }

    // argv: 0: program name, 1: input file, 2: output file, 3: filter name, 4: optional iterations
    string inputFile  = argv[1];
    string outputFile = argv[2];
    string filter     = toLower(argv[3]);

    int iterations = 1;
    if (argc >= 5) {
        try {
            iterations = stoi(argv[4]);
        } catch (...) {
            cout << "Error: iterations must be an integer." << endl;
            return 1;
        }
        if (iterations <= 0) {
            cout << "Error: iterations must be >= 1." << endl;
            return 1;
        }
    }

    if (filter != "mean") {
        cout << "Error: this starter supports only 'mean'." << endl;
        return 1;
    }

    Matrix img;
    if (!readMatrix(inputFile, img)) {
        cout << "Error: could not read input file '" << inputFile << "'." << endl;
        cout << "Check format: first line 'rows cols', then rows*cols integers." << endl;
        return 1;
    }

    for (int it = 0; it < iterations; it++) {
        img = meanFilter3x3_clampEdges(img);
    }

    if (!writeMatrix(outputFile, img)) {
        cout << "Error: could not write output file '" << outputFile << "'." << endl;
        return 1;
    }

    cout << "Done. Wrote: " << outputFile << endl;
    return 0;
}
