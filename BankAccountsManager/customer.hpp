#pragma once
#include "accounts.hpp"
#include <string>
#include <vector>
class Customer
{

private:
    std::string name;
    int age;
    std::string occupation;
    std::vector<Account *> accounts;

public:
    const std::string getName();
    void inputs();
    void addAccounts(Account *a);
    void deposit();
    int totalAccounts();
    void customerInfo();
    void accountsOwned();
};