#include "Statistics.h"

// 构造函数
Statistics::Statistics(const unordered_map<string, Student>& studentCredentials) {
    for (const auto& pair : studentCredentials) {
        students.push_back(pair.second); // 将每个 Student 对象添加到 vector 中
    }
}

// 按照总分排序
vector<Student> Statistics::sortByTotalScore() {
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
        return a.grade.getTotal() > b.grade.getTotal(); // 降序排列
    });

    return sortedStudents;
}

// 按照平均分排序
vector<Student> Statistics::sortByAverageScore() {
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
        return a.grade.getAverage() > b.grade.getAverage(); // 降序排列
    });

    return sortedStudents;
}

// 按照特定科目排序
vector<Student> Statistics::sortBySubjectScore(const string& subject) {
    vector<Student> sortedStudents = students;

    sort(sortedStudents.begin(), sortedStudents.end(), [&](const Student& a, const Student& b) {
        return a.grade.getScore(subject) > b.grade.getScore(subject); // 降序排列
    });

    return sortedStudents;
}

// 显示排名
void Statistics::displayRanking(const vector<Student>& sortedStudents) {
    // 获取科目列表
    auto subjects = sortedStudents[0].grade.getSubjects();

    // 输出表头
    cout << left << setw(5) << "排名"
         << setw(10) << "姓名"
         << setw(10) << "总分"
         << setw(10) << "平均分";

    // 输出科目名称
    for (const auto& subject : subjects) {
        cout << setw(10) << subject; // 每个科目宽度
    }
    cout << endl;
    cout << string(110, '-') << endl; // 分隔线

    for (size_t i = 0; i < sortedStudents.size(); ++i) {
        const Student& student = sortedStudents[i];

        // 输出排名、姓名、总分和平均分
        cout << left << setw(5) << (i + 1) // 排名
             << setw(10) << student.getName()
             << setw(10) << student.grade.getTotal()
             << setw(10) << student.grade.getAverage();

        // 输出科目成绩
        for (const auto& subject : subjects) {
            cout << setw(10) << student.grade.getScore(subject); // 每个科目的成绩
        }

        cout << endl; // 换行
    }
}

// 处理用户输入
void Statistics::handleUserInput() {
    int choice;
    string subject;

    while (true) {
        cout << "       查询成绩单      " << endl;
        cout << "1. 按总分排序并显示排名" << endl;
        cout << "2. 按平均分排序并显示排名" << endl;
        cout << "3. 按科目排序并显示排名" << endl;
        cout << "4. 退出" << endl;
        cout << "请输入选项: ";
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
                cout << "请输入科目 (math, english, science, history, geography, art): ";
                cin >> subject;
                vector<Student> sortedStudents = sortBySubjectScore(subject);
                displayRanking(sortedStudents);
                break;
            }
            case 4:
                cout << "退出程序" << endl;
                return;
            default:
                cout << "无效选项，请重试。" << endl;
        }
    }
}
