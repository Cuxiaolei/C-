#include "Customer.h"

Customer::Customer(std::string name, std::string id, std::string address, std::string phoneNumber)
    : name(name), id(id), address(address), phoneNumber(phoneNumber) {}

void Customer::updateInfo(std::string newAddress, std::string newPhoneNumber) {
    address = newAddress;
    phoneNumber = newPhoneNumber;
}

std::string Customer::getInfo() const { // const 修饰符
    return "姓名: " + name + ", ID: " + id + ", 地址: " + address + ", 电话: " + phoneNumber;
}
