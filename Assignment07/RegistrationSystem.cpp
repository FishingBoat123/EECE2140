#include <iostream>
using namespace std;

//==========================================================================
// Class Declaration
class Student
{
    private:
    int idNum;
    string lastName;
    double gpa;

    public:
    // Constructor
    Student ();
    Student(int id, string name, double studentGpa)
    {
        idNum = id;
        lastName = name;
        gpa = studentGpa;
    }

    // Setters
    void setidNUM(int id) {idNum = id;}
    void setlastName(string name) {lastName = name;}
    void setgpa(double studentGpa) {gpa = studentGpa;}

    //getters
    int getidNum() {return idNum;}
    string getlastName() {return lastName;}
    double getgpa() {return gpa;}

    // Function Prototype
    void displayStudentData();
};

//==========================================================================
// Function Implementation
void Student::displayStudentData()
{
    cout << "Student # " << idNum << " Name: " << lastName << endl;
    cout << "GPA: " << gpa << endl;
}


//Course ==========================================================================
class Course
{
    private:
    string department;
    int courseNum;
    int seats;
    int maxSeats;
    string courseName;

    // constructor ================================================================
    public:
    Course();
    Course(const string& department, int courseNum, int maxSeats, const string& courseName)
    {
        this->department = department;
        this->courseNum = courseNum;
        this->seats = 0;
        this->maxSeats = maxSeats;
        this->courseName = courseName;
    };
    
    //you can also do the following for your constructors:
    //Course(const string& department, int courseNum, int maxSeats, const string& courseName) : department(department), courseNum(courseNum), maxSeats(maxSeats), courseName(courseName) {};

    // setters ================================================================
    void setDepartment(const string& department) {this->department = department;}
    void setCourseNum(int courseNum) { this->courseNum = courseNum; }
    void setMaxSeats(int maxSeats) { this->maxSeats = maxSeats; }
    void setSeats(int seats) { this->seats = seats; }
    void setCourseName(const string& courseNam) { this->courseName = courseNam; }

    // getters ================================================================
    string getDepartment() const { return department; }
    int getCourseNum() const { return courseNum; }
    int getSeats() const { return seats; }
    int getMaxSeats() const { return maxSeats; }
    string getCourseName () const { return courseName; }

    bool hasAvailableSeats() const {return seats < maxSeats;} //another way of doing bool, return true if seats are available, false if course is full

    void addSeat() {if (hasAvailableSeats()) seats++;}

    void removeSeat() {if (seats > 0) seats--;}

    void displayCourseData() const
    {
        cout << "Course: " << department << " " << courseNum << " - " << courseName << " Seats: " << seats << "/" << maxSeats << endl;
    }
};

//Registration ==========================================================================
class Registration
{
    private:
    Student& student; //takes a reference to a student object
    Course& course; //takes a reference to a course object
    bool isRegistered;
    static int regCount;//static variable to keep track of total registrations, doesnt not belong to any object, belongs to the class, shared among all objects of the class
    public:


    //reg count reset
    void static setregCount(int activeReg) {regCount = activeReg;}
    int static getRegCount() {return regCount;}


    // Constructor ================================================================
    Registration();
    Registration(Student& s, Course& c) : student(s), course(c), isRegistered(false) {}

    // Register student ================================================================
    bool registerStudent()
    {
        if (isRegistered)
        {
            cout << "Student already registered.\n";
            return false;
        }
        if (!course.hasAvailableSeats())
        {
            cout << "Cannot register: Course is full.\n";
            return false;
        }
        course.addSeat();
        isRegistered = true;
        regCount++;
        cout << "Registration successful.\n";

        return true;
    }

    // Drop student ================================================================
    bool dropStudent()
    {
        if (!isRegistered)
        {
            cout << "Student is not registered.\n";
            return false;
        }
        course.removeSeat();
        isRegistered = false;
        regCount--;
        cout << "Dropped successfully.\n";

        return true;
    }

    // registration info ================================================================
    void regCountDisplay() const { cout << "Total Active Registrations: " << regCount << endl; }
    void display() const {
    //student.displayStudentData();
    /*when in class and has thing called by reference, no need for scope resolution operator, 
    just use . and it will automatically call the function of the object that is being referenced*/
    regCountDisplay();
    cout << "Status: " << (isRegistered ? "Registered" : "Not Registered") << endl;
    cout << endl;

    }
    // Static function to get total registrations
    static int getTotalRegs() // only belong to class, not to any object, can be called without creating an object of the class
    {
        return regCount;
    }

    ~Registration() {}
};

// Static variable definition (must be outside class)
int Registration::regCount = 0;

class RegInput : private Registration
{
    private:
    string deptInput;
    string *deptptr;
    int courseNum;
    int *courseNumptr;

    public:
    RegInput(string deptInput, int courseNum) : deptInput(deptInput), deptptr(nullptr), courseNum(courseNum), courseNumptr(nullptr) {}
    
};

// Main Function ================================================================
int main()
{
    //student

    //========== Test Case 1 ==========
    cout << "==========Test Case 1==========" << endl;
    // Create Student object
    Student s1(1001, "Smith", 3.85);

    //course (expected output: EECE 2140 - Computing Fundamentals 29/30)
    Course c1("EECE", 2140, 30, "Computing Fundamentals");
    c1.setSeats(29);
    
    Registration::setregCount(0);
    Registration r1 {s1, c1};
    r1.registerStudent();
    r1.display();


    //==========Test Case 2==========
    cout << "==========Test Case 2==========" << endl;
    r1.registerStudent();
    r1.regCountDisplay();
    cout << endl;

    //==========Test Case 3==========
    cout << "==========Test Case 3==========" << endl;
    Student s2(1002, "Johnson", 3.40);
    Student s3(1003, "Williams", 3.10);

    Course c2 ("EECE", 5626, 1, "Image Processing");

    Registration::setregCount(0); //reset active registration
    Registration r2 {s2, c2};
    Registration r3 {s3, c2};

    r2.registerStudent();
    r3.registerStudent();
    r2.regCountDisplay();

    cout << endl;

    //==========Test Case 4==========
    cout << "==========Test Case 4==========" << endl;
    Student s4(1004, "Brown", 3.70);
    
    Course c3("EECE", 7205, 25, "Advanced Algorithms");

    Registration::setregCount(0);
    Registration r4 {s4, c3};

    r4.registerStudent();
    r4.dropStudent();
    r4.display();

    
    //==========Test Case 5==========
    cout << "==========Test Case 5==========" << endl;
    
    Student s5(1005, "Davis", 2.95);

    Course c4("EECE", 2160, 20, "Embedded Design");

    Registration::setregCount(0);
    Registration r5 {s5, c4};
    
    r5.dropStudent();
    r5.regCountDisplay();

    return 0;

    cout << "==========Test Input Course==========" << endl;
    string department;
    int courseNum;
    int maxSeats;
    string courseName;
    Course c5(string& department, int courseNum, int maxSeats, string& courseName);

    cout << "Department: ";
    cin >> department;

    cout << "\nCourse Number/ID: ";
    cin >> courseNum;

    cout << "\nMaximum Seats: ";
    cin >> maxSeats;

    cout << "\nCourse Name: ";
    cin >> courseName;




}