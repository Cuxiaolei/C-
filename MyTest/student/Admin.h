#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include "Export.h"
#include "User.h"
#include "Announcement.h"
#include "Logger.h"

class Admin : public User{
private:
    Login& login;
    Logger* log;
public:
    //构造函数
    Admin(string username, string password, Login& loginInstance);
    virtual ~Admin();
    void modify_info() override;
    void find_info() override;
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
    //8.导出所有信息
    void exportAll();




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


