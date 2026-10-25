#include "inventoryManager.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <limits>

void InventoryManager::add_products_in_inventory()
{
    int n = 0;
    std::cout << "How many products you want to add?: ";
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (n != 0)
    {
        auto p = std::make_unique<Product>();
        p->input();
        inventory_object->addProduct(std::move(p));
        std::cout << std::endl;
        n--;
    }
}

void InventoryManager::remove_products_from_inventory()
{
    std::string id;
    int n = 0;
    std::cout << "How many products you want to remove ?: ";
    std::cin >> n;
    while (n != 0)
    {
        std::cout << "Enter ID: ";
        std::cin >> id;
        inventory_object->removeProduct(id);
        n--;
    }
}

void InventoryManager::total_products_in_inventory()
{
    std::cout << "Total Products in Inventory are: " << inventory_object->total_products();
    std::cout << std::endl;
}

void InventoryManager::total_value_of_inventory()
{
    std::cout << "Total Value of Inventory is: " << inventory_object->total_inventory_value();
    std::cout << std::endl;
}

void InventoryManager::search_a_product()
{
    inventory_object->search_product();
}

void InventoryManager::ProductsInfo()
{
    std::cout << "===== ALL PRODUCTS IN INVENTORY =====\n\n\n";
    inventory_object->allProductsInfo();
}