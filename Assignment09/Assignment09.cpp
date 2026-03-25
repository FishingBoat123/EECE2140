#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileWriter
{
    private:
    string fileName;

    public:
    FileWriter() {}
    FileWriter(string fileName) : fileName(fileName) {}

    bool fileExists()
    {
        ifstream f(fileName);
        return f.good();
    }

    void writeToFile(string text)
    {
        ofstream MyWriteFile(fileName);

        if (!MyWriteFile)
        {
            cout << "Error: Could not open file!" << endl;
            return;
        }
        MyWriteFile << text;
        MyWriteFile.close();
        cout << "File written successfully!" << endl;
    }

    //===== Question 4 =====
    void appendToFile(string text)
    {
        ofstream MyAppendFile(fileName, ios::app);

        if (!MyAppendFile)
        {
            cout << "Error: Could not open file!" << endl;
            return;
        }

        MyAppendFile << text;
        MyAppendFile.close();
        cout << "appended successfully!" << endl;
    }

    //===== Question 5 =====
    void prependToFile(string newText)
    {
        ifstream readFile(fileName);
        if (!readFile)
        {
            cout << "Error: Could not read file!" << endl;
            return;
        }

        string oldContent = "";
        string line;
        while (getline(readFile, line))
            oldContent += line + "\n";
        readFile.close();

        
        ofstream writeFile(fileName);
        if (!writeFile)
        {
            cout << "Error: Could not open file for writing!" << endl;
            return;
        }
        writeFile << newText << oldContent;
        writeFile.close();

        cout << "Text prepended successfully!" << endl;
    }

    void readFile()
    {
        if (!fileExists())
        {
            cout << "Error: File '" << fileName << "' does not exist!\n";
            return;
        }

        ifstream f(fileName);
        if (!f)
        {
            cout << "Error: Could not open '" << fileName << "'!\n";
            return;
        }

        string line;
        int lineCount = 0;
        while (getline(f, line))
        {
            cout << ++lineCount << ". " << line << "\n";
        }

        if (lineCount == 0)
            cout << "(file is empty)\n";
    }

    void clearFile()
    {
        if (!fileExists())
        {
            cout << "Error: File '" << fileName << "' does not exist!\n";
            return;
        }

        ofstream f(fileName, ios::trunc);  // ios::trunc wipes content on open
        if (!f)
        {
            cout << "Error: Could not clear '" << fileName << "'!\n";
            return;
        }
        cout << fileName << "' has been cleared.\n";
    }


};

int main() 
{
    string myText = "Hello, this is a sample text written to the file.\n";
    myText += "This is the second line.\n";
    
    // FileWriter file1("test.txt");
    // file1.writeToFile(myText);
    
    //===== Question 4 =====
    // file1.appendToFile("This is the third line (appended).\n");
    // file1.appendToFile("This is the fourth line (appended).\n");

    //===== Question 5 =====
    // file1.writeToFile("Line A: Original first line.\nLine B: Original second line.\n");
    // file1.prependToFile("*** NEW FIRST LINE (prepended correctly) ***\n");
    // cout << "\nAfter correct prepend:";

    //===== Question 6 =====
    //empty string
    // FileWriter file1("test.txt");
    // file1.writeToFile("");
    // file1.appendToFile("");

    //invalid file name
    // FileWriter file2("testss!@#$.txt");
    // file2.writeToFile("Some text");

    // //large string
    // FileWriter file3("large.txt");
    // string largeText(11 * 1000 * 1000 * 1000, 'A');
    // file3.writeToFile(largeText);

    // //writing multiple times in a loop
    // FileWriter file4("loop.txt");
    // file4.writeToFile("Loop start\n"); 
    // for (int i = 1; i <= 5; i++)
    //     file4.appendToFile("Loop line " + to_string(i) + "\n");

    
    //===== Question 9 =====
    FileWriter file1("test.txt");
    int choice;
    string text;

    cout << "\n===== File Manager Menu =====\n";
    cout << "1. Write to file\n";
    cout << "2. Append to file\n";
    cout << "3. Read file\n";
    cout << "4. Clear file\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
        case 1:
            cout << "Enter text to write: ";
            getline(cin, text);
            file1.writeToFile(text + "\n");
            break;
        case 2:
            cout << "Enter text to append: ";
            getline(cin, text);
            file1.appendToFile(text + "\n");
            break;
        case 3:
            file1.readFile();
            break;
        case 4:
            file1.clearFile();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice. Please enter 1-5.\n";
    }

    return 0;
}
