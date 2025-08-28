#pragma once
#include <iostream>
#include <vector>
#include "Login.h"
#include "Student.h"

using namespace std;


class Information {
private:
    string username;
    string role;
    Login& login;
public:
    Information(string username, string role, Login& loginInstance);
    void createNewStudent();//创建新的学生信息
    void display();//显示菜单

};


