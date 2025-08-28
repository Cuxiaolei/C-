#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "Login.h"
#include "Export.h"

class Admin {
private:
    string username;
    string password;
    string role; // "student", "teacher", "admin"
    Login& login;
public:
    //构造函数
    Admin(const string& username, const string& password, Login& loginInstance);
    //1.查看所有账户信息、（用户名、密码）
    void viewAllUsers();
    //2.录入新用户信息
    void addUser();
    //3.删除用户
    void deleteUser();
    //4.修改用户信息
    void modifyUser();
    //5.查看系统日志
    void systemLog();
    //6.发布系统公告
    void systemNotice();
    //7.设置学生、老师管理员
    void setAdmin();
    //8.导出所有信息
    void exportAll();
    //9.设置新的课程信息
    void addCourse();
    //10.修改或删除已有的课程信息
    void setCourse();




    //显示功能菜单
    void display();
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;
    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);
};

#endif // ADMIN_H


