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
    //���캯��
    Admin(string username, string password, Login& loginInstance);
    virtual ~Admin();
    void modify_info() override;
    void find_info() override;
    //1.�鿴�����˻���Ϣ�����û��������룩
    void viewAllUsers();
    //2.¼�����û���Ϣ
    void addUser();
    //3.ɾ���û�
    void deleteUser();
    //4.�޸��û���Ϣ
    void modifyUser();
    //5.�鿴ϵͳ��־
    void systemLog();
    //6.����ϵͳ����
    void systemNotice();
    //8.����������Ϣ
    void exportAll();




    //��ʾ���ܲ˵�
    void display();
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;
    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);
};

#endif // ADMIN_H


