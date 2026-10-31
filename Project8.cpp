#include <iostream>
using namespace std;

class Student
{
protected:
    int roll;
    char name[30];

public:
    void getStudent()
    {
        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;
    }
};

class Exam : public Student
{
protected:
    int m1, m2, m3, m4, m5, m6;

public:
    void getMarks()
    {
        cout << "Enter marks in six subjects: ";
        cin >> m1 >> m2 >> m3 >> m4 >> m5 >> m6;
    }
};

class Result : public Exam
{
    int total;

public:
    void display()
    {
        total = m1 + m2 + m3 + m4 + m5 + m6;

        cout << "\n--- Student Result ---" << endl;
        cout << "Roll Number: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Total Marks: " << total << endl;
        cout << "Percentage: " << total / 6.0 << "%" << endl;
    }
};

int main()
{
    Result r;

    r.getStudent();
    r.getMarks();
    r.display();

    return 0;
}