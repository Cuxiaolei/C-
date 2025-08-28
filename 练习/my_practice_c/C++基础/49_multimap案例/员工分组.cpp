#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define SALE_DEPARTMENT 1//���۲���
#define DEVELOP_DEPARTMENT 2//�з�����
#define FINACIAL_DEPARTMENT 3//������
using namespace std;

//multimap����
//��˾������Ƹ��5��Ա����5��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//��Ա��Ϣ�У����� ���� �绰 ����
//ͨ�� Multimap ������Ϣ�Ĳ��� ���� ��ʾ
//�ֲ�����ʾԱ����Ϣ ��ʾȫ��Ա����Ϣ





class Worker
{
public:
	string mName;
	string mTele;
	int mAge;
	int mSalary;
};


void ShowGroupWorkers(multimap<int, Worker>& workerGroup, int departID)
{
	multimap<int, Worker>::iterator it = workerGroup.find(departID);
	//���㵱ǰ���ŵ�������
	int DepartCount = workerGroup.count(departID);
	int num = 0;
	for (multimap<int, Worker>::iterator pos = it; pos != workerGroup.end() && num < DepartCount; pos++, num++)
	{
		cout << "����:" << pos->second.mName << "  ����:" << pos->second.mAge << "  �绰:" << pos->second.mTele << "  ����:" << pos->second.mSalary << endl;
	}
}



void Creat_Worker(vector<Worker>& vWorker)
{
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.mName = "Ա��";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mTele = "010-88888888";
		worker.mSalary = rand() % 100000 + 100000;
		//����Ա����Ϣ
		vWorker.push_back(worker);
	}
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup)
{
	srand(time(NULL));//���������
	//��Ա��������䵽��ͬ����
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		int departID = rand() % 3 + 1;
		switch (departID)
		{
			//���۲���
		case SALE_DEPARTMENT:
			workerGroup.insert(make_pair(SALE_DEPARTMENT, *it));
			break;
			//��������
		case DEVELOP_DEPARTMENT:
			workerGroup.insert(make_pair(DEVELOP_DEPARTMENT, *it));
			break;
			//������
		case FINACIAL_DEPARTMENT:
			workerGroup.insert(make_pair(FINACIAL_DEPARTMENT, *it));

			break;
		}
	}
}


//��ӡÿһ����Ա����Ϣ
void PrintWorkerGroup(multimap<int, Worker>& workerGroup)
{
	//��ӡ���۲�Ա����Ϣ
	cout << "���۲�����Ϣ��" << endl;
	ShowGroupWorkers(workerGroup, SALE_DEPARTMENT);
	//��ӡ������Ա����Ϣ
	cout << "����������Ϣ��" << endl;
	ShowGroupWorkers(workerGroup, DEVELOP_DEPARTMENT);
	//��ӡ����Ա����Ϣ
	cout << "��������Ϣ��" << endl;
	ShowGroupWorkers(workerGroup, FINACIAL_DEPARTMENT);
}



int main()
{
	//�����Ա����Ϣ
	vector<Worker> vWorker;
	//multimap���������Ϣ
	multimap<int, Worker> workerGroup;
	//����Ա��
	Creat_Worker(vWorker);
	//Ա������
	WorkerByGroup(vWorker, workerGroup);
	//��ӡÿһ���ŵ�Ա����Ϣ
	PrintWorkerGroup(workerGroup);



	return 0;
}