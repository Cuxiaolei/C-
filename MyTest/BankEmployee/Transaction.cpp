#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string transactionId, std::string accountNumber, double amount, std::string date, std::string type)
    : transactionId(transactionId), accountNumber(accountNumber), amount(amount), date(date), type(type) {}

void Transaction::displayTransaction() const { // const ���η�
    std::cout << "���� ID: " << transactionId << ", �˻�: " << accountNumber
        << ", ���: " << amount << ", ����: " << date << ", ����: " << type << std::endl;
}
