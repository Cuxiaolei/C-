//
// Created by 22890 on 2025/1/4.
//

#include "User.h"
User::User(string username, string password, string role) {
}
User::User(string username, string password,string role,string name) :username(username),password(password),role(role),name(name){
    this->sex="";
    this->phone="";
    this->address="";
}

User::User(string username, string password, string role,string name, string sex, string phone, string address) :
        username(username),password(password),name(name),role(role),sex(sex),phone(phone),address(address){
}

void User::modify_info() {

}

const string &User::getUsername() const {
    return username;
}

void User::setUsername(const string &username) {
    User::username = username;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    User::password = password;
}

const string &User::getRole() const {
    return role;
}

void User::setRole(const string &role) {
    User::role = role;
}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    User::name = name;
}

const string &User::getSex() const {
    return sex;
}

void User::setSex(const string &sex) {
    User::sex = sex;
}

const string &User::getPhone() const {
    return phone;
}

void User::setPhone(const string &phone) {
    User::phone = phone;
}

const string &User::getAddress() const {
    return address;
}

void User::setAddress(const string &address) {
    User::address = address;
}

void User::find_info() {

}








