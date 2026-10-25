#include "functions.hpp"

void functions()
{
    std::vector<Customer *> vec;
    int n;
    int noOfAccounts;
    std::cout << "=============== WELCOME =============== \n";

    std::cout << "How many customers ?: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(new Customer);
    }
    accountManager *manager = new accountManager;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i]->inputs();
        manager->addCustomer(vec[i]);
    }

    for (int i = 0; i < vec.size(); i++)
    {
        int accCount = 0;
        std::cout
            << "How many Accounts " << vec[i]->getName() << " wants?: ";
        std::cin >> noOfAccounts;
        for (int j = 0; j < noOfAccounts; j++)
        {
            accCount = j + 1;
            std::string typeOfAccount;
            std::cout << accCount << ". Savings or Current?: ";
            std::cin >> typeOfAccount;
            if (typeOfAccount == "Savings" || typeOfAccount == "savings" || typeOfAccount == "saving" || typeOfAccount == "Saving")
            {
                manager->addAccountToCustomer(vec[i], new SavingAccount("Savings"));
            }
            if (typeOfAccount == "Current" || typeOfAccount == "current")
            {
                manager->addAccountToCustomer(vec[i], new CurrentAccount("Current"));
            }
        }
    }

    manager->customerDeposit();
    manager->showCustomerInfo();
    delete manager;
}