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
    string gradeId;         //�ɼ�id����ѧ��ѧ��ƥ��
    float mathScore;        // ��ѧ�ɼ�
    float englishScore;     // Ӣ��ɼ�
    float scienceScore;     // ��ѧ�ɼ�
    float historyScore;     // ��ʷ�ɼ�
    float geographyScore;   // ����ɼ�
    float artScore;         // �����ɼ�
    float totalScore;       // �ܷ�
    float averageScore;     // ƽ����

public:

    Grade(); // �޲ι��캯��
    Grade(const string& gradeId, float mathScore, float englishScore,
          float scienceScore, float historyScore, float geographyScore, float artScore);
    Grade(const Grade& other); // �������캯��
    Grade& operator=(const Grade& other); // ��ֵ���������

    void addScore(const string& newGradeId,const string& name);//��ӳɼ�
    void updateScore(const string& gradeId);//���³ɼ�
    void deleteScore(const string& gradeId);//ɾ���ɼ�
    void calculateTotalAndAverage(); // �����ֺܷ�ƽ����
    string getAllScores() const; // ��ȡ���гɼ�

    float getScore(const string& subject) const;//��ȡ���Ƴɼ�
    string getGradeId() const;//��ȡid
    float getTotal() const;//��ȡ�ܷ�
    float getAverage() const;//��ȡƽ����
    vector<string> getSubjects() const;//��ȡ���п�Ŀ
};

#endif // GRADE_H

