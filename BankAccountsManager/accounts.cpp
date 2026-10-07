#include "accounts.hpp"
#include <iostream>
#include <string>

//======= Account ========
Account::Account(std::string type)
{
    this->type = type;
}

void Account::accDetails()
{
    std::cout << "Account Type: " << type << std::endl;
    std::cout << "Account Balance: " << balance << std::endl;
}

//======= Saving Account =======

std::string SavingAccount::getType()
{
    return type;
}
void SavingAccount::addDeposit(double amount)
{
    balance += amount;
}

void SavingAccount::accDetails()
{
    Account::accDetails();
    std::cout << "Interest Offered: " << interestRate * 100 << "%" << std::endl;
}
//======== Current Account ======

std::string CurrentAccount::getType()
{
    return type;
}
void CurrentAccount::addDeposit(double amount)
{
    balance += amount;
}

double CurrentAccount::overdraftCalc()
{

    return balance * 0.1;
}
void CurrentAccount::accDetails()
{
    Account::accDetails();
    std::cout << "OverDraft Limit: " << overdraftCalc() << std::endl;
}