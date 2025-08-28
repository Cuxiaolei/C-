#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
#include "Customer.h"

class Administrator {
private:
    std::string adminId;
    std::string name;

public:
    Administrator(std::string adminId, std::string name);
    void addUser(const Customer& customer) const; // const ����
    void deleteUser(const std::string& customerId) const; // const ����
    void generateReport() const; // const ���η�
};

#endif // ADMINISTRATOR_H
