#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>
#include "Login.h"

using namespace std;
class Announcement {
private:
    Login& login;
public:
    // 构造函数，初始化公告标题和内容
    Announcement(Login& login);
    // 发布新的公告
    void publishAnnouncement(string operation);
    // 打印所有公告
    void printAnnouncements() const;
private:
    // 获取当前时间戳的函数
    string getCurrentTime() const;
};

