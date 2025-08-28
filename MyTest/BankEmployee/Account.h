#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Customer.h"

class Account {
private:
    std::string accountNumber;
    double balance;
    Customer owner;

public:
    Account(std::string accountNumber, Customer owner);
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const; // const ���η�
    std::string getAccountNumber() const; // const ���η�
    std::string getOwnerInfo() const; // const ���η�
};

#endif // ACCOUNT_H
