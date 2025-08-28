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
        cout<<"��ǰ����û�гɼ�"<<endl;
    }
}

// Method to update student information
void Student::updateInfo() {
    string newName;
    string newClassName;
    cout<<"������������:";
    cin>>newName;
    cout<<"�������°༶:";
    cin>>newClassName;
    name = newName;
    className = newClassName;
    cout<<"�޸���Ϣ�ɹ�!!" <<endl;
    cout << "���º�ѧ����Ϣ:"<<"ѧ�� " << studentId<<" , ���� " << name << ", �༶ = " << className << "\n";
}

Student &Student::studentDisplay()
{
    int choice;
    do {
        cout << "\n--- ѧ���˵� ---\n";
        cout << "1. �鿴������Ϣ\n";
        cout << "2. �鿴�ɼ�\n";
        cout << "3. ��ѯ���Ƴɼ�"<<endl;
        cout << "4. ���¸�����Ϣ\n";
        cout << "5. �˳�\n";
        cout << "��ѡ��һ��ѡ��: ";
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
                cout << "�˳��˵���\n";
                break;
            default:
                cout << "��Чѡ�������ѡ��\n";
        }
    } while (choice != 5);
    return *this;
}


string Student::toString() const {
    return "ѧ�� { ѧ��: '" +
           studentId + "', " +
           "����: '" + name + "', " +
           "�༶: '" + className + "' }";
}

void Student::oneGrades() {
    if(this->grade.getGradeId() != "")
    {
        string subject;
        cout<<"��������Ҫ��ѯ�Ŀ�Ŀ:";
        cin>>subject;
        cout<<"����"<<subject<<"�ɼ�Ϊ:"<<grade.getScore(subject);
    }
    else
    {
        cout<<"��ǰ����û�гɼ�"<<endl;
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



