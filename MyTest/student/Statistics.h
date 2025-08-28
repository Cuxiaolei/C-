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
    Statistics(unordered_map<string, Student>& studentCredentials);

    // �����ܷ�����
    void sortByTotalScore();

    // ����ƽ��������
    //void sortByAverageScore();
    void sortById();
    // �����ض���Ŀ����
    void sortBySubjectScore(const string& subject);

    // ��ʾ����
    void displayRanking();

    // �˵�����
    void handleUserInput();
};

#endif // STATISTICS_H

