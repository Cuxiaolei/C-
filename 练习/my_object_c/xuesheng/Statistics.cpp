#include "Statistics.h"

// ���캯��
Statistics::Statistics(const unordered_map<string, Student>& studentCredentials) {
    for (const auto& pair : studentCredentials) {
        students.push_back(pair.second); // ��ÿ�� Student ������ӵ� vector ��
    }
}

// �����ܷ�����
vector<Student> Statistics::sortByTotalScore() {
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
        return a.grade.getTotal() > b.grade.getTotal(); // ��������
    });

    return sortedStudents;
}

// ����ƽ��������
vector<Student> Statistics::sortByAverageScore() {
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
        return a.grade.getAverage() > b.grade.getAverage(); // ��������
    });

    return sortedStudents;
}

// �����ض���Ŀ����
vector<Student> Statistics::sortBySubjectScore(const string& subject) {
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), [&](const Student& a, const Student& b) {
        return a.grade.getScore(subject) > b.grade.getScore(subject); // ��������
    });

    return sortedStudents;
}

// ��ʾ����
void Statistics::displayRanking(const vector<Student>& sortedStudents) {
    // ��ȡ��Ŀ�б�
    auto subjects = sortedStudents[0].grade.getSubjects();

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

    for (size_t i = 0; i < sortedStudents.size(); ++i) {
        const Student& student = sortedStudents[i];

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
        cout << "2. ��ƽ����������ʾ����" << endl;
        cout << "3. ����Ŀ������ʾ����" << endl;
        cout << "4. �˳�" << endl;
        cout << "������ѡ��: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                vector<Student> sortedStudents = sortByTotalScore();
                displayRanking(sortedStudents);
                break;
            }
            case 2: {
                vector<Student> sortedStudents = sortByAverageScore();
                displayRanking(sortedStudents);
                break;
            }
            case 3: {
                cout << "�������Ŀ (math, english, science, history, geography, art): ";
                cin >> subject;
                vector<Student> sortedStudents = sortBySubjectScore(subject);
                displayRanking(sortedStudents);
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
