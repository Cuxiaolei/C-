#include "Grade.h"
#include <iostream>

Grade::Grade()
        : gradeId(""), mathScore(0), englishScore(0), scienceScore(0),
          assembleScore(0), programmingscore(0), circuitScore(0),
          totalScore(0), averageScore(0) {
    // �޲ι��캯�������б�����ʼ��Ϊ0
}

Grade::Grade(const string& gradeId, float mathScore, float englishScore,
             float scienceScore, float assembleScore, float programmingscore, float circuitScore)
        : gradeId(gradeId), mathScore(mathScore), englishScore(englishScore),
          scienceScore(scienceScore), assembleScore(assembleScore), programmingscore(programmingscore),
          circuitScore(circuitScore) {
    calculateTotalAndAverage(); // �����ֺܷ�ƽ����
}

Grade::Grade(const Grade& other)
        : gradeId(other.gradeId), mathScore(other.mathScore), englishScore(other.englishScore),
          scienceScore(other.scienceScore), assembleScore(other.assembleScore), programmingscore(other.programmingscore),
          circuitScore(other.circuitScore), totalScore(other.totalScore), averageScore(other.averageScore) {
    // �������캯��
}

Grade& Grade::operator=(const Grade& other) {
    if (this != &other) { // ���Ҹ�ֵ���
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
    return *this; // �������������
}

void Grade::calculateTotalAndAverage() {
    totalScore = mathScore + englishScore + scienceScore + assembleScore + programmingscore + circuitScore;
    averageScore = totalScore / 6; // ����ƽ����
}

void Grade::updateScore(const string& gradeId) {
    if (this->gradeId != gradeId) {
        cout << "�ɼ������ڣ��޷��޸ġ�" << endl;
        return;
    }
    string subject;
    float newScore;
    cout << "��ǰѧ���ɼ�" << endl;
    cout << getAllScores();
    cout << "��������Ҫ�޸ĵĿ�Ŀ:";
    cin >> subject;
    cout<<"�������޸ĺ�ĳɼ�:";
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
        cout << "δ֪��Ŀ: " << subject << endl;
        return;
    }
    calculateTotalAndAverage(); // �����ֺܷ�ƽ����
    cout<<"�ѳɹ��޸ĳɼ�"<<endl;
}

void Grade::deleteScore(const string& gradeId)
{
    if (this->gradeId != gradeId) {
        cout << "�ɼ������ڣ��޷�ɾ����" << endl;
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
        cout<<"�ɹ�ɾ����ѧ���ɼ�";
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
        cout << "δ֪��Ŀ: " << subject << endl;
        return -1; // ����һ����Чֵ
    }
}

string Grade::getGradeId() const {
    return gradeId;
}

string Grade::getAllScores() const{
    stringstream ss;
    ss << "ѧ�� ID: " << gradeId << "\n";
    ss << "math(��ѧ): " << mathScore << "\n";
    ss << "english(Ӣ��): " << englishScore << "\n";
    ss << "science(��ѧ): " << scienceScore << "\n";
    ss << "assemble(���): " << assembleScore << "\n";
    ss << "programming(���): " << programmingscore << "\n";
    ss << "circuitScore(����): " << circuitScore << "\n";
    ss << "totalScore(�ܷ�): " << totalScore << "\n"; // ����ܷ�
    ss << "averageScore(ƽ����): " << averageScore << "\n"; // ���ƽ����
    return ss.str();
}


void Grade::addScore(const string& newGradeId,const string& name) {
    if (gradeId == newGradeId) {
        cout << "�ɼ��Ѵ��ڣ��޷���ӡ�" << endl;
        return;
    }
    else {
        gradeId = newGradeId;
        cout << "��¼��" << name << "��ѧ���ɼ���" << endl;
        cout << "��ѧ�ɼ�   ";
        cin >> mathScore;
        cout << "Ӣ��ɼ�   ";
        cin >> englishScore;
        cout << "����ɼ�   ";
        cin >> scienceScore;
        cout << "�������ɼ�   ";
        cin >> assembleScore;
        cout << "��̳ɼ�   ";
        cin >> programmingscore;
        cout << "����ɼ�   ";
        cin >> circuitScore;
        cout << "��Ϊѧ����" << name << "��ӳɼ�: " << endl;
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