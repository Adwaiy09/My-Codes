#pragma once
#include <string>
class Account
{
protected:
    std::string type;
    double balance = 0;

public:
    Account(std::string type);
    virtual void accDetails();
    virtual std::string getType() = 0;
    virtual void addDeposit(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double interestRate = 0.04;

public:
    using Account::Account;
    void accDetails() override;
    std::string getType() override;
    void addDeposit(double amount) override;
};

class CurrentAccount : public Account
{
public:
    using Account::Account;
    void accDetails() override;
    std::string getType() override;
    void addDeposit(double amount) override;
    double overdraftCalc();
};