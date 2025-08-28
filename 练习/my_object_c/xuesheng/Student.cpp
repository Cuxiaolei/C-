#include "Student.h"

Student::Student() : username(""), password(""),role("student"), studentId(""), name(""), className("")
{
}

// Constructor
Student::Student(const string& username, const string& password, const string& studentId,
                 const string& name, const string& className)
        : username(username), password(password),role("student"), studentId(studentId), name(name), className(className) {}

// Getter methods
string Student::getStudentId() const {
    return studentId;
}

string Student::getName() const {
    return name;
}

string Student::getClassName() const {
    return className;
}

// Setter methods
void Student::setStudentId(const string& studentId) {
    this->studentId = studentId;
}

void Student::setName(const string& name) {
    this->name = name;
}

void Student::setClassName(const string& className) {
    this->className = className;
}

// Method to view grades
void Student::viewGrades() {
    if(this->grade.getGradeId() != "")
    {
        cout << this->grade.getAllScores();
    }
    else
    {
        cout<<"当前您还没有成绩"<<endl;
    }
}

// Method to update student information
void Student::updateInfo() {
    string newName;
    string newClassName;
    cout<<"请输入新姓名:";
    cin>>newName;
    cout<<"请输入新班级:";
    cin>>newClassName;
    name = newName;
    className = newClassName;
    cout<<"修改信息成功!!" <<endl;
    cout << "更新后学生信息:"<<"学号 " << studentId<<" , 姓名 " << name << ", 班级 = " << className << "\n";
}

Student &Student::studentDisplay()
{
    int choice;
    do {
        cout << "\n--- 学生菜单 ---\n";
        cout << "1. 查看基础信息\n";
        cout << "2. 查看成绩\n";
        cout << "3. 查询单科成绩"<<endl;
        cout << "4. 更新个人信息\n";
        cout << "5. 退出\n";
        cout << "请选择一个选项: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showData();
                break;
            case 2:
                viewGrades();
                break;
            case 3:
                oneGrades();
                break;
            case 4: {
                updateInfo();
                break;
            }
            case 5:
                cout << "退出菜单。\n";
                break;
            default:
                cout << "无效选项，请重新选择。\n";
        }
    } while (choice != 5);
    return *this;
}


string Student::toString() const {
    return "学生 { 学号: '" +
           studentId + "', " +
           "姓名: '" + name + "', " +
           "班级: '" + className + "' }";
}

void Student::oneGrades() {
    if(this->grade.getGradeId() != "")
    {
        string subject;
        cout<<"请输入所要查询的科目:";
        cin>>subject;
        cout<<"您的"<<subject<<"成绩为:"<<grade.getScore(subject);
    }
    else
    {
        cout<<"当前您还没有成绩"<<endl;
    }
}

void Student::showData() {
    cout << this->toString();
}

const string &Student::getUsername() const {
    return username;
}

const string &Student::getPassword() const {
    return password;
}

const string &Student::getRole() const {
    return role;
}

void Student::setUsername(const string &username) {
    this->username = username;

}

void Student::setPassword(const string &password) {
    this->password = password;
}

void Student::setRole(const string &role) {
    this->role = role;

}



