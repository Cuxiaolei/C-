#include "Information.h"
#include "Admin.h"
#include "Teacher.h"

Information::Information(string username, string role, Login& loginInstance) : username(username), role(role),login(loginInstance)
{

}

void Information::createNewStudent()
{
    string studentId;
    string name;
    string className;
    cout << "请输入学号:";
    cin >> studentId;
    cout << "请输入姓名:";
    cin >> name;
    cout << "请输入班级:";
    cin >> className;
    login.studentCredentials.find(username)->second.setStudentId(studentId);
    login.studentCredentials.find(username)->second.setName(name);
    login.studentCredentials.find(username)->second.setClassName(className);

}

void Information::display() {
    if (role == "student")
    {
        auto it = login.studentCredentials.find(username);
        if(it->second.getStudentId() == "")
        {
            cout << "系统还没有您的信息，请创建：";
            createNewStudent();
            cout << "创建成功,已自动登录" << endl;
        }
        login.studentCredentials[username] = login.studentCredentials.find(username)->second.studentDisplay();
        login.saveCredentials();
    }
    else if (role == "teacher")
    {
        Teacher teacher(username,login.teacherCredentials[username],login);
        teacher.display();
    }
    else if(role == "admin")
    {
        Admin admin(username,login.adminCredentials[username],login);
        admin.display();
    }
    else
    {
        cout<<"登陆失败"<<endl;
    }
}

