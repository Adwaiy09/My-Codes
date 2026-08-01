#include <iostream>
using namespace std;

class Rectangle
{
private:
    string name;
    int length;
    int breadth;

public:
    Rectangle(string a, int b, int c)
    {
        name = a;
        length = b;
        breadth = c;
    }

    void area()
    {
        int area = length * breadth;
        cout << "Area of rectangle " << name << ": " << area << " sq m";
    }
    void perimeter()
    {
        int perimeter = 2 * (length + breadth);
        cout << "Perimeter of rectangle " << name << ":" << perimeter << "m";
    }
    bool squareOrNot()
    {
        if (length == breadth)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void displayInfo()
    {
        cout << "Rectangle " << name << ": " << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << area << endl;
        cout << "Perimeter: " << perimeter << endl;
        if (squareOrNot)
        {
            cout << "Is a Square ";
        }
        else
        {
            cout << "Not a Square ";
        }
    }
};

int main()
{
    Rectangle r1("r1", 10, 20);
    Rectangle r2("r2", 20, 30);
    Rectangle r3("r3", 20, 20);

    r1.area();
    r2.area();
    r3.area();
    cout << endl;
    r1.perimeter();
    r2.perimeter();
    r3.perimeter();
    cout << endl;

    r1.squareOrNot();
    r2.squareOrNot();
    r3.squareOrNot();
    cout << endl;

    r1.displayInfo();
    cout << endl;
    r2.displayInfo();
    cout << endl;
    r3.displayInfo();
}