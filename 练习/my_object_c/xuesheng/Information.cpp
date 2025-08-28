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
    cout << "������ѧ��:";
    cin >> studentId;
    cout << "����������:";
    cin >> name;
    cout << "������༶:";
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
            cout << "ϵͳ��û��������Ϣ���봴����";
            createNewStudent();
            cout << "�����ɹ�,���Զ���¼" << endl;
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
        cout<<"��½ʧ��"<<endl;
    }
}

