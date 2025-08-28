#include "BankEmployee.h"
#include <iostream>

BankEmployee::BankEmployee(std::string employeeId, std::string name)
    : employeeId(employeeId), name(name) {}

void BankEmployee::viewCustomerInfo(const Customer& customer) const { // const ����
    std::cout << customer.getInfo() << std::endl;
}

void BankEmployee::processLoanApplication(const std::string& loanId) const { // const ����
    std::cout << "����������� ID: " << loanId << std::endl;
}
