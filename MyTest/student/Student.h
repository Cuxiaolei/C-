#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Grade.h"
#include <string>
#include <iostream>
#include "User.h"

using namespace std;


class Student : public User{
private:
    string studentId;
    string className;
public:
    Grade grade;//作为公共成员，在其他类中也能访问

public:
    Student();
    Student(string username,string password,string role,string name,string sex,string phone,string address,string studentId,string className);
    void modify_info() override;
    void find_info() override;
    virtual ~Student()=default;

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

    Student &studentDisplay();//展示菜单
};

#endif // STUDENT_H

