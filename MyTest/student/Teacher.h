#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "Information.h"
#include "Login.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Statistics.h"
#include "Logger.h"

using namespace std;

class Teacher:public User{

private:
    Login& login;
    Logger* log;
public:
    Teacher(string username,string password,string role,string name,string sex,string phone,string address,Login& login);
    void find_info() override;
    void modify_info() override;
    void showStudents();//�鿴����ѧ����Ϣ
    void addStudent(); // ���ѧ��
    void modifyStudent(); // �޸�ѧ����Ϣ
    void deleteStudent(); // ɾ��ѧ��
    void addGrade(); // ��ӳɼ�
    void modifyGrade(); // �޸ĳɼ�
    void deleteGrade(); // ɾ���ɼ�
    void transcript();      //�鿴ѧ���ɼ���
    void qureyGrade();//��ѯĳ��ѧ���ĳɼ�
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);
    void display();     //չʾ�˵�
};

#endif // TEACHER_H


