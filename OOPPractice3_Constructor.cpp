#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
public:
    string companyName;
    string modelName;
    int year;
    Vehicle(string a, string b, int c)
    {
        companyName = a;
        modelName = b;
        year = c;
    }
    void displayInfo()
    {
        cout << "Company Name: " << companyName << endl;
        cout << "Model Name: " << modelName << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle
{
public:
    int doors;
    string fuelType;
    Car(int x, string y, string a, string b, int c) : Vehicle(a, b, c)
    {
        doors = x;
        fuelType = y;
    }
    void displayinfo()
    {
        Vehicle::displayInfo();
        cout << "No. of Doors: " << doors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class Bike : public Vehicle
{
public:
    string engineCapacity;
    string abs;
    Bike(string a, string b, string c, string d, int x) : Vehicle(c, d, x)
    {
        engineCapacity = a;
        abs = b;
    }
    void displayinFo()
    {
        Vehicle::displayInfo();
        cout << "Engine Capacity: " << engineCapacity << endl;
        cout << "ABS: " << abs << endl;
    }
};

int main()
{
    Car c1(4, "Octane", "Ford", "Mustang", 2014);
    Car c2(6, "E20", "Dodge", "Durango", 2022);
    Bike b1("200cc", "NO", "Royal Enfield", "Thunderbird", 2010);
    Bike b2("600cc", "YES", "Bajaj", "Pulsar", 2016);
    c1.displayinfo();
    cout << endl;
    c2.displayinfo();
    cout << endl;
    b1.displayinFo();
    cout << endl;
    b2.displayinFo();
}