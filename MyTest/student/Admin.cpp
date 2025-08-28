#include "Admin.h"

#include <iostream>
using namespace std;

// 构造函数实现
Admin::Admin(string username,string password, Login& loginInstance) : User(username,password,"admin"), login(loginInstance) {
    this->username = username;
    this->password = password;
    this->role = "admin";
    log = new Logger(login);
}

// 添加用户实现
void Admin::addUser() {
    string username, password,role;
    int flag;
    cout << "请选择添加的角色（1.学生/2.老师/3.管理员）：";
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
        cout<<"无效选项";
        return;
    }
    if (login.registerUser(username, password, role)) {
        cout << "用户 " << username << " 注册成功！" << endl;
        log->log("管理员用户："+this->username+" 添加了一名"+role+"用户:"+username);
        login.saveCredentials();
    }
    else {
        cout << "注册失败，用户名可能已存在！" << endl;
    }

}

// 查看所有用户实现
void Admin::viewAllUsers() {
    cout << "所有用户账号信息：" << endl;
    login.viewAllAccounts(); // 调用Login类的方法查看所有账户信息
    log->log("管理员用户："+this->username+" 查询了所有用户信息");
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
        log->log("管理员用户："+this->username+" 删除了"+ role+ "用户:" + username);
        login.saveCredentials();
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
        log->log("管理员用户："+this->username+" 删除了"+ role+ "用户:" + username);
        login.saveCredentials();
    }
    else {
        cout << "删除失败，用户不存在！" << endl;
    }
}

void Admin::exportAll() {
    Export myExport(login);
    myExport.exportToCSV();
    log->log("管理员用户："+this->username+" 导出了系统的信息");
}

void Admin::systemLog() {
    Logger log(login);
    log.printLogs();
}

void Admin::systemNotice() {
    string title;string message;
    cout<<"请输入公告标题:";cin>>title;
    cout<<"请输入公告内容:";cin>>message;
    Announcement announcement(login);
    announcement.publishAnnouncement("标题:"+title+"\n"+"公告内容:"+message);
    announcement.printAnnouncements();
    log->log("管理员用户："+this->username+" 发布了公告");
    login.saveCredentials();
}

void Admin::modify_info() {
    find_info();
    string newpas;
    cout<<"请输入新的密码:";
    cin>>newpas;
    this->password = newpas;
    login.adminCredentials[username] = newpas;
    cout<<"修改密码成功"<<endl;
    login.saveCredentials();
    log->log("管理员用户："+username+" 修改了自己的密码:"+this->password);
}

void Admin::find_info() {
    cout<<"尊贵的管理员："<<endl;
    cout<<"您当前的用户名为:"<<this->username<<endl;
    cout<<"您当前的密码为:"<<this->password<<endl;
    log->log("管理员用户："+this->username+" 查看了了自己的信息");
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
        cout << "7．导出所有信息" << endl;
        cout << "8. 查看个人信息"<<endl;
        cout << "9. 修改个人信息"<<endl;
        cout << "0. 退出" << endl;
        cout << "请选择操作 (0-9): ";
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
                exportAll();
                cout<<"导出成功"<<endl;
                return;
            case 8:
                find_info();
                break;
            case 9:
                modify_info();
                break;
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

Admin::~Admin() {
    login.saveCredentials();
}




