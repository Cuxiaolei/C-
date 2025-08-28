#include "Grade.h"
#include <iostream>

Grade::Grade()
        : gradeId(""), mathScore(0), englishScore(0), scienceScore(0),
          historyScore(0), geographyScore(0), artScore(0),
          totalScore(0), averageScore(0) {
    // �޲ι��캯�������б�����ʼ��Ϊ0
}

Grade::Grade(const string& gradeId, float mathScore, float englishScore,
             float scienceScore, float historyScore, float geographyScore, float artScore)
        : gradeId(gradeId), mathScore(mathScore), englishScore(englishScore),
          scienceScore(scienceScore), historyScore(historyScore), geographyScore(geographyScore),
          artScore(artScore) {
    calculateTotalAndAverage(); // �����ֺܷ�ƽ����
}

Grade::Grade(const Grade& other)
        : gradeId(other.gradeId), mathScore(other.mathScore), englishScore(other.englishScore),
          scienceScore(other.scienceScore), historyScore(other.historyScore), geographyScore(other.geographyScore),
          artScore(other.artScore), totalScore(other.totalScore), averageScore(other.averageScore) {
    // �������캯��
}

Grade& Grade::operator=(const Grade& other) {
    if (this != &other) { // ���Ҹ�ֵ���
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
    return *this; // �������������
}

void Grade::calculateTotalAndAverage() {
    totalScore = mathScore + englishScore + scienceScore + historyScore + geographyScore + artScore;
    averageScore = totalScore / 6; // ����ƽ����
}

void Grade::updateScore(const string& gradeId) {
    if (this->gradeId != gradeId) {
        cout << "�ɼ������ڣ��޷��޸ġ�" << endl;
        return;
    }
    string subject;
    float newScore;
    cout<<"��ǰѧ���ɼ�"<<endl;
    cout<< getAllScores();
    cout<<"��������Ҫ�޸ĵĿ�Ŀ:";
    cin>>subject;
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
        this->historyScore = 0;
        this->geographyScore = 0;
        this->artScore = 0;
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
    ss << "history(��ʷ): " << historyScore << "\n";
    ss << "geography(����): " << geographyScore << "\n";
    ss << "artScore(����): " << artScore << "\n";
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
        cout << "��ѧ�ɼ�   ";
        cin >> scienceScore;
        cout << "��ʷ�ɼ�   ";
        cin >> historyScore;
        cout << "����ɼ�   ";
        cin >> geographyScore;
        cout << "�����ɼ�   ";
        cin >> artScore;
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
