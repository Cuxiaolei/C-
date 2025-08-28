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

// 存储日志的容器
    Login& login;
    void log(const string& operation);
    void printLogs() const;
private:
    // 获取当前时间戳
    string getCurrentTime() const ;
};

