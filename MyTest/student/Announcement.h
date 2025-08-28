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
    // ���캯������ʼ��������������
    Announcement(Login& login);
    // �����µĹ���
    void publishAnnouncement(string operation);
    // ��ӡ���й���
    void printAnnouncements() const;
private:
    // ��ȡ��ǰʱ����ĺ���
    string getCurrentTime() const;
};

