#include "Teacher.h"
#include "Information.h"
#include <iostream>
using namespace std;

Teacher::Teacher(string username,string password,string role,string name,string sex,string phone,string address,Login& login)
        : User(username,password,role,name,sex,phone,address), login(login) {
    log = new Logger(login);
    this->username = username;
    this->password = password;
    this->role = role;
    this->name = name;
    this->sex = sex;
    this->phone = phone;
    this->address = address;
}

void Teacher::find_info() {
    cout<<"用户名:"<<this->username<<endl;
    cout<<"密码:"<<this->password<<endl;
    cout<<"姓名:"<<this->name<<endl;
    cout<<"性别:"<<this->sex<<endl;
    cout<<"联系方式:"<<this->phone<<endl;
    cout<<"家庭住址:"<<this->address<<endl;
    log->log("教师用户:"+this->username+"查询了个人信息");
}

void Teacher::modify_info() {
    find_info();
    cout<<"请输入修改后的密码：";
    cin>>this->password;
    cout<<"请输入修改后的姓名：";
    cin>>this->name;
    cout<<"请输入修改后的性别：（男：1，女：2)";
    cin>>this->sex;
    cout<<"请输入修改后的联系方式：";
    cin>>this->phone;
    cout<<"请输入修改后的家庭住址：";
    cin>>this->address;
    login.teacherCredentials[username]["password"] = password;
    login.teacherCredentials[username]["name"] = name;
    login.teacherCredentials[username]["sex"] = sex;
    login.teacherCredentials[username]["phone"] = phone;
    login.teacherCredentials[username]["address"] = address;

    log->log("教师用户:"+this->username+"修改了个人信息");

}

void Teacher::addStudent() {
    string username;
    string password;
    string studentId;
    string name;
    string className;
    string sex;
    string phone;
    string address;

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
            s.second.find_info();
            cout<<"请重新添加";
            break;
        }
    }
    cout<<"姓名:";
    cin>>name;
    cout<<"班级:";
    cin>>className;
    cout<<"性别:";
    cin>>sex;
    cout<<"电话:";
    cin>>phone;
    cout<<"家庭住址:";
    cin>>address;
    Student newStudent(username, password, "student", name, sex,phone,address,studentId,className);
    login.studentCredentials.insert({username, newStudent});
    cout << "已添加学生: 学号：" << studentId << "， 姓名" << name << endl;
    log->log("教师用户:"+this->username+"添加了学生账户："+username);
}

void Teacher::modifyStudent() {
    cout<<"请输入需要修改信息的学生的学号：";
    string id;
    cin>>id;
    bool f= true;
    for(auto &s : login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            f= false;
            cout<<"该学生的用户名为："<<s.second.getUsername()<<endl;
            cout<<"请输入修改后该学生的信息:"<<endl;
            string password;
            string name;
            string className;
            string username;
            cout << "用户名:" << endl;
            cin >> username;
            cout<<"密码:"<<endl;
            cin>>password;
            cout<<"姓名:"<<endl;
            cin>>name;
            cout<<"班级:"<<endl;
            cin>>className;
            s.second.setUsername(username);
            s.second.setPassword(password);
            s.second.setName(name);
            s.second.setClassName(className);
            cout << "已修改学生: " << "学号："<<id << ", 姓名：" << name << endl;
            log->log("教师用户:"+this->username+"修改了学生用户:"+username+"的信息");
            break;
        }
    }
    if(f)
    cout << "未找到学生: " << id << endl; // 未找到学生
}
void Teacher::deleteStudent() {
    string id;
    string username = " ";
    cout<<"请输入需要删除学生的学号：";
    cin>>id;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            username = s.second.getUsername();
            break;
        }
    }
    if(username != " ") {
        cout<<"已成功删除该学生：学号("<<id<<")，姓名("<<login.studentCredentials[username].getName()<<")"<<endl;
        login.studentCredentials.erase(username);
        log->log("教师用户:"+this->username+"删除了学生账户:"+username);
    }
    else {
        cout << "不存在该学生，无法删除" << endl;
    }

}

void Teacher::addGrade() {
    cout<<"请输入学生学号：";
    string id;
    cin>>id;
    bool f= true;
    // 检查成绩是否已存在
    for (auto &s : login.studentCredentials) {
        if(s.second.getStudentId() == id)
        {
            f= false;
            s.second.grade.addScore(id,s.second.getName());
            string usname = s.second.getUsername();
            log->log("教师用户:"+this->username+"为学生用户："+usname+"添加了成绩");
            break;
        }
    }
    if(f)
        cout << "不存在该学生，无法添加成绩" << endl;
}

void Teacher::modifyGrade() {
    string id;
    cout << "请输入需要修改成绩学生的学号：" << endl;
    cin>>id;
    bool f= true;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            f= false;
            s.second.grade.updateScore(id);
            string usname = s.second.getUsername();
            log->log("教师用户:"+this->username+"修改了学生用户:"+usname+"的成绩");
            break;
        }
    }
    if(f)
    cout << "不存在该学生，无法修改成绩" << endl;
}


// 删除成绩
void Teacher::deleteGrade() {
    string id;
    cout << "请输入需要删除成绩学生的学号：" << endl;
    cin>>id;
    bool f= true;
    for(auto &s:login.studentCredentials)
    {
        f= false;
        if(s.second.getStudentId() == id)
        {
            s.second.grade.deleteScore(id);
            string usname = s.second.getUsername();
            log->log("教师用户:"+this->username+"删除了了学生用户:"+usname+"的成绩");
            break;
        }
    }
    if(f)
    cout << "不存在该学生，无法删除成绩" << endl;
}

void Teacher::showStudents() {
    // 设置表头
    cout << left << setw(15) << "学号"
         << left<< setw(11) << "姓名"
         << left<< setw(11) << "数学"
         << left<< setw(11) << "英语"
         << left<< setw(11) << "物理"
         << left<< setw(11) << "汇编"
         << left<< setw(11) << "程序"
         << left << setw(11) << "电路"
         << left<< setw(11) << "总分"
         << left<< setw(11) << "平均分" << endl;

    for (auto& s : login.studentCredentials) {
        cout << left << setw(12) << s.second.getStudentId()
             << left << setw(8) << s.second.getName()
             << left << setw(8) << s.second.grade.getScore("math")
             << left << setw(8) << s.second.grade.getScore("english")
             << left << setw(8) << s.second.grade.getScore("science")
             << left << setw(8) << s.second.grade.getScore("assem1"
                                                           "ble")
             << left << setw(8) << s.second.grade.getScore("programming")
             << left << setw(8) << s.second.grade.getScore("circuit")
             << left << setw(8) << s.second.grade.getTotal()
             << left << setw(8) << s.second.grade.getAverage() << endl;
    }
}

void Teacher::display() {
    log->log("教师用户:"+this->username+"登录了系统");
    int choice;
    do {
        cout << "欢迎进入教师管理系统：" << endl;
        cout << "1. 查看所有学生信息"<<endl;
        cout << "2. 查询成绩单"<<endl;
        cout << "3. 添加学生" << endl;
        cout << "4. 修改学生信息" << endl;
        cout << "5. 删除学生" << endl;
        cout << "6. 添加成绩" << endl;
        cout << "7. 修改成绩" << endl;
        cout << "8. 删除成绩" << endl;
        cout << "9. 查看某个学生的成绩" << endl;
        cout << "10. 查看个人信息" << endl;
        cout << "11. 修改个人信息" << endl;
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
            case 9:
                qureyGrade();
                break;
            case 10:
                find_info();
                break;
            case 11:
                modify_info();
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
    log->log("教师用户:"+this->username+"查询了学生成绩单");
    statistics.handleUserInput();

}
//查看单个学生的成绩
void Teacher::qureyGrade()
{
    cout << "请输入需要查看成绩的学生的学号：";
    string stuid;
    cin >> stuid;
    bool f = true;
    for (auto& s : login.studentCredentials)
    {
        if (s.second.getStudentId() == stuid)
        {
            f = false;
            cout << "学号：" << s.second.getStudentId() << endl
                 << "姓名：" << s.second.getName() << endl
                 << "math：" << s.second.grade.getScore("math") << endl
                 << "english：" << s.second.grade.getScore("english") << endl
                 << "science：" << s.second.grade.getScore("science") << endl
                 << "history：" << s.second.grade.getScore("assemble") << endl
                 << "geography：" << s.second.grade.getScore("programming") << endl
                 << "art：" << s.second.grade.getScore("circuit") << endl
                 << "总分：" << s.second.grade.getTotal() << endl
                 << "平均分：" << s.second.grade.getAverage() << endl;
            string usname = s.second.getUsername();
            log->log("教师用户:"+this->username+"查询了学生用户:"+usname+"的成绩");
            break;
        }
    }
    if (f)
        cout << "不存在该学生，无法查看成绩" << endl;
}




