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
    cout<<"请输入修改后的密码：";
    cin>>this->password;
    cout<<"请输入修改后的姓名：";
    cin>>this->name;
    cout<<"请输入修改后的学号:";
    cin>>this->studentId;
    cout<<"请输入修改后的性别:";
    cin>>this->sex;
    cout<<"请输入修改后的班级：";
    cin>>this->className;
    cout<<"请输入修改后的联系方式：";
    cin>>this->phone;
    cout<<"请输入修改后的家庭住址：";
    cin>>this->address;
    cout<<"修改信息成功"<<endl;
}

void Student::find_info() {
    cout<<"您当前的信息为："<<endl;
    cout<<"用户名:"<<this->username<<endl;
    cout<<"密码:"<<this->password<<endl;
    cout<<"姓名:"<<this->name<<endl;
    cout<<"学号:"<<this->studentId<<endl;
    cout<<"性别:"<<this->sex<<endl;
    cout<<"班级:"<<this->className<<endl;
    cout<<"联系方式:"<<this->phone<<endl;
    cout<<"家庭住址:"<<this->address<<endl;
}



// Method to view grades
void Student::viewGrades() {
    if(this->grade.getGradeId() != ""){
        cout << this->grade.getAllScores();
    }else
    {
        cout<<"当前您还没有成绩"<<endl;
    }
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
        cout << "0. 退出\n";
        cout << "请选择一个选项: ";
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
                cout << "退出菜单。\n";
                break;
            default:
                cout << "无效选项，请重新选择。\n";
                break;
        }
    } while (choice != 0);
    return *this;
}



void Student::oneGrades() {
    if(this->grade.getGradeId() != "")
    {
        string subject;
        cout<<"请输入所要查询的科目:";
        cin>>subject;
        cout<<"您的"<<subject<<"成绩为:"<<grade.getScore(subject);
    }else
    {
        cout<<"当前您还没有成绩"<<endl;
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





