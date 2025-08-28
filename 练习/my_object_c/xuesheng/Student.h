#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"
#include <string>
#include <iostream>


using namespace std;


class Student {
private:
    string username;
    string password;
    string role; // "student", "teacher", "admin"
    string studentId;
    string name;
    string className;
public:
    Grade grade;//��Ϊ������Ա������������Ҳ�ܷ���

public:
    Student();
    Student(const string& username, const string& password, const string& studentId, const string& name, const string& className);

    string getStudentId() const;
    string getName() const;
    string getClassName() const;
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;

    void setStudentId(const string& studentId);
    void setName(const string& name);
    void setClassName(const string& className);
    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);



    void viewGrades();//�鿴���˳ɼ�
    void oneGrades();//�鿴���Ƴɼ�
    void updateInfo();//���¸�����Ϣ
    void showData();//�鿴������Ϣ

    Student &studentDisplay();//չʾ�˵�
    string toString() const;
};

#endif // STUDENT_H

