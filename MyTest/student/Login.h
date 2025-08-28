#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include "Student.h"
#include "User.h"
#include <unordered_map>
#include "map"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Login {
public:
    unordered_map<string, Student> studentCredentials; // 存储学生用户名和 Student 对象
    unordered_map<string, map<string,string>> teacherCredentials; // 存储教师用户名和基础信息
    unordered_map<string, string> adminCredentials; // 存储管理员用户名和密码对
    vector<string> systemLog;
    vector<string> announcement;

public:
    Login(); // 构造函数，用于初始化用户
    virtual ~Login();
    //注册用户
    bool registerUser(const string& username, const string& password, const string& role);
    //登陆
    bool loginUser(const string& username, const string& password, const string& role);
    //注销
    bool logoutUser(const string& username, const string& role); // 注销用户
    //修改用户信息
    bool modifyUser(const string& username, const string& newPassword, const string& role);
    void saveCredentials(); // 保存凭证到文件
    void loadCredentials(); // 从文件加载凭证
    void viewAllAccounts(); // 查看所有账户信息
};

#endif // LOGIN_H
