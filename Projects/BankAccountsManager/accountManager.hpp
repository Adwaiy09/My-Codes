#pragma once
#include "accounts.hpp"
#include "customer.hpp"
#include <string>
#include <vector>

class accountManager
{

private:
    std::vector<Customer *> customers;

public:
    ~accountManager();
    void addCustomer(Customer *c);
    void addAccountToCustomer(Customer *c, Account *a);
    void showCustomerInfo();
    void customerDeposit();
};