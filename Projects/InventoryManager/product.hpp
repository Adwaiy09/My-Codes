#pragma once
#include <string>

class Product
{
private:
    std::string id;
    std::string name;
    long int price;
    long int quantity;

public:
    void input();
    std::string getID();
    long int total_value_of_product();
    void productInfo();
};