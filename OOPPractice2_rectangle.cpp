#include <iostream>
using namespace std;

class Rectangle
{

public:
    string name;
    int length;
    int breadth;

    Rectangle(string a, int b, int c)
    {
        name = a;
        length = b;
        breadth = c;
    }
    int area()
    {
        return length * breadth;
    }

    int perimeter()
    {
        return 2 * (length + breadth);
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
        int a = area();
        int p = perimeter();
        bool bo = squareOrNot();
        cout << "Name: " << name << endl;
        cout << "Length: " << length << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Area: " << a << endl;
        cout << "Permeter: " << p << endl;
        if (bo)
        {
            cout << "Is a Square" << endl;
        }
        else
        {
            cout << "Not a Square" << endl;
        }
        cout << endl;
    }
};

int main()
{
    Rectangle r1("rectangle 1", 30, 20);
    Rectangle r2("rectangle 2", 40, 30);
    Rectangle r3("rectangle 3", 30, 30);
    r1.displayInfo();
    r2.displayInfo();
    r3.displayInfo();
}