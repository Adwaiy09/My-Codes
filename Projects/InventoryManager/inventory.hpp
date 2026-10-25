#pragma once
#include <vector>
#include <memory>
#include <string>
#include "product.hpp"

class Inventory
{
private:
    std::vector<std::unique_ptr<Product>> inventory;

public:
    void addProduct(std::unique_ptr<Product> p);
    void removeProduct(std::string);
    int total_products();
    long int total_inventory_value();
    void search_product();
    void allProductsInfo();
};