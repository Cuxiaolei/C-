#pragma once
#ifndef LOGIN_H
#define LOGIN_H

#include "Student.h"
#include "User.h"
#include <unordered_map>
#include "map"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Login {
public:
    unordered_map<string, Student> studentCredentials; // �洢ѧ���û����� Student ����
    unordered_map<string, map<string,string>> teacherCredentials; // �洢��ʦ�û����ͻ�����Ϣ
    unordered_map<string, string> adminCredentials; // �洢����Ա�û����������
    vector<string> systemLog;
    vector<string> announcement;

public:
    Login(); // ���캯�������ڳ�ʼ���û�
    virtual ~Login();
    //ע���û�
    bool registerUser(const string& username, const string& password, const string& role);
    //��½
    bool loginUser(const string& username, const string& password, const string& role);
    //ע��
    bool logoutUser(const string& username, const string& role); // ע���û�
    //�޸��û���Ϣ
    bool modifyUser(const string& username, const string& newPassword, const string& role);
    void saveCredentials(); // ����ƾ֤���ļ�
    void loadCredentials(); // ���ļ�����ƾ֤
    void viewAllAccounts(); // �鿴�����˻���Ϣ
};

#endif // LOGIN_H
