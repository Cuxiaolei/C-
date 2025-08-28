//
// Created by 22890 on 2024/11/1.
//


#include "Login.h"
#include "Information.h"
#include "Admin.h"
using namespace std;

int main() {
    Login login; //初始化并加载所有账户信息
    //加载信息
    login.loadCredentials();
    while (true) {
        cout << "欢迎来到学生管理系统！" << endl;
        cout << "1. 登录" << endl;
        cout << "2. 注册" << endl;
        cout << "0. 退出" << endl;
        cout << "请输入选项（0-2）：";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password,role;
            int flag;
            cout << "请选择登录的角色（1.学生/2.老师/3.管理员）：";
            cin >> flag;
            cout << "用户名: ";
            cin >> username;
            cout << "密码: ";
            cin >> password;
            if(flag == 1){
                role = "student";
            }else if(flag == 2){
                role = "teacher";
            }else if(flag == 3){
                role = "admin";
            }else{
                cout<<"请输入正确的选项";
                continue;
            }
            if (login.loginUser(username, password, role)) {
                cout << "登录成功！" << endl;
                Information information(username,role,login);
                information.display();
            }
            else {
                cout << "登录失败，请检查用户名或密码。" << endl;
                continue;
            }
        }
        else if (choice == 2) {
            string username, password, role;
            int flag;
            cout << "请选择登录的角色（1.学生/2.老师/3.管理员）：";
            cin >> flag;
            cout << "用户名: ";
            cin >> username;
            cout << "密码: ";
            cin >> password;
            if(flag == 1){
                role = "student";
            }else if(flag == 2){
                role = "teacher";
            }else if(flag == 3){
                role = "admin";
            }else{
                cout<<"请输入正确的选项";
                continue;
            }
            if (login.registerUser(username, password, role)) {
                cout << "注册成功！" << endl;
            }else {
                cout << "注册失败，用户名可能已存在。" << endl;
            }
        }
        else if (choice == 0) {
            cout << "退出程序。" << endl;
            break;
        }
        else {
            cout << "无效选项，请重新输入。" << endl;
        }
    }
    login.saveCredentials();
    return 0;
}