#include <iostream>
#include <string>
using namespace std;

class Room
{
protected:
    int roomNumber;
    int pricePerNight;
    bool isBooked;

public:
    virtual ~Room() {};
    Room(int roomNumber, int pricePerNight)
    {
        this->roomNumber = roomNumber;
        this->pricePerNight = pricePerNight;
    }

    void bookRoom()
    {
        string book;
        cout << "Do you want to book the room ?: ";
        cin >> book;
        if (book == "Yes" || book == "YES" || book == "yes")
        {
            isBooked = true;
        }
        else if (book == "No" || book == "NO" || book == "no")
        {
            isBooked = false;
        }
        else
        {
            cout << "Invalid action";
        }
    }

    virtual int cost()
    {
        int nights;
        cout << "How many nights you wish to stay ?: ";
        cin >> nights;
        if (nights > 0)
        {
            return pricePerNight * nights;
        }
        else
        {
            cout << "Invalid input\n ";
            return 0;
        }
    }

    virtual void displayInfo()
    {
        cout << "Room Number: " << roomNumber << endl;
        cout << "Price Per Night: " << pricePerNight << endl;
        cout << "Booked Status: ";
        if (isBooked)
        {
            cout << "Booked " << endl;
        }
        else
        {
            cout << "Not Booked " << endl;
        }
    }
};
class StandardRoom : public Room
{
private:
    int serviceCharge;

public:
    StandardRoom(int serviceCharge, int roomNumber, int pricePerNight) : Room(roomNumber, pricePerNight)
    {
        this->serviceCharge = serviceCharge;
    }

    int cost() override
    {
        int a = Room::cost();
        return a + serviceCharge;
    }
    void displayInfo()
    {
        int c = cost();
        cout << "Room type: Standard" << endl;
        Room::displayInfo();
        cout << "Total Cost: " << c << endl
             << endl;
    }
};

class LuxuryRoom : public Room
{

private:
    int serviceCharge;
    int luxuryTax;

public:
    LuxuryRoom(int serviceCharge, int luxuryTax, int roomNumber, int pricePerNight) : Room(roomNumber, pricePerNight)
    {
        this->serviceCharge = serviceCharge;
        this->luxuryTax = luxuryTax;
    }
    int cost() override
    {
        int b = Room::cost();
        return b + serviceCharge + luxuryTax;
    }
    void displayInfo()
    {
        int t = cost();
        cout << "Room type: Luxury" << endl;
        Room::displayInfo();
        cout << endl;
        cout << "Total Cost: " << t << endl;
    }
};

int main()
{
    Room *r1 = new StandardRoom(300, 100, 2000);
    r1->bookRoom();

    r1->displayInfo();
    delete r1;
    Room *r2 = new LuxuryRoom(300, 900, 105, 2000);
    r2->bookRoom();

    r2->displayInfo();
    delete r2;
}