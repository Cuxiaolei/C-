#include "Login.h"


Login::Login() {

}

bool Login::registerUser(const string& username, const string& password, const string& role) {
    if (role == "student") {
        if (studentCredentials.find(username) != studentCredentials.end()) {
            return false; // 账号已存在，返回 false
        }
        studentCredentials[username].setUsername(username);
        studentCredentials[username].setPassword(password);
        studentCredentials[username].setRole(role);
    }
    else if (role == "teacher") {
        if (teacherCredentials.find(username) != teacherCredentials.end()) {
            return false; // 账号已存在，返回 false
        }
        teacherCredentials[username]["username"] = username;
        teacherCredentials[username]["password"] = password;
        teacherCredentials[username]["role"] = role;
        teacherCredentials[username]["name"] = "";
        teacherCredentials[username]["sex"] = "";
        teacherCredentials[username]["phone"] = "";
        teacherCredentials[username]["address"] = "";
    }
    else if (role == "admin") {
        if (adminCredentials.find(username) != adminCredentials.end()) {
            return false; // 账号已存在，返回 false
        }
        adminCredentials[username] = password;
    }
    else {
        return false; // 无效角色，返回 false
    }
    saveCredentials(); // 注册成功后保存到文件
    return true;
}

bool Login::loginUser(const string& username, const string& password, const string& role) {
    if (role == "student") {
        auto it = studentCredentials.find(username);
        return it != studentCredentials.end() && it->second.getPassword() == password; // 登录成功或失败
    }
    else if (role == "teacher") {
        auto it = teacherCredentials.find(username);
        return it != teacherCredentials.end() && it->second["password"] == password; // 登录成功或失败
    }
    else if (role == "admin") {
        auto it = adminCredentials.find(username);
        return it != adminCredentials.end() && it->second == password; // 登录成功或失败
    }
    return false; // 登录失败
}


bool Login::logoutUser(const string& username, const string& role) {
    if (role == "student") {
        auto it = studentCredentials.find(username);
        if (it != studentCredentials.end()) {
            studentCredentials.erase(it); // 从学生账户集合中移除
        }
        else {
            cout << "该账户不存在,无法注销" << endl;
            return false;
        }
    }
    else if (role == "teacher") {
        auto it = teacherCredentials.find(username);
        if (it != teacherCredentials.end()) {
            teacherCredentials.erase(it); // 从教师账户集合中移除
        }
        else {
            cout << "该账户不存在,无法注销" << endl;
            return false;
        }
    }
    else if (role == "admin") {
        auto it = adminCredentials.find(username);
        if (it != adminCredentials.end()) {
            adminCredentials.erase(it); // 从管理员账户集合中移除
        }
        else {
            cout << "该账户不存在,无法注销" << endl;
            return false;
        }
    }
    else {
        cout << "不存在改类型账户" << endl;
        return false;
    }
    this->saveCredentials(); // 注销成功后保存到文件
    return true;
}

bool Login::modifyUser(const string& username, const string& newPassword, const string& role)
{
    if (role == "student") {
        auto it = studentCredentials.find(username);
        if (it != studentCredentials.end())
        {
            it->second.setPassword(newPassword);
            return true;
        }
    }
    else if (role == "teacher") {
        auto it = teacherCredentials.find(username);
        if (it != teacherCredentials.end())
        {
            it->second["password"] = newPassword;
            return true;
        }
    }
    else if (role == "admin") {
        auto it = adminCredentials.find(username);
        if (it != adminCredentials.end())
        {
            it->second = newPassword;
            return true;
        }
    }
    else
        cout << "类型错误" << endl;;
    return false;
}

void Login::saveCredentials() {
    // 保存学生信息
    ofstream outFile("students.txt", ios::out);
    if (outFile.is_open()) {
        for (const auto& entry : studentCredentials) {
            const Student& student = entry.second;
            // 保存用户名、密码、角色、姓名、性别、学号、班级、电话、住址
            outFile.write(student.getUsername().c_str(), student.getUsername().size() + 1);
            outFile.write(student.getPassword().c_str(), student.getPassword().size() + 1);
            outFile.write(student.getRole().c_str(), student.getRole().size() + 1);
            outFile.write(student.getName().c_str(), student.getName().size() + 1);
            outFile.write(student.getSex().c_str(), student.getSex().size() + 1);
            outFile.write(student.getStudentId().c_str(), student.getStudentId().size() + 1);
            outFile.write(student.getClassName().c_str(), student.getClassName().size() + 1);
            outFile.write(student.getPhone().c_str(), student.getPhone().size() + 1);
            outFile.write(student.getAddress().c_str(), student.getAddress().size() + 1);
            // 保存成绩信息
            const Grade& grade = student.grade;
            float mathScore = grade.getScore("math");
            float englishScore = grade.getScore("english");
            float scienceScore = grade.getScore("science");
            float assembleScore = grade.getScore("assemble");
            float programmingscore = grade.getScore("programming");
            float circuitScore = grade.getScore("circuit");
            outFile.write(reinterpret_cast<const char*>(&mathScore), sizeof(mathScore));
            outFile.write(reinterpret_cast<const char*>(&englishScore), sizeof(englishScore));
            outFile.write(reinterpret_cast<const char*>(&scienceScore), sizeof(scienceScore));
            outFile.write(reinterpret_cast<const char*>(&assembleScore), sizeof(assembleScore));
            outFile.write(reinterpret_cast<const char*>(&programmingscore), sizeof(programmingscore));
            outFile.write(reinterpret_cast<const char*>(&circuitScore), sizeof(circuitScore));
        }
        outFile.close();
    } else {
        cout << "无法打开文件保存学生信息" << endl;
    }

    // 保存教师信息
    ofstream teacherFile("teachers.txt", ios::out);
    if(teacherFile.is_open()){
        for (const auto& pair : teacherCredentials) {
            map<string,string> m = pair.second;
            //保存用户名、密码、角色、姓名、性别、电话、地址
            teacherFile.write(m["username"].c_str(), m["username"].size() + 1);
            teacherFile.write(m["password"].c_str(), m["password"].size() + 1);
            teacherFile.write(m["role"].c_str(), m["role"].size() + 1);
            teacherFile.write(m["name"].c_str(), m["name"].size() + 1);
            teacherFile.write(m["sex"].c_str(), m["sex"].size() + 1);
            teacherFile.write(m["phone"].c_str(), m["phone"].size() + 1);
            teacherFile.write(m["address"].c_str(), m["address"].size() + 1);
        }
        teacherFile.close();
    } else {cout << "无法打开文件保存教师信息" << endl;}
    // 保存管理员信息
    ofstream adminFile("admins.txt", ios::out | ios::trunc);
    if(adminFile.is_open()){
        for (const auto& pair : adminCredentials) {
            size_t usernameLength = pair.first.size();
            size_t passwordLength = pair.second.size();
            adminFile.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
            adminFile.write(pair.first.c_str(), usernameLength);
            adminFile.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
            adminFile.write(pair.second.c_str(), passwordLength);
        }adminFile.close();
    } else {cout << "无法打开文件保存管理员信息" << endl;}


    //保存日志信息
    ofstream logFile("log.txt",ios::out);
    if(logFile.is_open()){
        for (const auto& val : this->systemLog) {
            logFile << val << "\n";  // 每个元素写入一行
        }
    } else{
        cout << "无法打开文件保存日志" << endl;
    }

    //保存公告信息
    ofstream AnnouncementFile("announcement.txt",ios::out);
    if(AnnouncementFile.is_open()){
        for (const auto& val : this->announcement) {
            AnnouncementFile << val << "\n";  // 每个元素写入一行
        }
    } else{
        cout << "无法打开文件保存公告信息" << endl;
    }
}


void Login::loadCredentials() {
    // 从文件加载学生
    ifstream inFile("students.txt", ios::in);
    if (inFile.is_open()) {
        while (inFile.peek() != EOF) {
            char username[256];char password[256];char role[256];char name[256];
            char sex[256];char phone[256];char address[256];char studentId[256];
            char className[256];
            // 读取用户名、密码、角色、姓名、性别、学号、班级、电话、住址
            inFile.getline(username, sizeof(username), '\0');
            inFile.getline(password, sizeof(password), '\0');
            inFile.getline(role, sizeof(role), '\0');
            inFile.getline(name, sizeof(name), '\0');
            inFile.getline(sex, sizeof(sex), '\0');
            inFile.getline(phone, sizeof(phone), '\0');
            inFile.getline(address, sizeof(address), '\0');
            inFile.getline(studentId, sizeof(studentId), '\0');
            inFile.getline(className, sizeof(className), '\0');
            Student student(username, password, role, name, sex,phone,address,studentId,className);
            float mathScore, englishScore, scienceScore, assembleScore, programmingscore, circuitScore;
            inFile.read(reinterpret_cast<char*>(&mathScore), sizeof(mathScore));
            inFile.read(reinterpret_cast<char*>(&englishScore), sizeof(englishScore));
            inFile.read(reinterpret_cast<char*>(&scienceScore), sizeof(scienceScore));
            inFile.read(reinterpret_cast<char*>(&assembleScore), sizeof(assembleScore));
            inFile.read(reinterpret_cast<char*>(&programmingscore), sizeof(programmingscore));
            inFile.read(reinterpret_cast<char*>(&circuitScore), sizeof(circuitScore));
            Grade grade(username, mathScore, englishScore, scienceScore, assembleScore, programmingscore, circuitScore);
            student.grade = grade;      //重载函数
            studentCredentials[username] = student; // 保存学生对象到unordered_map
        }
        inFile.close();
        cout << "学生信息加载成功" << endl;
    } else {
        cout << "无法打开文件加载学生信息" << endl;
    }

    // 从文件加载教师
    ifstream teacherFile("teachers.txt", ios::in);
    if(teacherFile.is_open()){
        while (teacherFile.peek() != EOF) {
            char username[256];char password[256];char role[256];
            char name[256];char sex[256];char phone[256];char address[256];
            map<string,string> m;
            //读取用户名、密码、角色、姓名、性别、电话、地址
            teacherFile.getline(username, sizeof(username), '\0');
            teacherFile.getline(password, sizeof(password), '\0');
            teacherFile.getline(role, sizeof(role), '\0');
            teacherFile.getline(name, sizeof(name), '\0');
            teacherFile.getline(sex, sizeof(sex), '\0');
            teacherFile.getline(phone, sizeof(phone), '\0');
            teacherFile.getline(address, sizeof(address), '\0');
            m["username"] = username;m["password"] = password;m["role"] = role;
            m["name"] = name;m["sex"] = sex;m["phone"] = phone;m["address"] = address;
            teacherCredentials[username] = m;}
        teacherFile.close();
        cout << "教师信息加载成功" << endl;} else {cout << "无法打开文件加载教师信息" << endl;}
    // 从文件加载管理员
    ifstream adminFile("admins.txt", ios::in);
    if(adminFile.is_open()){
        while (adminFile.peek() != EOF) {
            size_t usernameLength;
            adminFile.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
            string username(usernameLength, '\0');
            adminFile.read(&username[0], usernameLength);
            size_t passwordLength;
            adminFile.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
            string password(passwordLength, '\0');
            adminFile.read(&password[0], passwordLength);
            adminCredentials[username] = password;}
        adminFile.close();
        cout << "管理员信息加载成功" << endl;
    } else{cout << "无法打开文件加载学管理员信息" << endl;}

    ifstream logFile("log.txt", ios::in);
    if(logFile.is_open()){
        string line;
        while (getline(logFile, line)) {
            this->systemLog.push_back(line);  // 将每一行存入vector
        }
        logFile.close();
        cout << "日志信息加载成功" << endl;
    } else{
        cout << "无法打开文件加载日志信息" << endl;
    }
    ifstream announcementFile("announcement.txt", ios::in);
    if(announcementFile.is_open()){
        string line;
        while (getline(logFile, line)) {
            this->announcement.push_back(line);  // 将每一行存入vector
        }
        announcementFile.close();
        cout << "公告信息加载成功" << endl;
    } else{
        cout << "无法打开文件加载公告信息" << endl;
    }
}

void Login::viewAllAccounts() {
    cout << "学生账户信息：" << endl;
    for (const auto& pair : studentCredentials) {
        cout << "用户名: " << pair.first << ", 密码: " << pair.second.getPassword() << endl;
    }
    cout << "教师账户信息：" << endl;
    for (const auto& pair : teacherCredentials) {
        map<string,string> m = pair.second;
        cout << "用户名: " << pair.first << ", 密码: " << m["password"] << endl;
    }
    cout << "管理员账户信息：" << endl;
    for (const auto& pair : adminCredentials) {
        cout << "用户名: " << pair.first << ", 密码: " << pair.second << endl;
    }
}

Login::~Login() {
    saveCredentials();
}
