#include "customer.hpp"
#include <iostream>
#include <string>

void Customer::inputs()
{
    std::cout << "Enter your Name: ";
    std::cin >> name;
    std::cout << "Enter your Age: ";
    std::cin >> age;
    std::cout << "Enter your Occupation: ";
    std::cin >> occupation;
    std::cout << std::endl;
}
const std::string Customer::getName()
{
    return name;
}

void Customer::addAccounts(Account *a)
{
    accounts.push_back(a);
}
void Customer::deposit()
{
    int n;
    int accSerial = 0;
    for (auto account : accounts)
    {
        accSerial++;
        std::cout << "Enter amount you wish to deposit in " << accSerial << ". " << account->getType() << " Account of " << getName() << ": ";
        std::cin >> n;
        if (n > 0)
        {
            account->addDeposit(n);
        }
        else
        {
            std::cout << "Invalid amount!!!";
        }
    }
}
// one single amount is being transferred to every account , thats why im getting the same amount in every account

int Customer::totalAccounts()
{
    int count = 0;
    for (auto account : accounts)
    {
        count++;
    }
    return count;
}
void Customer::customerInfo()
{
    std::cout << "Customer Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Occupation: " << occupation << std::endl;
    std::cout << "Total Accounts Owned: " << totalAccounts() << std::endl;
}
void Customer::accountsOwned()
{
    int num = 0;
    std::cout << "===== All Accounts Details =====\n";
    for (auto account : accounts)
    {
        num++;
        std::cout << "Account No." << num << ":- ";
        account->accDetails();
        std::cout << std::endl;
    }
}