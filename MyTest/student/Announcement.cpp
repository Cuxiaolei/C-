//
// Created by 22890 on 2025/1/4.
//

#include "Announcement.h"

Announcement::Announcement(Login& login) : login(login){

}

void Announcement::publishAnnouncement(string operation) {
    login.announcement.push_back(getCurrentTime()+operation);
}

string Announcement::getCurrentTime() const {
    auto now = chrono::system_clock::now();
    auto now_time_t = chrono::system_clock::to_time_t(now);
    tm tm = *localtime(&now_time_t);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

void Announcement::printAnnouncements() const {
    if (login.announcement.empty()) {
        cout << "系统还未发布公告" << endl;
        return;
    }
    cout << "系统公告:" << endl;
    for (const auto& announcement : login.announcement) {
        cout << announcement << endl;
    }
}
