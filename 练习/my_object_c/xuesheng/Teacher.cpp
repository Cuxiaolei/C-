#include "Teacher.h"
#include "Information.h"
#include <iostream>
using namespace std;

Teacher::Teacher(const string& username, const string& password, Login& login)
        : username(username), password(password), role("teacher"), login(login) {}

void Teacher::addStudent() {
    string username;
    string password;
    string studentId;
    string name;
    string className;
    cout<<"请输入添加学生的信息"<<endl;
    cout<<"用户名:";
    cin>>username;
    // 检查学生是否已经存在
    auto it = login.studentCredentials.find(username);
    if (it != login.studentCredentials.end()){
        cout << "用户名 " << username << " 已存在，无法添加。" << endl;
        return;
    }
    cout<<"密码:";
    cin>>password;
    cout<<"学号:";
    cin>>studentId;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == studentId)
        {
            cout<<"该学号已存在,学好信息为：";
            s.second.toString();
            cout<<"请重新添加";
            return;
        }
    }
    cout<<"姓名:";
    cin>>name;
    cout<<"班级";
    cin>>className;
    Student newStudent(username,password,studentId,name,className);
    login.studentCredentials.insert({username, newStudent});
    cout << "已添加学生: ID" << studentId << " (" << name << ")" << endl;
}

void Teacher::modifyStudent() {
    cout<<"请输入需要修改学生信息的id:";
    string id;
    cin>>id;
    for(auto &s : login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            cout<<"该学生的用户名为："<<s.second.getUsername();
            cout<<"请输入修改后该学生的信息:";
            string password;
            string name;
            string className;
            cout<<"密码:";
            cin>>password;
            cout<<"姓名:";
            cin>>name;
            cout<<"班级:";
            cin>>className;
            s.second.setPassword(password);
            s.second.setName(name);
            s.second.setClassName(className);
            cout << "已修改学生: " << id << " (" << name << ")" << endl;
            return;
        }

    }
    cout << "未找到学生: " << id << endl; // 未找到学生
}
void Teacher::deleteStudent() {
    string id;
    string username = " ";
    cout<<"请输入需要删除学生的学号:";
    cin>>id;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            username = s.second.getUsername();
            return;
        }
    }
    if(username != " ") {
        cout<<"已成功删除该学生：id("<<id<<")，姓名("<<login.studentCredentials[username].getName()<<")"<<endl;
        login.studentCredentials.erase(username);
    }
    else {
        cout<<"不存在该学生，无法删除";
    }

}

void Teacher::addGrade() {
    cout<<"请输入学生id";
    string id;
    cin>>id;
    // 检查成绩是否已存在
    for (auto &s : login.studentCredentials) {
        if(s.second.getStudentId() == id)
        {
            s.second.grade.addScore(id,s.second.getName());
            return;
        }
    }
    cout<<"不存在该学生，无法添加成绩"<<endl;
}

void Teacher::modifyGrade() {
    string id;
    cout<<"请输入需要修改成绩学生的学号:";
    cin>>id;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            s.second.grade.updateScore(id);
            return;
        }
    }
    cout<<"不存在该学生，无法修改成绩"<<endl;
}


// 删除成绩
void Teacher::deleteGrade() {
    string id;
    cout<<"请输入需要删除成绩学生的学号:";
    cin>>id;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            s.second.grade.deleteScore(id);
            return;
        }
    }
    cout<<"不存在该学生，无法删除成绩"<<endl;
}

void Teacher::showStudents() {
    // 设置表头
    cout << left << setw(15) << "学号"
        << left<< setw(11) << "姓名"
        << left<< setw(11) << "数学"
        << left<< setw(11) << "英语"
        << left<< setw(11) << "科学"
        << left<< setw(11) << "历史"
        << left<< setw(11) << "地理"
        << left << setw(11) << "艺术"
        << left<< setw(11) << "总分"
        << left<< setw(11) << "平均分" << endl;

    for (auto& s : login.studentCredentials) {
        cout << left << setw(12) << s.second.getStudentId()
             << left << setw(8) << s.second.getName()
             << left << setw(8) << s.second.grade.getScore("math")
             << left << setw(8) << s.second.grade.getScore("english")
             << left << setw(8) << s.second.grade.getScore("science")
             << left << setw(8) << s.second.grade.getScore("history")
             << left << setw(8) << s.second.grade.getScore("geography")
             << left << setw(8) << s.second.grade.getScore("art")
             << left << setw(8) << s.second.grade.getTotal()
             << left << setw(8) << s.second.grade.getAverage() << endl;
    }
}

void Teacher::display() {
    int choice;
    do {
        cout << "欢迎使用教师菜单：" << endl;
        cout << "1. 查看所有学生信息"<<endl;
        cout << "2. 查询成绩单"<<endl;
        cout << "3. 添加学生" << endl;
        cout << "4. 修改学生信息" << endl;
        cout << "5. 删除学生" << endl;
        cout << "6. 添加成绩" << endl;
        cout << "7. 修改成绩" << endl;
        cout << "8. 删除成绩" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入您的选择: ";
        cin >> choice;
        switch (choice) {
            case 1:
                showStudents();
                break;
            case 2:
                transcript();
                break;
            case 3:
                addStudent();
                break;
            case 4:
                modifyStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                addGrade();
                break;
            case 7:
                modifyGrade();
                break;
            case 8:
                deleteGrade();
                break;
            case 0:
                cout << "退出程序..." << endl;
                break;
            default:
                cout << "无效的选择，请重试。" << endl;
                break;
        }
        cout << endl; // 添加空行以提高可读性
    } while (choice != 0);
}


const string &Teacher::getUsername() const {
    return username;
}

const string &Teacher::getPassword() const {
    return password;
}

const string &Teacher::getRole() const {
    return role;
}

void Teacher::setUsername(const string &username) {
    this->username = username;

}

void Teacher::setPassword(const string &password) {
    this->password = password;
}

void Teacher::setRole(const string &role) {
    this->role = role;

}

void Teacher::transcript() {
    Statistics statistics(login.studentCredentials);
    statistics.handleUserInput();
}



