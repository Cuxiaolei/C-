#include "Grade.h"
#include <iostream>

Grade::Grade()
        : gradeId(""), mathScore(0), englishScore(0), scienceScore(0),
          assembleScore(0), programmingscore(0), circuitScore(0),
          totalScore(0), averageScore(0) {
    // 无参构造函数，所有变量初始化为0
}

Grade::Grade(const string& gradeId, float mathScore, float englishScore,
             float scienceScore, float assembleScore, float programmingscore, float circuitScore)
        : gradeId(gradeId), mathScore(mathScore), englishScore(englishScore),
          scienceScore(scienceScore), assembleScore(assembleScore), programmingscore(programmingscore),
          circuitScore(circuitScore) {
    calculateTotalAndAverage(); // 计算总分和平均分
}

Grade::Grade(const Grade& other)
        : gradeId(other.gradeId), mathScore(other.mathScore), englishScore(other.englishScore),
          scienceScore(other.scienceScore), assembleScore(other.assembleScore), programmingscore(other.programmingscore),
          circuitScore(other.circuitScore), totalScore(other.totalScore), averageScore(other.averageScore) {
    // 拷贝构造函数
}

Grade& Grade::operator=(const Grade& other) {
    if (this != &other) { // 自我赋值检查
        gradeId = other.gradeId;
        mathScore = other.mathScore;
        englishScore = other.englishScore;
        scienceScore = other.scienceScore;
        assembleScore = other.assembleScore;
        programmingscore = other.programmingscore;
        circuitScore = other.circuitScore;
        totalScore = other.totalScore;
        averageScore = other.averageScore;
    }
    return *this; // 返回自身的引用
}

void Grade::calculateTotalAndAverage() {
    totalScore = mathScore + englishScore + scienceScore + assembleScore + programmingscore + circuitScore;
    averageScore = totalScore / 6; // 计算平均分
}

void Grade::updateScore(const string& gradeId) {
    if (this->gradeId != gradeId) {
        cout << "成绩不存在，无法修改。" << endl;
        return;
    }
    string subject;
    float newScore;
    cout << "当前学生成绩" << endl;
    cout << getAllScores();
    cout << "请输入需要修改的科目:";
    cin >> subject;
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
    else if (subject == "assemble") {
        assembleScore = newScore;
    }
    else if (subject == "programming") {
        programmingscore = newScore;
    }
    else if (subject == "circuit") {
        circuitScore = newScore;
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
        this->assembleScore = 0;
        this->programmingscore = 0;
        this->circuitScore = 0;
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
    else if (subject == "assemble") {
        return assembleScore;
    }
    else if (subject == "programming") {
        return programmingscore;
    }
    else if (subject == "circuit") {
        return circuitScore;
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
    ss << "assemble(汇编): " << assembleScore << "\n";
    ss << "programming(编程): " << programmingscore << "\n";
    ss << "circuitScore(数电): " << circuitScore << "\n";
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
        cout << "物理成绩   ";
        cin >> scienceScore;
        cout << "面向对象成绩   ";
        cin >> assembleScore;
        cout << "编程成绩   ";
        cin >> programmingscore;
        cout << "数电成绩   ";
        cin >> circuitScore;
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



vector<string> Grade::getSubjects() const {
    vector<string> v;
    v.push_back("math");
    v.push_back("english");
    v.push_back("science");
    v.push_back("assemble");
    v.push_back("programming");
    v.push_back("circuit");
    return v;
}