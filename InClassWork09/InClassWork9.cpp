#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
using namespace std;

class FileReader
{
    private:
    string filename;

    public:
    FileReader(string fname)
    {
        this->filename = fname;
    }
    void readFile()
    {
        ifstream file(filename);
        if (!file)
        {
            cout << "error" << endl;
            return;
        }

        string line;
        cout << "printing file content:" << endl;
        cout << "----------------------" << endl;

        while (getline(file,line))
        {
            cout << line << endl;
        }

        file.close();
    }
};

int main()
{
    string mystring = "Hello, this is a test string.";
    string mystring1 = "Hello, this is a test string.";

    string filename = "data.txt";

    ofstream mywritefile(filename);
    if(!mywritefile)
    {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    mywritefile << mystring << endl;
    mywritefile << mystring1 << endl;
    mywritefile.close();
    cout << "String written to file: " << filename << endl;

    FileReader f1(filename);
    f1.readFile();
}
