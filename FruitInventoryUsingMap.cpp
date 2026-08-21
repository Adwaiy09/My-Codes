#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> inventory = {
        {"Apple", 12},
        {"Banana", 5},
        {"Mango", 8},
        {"Orange", 15},
        {"Grapes", 10}};

    string fruit;
    int quantity;
    string more = "yes";
    while (more != "no")
    {
        cout << "Enter fruit: ";
        cin >> fruit;
        cout << "Enter quantity: ";
        cin >> quantity;
        inventory[fruit] -= quantity;
        cout << "More fruit ? : ";
        cin >> more;
        cout << endl;
    }

    cout << "Final Inventory: " << endl;
    for (auto i : inventory)
    {
        cout << i.first << " " << i.second << endl;
    }

    int highest = INT_MIN;
    string highestStock = " ";
    for (auto i : inventory)
    {
        if (i.second > highest)
        {
            highest = i.second;
            highestStock = i.first;
        }
    }
    cout << "Fruit with highest stock: " << highestStock << endl;

    int lowest = INT_MAX;
    string lowestStock = " ";
    for (auto i : inventory)
    {
        if (i.second < lowest)
        {
            lowest = i.second;
            lowestStock = i.first;
        }
    }
    cout << "Fruit with lowest stock: " << lowestStock << endl;
}