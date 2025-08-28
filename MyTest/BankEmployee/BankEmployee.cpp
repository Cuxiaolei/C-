#include "BankEmployee.h"
#include <iostream>

BankEmployee::BankEmployee(std::string employeeId, std::string name)
    : employeeId(employeeId), name(name) {}

void BankEmployee::viewCustomerInfo(const Customer& customer) const { // const 引用
    std::cout << customer.getInfo() << std::endl;
}

void BankEmployee::processLoanApplication(const std::string& loanId) const { // const 引用
    std::cout << "处理贷款申请 ID: " << loanId << std::endl;
}
