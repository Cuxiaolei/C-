#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define SALE_DEPARTMENT 1//销售部门
#define DEVELOP_DEPARTMENT 2//研发部门
#define FINACIAL_DEPARTMENT 3//财务部门
using namespace std;

//multimap案例
//公司今天招聘了5个员工，5名员工进入公司之后，需要指派员工在那个部门工作
//人员信息有：姓名 年龄 电话 工资
//通过 Multimap 进行信息的插入 保存 显示
//分部门显示员工信息 显示全部员工信息





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
	//计算当前部门的总人数
	int DepartCount = workerGroup.count(departID);
	int num = 0;
	for (multimap<int, Worker>::iterator pos = it; pos != workerGroup.end() && num < DepartCount; pos++, num++)
	{
		cout << "姓名:" << pos->second.mName << "  年龄:" << pos->second.mAge << "  电话:" << pos->second.mTele << "  工资:" << pos->second.mSalary << endl;
	}
}



void Creat_Worker(vector<Worker>& vWorker)
{
	string seedName = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Worker worker;
		worker.mName = "员工";
		worker.mName += seedName[i];

		worker.mAge = rand() % 10 + 20;
		worker.mTele = "010-88888888";
		worker.mSalary = rand() % 100000 + 100000;
		//保存员工信息
		vWorker.push_back(worker);
	}
}

void WorkerByGroup(vector<Worker>& vWorker, multimap<int, Worker>& workerGroup)
{
	srand(time(NULL));//随机数种子
	//把员工随机分配到不同部门
	for (vector<Worker>::iterator it = vWorker.begin(); it != vWorker.end(); it++)
	{
		int departID = rand() % 3 + 1;
		switch (departID)
		{
			//销售部门
		case SALE_DEPARTMENT:
			workerGroup.insert(make_pair(SALE_DEPARTMENT, *it));
			break;
			//开发部门
		case DEVELOP_DEPARTMENT:
			workerGroup.insert(make_pair(DEVELOP_DEPARTMENT, *it));
			break;
			//财务部门
		case FINACIAL_DEPARTMENT:
			workerGroup.insert(make_pair(FINACIAL_DEPARTMENT, *it));

			break;
		}
	}
}


//打印每一部分员工信息
void PrintWorkerGroup(multimap<int, Worker>& workerGroup)
{
	//打印销售部员工信息
	cout << "销售部门信息：" << endl;
	ShowGroupWorkers(workerGroup, SALE_DEPARTMENT);
	//打印开发部员工信息
	cout << "开发部门信息：" << endl;
	ShowGroupWorkers(workerGroup, DEVELOP_DEPARTMENT);
	//打印财务部员工信息
	cout << "财务部门信息：" << endl;
	ShowGroupWorkers(workerGroup, FINACIAL_DEPARTMENT);
}



int main()
{
	//存放新员工信息
	vector<Worker> vWorker;
	//multimap保存分组信息
	multimap<int, Worker> workerGroup;
	//创建员工
	Creat_Worker(vWorker);
	//员工分组
	WorkerByGroup(vWorker, workerGroup);
	//打印每一部门的员工信息
	PrintWorkerGroup(workerGroup);



	return 0;
}