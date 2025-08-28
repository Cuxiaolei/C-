//
// Created by 22890 on 2025/1/4.
//

#include "Logger.h"

Logger::Logger(Login &login):login(login) {

}

void Logger::log(const string &operation)  {
    string timestamp = getCurrentTime();
    string logMessage = timestamp + " - " + operation;
    login.systemLog.push_back(logMessage);
}

void Logger::printLogs() const {
    if (login.systemLog.empty()) {
        cout << "No logs to display." << endl;
        return;
    }
    cout << "系统日志:" << endl;
    for (const auto& log : login.systemLog) {
        cout << log << endl;
    }
}

string Logger::getCurrentTime() const {
    auto now = chrono::system_clock::now();
    auto now_time_t = chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&now_time_t);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}




