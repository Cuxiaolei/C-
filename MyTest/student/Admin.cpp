#include "Admin.h"

#include <iostream>
using namespace std;

// ���캯��ʵ��
Admin::Admin(string username,string password, Login& loginInstance) : User(username,password,"admin"), login(loginInstance) {
    this->username = username;
    this->password = password;
    this->role = "admin";
    log = new Logger(login);
}

// ����û�ʵ��
void Admin::addUser() {
    string username, password,role;
    int flag;
    cout << "��ѡ����ӵĽ�ɫ��1.ѧ��/2.��ʦ/3.����Ա����";
    cin >> flag;
    cout << "�û���: ";
    cin >> username;
    cout << "����: ";
    cin >> password;
    if(flag == 1){
        role = "student";
    }else if(flag == 2){
        role = "teacher";
    }else if(flag == 3){
        role = "admin";
    }else{
        cout<<"��Чѡ��";
        return;
    }
    if (login.registerUser(username, password, role)) {
        cout << "�û� " << username << " ע��ɹ���" << endl;
        log->log("����Ա�û���"+this->username+" �����һ��"+role+"�û�:"+username);
        login.saveCredentials();
    }
    else {
        cout << "ע��ʧ�ܣ��û��������Ѵ��ڣ�" << endl;
    }

}

// �鿴�����û�ʵ��
void Admin::viewAllUsers() {
    cout << "�����û��˺���Ϣ��" << endl;
    login.viewAllAccounts(); // ����Login��ķ����鿴�����˻���Ϣ
    log->log("����Ա�û���"+this->username+" ��ѯ�������û���Ϣ");
}

// �޸�����ʵ��
void Admin::modifyUser() {
    string username;
    string newPassword;
    string role;
    cout << "�������ɫ (student/teacher/admin): ";
    cin >> role;
    cout << "�������û���: ";
    cin >> username;
    cout << "������������: ";
    cin >> newPassword;
    if (login.modifyUser(username, newPassword, role)) {
        cout << "�޸�����ɹ���" << endl;
        log->log("����Ա�û���"+this->username+" ɾ����"+ role+ "�û�:" + username);
        login.saveCredentials();
    }
    else {
        cout << "�޸�����ʧ�ܣ��û������ڻ��������" << endl;
    }
}

// ɾ���û�ʵ��
void Admin::deleteUser() {
    string username;
    string role;
    cout << "�������ɫ (student/teacher/admin): ";
    cin >> role;
    cout << "������Ҫɾ�����û���: ";
    cin >> username;
    if (login.logoutUser(username, role)) {
        cout << "�û� " << username << " ��ע����" << endl;
        log->log("����Ա�û���"+this->username+" ɾ����"+ role+ "�û�:" + username);
        login.saveCredentials();
    }
    else {
        cout << "ɾ��ʧ�ܣ��û������ڣ�" << endl;
    }
}

void Admin::exportAll() {
    Export myExport(login);
    myExport.exportToCSV();
    log->log("����Ա�û���"+this->username+" ������ϵͳ����Ϣ");
}

void Admin::systemLog() {
    Logger log(login);
    log.printLogs();
}

void Admin::systemNotice() {
    string title;string message;
    cout<<"�����빫�����:";cin>>title;
    cout<<"�����빫������:";cin>>message;
    Announcement announcement(login);
    announcement.publishAnnouncement("����:"+title+"\n"+"��������:"+message);
    announcement.printAnnouncements();
    log->log("����Ա�û���"+this->username+" �����˹���");
    login.saveCredentials();
}

void Admin::modify_info() {
    find_info();
    string newpas;
    cout<<"�������µ�����:";
    cin>>newpas;
    this->password = newpas;
    login.adminCredentials[username] = newpas;
    cout<<"�޸�����ɹ�"<<endl;
    login.saveCredentials();
    log->log("����Ա�û���"+username+" �޸����Լ�������:"+this->password);
}

void Admin::find_info() {
    cout<<"���Ĺ���Ա��"<<endl;
    cout<<"����ǰ���û���Ϊ:"<<this->username<<endl;
    cout<<"����ǰ������Ϊ:"<<this->password<<endl;
    log->log("����Ա�û���"+this->username+" �鿴�����Լ�����Ϣ");
}


// ��ʾ�˵�ʵ��
void Admin::display() {
    int choice;
    while (true) {
        cout << "����Ա�˵�:" << endl;
        cout << "1���鿴�����˻���Ϣ���û��������룩" << endl;
        cout << "2��¼�����û���Ϣ" << endl;
        cout << "3��ɾ���û���Ϣ" << endl;
        cout << "4���޸��û���Ϣ" << endl;
        cout << "5���鿴ϵͳ��־" <<endl;
        cout << "6������ϵͳ����" << endl;
        cout << "7������������Ϣ" << endl;
        cout << "8. �鿴������Ϣ"<<endl;
        cout << "9. �޸ĸ�����Ϣ"<<endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ����� (0-9): ";
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
                cout<<"�����ɹ�"<<endl;
                return;
            case 8:
                find_info();
                break;
            case 9:
                modify_info();
                break;
            case 0:
                cout << "�˳�����" << endl;
                return;
            default:
                cout << "��Чѡ�������ѡ��" << endl;
        }
        cout << endl; // ��ӿ����Ա����Ķ�
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




