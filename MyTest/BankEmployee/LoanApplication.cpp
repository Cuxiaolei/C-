#include "LoanApplication.h"

LoanApplication::LoanApplication(std::string applicationId, Customer applicant, double loanAmount)
    : applicationId(applicationId), applicant(applicant), loanAmount(loanAmount), status("待处理") {}

void LoanApplication::approve() {
    status = "已批准";
}

void LoanApplication::reject() {
    status = "已拒绝";
}

std::string LoanApplication::getStatus() const { // const 修饰符
    return status;
}
