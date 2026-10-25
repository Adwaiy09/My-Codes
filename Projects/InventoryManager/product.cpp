#include <iostream>
#include <limits>
#include "product.hpp"

void Product::input()
{
    std::cout << "Enter Product ID: ";
    getline(std::cin, id);
    std::cout << "Enter Product Name: ";
    getline(std::cin, name);
    std::cout << "Enter Price: ";
    std::cin >> price;
    std::cout << "Enter Quantity: ";
    std::cin >> quantity;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string Product::getID()
{
    return id;
}
long int Product::total_value_of_product()
{
    return price * quantity;
}
void Product::productInfo()
{
    std::cout << "Product ID: " << id << std::endl;
    std::cout << "Product Name: " << name << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Quantity: " << quantity << std::endl;
}