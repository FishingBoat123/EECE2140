#include <iostream>
#include <string>
using namespace std;

class student
{
    private:
    int id;
    string name;
    float gpa;
    static int studentCount;

    public:

    student ();
    student(int setid, string setname, float setgpa) : id(setid), name(setname), gpa(setgpa) {studentCount++;}; 

    /* whats the difference between a constructor done like this and a constructor done like this: 
    student(int setid, string setname, float setgpa) 
    { id = setid; name = setname; gpa = setgpa; };*/

    void setId(int setid)
    {
        id = setid;
    }
    void setName(const string& setname)
    {
        name = setname;
    }
    void setGpa(float setgpa)
    {
        gpa = setgpa;
    }

    int getId()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    float getGpa()
    {
        return gpa;
    }

    void display()
    {
        cout << "ID: " << getId() << endl;
        cout << "Name: " << getName() << endl;
        cout << "GPA: " << getGpa() << endl;
    }
    static int getStudentCount()
    {
        return studentCount;
    }
};

int student::studentCount = 0;

//=============================

class course
{
    private:
    int courseId;
    string courseName;
    int creditHours;
    int maxSeats;
    string department;
    int enrolledStudents;

    public:

    // setters
    void setcourseId(int setCourseId)
    {
        courseId = setCourseId;
    }
    void setcourseName(const string& setCourseName)
    {        
        courseName = setCourseName;
    }
    void setcreditHours(int setCreditHours)
    {
        creditHours = setCreditHours;
    }
    void setmaxSeats(int setMaxSeats)
    {
        maxSeats = setMaxSeats;
    }
    void setdepartment(const string& setDepartment)
    {
        department = setDepartment;
    }
    void setenrolledStudents(int setEnrolledStudents)
    {
        enrolledStudents = setEnrolledStudents;
    }

    // getters
    int getcourseId()
    {
        return courseId;
    }
    string getcourseName()
    {
        return courseName;
    }
    int getcreditHours()
    {
        return creditHours;
    }
    int getmaxSeats()
    {
        return maxSeats;
    }
    string getdepartment()
    {
        return department;
    }
    int getenrolledStudents()
    {
        return enrolledStudents;
    }

    course();
    course(string setDepartment, int setCourseId, string setCourseName, int setCreditHours, int setMaxSeats, int setEnrolledStudents)
    {
        courseId = setCourseId;
        courseName = setCourseName;
        creditHours = setCreditHours;
        maxSeats = setMaxSeats;
        department = setDepartment;
        enrolledStudents = setEnrolledStudents;
    };

    void display()
    {
        cout << "Course ID: " << getcourseId() << endl;
        cout << "Course Name: " << getcourseName() << endl;
        cout << "Credit Hours: " << getcreditHours() << endl;
        cout << "Max Seats: " << getmaxSeats() << endl;
        cout << "Department: " << getdepartment() << endl;
        cout << "Full course name: " << getdepartment() << getcourseId() << " " << getcourseName() << endl;
    }

    bool isFull(int enrolledStudents)
    {
        return enrolledStudents >= maxSeats;
    }

};

class registration 
{
    private:
    bool isRegistered;
    student s;
    course c;

    public:

    registration ();
    registration (student s, course c) : s(s), c(c), isRegistered(false) {};

    bool registerStudent(course course, student student)
    {
        if (!course.isFull(course.getenrolledStudents()))
        {
            isRegistered = true;
            course.setenrolledStudents(course.getenrolledStudents() + 1);
            cout << "Student " << student.getName() << " has been registered for " << course.getcourseName() << endl;
            return true;
        }
        else
        {
            isRegistered = false;
            cout << "Course " << course.getcourseName() << " is full. Student " << student.getName() << " cannot be registered." << endl;
            return false;
        }
    }
};

//=============================

int main()
{
    student s1(101, "Smith", 3.75);
    student s2(102, "Johnson", 3.85);
    

    //call member function

    s1.display();
    cout << "Number of students: " << student::getStudentCount() << endl;

    s2.display();
    cout << "Number of students: " << student::getStudentCount() << endl;

    course c1("EECE", 2140, "Computing Fundamentals", 4, 40, 30);
    c1.display();

    return 0;
} 
