#pragma once
#ifndef GRADE_H
#define GRADE_H

#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

class Grade {
private:
    string gradeId;         //成绩id，与学生学号匹配
    float mathScore;        // 高数成绩
    float englishScore;     // 英语成绩
    float scienceScore;     // 物理成绩
    float assembleScore;     // 汇编成绩
    float programmingscore;   // 编程成绩
    float circuitScore;         // 数电成绩
    float totalScore;       // 总分
    float averageScore;     // 平均分

public:

    Grade(); // 无参构造函数
    Grade(const string& gradeId, float mathScore, float englishScore,
          float scienceScore, float assembleScore, float programmingscore, float circuitScore);
    Grade(const Grade& other); // 拷贝构造函数
    Grade& operator=(const Grade& other); // 赋值运算符重载

    void addScore(const string& newGradeId,const string& name);//添加成绩
    void updateScore(const string& gradeId);//更新成绩
    void deleteScore(const string& gradeId);//删除成绩
    void calculateTotalAndAverage(); // 计算总分和平均分
    string getAllScores() const; // 获取所有成绩

    float getScore(const string& subject) const;//获取单科成绩
    string getGradeId() const;//获取id
    float getTotal() const;//获取总分
    float getAverage() const;//获取平均分
    vector<string> getSubjects() const;//获取所有科目
};

#endif // GRADE_H

