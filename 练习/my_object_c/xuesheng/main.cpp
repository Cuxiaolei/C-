//
// Created by 22890 on 2024/11/1.
//


#include "Login.h"
#include "Information.h"

using namespace std;

int main() {
    Login login; //��ʼ�������������˻���Ϣ
    login.loadCredentials();    //������Ϣ


    Student student("aklsjd","123546","2340000","tlx","jike2302");
    cout<<"��ѯ�ɼ�"<<endl;
    student.viewGrades();
    cout<<"��ѯ������Ϣ"<<endl;
    student.showData();



//    while (true) {
//        cout << "��ӭ����ѧ������ϵͳ��" << endl;
//        cout << "1. ��¼" << endl;
//        cout << "2. ע��" << endl;
//        cout << "3. �˳�" << endl;
//        cout << "������ѡ�1-3����";
//
//        int choice;
//        cin >> choice;
//
//        if (choice == 1) {
//            string username, password, role;
//            cout << "�������ɫ��student(ѧ��)/teacher(��ʦ)/admin(����Ա)����";
//            cin >> role;
//            cout << "�û���: ";
//            cin >> username;
//            cout << "����: ";
//            cin >> password;
//            if (login.loginUser(username, password, role)) {
//                cout << "��¼�ɹ���" << endl;
//                Information information(username,role,login);
//                information.display();
//            }
//            else {
//                cout << "��¼ʧ�ܣ������û��������롣" << endl;
//            }
//        }
//        else if (choice == 2) {
//            string username, password, role;
//            cout << "�������ɫ��student(ѧ��)/teacher(��ʦ)/admin(����Ա)����";
//            cin >> role;
//            cout << "�û���: ";
//            cin >> username;
//            cout << "����: ";
//            cin >> password;
//            if (login.registerUser(username, password, role)) {
//                cout << "ע��ɹ���" << endl;
//            }
//            else {
//                cout << "ע��ʧ�ܣ��û��������Ѵ��ڡ�" << endl;
//            }
//        }
//        else if (choice == 3) {
//            cout << "�˳�����" << endl;
//            break;
//        }
//        else {
//            cout << "��Чѡ����������롣" << endl;
//        }
//    }
//    login.saveCredentials();
    return 0;
}