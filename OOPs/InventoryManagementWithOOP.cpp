#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{
protected:
    int id;
    string name;
    double price;

public:
    virtual ~Item() {}
    Item(int id, string name, double price)
    {
        this->id = id;
        this->name = name;
        this->price = price;
    }
    virtual void itemInfo()
    {
        cout << "Item name: " << name << endl;
        cout << "Item id: " << id << endl;
        cout << "Item price: " << price << endl;
    }
    virtual int totalValue() = 0;
    int itemID()
    {
        return id;
    }
};

class Weapon : public Item
{
private:
    int damage;

public:
    Weapon(int id, string name, double price, int damage) : Item(id, name, price)
    {
        this->damage = damage;
    }
    int totalValue() override
    {
        return price + damage;
    }
    void itemInfo() override
    {
        cout << "\n---Item: Weapon---\n";
        Item::itemInfo();
        cout << "Damage: " << damage << endl;
        cout << "Value: " << totalValue() << endl;
    }
};

class Potion : public Item
{
private:
    int healAmt;

public:
    Potion(int id, string name, double price, int healAmt) : Item(id, name, price)
    {
        this->healAmt = healAmt;
    }
    int totalValue() override
    {
        return price + healAmt;
    }
    void itemInfo() override
    {
        cout << "\n---Item: Potion---\n";
        Item::itemInfo();
        cout << "Healing power: " << healAmt << endl;
        cout << "Value: " << totalValue() << endl;
    }
};
class Armour : public Item
{
private:
    int defense;

public:
    Armour(int id, string name, double price, int defense) : Item(id, name, price)
    {
        this->defense = defense;
    }
    int totalValue() override
    {
        return price + defense;
    }
    void itemInfo() override
    {
        cout << "\n---Item: Armour---\n";
        Item::itemInfo();
        cout << "Defense: " << defense << endl;
        cout << "Value: " << totalValue() << endl;
    }
};

class Player
{
private:
    string playerName;
    vector<Item *> inventory;

public:
    virtual ~Player() // very important to make Player destructor to clean up the allocated memory of items in inentory.
    {
        for (auto i : inventory)
        {
            delete i;
        }
    }
    Player(string playerName)
    {
        this->playerName = playerName;
    }
    void addItem(Item *item)
    {
        inventory.push_back(item);
    }
    void displayInfo()
    {
        for (auto i : inventory)
        {
            i->itemInfo();
        }
        // ANALOGY:-
        // Item* n = new Weapon(100 , "Sword") ;
        // n->itemInfo() ;
    }
    void inventoryValue()
    {
        int totalval = 0;
        for (auto i : inventory)
        {
            totalval += i->totalValue();
        }
        cout << "Total inventory value: " << totalval << endl;
    }
    void removeItem(int n)
    {
        for (auto i : inventory)
        {
            if (n == i->itemID())
            {
                auto it = find(inventory.begin(), inventory.end(), i);
                inventory.erase(it);
                delete i; // clean up allocated memory after erasing the element
                return;   // return immediately
            }
        }
    }
    void particularItem(int n)
    {
        for (auto i : inventory)
        {
            if (n == i->itemID())
            {
                i->itemInfo();
            }
        }
    }
};

int main()
{
    Player *p1 = new Player("Adwaiy");
    p1->addItem(new Weapon(100, "Sword", 1000, 100));
    p1->addItem(new Potion(101, "Mana Potion", 1200, 100));
    p1->addItem(new Armour(102, "Helmet", 500, 30));
    p1->addItem(new Weapon(105, "Bow", 20, 4));
    p1->addItem(new Armour(106, "Shield", 800, 20));
    cout << "Every Item Currently Owned: " << endl;
    p1->displayInfo();
    cout << endl;
    p1->inventoryValue();
    p1->removeItem(102);
    p1->particularItem(100);
    delete p1;
    p1 = nullptr;
}