#include "Admin.h"
#include <iostream>
using namespace std;

// 构造函数实现
Admin::Admin(const string& username, const string& password, Login& loginInstance) : username(username), password(password), role("admin"), login(loginInstance) {

}

// 添加用户实现
void Admin::addUser() {
    string username;
    string password;
    string role;
    cout << "请输入角色 (student/teacher/admin): ";
    cin >> role;
    cout << "请输入用户名: ";
    cin >> username;
    cout << "请输入密码: ";
    cin >> password;
    if (login.registerUser(username, password, role)) {
        cout << "用户 " << username << " 注册成功！" << endl;
    }
    else {
        cout << "注册失败，用户名可能已存在！" << endl;
    }
}

// 查看所有用户实现
void Admin::viewAllUsers() {
    cout << "所有用户账号信息：" << endl;
    login.viewAllAccounts(); // 调用Login类的方法查看所有账户信息
}

// 修改密码实现
void Admin::modifyUser() {
    string username;
    string newPassword;
    string role;
    cout << "请输入角色 (student/teacher/admin): ";
    cin >> role;
    cout << "请输入用户名: ";
    cin >> username;
    cout << "请输入新密码: ";
    cin >> newPassword;
    if (login.modifyUser(username, newPassword, role)) {
        cout << "修改密码成功！" << endl;
    }
    else {
        cout << "修改密码失败，用户不存在或密码错误！" << endl;
    }
}

// 删除用户实现
void Admin::deleteUser() {
    string username;
    string role;
    cout << "请输入角色 (student/teacher/admin): ";
    cin >> role;
    cout << "请输入要删除的用户名: ";
    cin >> username;
    if (login.logoutUser(username, role)) {
        cout << "用户 " << username << " 已注销。" << endl;
    }
    else {
        cout << "删除失败，用户不存在！" << endl;
    }
}

void Admin::exportAll() {
    Export myExport(login);
    myExport.exportToCSV();
}

void Admin::systemLog() {

}

void Admin::systemNotice() {

}

void Admin::setAdmin() {

}

void Admin::addCourse() {

}

void Admin::setCourse() {

}


// 显示菜单实现
void Admin::display() {
    int choice;
    while (true) {
        cout << "管理员菜单:" << endl;
        cout << "1．查看所有账户信息（用户名、密码）" << endl;
        cout << "2．录入新用户信息" << endl;
        cout << "3．删除用户信息" << endl;
        cout << "4．修改用户信息" << endl;
        cout << "5．查看系统日志" <<endl;
        cout << "6．发布系统公告" << endl;
        cout << "7．设置学生、老师管理员" << endl;
        cout << "8．导出所有信息" << endl;
        cout << "9．设置新的课程信息" << endl;
        cout << "10．修改或删除已有的课程信息" << endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作 (0-10): ";
        cin >> choice;

        switch (choice) {
            case 1:
                viewAllUsers();
                break;

            case 2:
                addUser();
                break;

            case 3:
                deleteUser();
                break;

            case 4:
                modifyUser();
                break;

            case 5:
                systemLog();
                break;

            case 6:
                systemNotice();
                return;

            case 7:
                setAdmin();
                return;
            case 8:
                exportAll();
                cout<<"导出成功"<<endl;
                return;
            case 9:
                addCourse();
                return;
            case 10:
                setCourse();
                return;
            case 0:
                cout << "退出程序。" << endl;
                return;
            default:
                cout << "无效选项，请重新选择！" << endl;
        }
        cout << endl; // 添加空行以便于阅读
    }
}

const string &Admin::getUsername() const {
    return username;
}

const string &Admin::getPassword() const {
    return password;
}

const string &Admin::getRole() const {
    return role;
}

void Admin::setUsername(const string &username) {
    this->username = username;

}

void Admin::setPassword(const string &password) {
    this->password = password;
}

void Admin::setRole(const string &role) {
    this->role = role;

}



