#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string id;
    std::string address;
    std::string phoneNumber;

public:
    Customer(std::string name, std::string id, std::string address, std::string phoneNumber);
    void updateInfo(std::string newAddress, std::string newPhoneNumber);
    std::string getInfo() const; // const ÐÞÊÎ·û
};

#endif // CUSTOMER_H
