#include "accountManager.hpp"
#include <iostream>
#include <string>

void accountManager::addCustomer(Customer *c)
{
    customers.push_back(c);
}

void accountManager::addAccountToCustomer(Customer *c, Account *a)
{
    c->addAccounts(a);
}
void accountManager::customerDeposit()
{
    for (auto customer : customers)
    {
        customer->deposit();
    }
}

void accountManager::showCustomerInfo()
{
    std::cout << std::endl;
    std::cout << "======== Listed Customers ======== \n";
    for (auto customer : customers)
    {
        customer->customerInfo();
        customer->accountsOwned();
        std::cout << std::endl;
    }
}