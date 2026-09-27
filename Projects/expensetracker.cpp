#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

class userInfo
{
private:
    std::string name;
    std::string date;

public:
    void takeUserInfo()
    {
        std::cout << "Enter your name: ";
        getline(std::cin, name);
        std::cout << "Enter date(dd/mm/yy): ";
        std::cin >> date;
        std::cout << std::endl;
    }
    void userDetails(std::ostream &output)
    {
        output << "Name: " << name << std::endl;
        output << "Date: " << date << std::endl;
    }
};

class Expenses
{
private:
    double food;
    double electricity;
    double emi;
    std::string custom;
    double expensenum;

    std::unordered_map<std::string, double> store;

public:
    void askUser()
    {
        std::cout << " ===== ENTER CHOICES =====\n";
        std::cout << "1. Food\n2. Electricity Bill\n3. EMI\n4. Custom\n5. EXIT\n";
    }
    void inputExpenses()
    {
        int input = 0;

        while (input != 5)
        {
            std::cout << "Enter choice: ";
            std::cin >> input;
            if (input == 0)
            {
                std::cout << "Enter valid choice !!" << std::endl;
            }
            if (input > 5)
            {
                std::cout << "Invalid choice" << std::endl;
            }

            if (input == 1)
            {
                std::cout << "Food expense: ";
                std::cin >> food;
                store["Food"] = food;
            }
            if (input == 2)
            {
                std::cout << "Electricity expense: ";
                std::cin >> electricity;
                store["Electricity"] = electricity;
            }
            if (input == 3)
            {
                std::cout << "EMI expense: ";
                std::cin >> emi;
                store["EMI"] = emi;
            }
            if (input == 4)
            {
                std::cout << "Name of custom category: ";
                std::cin >> custom;
                std::cout << "Enter " << custom << " expense: ";
                std::cin >> expensenum;
                store[custom] = expensenum;
            }
        }
    }
    double totalExpense()
    {
        double sum = 0;
        for (auto i : store)
        {
            sum += i.second;
        }
        return sum;
    }
    void expensesDetails(std::ostream &out)
    {
        out << "  ===== Expenses =====\n";
        for (auto i : store)
        {
            out << "   " << i.first << ": " << i.second << std::endl;
        }
        out << "Total Expenses: " << totalExpense() << std::endl
            << std::endl;
    }
};

int main()
{
    userInfo *uinfo = new userInfo;
    Expenses *exp = new Expenses;
    std::ofstream expensefile("expenses.txt", std::ios::app);

    std::cout << "               ========== EXPENSE TRACKER ==========\n";
    uinfo->takeUserInfo();
    exp->askUser();
    exp->inputExpenses();
    std::cout << std::endl;
    uinfo->userDetails(std::cout);
    uinfo->userDetails(expensefile);
    exp->expensesDetails(std::cout);
    exp->expensesDetails(expensefile);
    expensefile.close();
    delete uinfo;
    delete exp;
}