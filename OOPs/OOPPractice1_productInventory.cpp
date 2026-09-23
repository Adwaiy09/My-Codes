#include <iostream>
using namespace std;

class Product
{
private:
    string name;
    int id;
    double price;
    int quantity;

public:
    Product(string a, int b, double c, int d)
    {
        name = a;
        id = b;
        price = c;
        quantity = d;
    }

    void increaseQuantity()
    {
        int add;
        cout << "Enter quantity to be added: ";
        cin >> add;
        quantity += add;
    }

    void decreaseQuantity()
    {
        int remove;
        cout << "Enter quantity to be reduced: ";
        cin >> remove;
        if (remove > quantity)
        {
            cout << "Cannot decrease more than quantity !!!";
        }
        else
        {
            quantity -= remove;
        }
    }
    void displayDetails()
    {
        cout << "Product Name: " << name << endl;
        cout << "Product ID: " << id << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: " << price * quantity << endl;
    }
};

int main()
{
    Product p1("Mobile", 1234567, 140000, 2);
    Product p2("Car", 2345432, 230000, 1);
    Product p3("Pen", 2313456, 200, 30);

    p1.increaseQuantity();
    cout << endl;
    p2.decreaseQuantity();
    cout << endl;
    p3.decreaseQuantity();
    cout << endl;
    p1.displayDetails();
    p2.displayDetails();
    p3.displayDetails();
}