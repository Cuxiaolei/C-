#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include "Login.h"
#pragma once
using namespace std;

class Logger {
public:
    explicit Logger(Login& login);

// �洢��־������
    Login& login;
    void log(const string& operation);
    void printLogs() const;
private:
    // ��ȡ��ǰʱ���
    string getCurrentTime() const ;
};

