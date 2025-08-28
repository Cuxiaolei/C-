#pragma once
#ifndef STATISTICS_H
#define STATISTICS_H

#include "Student.h"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iomanip> // ����ͷ�ļ����ڸ�ʽ�����

using namespace std;

class Statistics {
private:
    vector<Student> students; // �洢����ѧ������

public:
    Statistics(const unordered_map<string, Student>& studentCredentials);

    // �����ܷ�����
    vector<Student> sortByTotalScore();

    // ����ƽ��������
    vector<Student> sortByAverageScore();

    // �����ض���Ŀ����
    vector<Student> sortBySubjectScore(const string& subject);

    // ��ʾ����
    void displayRanking(const vector<Student>& sortedStudents);

    // �˵�����
    void handleUserInput();
};

#endif // STATISTICS_H


