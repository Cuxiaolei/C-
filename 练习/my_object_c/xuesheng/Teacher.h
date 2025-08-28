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
    void showStudents();//查看所有学生信息
    void addStudent(); // 添加学生
    void modifyStudent(); // 修改学生信息
    void deleteStudent(); // 删除学生
    void addGrade(); // 添加成绩
    void modifyGrade(); // 修改成绩
    void deleteGrade(); // 删除成绩
    void transcript();      //查看学生成绩单

    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);

    void display();     //展示菜单
};

#endif // TEACHER_H


