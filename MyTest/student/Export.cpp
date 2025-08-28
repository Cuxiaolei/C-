#include "Export.h"

Export::Export(Login &login) : login(login){

}


void Export::exportToCSV() {
    // Export students
    ofstream studentFile("students.csv");
    if (studentFile.is_open()) {
        studentFile << "�û���,����,��ɫ,����,ѧ��,�༶,�Ա�,��ϵ��ʽ,��ͥסַ\n";
        for (const auto& pair : login.studentCredentials) {
            const Student& student = pair.second;
            studentFile << student.getUsername() << ","
                        << student.getPassword() <<",student,"
                        << student.getName() << ","
                        << student.getStudentId() << ","
                        << student.getClassName() << ","
                        << student.getSex() << ","
                        << student.getPhone() << ","
                        << student.getAddress() << endl;
        }
        studentFile.close();
    }

    // Export teachers
    ofstream teacherFile("teachers.csv");
    if (teacherFile.is_open()) {
        teacherFile << "�û���,����,��ɫ,����,�Ա�,��ϵ��ʽ,��ͥסַ\n";
        for (const auto& pair : login.teacherCredentials) {
            map<string,string> m = pair.second;
            teacherFile << pair.first << ","
                        << m["password"] << ",teacher,"
                        << m["name"] << ","
                        << m["sex"] << ","
                        << m["phone"] << ","
                        << m["adress"] << endl;
        }
        teacherFile.close();
    }

    // Export admins
    ofstream adminFile("admins.csv");
    if (adminFile.is_open()) {
        adminFile << "�û���,����,��ɫ\n";
        for (const auto& pair : login.adminCredentials) {
            adminFile << pair.first << ","
                        << pair.second << ",admin\n";
        }
        adminFile.close();
    }

    vector<Grade> grades = getAllGradesFromLogin();
    ofstream gradesFile("grades.csv");
    if (gradesFile.is_open()) {
        gradesFile << "�û���,����,��ɫ,ѧ��,����,�༶,��ѧ�ɼ�,Ӣ��ɼ�,����ɼ�,���ɼ�,������Ƴɼ�,����ɼ�,�ܳɼ�,ƽ���ɼ�\n";
        for (const auto& s : login.studentCredentials) {
            gradesFile << s.second.getUsername() << ","
                       << s.second.getPassword() << ","
                       << s.second.getRole() << ","
                       << s.second.getStudentId() << ","
                       << s.second.getName() << ","
                       << s.second.getClassName() << ","
                       << s.second.grade.getScore("math") << ","
                       << s.second.grade.getScore("english") << ","
                       << s.second.grade.getScore("science") << ","
                       << s.second.grade.getScore("assemble") << ","
                       << s.second.grade.getScore("programming") << ","
                       << s.second.grade.getScore("circuit") << ","
                       << s.second.grade.getTotal() << ","
                       << s.second.grade.getAverage() << "\n";
        }
        gradesFile.close();
    }
}


vector<Grade> Export::getAllGradesFromLogin() {
    // ʵ�ָ���login�����ȡѧ���ɼ����߼�
    vector<Grade> grades;
    // ��������ѧ����ƾ��
    for (const auto& pair : login.studentCredentials) {
        const string& username = pair.first;
        const Student& student = pair.second;
        grades.push_back(student.grade);
    }
    return grades;
}


