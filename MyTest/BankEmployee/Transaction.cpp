#include "Transaction.h"
#include <iostream>

Transaction::Transaction(std::string transactionId, std::string accountNumber, double amount, std::string date, std::string type)
    : transactionId(transactionId), accountNumber(accountNumber), amount(amount), date(date), type(type) {}

void Transaction::displayTransaction() const { // const 修饰符
    std::cout << "交易 ID: " << transactionId << ", 账户: " << accountNumber
        << ", 金额: " << amount << ", 日期: " << date << ", 类型: " << type << std::endl;
}
