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
    cout<<"���������ѧ������Ϣ"<<endl;
    cout<<"�û���:";
    cin>>username;
    // ���ѧ���Ƿ��Ѿ�����
    auto it = login.studentCredentials.find(username);
    if (it != login.studentCredentials.end()){
        cout << "�û��� " << username << " �Ѵ��ڣ��޷���ӡ�" << endl;
        return;
    }
    cout<<"����:";
    cin>>password;
    cout<<"ѧ��:";
    cin>>studentId;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == studentId)
        {
            cout<<"��ѧ���Ѵ���,ѧ����ϢΪ��";
            s.second.toString();
            cout<<"���������";
            return;
        }
    }
    cout<<"����:";
    cin>>name;
    cout<<"�༶";
    cin>>className;
    Student newStudent(username,password,studentId,name,className);
    login.studentCredentials.insert({username, newStudent});
    cout << "�����ѧ��: ID" << studentId << " (" << name << ")" << endl;
}

void Teacher::modifyStudent() {
    cout<<"��������Ҫ�޸�ѧ����Ϣ��id:";
    string id;
    cin>>id;
    for(auto &s : login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            cout<<"��ѧ�����û���Ϊ��"<<s.second.getUsername();
            cout<<"�������޸ĺ��ѧ������Ϣ:";
            string password;
            string name;
            string className;
            cout<<"����:";
            cin>>password;
            cout<<"����:";
            cin>>name;
            cout<<"�༶:";
            cin>>className;
            s.second.setPassword(password);
            s.second.setName(name);
            s.second.setClassName(className);
            cout << "���޸�ѧ��: " << id << " (" << name << ")" << endl;
            return;
        }

    }
    cout << "δ�ҵ�ѧ��: " << id << endl; // δ�ҵ�ѧ��
}
void Teacher::deleteStudent() {
    string id;
    string username = " ";
    cout<<"��������Ҫɾ��ѧ����ѧ��:";
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
        cout<<"�ѳɹ�ɾ����ѧ����id("<<id<<")������("<<login.studentCredentials[username].getName()<<")"<<endl;
        login.studentCredentials.erase(username);
    }
    else {
        cout<<"�����ڸ�ѧ�����޷�ɾ��";
    }

}

void Teacher::addGrade() {
    cout<<"������ѧ��id";
    string id;
    cin>>id;
    // ���ɼ��Ƿ��Ѵ���
    for (auto &s : login.studentCredentials) {
        if(s.second.getStudentId() == id)
        {
            s.second.grade.addScore(id,s.second.getName());
            return;
        }
    }
    cout<<"�����ڸ�ѧ�����޷���ӳɼ�"<<endl;
}

void Teacher::modifyGrade() {
    string id;
    cout<<"��������Ҫ�޸ĳɼ�ѧ����ѧ��:";
    cin>>id;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            s.second.grade.updateScore(id);
            return;
        }
    }
    cout<<"�����ڸ�ѧ�����޷��޸ĳɼ�"<<endl;
}


// ɾ���ɼ�
void Teacher::deleteGrade() {
    string id;
    cout<<"��������Ҫɾ���ɼ�ѧ����ѧ��:";
    cin>>id;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            s.second.grade.deleteScore(id);
            return;
        }
    }
    cout<<"�����ڸ�ѧ�����޷�ɾ���ɼ�"<<endl;
}

void Teacher::showStudents() {
    // ���ñ�ͷ
    cout << left << setw(15) << "ѧ��"
        << left<< setw(11) << "����"
        << left<< setw(11) << "��ѧ"
        << left<< setw(11) << "Ӣ��"
        << left<< setw(11) << "��ѧ"
        << left<< setw(11) << "��ʷ"
        << left<< setw(11) << "����"
        << left << setw(11) << "����"
        << left<< setw(11) << "�ܷ�"
        << left<< setw(11) << "ƽ����" << endl;

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
        cout << "��ӭʹ�ý�ʦ�˵���" << endl;
        cout << "1. �鿴����ѧ����Ϣ"<<endl;
        cout << "2. ��ѯ�ɼ���"<<endl;
        cout << "3. ���ѧ��" << endl;
        cout << "4. �޸�ѧ����Ϣ" << endl;
        cout << "5. ɾ��ѧ��" << endl;
        cout << "6. ��ӳɼ�" << endl;
        cout << "7. �޸ĳɼ�" << endl;
        cout << "8. ɾ���ɼ�" << endl;
        cout << "0. �˳�" << endl;
        cout << "����������ѡ��: ";
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
                cout << "�˳�����..." << endl;
                break;
            default:
                cout << "��Ч��ѡ�������ԡ�" << endl;
                break;
        }
        cout << endl; // ��ӿ�������߿ɶ���
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



