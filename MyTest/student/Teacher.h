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
    void showStudents();//查看所有学生信息
    void addStudent(); // 添加学生
    void modifyStudent(); // 修改学生信息
    void deleteStudent(); // 删除学生
    void addGrade(); // 添加成绩
    void modifyGrade(); // 修改成绩
    void deleteGrade(); // 删除成绩
    void transcript();      //查看学生成绩单
    void qureyGrade();//查询某个学生的成绩
    const string &getUsername() const;
    const string &getPassword() const;
    const string &getRole() const;

    void setUsername(const string &username);
    void setPassword(const string &password);
    void setRole(const string &role);
    void display();     //展示菜单
};

#endif // TEACHER_H


