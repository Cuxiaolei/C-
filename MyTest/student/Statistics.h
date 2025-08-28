#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include "Student.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip> // 引入头文件用于格式化输出

using namespace std;

class Statistics {
private:
    vector<Student> students; // 存储所有学生对象

public:
    Statistics(unordered_map<string, Student>& studentCredentials);

    // 按照总分排序
    void sortByTotalScore();

    // 按照平均分排序
    //void sortByAverageScore();
    void sortById();
    // 按照特定科目排序
    void sortBySubjectScore(const string& subject);

    // 显示排名
    void displayRanking();

    // 菜单方法
    void handleUserInput();
};

#endif // STATISTICS_H

