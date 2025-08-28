#include "Information.h"
#include "Admin.h"
#include "Teacher.h"
Information::Information(string username, string role, Login& loginInstance) : username(username), role(role),login(loginInstance)
{

}
void Information::addStudent_info(){
    string name;string studentId;string className;
    string sex;string phone;string address;
    cout << "����������:";cin >> name;
    cout << "������ѧ��:";cin >> studentId;
    cout << "������༶:";cin >> className;
    cout << "�������Ա�:";cin >> sex;
    cout << "������绰:";cin >> phone;
    cout << "�������ͥסַ:";cin >> address;
    login.studentCredentials.find(username)->second.setName(name);
    login.studentCredentials.find(username)->second.setStudentId(studentId);
    login.studentCredentials.find(username)->second.setClassName(className);
    login.studentCredentials.find(username)->second.setSex(sex);
    login.studentCredentials.find(username)->second.setPhone(phone);
    login.studentCredentials.find(username)->second.setAddress(address);
    cout<<"�ɹ������Ϣ"<<endl;
}
void Information::addTeacher_info() {
    string name;string sex;string phone;string address;
    cout << "����������:";cin >> name;
    cout << "�������Ա�:";cin >> sex;
    cout << "������绰:";cin >> phone;
    cout << "��������ϵ��ʽ:";cin >> address;
    login.teacherCredentials.find(username)->second["name"] = name;
    login.teacherCredentials.find(username)->second["sex"] = sex;
    login.teacherCredentials.find(username)->second["phone"] = phone;
    login.teacherCredentials.find(username)->second["address"] = address;
    cout<<"�ɹ������Ϣ"<<endl;
}

void Information::display() {
    if (role == "student"){
        auto it = login.studentCredentials.find(username);
        if(it->second.getStudentId() == "")
        {
            cout << "ϵͳ��û��������Ϣ���봴����";
            addStudent_info();
            cout << "�����ɹ�,���Զ���¼" << endl;
        }
        login.studentCredentials[username] = login.studentCredentials.find(username)->second.studentDisplay();
        login.saveCredentials();
    }else if (role == "teacher"){
        map<string,string> m = login.teacherCredentials[username];
        if(m["name"] == ""){
            cout<<"����û�л�����Ϣ���봴��:";
            addTeacher_info();
        }
        Teacher teacher(username, m["password"], role, m["name"], m["sex"],
                        m["phone"],m["address"],login);
        teacher.display();
    }else if(role == "admin"){
        Admin admin(username,login.adminCredentials[username],login);
        admin.display();
    }else{
        cout<<"��½ʧ��"<<endl;
    }
}



