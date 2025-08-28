#include "Statistics.h"
#include "Teacher.h"

// ���캯��
Statistics::Statistics(unordered_map<string, Student>& studentCredentials) {
    for (auto& pair : studentCredentials) {
        Student& student = pair.second;
        students.push_back(student); // ��ÿ�� Student ������ӵ� vector ��
    }
}

// �����ܷ�����
void Statistics::sortByTotalScore() {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade.getTotal() > b.grade.getTotal(); // ��������
    });

}

////// ����ƽ��������
//void Statistics::sortByAverageScore() {
//    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
//        return a.grade.getAverage() > b.grade.getAverage(); // ��������
//    });
//
//}
//����ѧ�Ŵ�С���򣬴�С����
void Statistics::sortById()
{
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.getStudentId()< b.getStudentId(); // ��������
    });
}

// �����ض���Ŀ����
void Statistics::sortBySubjectScore(const string& subject) {
    sort(students.begin(), students.end(), [&](const Student& a, const Student& b) {
        return a.grade.getScore(subject) > b.grade.getScore(subject); // ��������
    });
}

// ��ʾ����
void Statistics::displayRanking() {
    // ��ȡ��Ŀ�б�
    auto subjects = students[0].grade.getSubjects();

    // �����ͷ
    cout << left << setw(5) << "����"
         << setw(10) << "����"
         << setw(10) << "�ܷ�"
         << setw(10) << "ƽ����";

    // �����Ŀ����
    for (const auto& subject : subjects) {
        cout << setw(10) << subject; // ÿ����Ŀ���
    }
    cout << endl;
    cout << string(110, '-') << endl; // �ָ���

    for (size_t i = 0; i < students.size(); ++i) {
        const Student& student = students[i];

        // ����������������ֺܷ�ƽ����
        cout << left << setw(5) << (i + 1) // ����
             << setw(10) << student.getName()
             << setw(10) << student.grade.getTotal()
             << setw(10) << student.grade.getAverage();

        // �����Ŀ�ɼ�
        for (const auto& subject : subjects) {
            cout << setw(10) << student.grade.getScore(subject); // ÿ����Ŀ�ĳɼ�
        }

        cout << endl; // ����
    }
}

// �����û�����
void Statistics::handleUserInput() {
    int choice;
    string subject;

    while (true) {
        cout << "       ��ѯ�ɼ���      " << endl;
        cout << "1. ���ܷ�������ʾ����" << endl;
        cout << "2. ��ѧ��������ʾ����" << endl;
        cout << "3. ����Ŀ������ʾ����" << endl;
        cout << "4. �˳�" << endl;
        cout << "������ѡ��: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                sortByTotalScore();
                displayRanking();
                break;
            }
            case 2: {
                sortById();
                displayRanking();
                break;
            }
            case 3: {
                cout << "�������Ŀ (math, english, science, assemble , programming, circuit): ";
                cin >> subject;
                sortBySubjectScore(subject);
                displayRanking();
                break;
            }
            case 4:
                cout << "�˳�����" << endl;
                return;
            default:
                cout << "��Чѡ������ԡ�" << endl;
        }
    }
}