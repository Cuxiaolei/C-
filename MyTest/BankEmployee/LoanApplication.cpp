#include "LoanApplication.h"

LoanApplication::LoanApplication(std::string applicationId, Customer applicant, double loanAmount)
    : applicationId(applicationId), applicant(applicant), loanAmount(loanAmount), status("������") {}

void LoanApplication::approve() {
    status = "����׼";
}

void LoanApplication::reject() {
    status = "�Ѿܾ�";
}

std::string LoanApplication::getStatus() const { // const ���η�
    return status;
}
