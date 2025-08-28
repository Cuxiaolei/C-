#include "Administrator.h"
#include <iostream>

Administrator::Administrator(std::string adminId, std::string name)
    : adminId(adminId), name(name) {}

void Administrator::addUser(const Customer& customer) const { // const ����
    std::cout << "����û�: " << customer.getInfo() << std::endl;
}

void Administrator::deleteUser(const std::string& customerId) const { // const ����
    std::cout << "ɾ���û� ID: " << customerId << std::endl;
}

void Administrator::generateReport() const { // const ���η�
    std::cout << "���ɱ���..." << std::endl;
}
