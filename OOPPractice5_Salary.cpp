#include <iostream>
using namespace std;

class Employee
{
protected:
    int id;
    int salary;

public:
    virtual ~Employee() {};
    string name;
    Employee(int id, int salary, string name)
    {
        this->id = id;
        this->name = name;
        this->salary = salary;
    }

    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};
class Manager : public Employee
{

private:
    int bonus;

public:
    Manager(int bonus, int id, int salary, string name) : Employee(id, salary, name)
    {
        this->bonus = bonus;
    }
    void displayInfo()
    {

        cout << "MANAGER: " << endl;
        Employee::displayInfo();
        cout << "Annual Compensation: " << salary + bonus << endl;
        cout << endl;
    }
};

class Developer : public Employee
{

private:
    int projectBonus;

public:
    Developer(int projectBonus, int id, int salary, string name) : Employee(id, salary, name)
    {
        this->projectBonus = projectBonus;
    }

    void displayInfo()
    {
        cout << "DEVELOPER: " << endl;
        Employee::displayInfo();
        cout << "Annual Compensation: " << salary + projectBonus << endl;
    }
};

int main()
{
    Employee *e = new Manager(300000, 101, 2000000, "Rahul");
    e->displayInfo();
    delete e;
    e = new Developer(120000, 110, 1300000, "Adwaiy");
    e->displayInfo();
    delete e;
}
