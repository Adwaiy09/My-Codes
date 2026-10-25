#pragma once
#include "inventory.hpp"
#include "product.hpp"
#include <memory>

class InventoryManager
{
private:
    std::unique_ptr<Inventory> inventory_object = std::make_unique<Inventory>();

public:
    void add_products_in_inventory();
    void remove_products_from_inventory();
    void total_products_in_inventory();
    void total_value_of_inventory();
    void search_a_product();
    void ProductsInfo();
};