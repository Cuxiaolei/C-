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
    void addUser(const Customer& customer) const; // const 引用
    void deleteUser(const std::string& customerId) const; // const 引用
    void generateReport() const; // const 修饰符
};

#endif // ADMINISTRATOR_H
