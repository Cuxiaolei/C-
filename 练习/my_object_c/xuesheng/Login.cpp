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
        teacherCredentials[username] = password;
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
        return it != teacherCredentials.end() && it->second == password; // 登录成功或失败
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
            it->second = newPassword;
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
    ofstream outFile("students.txt", ios::binary);
    if (outFile.is_open()) {
        for (const auto& entry : studentCredentials) {
            const Student& student = entry.second;

            // 保存用户名、密码、角色、学号、姓名和班级
            outFile.write(student.getUsername().c_str(), student.getUsername().size() + 1);
            outFile.write(student.getPassword().c_str(), student.getPassword().size() + 1);
            outFile.write(student.getRole().c_str(), student.getRole().size() + 1);
            outFile.write(student.getStudentId().c_str(), student.getStudentId().size() + 1);
            outFile.write(student.getName().c_str(), student.getName().size() + 1);
            outFile.write(student.getClassName().c_str(), student.getClassName().size() + 1);

            // 保存成绩信息
            const Grade& grade = student.grade;
            float mathScore = grade.getScore("math");
            float englishScore = grade.getScore("english");
            float scienceScore = grade.getScore("science");
            float historyScore = grade.getScore("history");
            float geographyScore = grade.getScore("geography");
            float artScore = grade.getScore("art");

            outFile.write(reinterpret_cast<const char*>(&mathScore), sizeof(mathScore));
            outFile.write(reinterpret_cast<const char*>(&englishScore), sizeof(englishScore));
            outFile.write(reinterpret_cast<const char*>(&scienceScore), sizeof(scienceScore));
            outFile.write(reinterpret_cast<const char*>(&historyScore), sizeof(historyScore));
            outFile.write(reinterpret_cast<const char*>(&geographyScore), sizeof(geographyScore));
            outFile.write(reinterpret_cast<const char*>(&artScore), sizeof(artScore));
        }
        outFile.close();
    } else {
        cout << "无法打开文件保存学生信息" << endl;
    }

    // 保存教师信息
    ofstream teacherFile("teachers.txt", ios::binary | ios::trunc);
    for (const auto& pair : teacherCredentials) {
        size_t usernameLength = pair.first.size();
        size_t passwordLength = pair.second.size();
        teacherFile.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
        teacherFile.write(pair.first.c_str(), usernameLength);
        teacherFile.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
        teacherFile.write(pair.second.c_str(), passwordLength);
    }
    teacherFile.close();

    // 保存管理员信息
    ofstream adminFile("admins.txt", ios::binary | ios::trunc);
    for (const auto& pair : adminCredentials) {
        size_t usernameLength = pair.first.size();
        size_t passwordLength = pair.second.size();
        adminFile.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
        adminFile.write(pair.first.c_str(), usernameLength);
        adminFile.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
        adminFile.write(pair.second.c_str(), passwordLength);
    }
    adminFile.close();
}


void Login::loadCredentials() {
    // 从文件加载学生
    ifstream inFile("students.bin", ios::binary);
    if (inFile.is_open()) {
        while (inFile.peek() != EOF) {
            char username[256];
            char password[256];
            char role[256];
            char studentId[256];
            char name[256];
            char className[256];

            // 读取用户名、密码、角色、学号、姓名和班级
            inFile.getline(username, sizeof(username), '\0');
            inFile.getline(password, sizeof(password), '\0');
            inFile.getline(role, sizeof(role), '\0');
            inFile.getline(studentId, sizeof(studentId), '\0');
            inFile.getline(name, sizeof(name), '\0');
            inFile.getline(className, sizeof(className), '\0');

            // 创建学生对象
            Student student(username, password, studentId, name, className); // 假设Student类有这个构造函数

            // 读取成绩信息
            float mathScore, englishScore, scienceScore, historyScore, geographyScore, artScore;
            inFile.read(reinterpret_cast<char*>(&mathScore), sizeof(mathScore));
            inFile.read(reinterpret_cast<char*>(&englishScore), sizeof(englishScore));
            inFile.read(reinterpret_cast<char*>(&scienceScore), sizeof(scienceScore));
            inFile.read(reinterpret_cast<char*>(&historyScore), sizeof(historyScore));
            inFile.read(reinterpret_cast<char*>(&geographyScore), sizeof(geographyScore));
            inFile.read(reinterpret_cast<char*>(&artScore), sizeof(artScore));

            // 创建成绩对象
            Grade grade(username, mathScore, englishScore, scienceScore, historyScore, geographyScore, artScore);
            student.grade = grade;      //重载函数

            studentCredentials[username] = student; // 保存学生对象到unordered_map
        }
        inFile.close();
    } else {
        cout << "无法打开文件加载学生信息" << endl;
    }

    // 从文件加载教师
    ifstream teacherFile("teachers.txt", ios::binary);
    while (teacherFile.peek() != EOF) {
        size_t usernameLength;
        teacherFile.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
        string username(usernameLength, '\0');
        teacherFile.read(&username[0], usernameLength);

        size_t passwordLength;
        teacherFile.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
        string password(passwordLength, '\0');
        teacherFile.read(&password[0], passwordLength);

        teacherCredentials[username] = password;
    }
    teacherFile.close();

    // 从文件加载管理员
    ifstream adminFile("admins.txt", ios::binary);
    while (adminFile.peek() != EOF) {
        size_t usernameLength;
        adminFile.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
        string username(usernameLength, '\0');
        adminFile.read(&username[0], usernameLength);

        size_t passwordLength;
        adminFile.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
        string password(passwordLength, '\0');
        adminFile.read(&password[0], passwordLength);

        adminCredentials[username] = password;
    }
    adminFile.close();
    cout<<"信息加载成功"<<endl;
}


void Login::viewAllAccounts() {
    cout << "学生账户信息：" << endl;
    for (const auto& pair : studentCredentials) {
        cout << "用户名: " << pair.first << ", 密码: " << pair.second.getPassword() << endl;
    }

    cout << "教师账户信息：" << endl;
    for (const auto& pair : teacherCredentials) {
        cout << "用户名: " << pair.first << ", 密码: " << pair.second << endl;
    }

    cout << "管理员账户信息：" << endl;
    for (const auto& pair : adminCredentials) {
        cout << "用户名: " << pair.first << ", 密码: " << pair.second << endl;
    }
}
