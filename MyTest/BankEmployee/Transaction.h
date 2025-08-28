#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    std::string transactionId;
    std::string accountNumber;
    double amount;
    std::string date;
    std::string type;

public:
    Transaction(std::string transactionId, std::string accountNumber, double amount, std::string date, std::string type);
    void displayTransaction() const; // const ���η�
};

#endif // TRANSACTION_H
