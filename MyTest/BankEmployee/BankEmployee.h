#ifndef BANKEMPLOYEE_H
#define BANKEMPLOYEE_H

#include <string>
#include "Customer.h"

class BankEmployee {
private:
    std::string employeeId;
    std::string name;

public:
    BankEmployee(std::string employeeId, std::string name);
    void viewCustomerInfo(const Customer& customer) const; // const ����
    void processLoanApplication(const std::string& loanId) const; // const ����
};

#endif // BANKEMPLOYEE_H
