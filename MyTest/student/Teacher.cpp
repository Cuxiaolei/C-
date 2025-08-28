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
    cout<<"�û���:"<<this->username<<endl;
    cout<<"����:"<<this->password<<endl;
    cout<<"����:"<<this->name<<endl;
    cout<<"�Ա�:"<<this->sex<<endl;
    cout<<"��ϵ��ʽ:"<<this->phone<<endl;
    cout<<"��ͥסַ:"<<this->address<<endl;
    log->log("��ʦ�û�:"+this->username+"��ѯ�˸�����Ϣ");
}

void Teacher::modify_info() {
    find_info();
    cout<<"�������޸ĺ�����룺";
    cin>>this->password;
    cout<<"�������޸ĺ��������";
    cin>>this->name;
    cout<<"�������޸ĺ���Ա𣺣��У�1��Ů��2)";
    cin>>this->sex;
    cout<<"�������޸ĺ����ϵ��ʽ��";
    cin>>this->phone;
    cout<<"�������޸ĺ�ļ�ͥסַ��";
    cin>>this->address;
    login.teacherCredentials[username]["password"] = password;
    login.teacherCredentials[username]["name"] = name;
    login.teacherCredentials[username]["sex"] = sex;
    login.teacherCredentials[username]["phone"] = phone;
    login.teacherCredentials[username]["address"] = address;

    log->log("��ʦ�û�:"+this->username+"�޸��˸�����Ϣ");

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
            s.second.find_info();
            cout<<"���������";
            break;
        }
    }
    cout<<"����:";
    cin>>name;
    cout<<"�༶:";
    cin>>className;
    cout<<"�Ա�:";
    cin>>sex;
    cout<<"�绰:";
    cin>>phone;
    cout<<"��ͥסַ:";
    cin>>address;
    Student newStudent(username, password, "student", name, sex,phone,address,studentId,className);
    login.studentCredentials.insert({username, newStudent});
    cout << "�����ѧ��: ѧ�ţ�" << studentId << "�� ����" << name << endl;
    log->log("��ʦ�û�:"+this->username+"�����ѧ���˻���"+username);
}

void Teacher::modifyStudent() {
    cout<<"��������Ҫ�޸���Ϣ��ѧ����ѧ�ţ�";
    string id;
    cin>>id;
    bool f= true;
    for(auto &s : login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            f= false;
            cout<<"��ѧ�����û���Ϊ��"<<s.second.getUsername()<<endl;
            cout<<"�������޸ĺ��ѧ������Ϣ:"<<endl;
            string password;
            string name;
            string className;
            string username;
            cout << "�û���:" << endl;
            cin >> username;
            cout<<"����:"<<endl;
            cin>>password;
            cout<<"����:"<<endl;
            cin>>name;
            cout<<"�༶:"<<endl;
            cin>>className;
            s.second.setUsername(username);
            s.second.setPassword(password);
            s.second.setName(name);
            s.second.setClassName(className);
            cout << "���޸�ѧ��: " << "ѧ�ţ�"<<id << ", ������" << name << endl;
            log->log("��ʦ�û�:"+this->username+"�޸���ѧ���û�:"+username+"����Ϣ");
            break;
        }
    }
    if(f)
    cout << "δ�ҵ�ѧ��: " << id << endl; // δ�ҵ�ѧ��
}
void Teacher::deleteStudent() {
    string id;
    string username = " ";
    cout<<"��������Ҫɾ��ѧ����ѧ�ţ�";
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
        cout<<"�ѳɹ�ɾ����ѧ����ѧ��("<<id<<")������("<<login.studentCredentials[username].getName()<<")"<<endl;
        login.studentCredentials.erase(username);
        log->log("��ʦ�û�:"+this->username+"ɾ����ѧ���˻�:"+username);
    }
    else {
        cout << "�����ڸ�ѧ�����޷�ɾ��" << endl;
    }

}

void Teacher::addGrade() {
    cout<<"������ѧ��ѧ�ţ�";
    string id;
    cin>>id;
    bool f= true;
    // ���ɼ��Ƿ��Ѵ���
    for (auto &s : login.studentCredentials) {
        if(s.second.getStudentId() == id)
        {
            f= false;
            s.second.grade.addScore(id,s.second.getName());
            string usname = s.second.getUsername();
            log->log("��ʦ�û�:"+this->username+"Ϊѧ���û���"+usname+"����˳ɼ�");
            break;
        }
    }
    if(f)
        cout << "�����ڸ�ѧ�����޷���ӳɼ�" << endl;
}

void Teacher::modifyGrade() {
    string id;
    cout << "��������Ҫ�޸ĳɼ�ѧ����ѧ�ţ�" << endl;
    cin>>id;
    bool f= true;
    for(auto &s:login.studentCredentials)
    {
        if(s.second.getStudentId() == id)
        {
            f= false;
            s.second.grade.updateScore(id);
            string usname = s.second.getUsername();
            log->log("��ʦ�û�:"+this->username+"�޸���ѧ���û�:"+usname+"�ĳɼ�");
            break;
        }
    }
    if(f)
    cout << "�����ڸ�ѧ�����޷��޸ĳɼ�" << endl;
}


// ɾ���ɼ�
void Teacher::deleteGrade() {
    string id;
    cout << "��������Ҫɾ���ɼ�ѧ����ѧ�ţ�" << endl;
    cin>>id;
    bool f= true;
    for(auto &s:login.studentCredentials)
    {
        f= false;
        if(s.second.getStudentId() == id)
        {
            s.second.grade.deleteScore(id);
            string usname = s.second.getUsername();
            log->log("��ʦ�û�:"+this->username+"ɾ������ѧ���û�:"+usname+"�ĳɼ�");
            break;
        }
    }
    if(f)
    cout << "�����ڸ�ѧ�����޷�ɾ���ɼ�" << endl;
}

void Teacher::showStudents() {
    // ���ñ�ͷ
    cout << left << setw(15) << "ѧ��"
         << left<< setw(11) << "����"
         << left<< setw(11) << "��ѧ"
         << left<< setw(11) << "Ӣ��"
         << left<< setw(11) << "����"
         << left<< setw(11) << "���"
         << left<< setw(11) << "����"
         << left << setw(11) << "��·"
         << left<< setw(11) << "�ܷ�"
         << left<< setw(11) << "ƽ����" << endl;

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
    log->log("��ʦ�û�:"+this->username+"��¼��ϵͳ");
    int choice;
    do {
        cout << "��ӭ�����ʦ����ϵͳ��" << endl;
        cout << "1. �鿴����ѧ����Ϣ"<<endl;
        cout << "2. ��ѯ�ɼ���"<<endl;
        cout << "3. ���ѧ��" << endl;
        cout << "4. �޸�ѧ����Ϣ" << endl;
        cout << "5. ɾ��ѧ��" << endl;
        cout << "6. ��ӳɼ�" << endl;
        cout << "7. �޸ĳɼ�" << endl;
        cout << "8. ɾ���ɼ�" << endl;
        cout << "9. �鿴ĳ��ѧ���ĳɼ�" << endl;
        cout << "10. �鿴������Ϣ" << endl;
        cout << "11. �޸ĸ�����Ϣ" << endl;
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
    log->log("��ʦ�û�:"+this->username+"��ѯ��ѧ���ɼ���");
    statistics.handleUserInput();

}
//�鿴����ѧ���ĳɼ�
void Teacher::qureyGrade()
{
    cout << "��������Ҫ�鿴�ɼ���ѧ����ѧ�ţ�";
    string stuid;
    cin >> stuid;
    bool f = true;
    for (auto& s : login.studentCredentials)
    {
        if (s.second.getStudentId() == stuid)
        {
            f = false;
            cout << "ѧ�ţ�" << s.second.getStudentId() << endl
                 << "������" << s.second.getName() << endl
                 << "math��" << s.second.grade.getScore("math") << endl
                 << "english��" << s.second.grade.getScore("english") << endl
                 << "science��" << s.second.grade.getScore("science") << endl
                 << "history��" << s.second.grade.getScore("assemble") << endl
                 << "geography��" << s.second.grade.getScore("programming") << endl
                 << "art��" << s.second.grade.getScore("circuit") << endl
                 << "�ܷ֣�" << s.second.grade.getTotal() << endl
                 << "ƽ���֣�" << s.second.grade.getAverage() << endl;
            string usname = s.second.getUsername();
            log->log("��ʦ�û�:"+this->username+"��ѯ��ѧ���û�:"+usname+"�ĳɼ�");
            break;
        }
    }
    if (f)
        cout << "�����ڸ�ѧ�����޷��鿴�ɼ�" << endl;
}




