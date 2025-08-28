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
    Grade grade;//作为公共成员，在其他类中也能访问

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



    void viewGrades();//查看个人成绩
    void oneGrades();//查看单科成绩
    void updateInfo();//更新个人信息
    void showData();//查看个人信息

    Student &studentDisplay();//展示菜单
    string toString() const;
};

#endif // STUDENT_H

