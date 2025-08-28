#include "Login.h"


Login::Login() {

}

bool Login::registerUser(const string& username, const string& password, const string& role) {
    if (role == "student") {
        if (studentCredentials.find(username) != studentCredentials.end()) {
            return false; // �˺��Ѵ��ڣ����� false
        }
        studentCredentials[username].setUsername(username);
        studentCredentials[username].setPassword(password);
        studentCredentials[username].setRole(role);
    }
    else if (role == "teacher") {
        if (teacherCredentials.find(username) != teacherCredentials.end()) {
            return false; // �˺��Ѵ��ڣ����� false
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
            return false; // �˺��Ѵ��ڣ����� false
        }
        adminCredentials[username] = password;
    }
    else {
        return false; // ��Ч��ɫ������ false
    }
    saveCredentials(); // ע��ɹ��󱣴浽�ļ�
    return true;
}

bool Login::loginUser(const string& username, const string& password, const string& role) {
    if (role == "student") {
        auto it = studentCredentials.find(username);
        return it != studentCredentials.end() && it->second.getPassword() == password; // ��¼�ɹ���ʧ��
    }
    else if (role == "teacher") {
        auto it = teacherCredentials.find(username);
        return it != teacherCredentials.end() && it->second["password"] == password; // ��¼�ɹ���ʧ��
    }
    else if (role == "admin") {
        auto it = adminCredentials.find(username);
        return it != adminCredentials.end() && it->second == password; // ��¼�ɹ���ʧ��
    }
    return false; // ��¼ʧ��
}


bool Login::logoutUser(const string& username, const string& role) {
    if (role == "student") {
        auto it = studentCredentials.find(username);
        if (it != studentCredentials.end()) {
            studentCredentials.erase(it); // ��ѧ���˻��������Ƴ�
        }
        else {
            cout << "���˻�������,�޷�ע��" << endl;
            return false;
        }
    }
    else if (role == "teacher") {
        auto it = teacherCredentials.find(username);
        if (it != teacherCredentials.end()) {
            teacherCredentials.erase(it); // �ӽ�ʦ�˻��������Ƴ�
        }
        else {
            cout << "���˻�������,�޷�ע��" << endl;
            return false;
        }
    }
    else if (role == "admin") {
        auto it = adminCredentials.find(username);
        if (it != adminCredentials.end()) {
            adminCredentials.erase(it); // �ӹ���Ա�˻��������Ƴ�
        }
        else {
            cout << "���˻�������,�޷�ע��" << endl;
            return false;
        }
    }
    else {
        cout << "�����ڸ������˻�" << endl;
        return false;
    }
    this->saveCredentials(); // ע���ɹ��󱣴浽�ļ�
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
        cout << "���ʹ���" << endl;;
    return false;
}

void Login::saveCredentials() {
    // ����ѧ����Ϣ
    ofstream outFile("students.txt", ios::out);
    if (outFile.is_open()) {
        for (const auto& entry : studentCredentials) {
            const Student& student = entry.second;
            // �����û��������롢��ɫ���������Ա�ѧ�š��༶���绰��סַ
            outFile.write(student.getUsername().c_str(), student.getUsername().size() + 1);
            outFile.write(student.getPassword().c_str(), student.getPassword().size() + 1);
            outFile.write(student.getRole().c_str(), student.getRole().size() + 1);
            outFile.write(student.getName().c_str(), student.getName().size() + 1);
            outFile.write(student.getSex().c_str(), student.getSex().size() + 1);
            outFile.write(student.getStudentId().c_str(), student.getStudentId().size() + 1);
            outFile.write(student.getClassName().c_str(), student.getClassName().size() + 1);
            outFile.write(student.getPhone().c_str(), student.getPhone().size() + 1);
            outFile.write(student.getAddress().c_str(), student.getAddress().size() + 1);
            // ����ɼ���Ϣ
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
        cout << "�޷����ļ�����ѧ����Ϣ" << endl;
    }

    // �����ʦ��Ϣ
    ofstream teacherFile("teachers.txt", ios::out);
    if(teacherFile.is_open()){
        for (const auto& pair : teacherCredentials) {
            map<string,string> m = pair.second;
            //�����û��������롢��ɫ���������Ա𡢵绰����ַ
            teacherFile.write(m["username"].c_str(), m["username"].size() + 1);
            teacherFile.write(m["password"].c_str(), m["password"].size() + 1);
            teacherFile.write(m["role"].c_str(), m["role"].size() + 1);
            teacherFile.write(m["name"].c_str(), m["name"].size() + 1);
            teacherFile.write(m["sex"].c_str(), m["sex"].size() + 1);
            teacherFile.write(m["phone"].c_str(), m["phone"].size() + 1);
            teacherFile.write(m["address"].c_str(), m["address"].size() + 1);
        }
        teacherFile.close();
    } else {cout << "�޷����ļ������ʦ��Ϣ" << endl;}
    // �������Ա��Ϣ
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
    } else {cout << "�޷����ļ��������Ա��Ϣ" << endl;}


    //������־��Ϣ
    ofstream logFile("log.txt",ios::out);
    if(logFile.is_open()){
        for (const auto& val : this->systemLog) {
            logFile << val << "\n";  // ÿ��Ԫ��д��һ��
        }
    } else{
        cout << "�޷����ļ�������־" << endl;
    }

    //���湫����Ϣ
    ofstream AnnouncementFile("announcement.txt",ios::out);
    if(AnnouncementFile.is_open()){
        for (const auto& val : this->announcement) {
            AnnouncementFile << val << "\n";  // ÿ��Ԫ��д��һ��
        }
    } else{
        cout << "�޷����ļ����湫����Ϣ" << endl;
    }
}


void Login::loadCredentials() {
    // ���ļ�����ѧ��
    ifstream inFile("students.txt", ios::in);
    if (inFile.is_open()) {
        while (inFile.peek() != EOF) {
            char username[256];char password[256];char role[256];char name[256];
            char sex[256];char phone[256];char address[256];char studentId[256];
            char className[256];
            // ��ȡ�û��������롢��ɫ���������Ա�ѧ�š��༶���绰��סַ
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
            student.grade = grade;      //���غ���
            studentCredentials[username] = student; // ����ѧ������unordered_map
        }
        inFile.close();
        cout << "ѧ����Ϣ���سɹ�" << endl;
    } else {
        cout << "�޷����ļ�����ѧ����Ϣ" << endl;
    }

    // ���ļ����ؽ�ʦ
    ifstream teacherFile("teachers.txt", ios::in);
    if(teacherFile.is_open()){
        while (teacherFile.peek() != EOF) {
            char username[256];char password[256];char role[256];
            char name[256];char sex[256];char phone[256];char address[256];
            map<string,string> m;
            //��ȡ�û��������롢��ɫ���������Ա𡢵绰����ַ
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
        cout << "��ʦ��Ϣ���سɹ�" << endl;} else {cout << "�޷����ļ����ؽ�ʦ��Ϣ" << endl;}
    // ���ļ����ع���Ա
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
        cout << "����Ա��Ϣ���سɹ�" << endl;
    } else{cout << "�޷����ļ�����ѧ����Ա��Ϣ" << endl;}

    ifstream logFile("log.txt", ios::in);
    if(logFile.is_open()){
        string line;
        while (getline(logFile, line)) {
            this->systemLog.push_back(line);  // ��ÿһ�д���vector
        }
        logFile.close();
        cout << "��־��Ϣ���سɹ�" << endl;
    } else{
        cout << "�޷����ļ�������־��Ϣ" << endl;
    }
    ifstream announcementFile("announcement.txt", ios::in);
    if(announcementFile.is_open()){
        string line;
        while (getline(logFile, line)) {
            this->announcement.push_back(line);  // ��ÿһ�д���vector
        }
        announcementFile.close();
        cout << "������Ϣ���سɹ�" << endl;
    } else{
        cout << "�޷����ļ����ع�����Ϣ" << endl;
    }
}

void Login::viewAllAccounts() {
    cout << "ѧ���˻���Ϣ��" << endl;
    for (const auto& pair : studentCredentials) {
        cout << "�û���: " << pair.first << ", ����: " << pair.second.getPassword() << endl;
    }
    cout << "��ʦ�˻���Ϣ��" << endl;
    for (const auto& pair : teacherCredentials) {
        map<string,string> m = pair.second;
        cout << "�û���: " << pair.first << ", ����: " << m["password"] << endl;
    }
    cout << "����Ա�˻���Ϣ��" << endl;
    for (const auto& pair : adminCredentials) {
        cout << "�û���: " << pair.first << ", ����: " << pair.second << endl;
    }
}

Login::~Login() {
    saveCredentials();
}
