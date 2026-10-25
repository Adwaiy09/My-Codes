#include <iostream>
#include "inventory.hpp"

void Inventory::addProduct(std::unique_ptr<Product> p)
{
    inventory.push_back(std::move(p));
}

void Inventory::removeProduct(std::string id)
{
    for (auto it = inventory.begin(); it != inventory.end(); ++it)
    {
        if ((*it)->getID() == id)
        {

            inventory.erase(it);
            return;
        }
    }
}

int Inventory::total_products()
{
    int sum = 0;
    for (auto &i : inventory)
    {
        sum++;
    }
    return sum;
}

long int Inventory::total_inventory_value()
{
    long int value = 0;
    for (auto &i : inventory)
    {
        value += i->total_value_of_product();
    }
    return value;
}

void Inventory::search_product()
{
    std::string id;
    std::cout << "Enter ID of the product you want to search: ";
    std::cin >> id;
    for (auto &i : inventory)
    {
        if (id == i->getID())
        {
            std::cout << "=== PRODUCT INFO ===\n";
            i->productInfo();
            return;
        }
    }
    std::cout << "Invalid ID !!!";
}

void Inventory::allProductsInfo()
{
    int y = 1;
    for (auto &i : inventory)
    {
        std::cout << "===== ITEM No. " << y << " =====\n";
        i->productInfo();
        std::cout << std::endl;
        y++;
    }
}