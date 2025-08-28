//
// Created by 22890 on 2025/1/4.
//

#ifndef MYTEST_USER_H
#define MYTEST_USER_H
#include "iostream"

using namespace std;

class User {
public:
    string username;
    string password;
    string role; // "student", "teacher", "admin"
    string name;
    string sex;
    string phone;
    string address;
    User(string username,string password,string role);
    User(string username,string password,string role,string name);
    User(string username,string password,string name,string role,string sex,string phone,string address);
    virtual void modify_info();
    virtual void find_info();

    // getter\setter
    const string &getUsername() const;
    void setUsername(const string &username);
    const string &getPassword() const;
    void setPassword(const string &password);
    const string &getRole() const;
    void setRole(const string &role);
    const string &getName() const;
    void setName(const string &name);
    const string &getSex() const;
    void setSex(const string &sex);
    const string &getPhone() const;
    void setPhone(const string &phone);
    const string &getAddress() const;
    void setAddress(const string &address);
};


#endif //MYTEST_USER_H
