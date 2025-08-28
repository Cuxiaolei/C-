#include "Account.h"
#include <iostream>

Account::Account(std::string accountNumber, Customer owner)
    : accountNumber(accountNumber), owner(owner), balance(0.0) {}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        std::cout << "³É¹¦È¡¿î: " << amount << std::endl;
    }
    else {
        std::cout << "Óà¶î²»×ã£¡" << std::endl;
    }
}

double Account::getBalance() const { // const ÐÞÊÎ·û
    return balance;
}

std::string Account::getAccountNumber() const { // const ÐÞÊÎ·û
    return accountNumber;
}

std::string Account::getOwnerInfo() const { // const ÐÞÊÎ·û
    return owner.getInfo();
}
