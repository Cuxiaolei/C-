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
    //���캯��
    Admin(const string& username, const string& password, Login& loginInstance);
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
    //7.����ѧ������ʦ����Ա
    void setAdmin();
    //8.����������Ϣ
    void exportAll();
    //9.�����µĿγ���Ϣ
    void addCourse();
    //10.�޸Ļ�ɾ�����еĿγ���Ϣ
    void setCourse();




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


