#ifndef LOANAPPLICATION_H
#define LOANAPPLICATION_H

#include <string>
#include "Customer.h"

class LoanApplication {
private:
    std::string applicationId;
    Customer applicant;
    double loanAmount;
    std::string status;

public:
    LoanApplication(std::string applicationId, Customer applicant, double loanAmount);
    void approve();
    void reject();
    std::string getStatus() const; // const ÐÞÊÎ·û
};

#endif // LOANAPPLICATION_H
