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
        std::cout << "�ɹ�ȡ��: " << amount << std::endl;
    }
    else {
        std::cout << "���㣡" << std::endl;
    }
}

double Account::getBalance() const { // const ���η�
    return balance;
}

std::string Account::getAccountNumber() const { // const ���η�
    return accountNumber;
}

std::string Account::getOwnerInfo() const { // const ���η�
    return owner.getInfo();
}
