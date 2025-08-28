//
// Created by 22890 on 2024/11/1.
//


#include "Login.h"
#include "Information.h"
#include "Admin.h"
using namespace std;

int main() {
    Login login; //��ʼ�������������˻���Ϣ
    //������Ϣ
    login.loadCredentials();
    while (true) {
        cout << "��ӭ����ѧ������ϵͳ��" << endl;
        cout << "1. ��¼" << endl;
        cout << "2. ע��" << endl;
        cout << "0. �˳�" << endl;
        cout << "������ѡ�0-2����";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password,role;
            int flag;
            cout << "��ѡ���¼�Ľ�ɫ��1.ѧ��/2.��ʦ/3.����Ա����";
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
                cout<<"��������ȷ��ѡ��";
                continue;
            }
            if (login.loginUser(username, password, role)) {
                cout << "��¼�ɹ���" << endl;
                Information information(username,role,login);
                information.display();
            }
            else {
                cout << "��¼ʧ�ܣ������û��������롣" << endl;
                continue;
            }
        }
        else if (choice == 2) {
            string username, password, role;
            int flag;
            cout << "��ѡ���¼�Ľ�ɫ��1.ѧ��/2.��ʦ/3.����Ա����";
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
                cout<<"��������ȷ��ѡ��";
                continue;
            }
            if (login.registerUser(username, password, role)) {
                cout << "ע��ɹ���" << endl;
            }else {
                cout << "ע��ʧ�ܣ��û��������Ѵ��ڡ�" << endl;
            }
        }
        else if (choice == 0) {
            cout << "�˳�����" << endl;
            break;
        }
        else {
            cout << "��Чѡ����������롣" << endl;
        }
    }
    login.saveCredentials();
    return 0;
}