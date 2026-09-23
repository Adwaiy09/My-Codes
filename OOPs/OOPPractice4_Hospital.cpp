#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Doctor : public Person
{
private:
    double salary;

public:
    string speciality;
    string experience;
    Doctor(double salary, string speciality, string experience, string name, int age) : Person(name, age)
    {
        this->salary = salary;
        this->speciality = speciality;
        this->experience = experience;
    }
    void displayInfo()
    {
        Person::displayInfo();
        cout << "Speciality: " << speciality << endl;
        cout << "Experience: " << experience << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Patient : public Person
{
private:
    double expense;

public:
    string illness;
    int wardNo;

    Patient(double expense, string illness, int wardNo, string name, int age) : Person(name, age)
    {
        this->expense = expense;
        this->illness = illness;
        this->wardNo = wardNo;
    }

    void displayInfo()
    {
        Person::displayInfo();
        cout << "Illness: " << illness << endl;
        cout << "Ward number: " << wardNo << endl;
        cout << "Expense: " << expense << endl;
    }
};

int main()
{
    Doctor d1(200000, "Cardiologist", "7.5 yrs", "Mohan", 32);
    Doctor d2(350000, "Neurologist", "10 yrs", "Rohan", 42);
    Doctor d3(150000, "Pediatrician", "6 yrs", "Ram", 30);
    Patient p1(20000, "AIDS", 3, "Bicky", 34);
    Patient p2(200000, "Kidney Failure", 7, "Micky", 57);
    Patient p3(10000, "Typhoid", 1, "Rahul", 20);
    d1.displayInfo();
    cout << endl;
    d2.displayInfo();
    cout << endl;
    d3.displayInfo();
    cout << endl;
    p1.displayInfo();
    cout << endl;
    p2.displayInfo();
    cout << endl;
    p3.displayInfo();
}