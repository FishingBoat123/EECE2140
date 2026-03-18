#include <iostream>
using namespace std;

class employee 
{
    private:
    string name;
    int id;
    int age;
    double salary;
    string status;
    bool intern;

    public:
    employee();
    employee(string name, int id, int age, double salary, string status) : name(name), id(id), age(age), salary(salary), status(status) {setStatus(status);}

    void setName(string name) {this->name = name;}
    void setId(int id) {this->id = id;}
    void setAge(int age) {this->age = age;}
    void setSalary(double salary) {this->salary = salary;}
    void setStatus(string status) {if(status == "Intern" || status == "intern") {intern = true;} else {intern = false;}}

    string getName() const {return name;}
    int getId() const {return id;}
    int getAge() const {return age;}
    double getSalary() const {return salary;}

    bool isIntern() const {return intern;}


    void displayEmployeeInfo()
    {
        cout << endl << "========== Employee Information ==========" << endl;
        cout << "Employee Name: " << getName() << " " << getId() << endl;
        cout << "Age: " << getAge() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "Intern? " << (intern ? "Yes" : "No")  << endl << endl;
    }
};

void printArray(int arr[], int size)
{
    for (int i = 0; i <= size; i++)
    {
        cout << "Pointer: " << arr[i] << endl;;
    }
}

int main()
{
    employee e1 {"John Smith", 10001, 39, 70000, "not intern"};
    e1.displayEmployeeInfo();
    employee e2("Jane Doe", 10002, 20, 30000, "intern");
    e2.displayEmployeeInfo();

    int size;
    cout << "array size: ";
    cin >> size;
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i+1;
    }

    printArray(arr, size);

    delete[] arr;

    arr = nullptr;

    if (arr == nullptr) {cout << "Pointer is deleted and nullified" << endl;}

    cout << arr[0];

}
