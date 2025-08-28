#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "Information.h"
#include "Login.h"
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Statistics.h"
using namespace std;

class Teacher{

private:
    string username;
    string password;
    string role; // "student", "teacher", "admin"
    Login& login;
public:
    Teacher(const string& username, const string& password,Login& login);
    void showStudents();//�鿴����ѧ����Ϣ
    void addStudent(); // ���ѧ��
    void modifyStudent(); // �޸�ѧ����Ϣ
    void deleteStudent(); // ɾ��ѧ��
    void addGrade(); // ��ӳɼ�
    void modifyGrade(); // �޸ĳɼ�
    void deleteGrade(); // ɾ���ɼ�
    void transcript();      //�鿴ѧ���ɼ���

    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);

    void display();     //չʾ�˵�
};

#endif // TEACHER_H


