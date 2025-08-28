#include "Grade.h"
#include <iostream>

Grade::Grade()
        : gradeId(""), mathScore(0), englishScore(0), scienceScore(0),
          historyScore(0), geographyScore(0), artScore(0),
          totalScore(0), averageScore(0) {
    // 无参构造函数，所有变量初始化为0
}

Grade::Grade(const string& gradeId, float mathScore, float englishScore,
             float scienceScore, float historyScore, float geographyScore, float artScore)
        : gradeId(gradeId), mathScore(mathScore), englishScore(englishScore),
          scienceScore(scienceScore), historyScore(historyScore), geographyScore(geographyScore),
          artScore(artScore) {
    calculateTotalAndAverage(); // 计算总分和平均分
}

Grade::Grade(const Grade& other)
        : gradeId(other.gradeId), mathScore(other.mathScore), englishScore(other.englishScore),
          scienceScore(other.scienceScore), historyScore(other.historyScore), geographyScore(other.geographyScore),
          artScore(other.artScore), totalScore(other.totalScore), averageScore(other.averageScore) {
    // 拷贝构造函数
}

Grade& Grade::operator=(const Grade& other) {
    if (this != &other) { // 自我赋值检查
        gradeId = other.gradeId;
        mathScore = other.mathScore;
        englishScore = other.englishScore;
        scienceScore = other.scienceScore;
        historyScore = other.historyScore;
        geographyScore = other.geographyScore;
        artScore = other.artScore;
        totalScore = other.totalScore;
        averageScore = other.averageScore;
    }
    return *this; // 返回自身的引用
}

void Grade::calculateTotalAndAverage() {
    totalScore = mathScore + englishScore + scienceScore + historyScore + geographyScore + artScore;
    averageScore = totalScore / 6; // 计算平均分
}

void Grade::updateScore(const string& gradeId) {
    if (this->gradeId != gradeId) {
        cout << "成绩不存在，无法修改。" << endl;
        return;
    }
    string subject;
    float newScore;
    cout<<"当前学生成绩"<<endl;
    cout<< getAllScores();
    cout<<"请输入需要修改的科目:";
    cin>>subject;
    cout<<"请输入修改后的成绩:";
    cin>>newScore;
    if (subject == "math") {
        mathScore = newScore;
    }
    else if (subject == "english") {
        englishScore = newScore;
    }
    else if (subject == "science") {
        scienceScore = newScore;
    }
    else if (subject == "history") {
        historyScore = newScore;
    }
    else if (subject == "geography") {
        geographyScore = newScore;
    }
    else if (subject == "art") {
        artScore = newScore;
    }
    else {
        cout << "未知科目: " << subject << endl;
        return;
    }
    calculateTotalAndAverage(); // 更新总分和平均分
    cout<<"已成功修改成绩"<<endl;
}

void Grade::deleteScore(const string& gradeId)
{
    if (this->gradeId != gradeId) {
        cout << "成绩不存在，无法删除。" << endl;
        return;
    }
    else
    {
        this->gradeId = "";
        this->mathScore = 0;
        this->englishScore = 0;
        this->scienceScore = 0;
        this->historyScore = 0;
        this->geographyScore = 0;
        this->artScore = 0;
        this->totalScore = 0;
        this->averageScore = 0;
        cout<<"成功删除改学生成绩";
    }
}

float Grade::getScore(const string& subject) const {
    if (subject == "math") {
        return mathScore;
    }
    else if (subject == "english") {
        return englishScore;
    }
    else if (subject == "science") {
        return scienceScore;
    }
    else if (subject == "history") {
        return historyScore;
    }
    else if (subject == "geography") {
        return geographyScore;
    }
    else if (subject == "art") {
        return artScore;
    }
    else {
        cout << "未知科目: " << subject << endl;
        return -1; // 返回一个无效值
    }
}

string Grade::getGradeId() const {
    return gradeId;
}

string Grade::getAllScores() const{
    stringstream ss;
    ss << "学生 ID: " << gradeId << "\n";
    ss << "math(数学): " << mathScore << "\n";
    ss << "english(英语): " << englishScore << "\n";
    ss << "science(科学): " << scienceScore << "\n";
    ss << "history(历史): " << historyScore << "\n";
    ss << "geography(地理): " << geographyScore << "\n";
    ss << "artScore(艺术): " << artScore << "\n";
    ss << "totalScore(总分): " << totalScore << "\n"; // 添加总分
    ss << "averageScore(平均分): " << averageScore << "\n"; // 添加平均分
    return ss.str();
}


void Grade::addScore(const string& newGradeId,const string& name) {
    if (gradeId == newGradeId) {
        cout << "成绩已存在，无法添加。" << endl;
        return;
    }
    else {
        gradeId = newGradeId;
        cout << "请录入" << name << "的学生成绩：" << endl;
        cout << "数学成绩   ";
        cin >> mathScore;
        cout << "英语成绩   ";
        cin >> englishScore;
        cout << "科学成绩   ";
        cin >> scienceScore;
        cout << "历史成绩   ";
        cin >> historyScore;
        cout << "地理成绩   ";
        cin >> geographyScore;
        cout << "艺术成绩   ";
        cin >> artScore;
        cout << "已为学生：" << name << "添加成绩: " << endl;
        calculateTotalAndAverage();
        cout << getAllScores();
    }
}

float Grade::getTotal() const {
    return totalScore;
}

float Grade::getAverage() const {
    return averageScore;
}



vector<string> Grade::getSubjects() const{
    vector<string> v;
    v.push_back("math");
    v.push_back("english");
    v.push_back("science");
    v.push_back("history");
    v.push_back("geography");
    v.push_back("art");
    return v;
}
