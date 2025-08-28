//
// Created by 22890 on 2024/11/1.
//


#include "Login.h"
#include "Information.h"

using namespace std;

int main() {
    Login login; //初始化并加载所有账户信息
    login.loadCredentials();    //加载信息


    Student student("aklsjd","123546","2340000","tlx","jike2302");
    cout<<"查询成绩"<<endl;
    student.viewGrades();
    cout<<"查询个人信息"<<endl;
    student.showData();



//    while (true) {
//        cout << "欢迎来到学生管理系统！" << endl;
//        cout << "1. 登录" << endl;
//        cout << "2. 注册" << endl;
//        cout << "3. 退出" << endl;
//        cout << "请输入选项（1-3）：";
//
//        int choice;
//        cin >> choice;
//
//        if (choice == 1) {
//            string username, password, role;
//            cout << "请输入角色（student(学生)/teacher(老师)/admin(管理员)）：";
//            cin >> role;
//            cout << "用户名: ";
//            cin >> username;
//            cout << "密码: ";
//            cin >> password;
//            if (login.loginUser(username, password, role)) {
//                cout << "登录成功！" << endl;
//                Information information(username,role,login);
//                information.display();
//            }
//            else {
//                cout << "登录失败，请检查用户名或密码。" << endl;
//            }
//        }
//        else if (choice == 2) {
//            string username, password, role;
//            cout << "请输入角色（student(学生)/teacher(老师)/admin(管理员)）：";
//            cin >> role;
//            cout << "用户名: ";
//            cin >> username;
//            cout << "密码: ";
//            cin >> password;
//            if (login.registerUser(username, password, role)) {
//                cout << "注册成功！" << endl;
//            }
//            else {
//                cout << "注册失败，用户名可能已存在。" << endl;
//            }
//        }
//        else if (choice == 3) {
//            cout << "退出程序。" << endl;
//            break;
//        }
//        else {
//            cout << "无效选项，请重新输入。" << endl;
//        }
//    }
//    login.saveCredentials();
    return 0;
}