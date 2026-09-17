#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    char name[64];
    int age;
    char address[64];
    float salary;

public:
    // Default constructor
    Person()
    {
        strcpy(name, "");
        age = 0;
        strcpy(address, "");
        salary = 0;
    }

    // Parameterized constructor
    Person(char n[], int a, char ad[], float s)
    {
        strcpy(name, n);
        age = a;
        strcpy(address, ad);
        salary = s;
    }

    // Display person details
    void display()
    {
        cout << "Name    : " << name << endl;
        cout << "Age     : " << age << endl;
        cout << "Address : " << address << endl;
        cout << "Salary  : " << salary << endl;
    }

    // Inline function to find youngest age
    inline static int youngest(Person p[], int n)
    {
        int minAge = p[0].age;

        for (int i = 1; i < n; i++)
        {
            if (p[i].age < minAge)
                minAge = p[i].age;
        }

        return minAge;
    }

    // Inline function to find eldest age
    inline static int eldest(Person p[], int n)
    {
        int maxAge = p[0].age;

        for (int i = 1; i < n; i++)
        {
            if (p[i].age > maxAge)
                maxAge = p[i].age;
        }

        return maxAge;
    }

    // Salary slip
    void salarySlip()
    {
        float basic, hra, da, total;

        basic = salary * 0.50;
        hra = salary * 0.20;
        da = salary * 0.30;
        total = basic + hra + da;

        cout << "\n----- SALARY SLIP -----" << endl;
        cout << "Name        : " << name << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "HRA         : " << hra << endl;
        cout << "DA          : " << da << endl;
        cout << "Total Salary: " << total << endl;
    }
};

int main()
{
    // Array of 10 Person objects
    Person p[10] =
    {
        Person((char*)"Amit", 25, (char*)"Kolkata", 30000),
        Person((char*)"Rahul", 30, (char*)"Delhi", 40000),
        Person((char*)"Priya", 22, (char*)"Mumbai", 35000),
        Person((char*)"Riya", 28, (char*)"Pune", 45000),
        Person((char*)"Ankit", 35, (char*)"Patna", 50000),
        Person((char*)"Neha", 24, (char*)"Delhi", 32000),
        Person((char*)"Rohan", 40, (char*)"Kolkata", 60000),
        Person((char*)"Sneha", 27, (char*)"Mumbai", 38000),
        Person((char*)"Vivek", 32, (char*)"Chennai", 42000),
        Person((char*)"Pooja", 29, (char*)"Pune", 36000)
    };

    // Display all persons
    cout << "----- PERSON DETAILS -----\n";

    for (int i = 0; i < 10; i++)
    {
        cout << "\nPerson " << i + 1 << endl;
        p[i].display();
    }

    // Find youngest and eldest
    cout << "\nYoungest Age = "
         << Person::youngest(p, 10) << endl;

    cout << "Eldest Age = "
         << Person::eldest(p, 10) << endl;

    // Salary slip
    p[0].salarySlip();

    return 0;
}