#include "Administrator.h"
#include <iostream>

Administrator::Administrator(std::string adminId, std::string name)
    : adminId(adminId), name(name) {}

void Administrator::addUser(const Customer& customer) const { // const 引用
    std::cout << "添加用户: " << customer.getInfo() << std::endl;
}

void Administrator::deleteUser(const std::string& customerId) const { // const 引用
    std::cout << "删除用户 ID: " << customerId << std::endl;
}

void Administrator::generateReport() const { // const 修饰符
    std::cout << "生成报告..." << std::endl;
}
