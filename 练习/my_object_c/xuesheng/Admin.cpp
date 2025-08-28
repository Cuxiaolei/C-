#include "Admin.h"
#include <iostream>
using namespace std;

// ���캯��ʵ��
Admin::Admin(const string& username, const string& password, Login& loginInstance) : username(username), password(password), role("admin"), login(loginInstance) {

}

// ����û�ʵ��
void Admin::addUser() {
    string username;
    string password;
    string role;
    cout << "�������ɫ (student/teacher/admin): ";
    cin >> role;
    cout << "�������û���: ";
    cin >> username;
    cout << "����������: ";
    cin >> password;
    if (login.registerUser(username, password, role)) {
        cout << "�û� " << username << " ע��ɹ���" << endl;
    }
    else {
        cout << "ע��ʧ�ܣ��û��������Ѵ��ڣ�" << endl;
    }
}

// �鿴�����û�ʵ��
void Admin::viewAllUsers() {
    cout << "�����û��˺���Ϣ��" << endl;
    login.viewAllAccounts(); // ����Login��ķ����鿴�����˻���Ϣ
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
    }
    else {
        cout << "ɾ��ʧ�ܣ��û������ڣ�" << endl;
    }
}

void Admin::exportAll() {
    Export myExport(login);
    myExport.exportToCSV();
}

void Admin::systemLog() {

}

void Admin::systemNotice() {

}

void Admin::setAdmin() {

}

void Admin::addCourse() {

}

void Admin::setCourse() {

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
        cout << "7������ѧ������ʦ����Ա" << endl;
        cout << "8������������Ϣ" << endl;
        cout << "9�������µĿγ���Ϣ" << endl;
        cout << "10���޸Ļ�ɾ�����еĿγ���Ϣ" << endl;
        cout << "0. �˳�" << endl;
        cout << "��ѡ����� (0-10): ";
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
                setAdmin();
                return;
            case 8:
                exportAll();
                cout<<"�����ɹ�"<<endl;
                return;
            case 9:
                addCourse();
                return;
            case 10:
                setCourse();
                return;
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



