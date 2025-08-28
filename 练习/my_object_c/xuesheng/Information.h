#pragma once
#include <iostream>
#include <vector>
#include "Login.h"
#include "Student.h"

using namespace std;


class Information {
private:
    string username;
    string role;
    Login& login;
public:
    Information(string username, string role, Login& loginInstance);
    void createNewStudent();//�����µ�ѧ����Ϣ
    void display();//��ʾ�˵�

};


