#include "Information.h"
#include "Admin.h"
#include "Teacher.h"
Information::Information(string username, string role, Login& loginInstance) : username(username), role(role),login(loginInstance)
{

}
void Information::addStudent_info(){
    string name;string studentId;string className;
    string sex;string phone;string address;
    cout << "请输入姓名:";cin >> name;
    cout << "请输入学号:";cin >> studentId;
    cout << "请输入班级:";cin >> className;
    cout << "请输入性别:";cin >> sex;
    cout << "请输入电话:";cin >> phone;
    cout << "请输入家庭住址:";cin >> address;
    login.studentCredentials.find(username)->second.setName(name);
    login.studentCredentials.find(username)->second.setStudentId(studentId);
    login.studentCredentials.find(username)->second.setClassName(className);
    login.studentCredentials.find(username)->second.setSex(sex);
    login.studentCredentials.find(username)->second.setPhone(phone);
    login.studentCredentials.find(username)->second.setAddress(address);
    cout<<"成功添加信息"<<endl;
}
void Information::addTeacher_info() {
    string name;string sex;string phone;string address;
    cout << "请输入姓名:";cin >> name;
    cout << "请输入性别:";cin >> sex;
    cout << "请输入电话:";cin >> phone;
    cout << "请输入联系方式:";cin >> address;
    login.teacherCredentials.find(username)->second["name"] = name;
    login.teacherCredentials.find(username)->second["sex"] = sex;
    login.teacherCredentials.find(username)->second["phone"] = phone;
    login.teacherCredentials.find(username)->second["address"] = address;
    cout<<"成功添加信息"<<endl;
}

void Information::display() {
    if (role == "student"){
        auto it = login.studentCredentials.find(username);
        if(it->second.getStudentId() == "")
        {
            cout << "系统还没有您的信息，请创建：";
            addStudent_info();
            cout << "创建成功,已自动登录" << endl;
        }
        login.studentCredentials[username] = login.studentCredentials.find(username)->second.studentDisplay();
        login.saveCredentials();
    }else if (role == "teacher"){
        map<string,string> m = login.teacherCredentials[username];
        if(m["name"] == ""){
            cout<<"您还没有基础信息，请创建:";
            addTeacher_info();
        }
        Teacher teacher(username, m["password"], role, m["name"], m["sex"],
                        m["phone"],m["address"],login);
        teacher.display();
    }else if(role == "admin"){
        Admin admin(username,login.adminCredentials[username],login);
        admin.display();
    }else{
        cout<<"登陆失败"<<endl;
    }
}



