#include "Student.h"

Student::Student() : User("","","student"), studentId(""), className("")
{
    this->username = "";
    this->password = "";
}

Student::Student(string username, string password, string role, string name, string sex, string phone, string address,
                 string studentId, string className) : User(username,password,role,name,sex,phone,address),studentId(studentId),className(className){
    this->username = username;
    this->password = password;
    this->role = role;
    this->name = name;
    this->sex = sex;
    this->phone = phone;
    this->address = address;
}

void Student::modify_info() {
    find_info();
    cout<<"�������޸ĺ�����룺";
    cin>>this->password;
    cout<<"�������޸ĺ��������";
    cin>>this->name;
    cout<<"�������޸ĺ��ѧ��:";
    cin>>this->studentId;
    cout<<"�������޸ĺ���Ա�:";
    cin>>this->sex;
    cout<<"�������޸ĺ�İ༶��";
    cin>>this->className;
    cout<<"�������޸ĺ����ϵ��ʽ��";
    cin>>this->phone;
    cout<<"�������޸ĺ�ļ�ͥסַ��";
    cin>>this->address;
    cout<<"�޸���Ϣ�ɹ�"<<endl;
}

void Student::find_info() {
    cout<<"����ǰ����ϢΪ��"<<endl;
    cout<<"�û���:"<<this->username<<endl;
    cout<<"����:"<<this->password<<endl;
    cout<<"����:"<<this->name<<endl;
    cout<<"ѧ��:"<<this->studentId<<endl;
    cout<<"�Ա�:"<<this->sex<<endl;
    cout<<"�༶:"<<this->className<<endl;
    cout<<"��ϵ��ʽ:"<<this->phone<<endl;
    cout<<"��ͥסַ:"<<this->address<<endl;
}



// Method to view grades
void Student::viewGrades() {
    if(this->grade.getGradeId() != ""){
        cout << this->grade.getAllScores();
    }else
    {
        cout<<"��ǰ����û�гɼ�"<<endl;
    }
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
        cout << "0. �˳�\n";
        cout << "��ѡ��һ��ѡ��: ";
        cin >> choice;

        switch (choice) {
            case 1:
                find_info();
                break;
            case 2:
                viewGrades();
                break;
            case 3:
                oneGrades();
                break;
            case 4: {
                modify_info();
                break;
            }
            case 0:
                cout << "�˳��˵���\n";
                break;
            default:
                cout << "��Чѡ�������ѡ��\n";
                break;
        }
    } while (choice != 0);
    return *this;
}



void Student::oneGrades() {
    if(this->grade.getGradeId() != "")
    {
        string subject;
        cout<<"��������Ҫ��ѯ�Ŀ�Ŀ:";
        cin>>subject;
        cout<<"����"<<subject<<"�ɼ�Ϊ:"<<grade.getScore(subject);
    }else
    {
        cout<<"��ǰ����û�гɼ�"<<endl;
    }
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





