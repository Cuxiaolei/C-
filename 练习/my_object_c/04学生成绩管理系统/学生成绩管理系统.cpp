#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<iomanip>  //输入输出格式
#include<string>
#include<stdio.h>
#include<stdlib.h>

#define NAME 20
using namespace std;

//结构体单元---------------------------------------------------------------------------------
typedef struct stu
{
	int count = 0;
	int id;
	char name[NAME];
	float E;
	float M;
	float C;
	float Sum;
}stu;
typedef struct sys
{
	int count = 0;
	stu date;
	sys* next;
}sys;
sys* head = NULL;
sys* tail = NULL;

//为排序创建的数组
typedef struct sysarr
{
	stu* date1;
	int count;
}sysarr;
//初始化
void init(sysarr* ps)
{
	ps->date1 = (stu*)calloc(1, sizeof(stu));
	ps->count = 0;
	cout << "666666666" << endl;
}



//辅助函数1-----------------------------------------------------------------------------------

//打印表头
void showbiaotou()
{
	cout << setw(8) << left << "序号";
	cout << setw(10) << left << "学号";
	cout << setw(15) << left << "姓名";
	cout << setw(15) << left << "英语成绩";
	cout << setw(15) << left << "数学成绩";
	cout << setw(15) << left << "计算机成绩";
	cout << setw(15) << left << "总分";
	cout << setw(8) << left << "名次";
	cout << endl;
}

//检查学号是否重复
int check(int id, sys* ps)
{
	int n = 1;
	sys* p = head;
	void shuchuxinxi(sys * ps, int i);
	while (p != NULL)
	{
		if (p->date.id == id)
		{
			cout << "此学号已存在,如下：" << endl;
			showbiaotou();
			shuchuxinxi(p, n);
			n++;
			cout << endl << "请重新输入!" << endl;
			free(ps);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

//检查学号是否重复(修改模式版本)
int check1(int id, sys* ps, int x)
{
	int n = 1;
	sys* p = head;
	void shuchuxinxi(sys * ps, int i);
	while (p != NULL)	//其实不需要while，ps传过来时ps->date.id就已经等于id了
	{
		if (p->date.id == id)
		{
			if (id == x)
			{
				p = p->next;
				continue;
			}
			cout << "此学号已存在,如下：" << endl;
			showbiaotou();
			shuchuxinxi(p, n);
			n++;
			cout << endl << "请重新输入!" << endl;
			free(ps);
			return 1;
		}
		p = p->next;
	}
	return 0;
}

//输入信息
int shurustu(sys* ps)
{
	cout << "请输入学生学号:";
	cin >> ps->date.id;
	int a = check(ps->date.id, ps);		//判断学号重复
	if (a == 1)
	{
		return 1;
	}
	cout << "请输入学生姓名:";
	cin >> ps->date.name;
	cout << "请输入英语成绩:";
	cin >> ps->date.E;
	cout << "请输入数学成绩:";
	cin >> ps->date.M;
	cout << "请输入计算机成绩:";
	cin >> ps->date.C;
	ps->date.Sum = ps->date.M + ps->date.C + ps->date.E;
	//ps->date.count = 0;
	return 0;
}

//输入信息2(修改模式版本)
int shurustu1(sys* ps, int x)
{
	cout << "请输入学生学号:";
	cin >> ps->date.id;
	int a = check1(ps->date.id, ps, x);		//判断学号重复
	if (a == 1)
	{
		return 1;
	}
	cout << "请输入学生姓名:";
	cin >> ps->date.name;
	cout << "请输入英语成绩:";
	cin >> ps->date.E;
	cout << "请输入数学成绩:";
	cin >> ps->date.M;
	cout << "请输入计算机成绩:";
	cin >> ps->date.C;
	ps->date.Sum = ps->date.M + ps->date.C + ps->date.E;
	//ps->date.count = 0;
	return 0;
}

//输出信息
void shuchuxinxi(sys* ps, int i)
{
	cout << setw(8) << left << i;
	cout << setprecision(2) << fixed;
	cout << setw(10) << left << ps->date.id;
	cout << setw(15) << left << ps->date.name;
	cout << setw(15) << left << ps->date.E;
	cout << setw(15) << left << ps->date.M;
	cout << setw(15) << left << ps->date.C;
	cout << setw(15) << left << ps->date.Sum;
	cout << setw(8) << left << ps->date.count;
	cout << endl;
}

//加载信息
void loadsys(sys* ps)
{
	FILE* pfread = fopen("stusys.txt", "rb");
	if (pfread == NULL)
	{
		perror("loadsys");
		return;
	}
	ps = (sys*)calloc(1, sizeof(sys));
	while (fread(&ps->date, sizeof(stu), 1, pfread))
	{
		ps->next = NULL;
		if (head == NULL)
		{
			head = ps;
		}
		else
		{
			tail->next = ps;
		}
		tail = ps;
		ps = (sys*)calloc(1, sizeof(sys));
	}
	fclose(pfread);
	pfread = NULL;
}

//外部数组排序(学号)
int cmp_arr1(const void* e1, const void* e2)
{
	return (int)(((stu*)e1)->id - ((stu*)e2)->id);
}

//外部数组排序(名字)
int cmp_arr2(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
}

//外部数组排序(总分)
int cmp_arr3(const void* e1, const void* e2)
{
	return (int)(((stu*)e2)->Sum - ((stu*)e1)->Sum);
}



//辅助函数2--------------------------------------------------------

//统计人数
int Count(sys* ps)
{
	int count = 0;
	while (ps != NULL)
	{
		count++;
		ps = ps->next;
	}
	return count;
}

//英语最高分
float MaxEnglish(sys* ps)
{
	float max = 0;
	while (ps != NULL)
	{
		if (max < ps->date.E)
		{
			max = ps->date.E;
		}
		ps = ps->next;
	}
	return max;
}

//英语最低分
float MinEnglish(sys* ps)
{
	float min = 101;
	while (ps != NULL)
	{
		if (min > ps->date.E)
		{
			min = ps->date.E;
		}
		ps = ps->next;
	}
	return min;
}

//英语平均分
float AveEnglish(sys* ps)
{
	float count = (float)Count(ps);
	float sum = 0;
	float ave;
	while (ps != NULL)
	{
		sum += ps->date.E;
		ps = ps->next;
	}
	ave = sum / count;
	return ave;
}

//数学最高分
float MaxMath(sys* ps)
{
	float max = 0;
	while (ps != NULL)
	{
		if (max < ps->date.M)
		{
			max = ps->date.M;
		}
		ps = ps->next;
	}
	return max;
}

//数学最低分
float MinMath(sys* ps)
{
	float min = 101;
	while (ps != NULL)
	{
		if (min > ps->date.M)
		{
			min = ps->date.M;
		}
		ps = ps->next;
	}
	return min;
}

//数学平均分
float AveMath(sys* ps)
{
	float count = (float)Count(ps);
	float sum = 0;
	float ave;
	while (ps != NULL)
	{
		sum += ps->date.M;
		ps = ps->next;
	}
	ave = sum / count;
	return ave;
}

//计算机最高分
float MaxComputer(sys* ps)
{
	float max = 0;
	while (ps != NULL)
	{
		if (max < ps->date.C)
		{
			max = ps->date.C;
		}
		ps = ps->next;
	}
	return max;
}

//计算机最低分
float MinComputer(sys* ps)
{
	float min = 101;
	while (ps != NULL)
	{
		if (min > ps->date.C)
		{
			min = ps->date.C;
		}
		ps = ps->next;
	}
	return min;
}

//计算机平均分
float AveComputer(sys* ps)
{
	float count = (float)Count(ps);
	float sum = 0;
	float ave;
	while (ps != NULL)
	{
		sum += ps->date.C;
		ps = ps->next;
	}
	ave = sum / count;
	return ave;
}

//查找是否有这个人(学号查询)（有的话返回1，没有的话返回0）
int find(sys* ps, int id)
{
	while (ps != NULL && ps->date.id != id)
	{
		ps = ps->next;
	}
	if (ps != NULL && ps->date.id == id)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//查找是否有这个人(姓名查询)（有的话返回1，没有的话返回0）
int find(sys* ps, char name[])
{
	while (ps != NULL && strcmp(ps->date.name, name) != 0)
	{
		ps = ps->next;
	}
	if (ps != NULL && strcmp(ps->date.name, name) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


//功能函数------------------------------------------------------------------------------------

//1.录入信息
void addsys(sys* ps)
{
	cout << "请输入所要添加的学生信息" << endl;
	ps = (sys*)calloc(1, sizeof(sys));
	ps->next = NULL;
	int a = shurustu(ps);		//判断是否学号重复
	if (a == 1)
	{
		return;
	}
	if (head == NULL)
	{
		head = ps;
	}
	else
	{
		tail->next = ps;
	}
	tail = ps;
	cout << "添加成功！" << endl << endl;
}

//2.显示信息
void showsys(sys* ps)
{
	if (ps == NULL)
	{
		cout << "系统为空，请先录入学生信息!" << endl;
		return;
	}
	showbiaotou();
	int n = 1;
	while (ps != NULL)
	{
		shuchuxinxi(ps, n);
		n++;
		ps = ps->next;
	}
	cout << endl;
}

//3.查找
void search(sys* ps)
{
	if (ps == NULL)
	{
		cout << "系统还没有学生信息，找了也是白找！" << endl;
		return;
	}
	char a;
	cout << "请输入要查找的关键词的选项 (1.学号   2.姓名   0.取消):";
	cin >> a;
	//查找学生学号
	if (a == '1')
	{
		int n = 1;
		int id;
		int flag = 0;
		cout << "请输入要查找的学号：";
		cin >> id;
		while (ps != NULL)
		{
			while (ps != NULL && ps->date.id != id)
			{
				ps = ps->next;
			}
			if (ps != NULL && ps->date.id == id)
			{
				if (flag == 0)
				{
					showbiaotou();
				}
				flag = 1;
				shuchuxinxi(ps, n);
				n++;
				ps = ps->next;
			}
		}
		if (flag == 0)
		{
			cout << "查无此号!!" << endl;
			return;
		}
	}
	//查找学生姓名
	else if (a == '2')
	{
		int n = 1;
		char name[NAME];
		int flag = 0;
		cout << "请输入要查找的学生姓名：";
		cin >> name;
		while (ps != NULL)
		{
			while (ps != NULL && strcmp(ps->date.name, name) != 0)
			{
				ps = ps->next;
			}
			if (ps != NULL && strcmp(ps->date.name, name) == 0)
			{
				if (flag == 0)
				{
					showbiaotou();
				}
				flag = 1;
				shuchuxinxi(ps, n);
				n++;
				ps = ps->next;
			}
		}
		if (flag == 0)
		{
			cout << "查无此人!!" << endl;
			return;
		}
	}
	//退出
	else
	{
		cout << "已退出查找" << endl;
		return;
	}
}

//4.排序
void sort(sys* ps)
{
	if (ps == NULL)
	{
		cout << "系统为空，赶紧去录如学生信息吧" << endl;
		return;
	}
	char n;
	cout << "请选择排序方式(1.按学号升序  2.按姓名排序  3.按总分排序+排名):";
	cin >> n;
	if (n == '1')
	{
		sys* pd = ps;
		sysarr arr;
		init(&arr);
		while (pd != NULL)
		{
			arr.date1[arr.count] = pd->date;
			arr.count++;
			arr.date1 = (stu*)realloc(arr.date1, (arr.count + 1) * sizeof(stu));
			pd = pd->next;
		}
		qsort(arr.date1, arr.count, sizeof(stu), cmp_arr1);
		for (int i = 0; i < arr.count; i++)
		{
			ps->date = arr.date1[i];
			ps = ps->next;
		}
		free(arr.date1);
		cout << "按学号排序成功！！" << endl;
	}
	else if (n == '2')
	{
		sys* pd = ps;
		sysarr arr;
		init(&arr);
		while (pd != NULL)
		{
			arr.date1[arr.count] = pd->date;
			arr.count++;
			arr.date1 = (stu*)realloc(arr.date1, (arr.count + 1) * sizeof(stu));
			pd = pd->next;
		}
		qsort(arr.date1, arr.count, sizeof(stu), cmp_arr2);
		for (int i = 0; i < arr.count; i++)
		{
			ps->date = arr.date1[i];
			ps = ps->next;
		}
		free(arr.date1);
		cout << "按姓名排序成功！！" << endl;
	}
	else if (n == '3')
	{
		sys* pd = ps;
		sysarr arr;
		init(&arr);
		while (pd != NULL)
		{
			arr.date1[arr.count] = pd->date;
			arr.count++;
			arr.date1 = (stu*)realloc(arr.date1, (arr.count + 1) * sizeof(stu));
			pd = pd->next;
		}
		qsort(arr.date1, arr.count, sizeof(stu), cmp_arr3);
		for (int i = 0; i < arr.count; i++)
		{
			ps->date = { 0 };
			ps->date = arr.date1[i];
			ps->date.count = i + 1;
			ps = ps->next;
		}
		free(arr.date1);
		cout << "按总分排序成功！！" << endl;
	}
	else
	{
		cout << "输入错误，请认真选择，排序已退出" << endl;
	}
}

//5.统计
void statistic(sys* ps)
{
	if (ps == NULL)
	{
		cout << "系统为空，赶紧去录入学生信息吧" << endl;
		return;
	}
	char flag;
	int count = Count(ps);
	cout << "请选择对应哪门课（1.英语  2.数学  3.计算机  0.退出）进行统计：";
	cin >> flag;
	//英语
	if (flag == '1')
	{
		float e1 = MaxEnglish(ps);
		float e2 = MinEnglish(ps);
		float e3 = AveEnglish(ps);
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
		while (ps != NULL)
		{
			if (ps->date.E >= 90.0)
			{
				a1++;
			}
			else if (ps->date.E >= 80.0)
			{
				a2++;
			}
			else if (ps->date.E >= 70.0)
			{
				a3++;
			}
			else if (ps->date.E >= 60.0)
			{
				a4++;
			}
			else if (ps->date.E < 60.0)
			{
				a5++;
			}
			ps = ps->next;
		}
		cout << setprecision(2) << fixed;
		cout << "*********************************************************" << endl;
		cout << "学生总数：" << count << endl;
		cout << "最高分：" << e1 << endl;
		cout << "最低分：" << e2 << endl;
		cout << "平均成绩：" << e3 << endl;
		cout << "成绩分布情况：" << endl;
		cout << setw(10) << left << "分数段";
		cout << setw(10) << left << "人数";
		cout << setw(10) << left << "百分比";
		cout << endl;
		cout << setw(10) << left << "[90,100]";
		cout << setw(10) << left << a1;
		cout << (a1 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[80,90)";
		cout << setw(10) << left << a2;
		cout << (a2 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[70,80)";
		cout << setw(10) << left << a3;
		cout << (a3 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[60,70)";
		cout << setw(10) << left << a4;
		cout << (a4 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[0,60)";
		cout << setw(10) << left << a5;
		cout << (a5 / (float)count) * 100 << "%" << endl;
		cout << "*********************************************************" << endl;
	}
	//数学
	else if (flag == '2')
	{
		float e1 = MaxMath(ps);
		float e2 = MinMath(ps);
		float e3 = AveMath(ps);
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
		while (ps != NULL)
		{
			if (ps->date.M >= 90.0)
			{
				a1++;
			}
			else if (ps->date.M >= 80.0)
			{
				a2++;
			}
			else if (ps->date.M >= 70.0)
			{
				a3++;
			}
			else if (ps->date.M >= 60.0)
			{
				a4++;
			}
			else if (ps->date.M < 60.0)
			{
				a5++;
			}
			ps = ps->next;
		}
		cout << setprecision(2) << fixed;
		cout << "*********************************************************" << endl;
		cout << "学生总数：" << count << endl;
		cout << "最高分：" << e1 << endl;
		cout << "最低分：" << e2 << endl;
		cout << "平均成绩：" << e3 << endl;
		cout << "成绩分布情况：" << endl;
		cout << setw(10) << left << "分数段";
		cout << setw(10) << left << "人数";
		cout << setw(10) << left << "百分比";
		cout << endl;
		cout << setw(10) << left << "[90,100]";
		cout << setw(10) << left << a1;
		cout << (a1 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[80,90)";
		cout << setw(10) << left << a2;
		cout << (a2 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[70,80)";
		cout << setw(10) << left << a3;
		cout << (a3 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[60,70)";
		cout << setw(10) << left << a4;
		cout << (a4 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[0,60)";
		cout << setw(10) << left << a5;
		cout << (a5 / (float)count) * 100 << "%" << endl;
		cout << "*********************************************************" << endl;
	}
	//计算机
	else if (flag == '3')
	{
		float e1 = MaxComputer(ps);
		float e2 = MinComputer(ps);
		float e3 = AveComputer(ps);
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
		while (ps != NULL)
		{
			if (ps->date.C >= 90.0)
			{
				a1++;
			}
			else if (ps->date.C >= 80.0)
			{
				a2++;
			}
			else if (ps->date.C >= 70.0)
			{
				a3++;
			}
			else if (ps->date.C >= 60.0)
			{
				a4++;
			}
			else if (ps->date.C < 60.0)
			{
				a5++;
			}
			ps = ps->next;
		}
		cout << setprecision(2) << fixed;
		cout << "*********************************************************" << endl;
		cout << "学生总数：" << count << endl;
		cout << "最高分：" << e1 << endl;
		cout << "最低分：" << e2 << endl;
		cout << "平均成绩：" << e3 << endl;
		cout << "成绩分布情况：" << endl;
		cout << setw(10) << left << "分数段";
		cout << setw(10) << left << "人数";
		cout << setw(10) << left << "百分比";
		cout << endl;
		cout << setw(10) << left << "[90,100]";
		cout << setw(10) << left << a1;
		cout << (a1 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[80,90)";
		cout << setw(10) << left << a2;
		cout << (a2 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[70,80)";
		cout << setw(10) << left << a3;
		cout << (a3 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[60,70)";
		cout << setw(10) << left << a4;
		cout << (a4 / (float)count) * 100 << "%" << endl;
		cout << setw(10) << left << "[0,60)";
		cout << setw(10) << left << a5;
		cout << (a5 / (float)count) * 100 << "%" << endl;
		cout << "*********************************************************" << endl;
	}
	//退出
	else
	{
		cout << "已退出统计" << endl;
		return;
	}
}

//6.修改
void modify(sys* ps)
{
	if (ps == NULL)
	{
		cout << "系统里还没有学生信息，赶紧去添加吧：" << endl;
		return;
	}
	cout << "请输入选择学生方式（1.学号  2.姓名  0.退出）：";
	char n;
	cin >> n;
	if (n == '1')
	{
		cout << "请输入想要修改信息的学生的学号：";
		int id;
		cin >> id;
		while (ps != NULL && ps->date.id != id)
		{
			ps = ps->next;
		}
		if (ps->date.id == id)
		{
			cout << "请输入修改后的信息：" << endl;
			ps->date = { 0 };
			int a = shurustu1(ps, id);
			if (a == 1)
			{
				return;
			}
			cout << "修改成功！" << endl;
		}
	}
	else if (n == '2')
	{
		cout << "请输入想要修改信息的学生的姓名：";
		char name[NAME];
		cin >> name;
		while (ps != NULL && strcmp(ps->date.name, name) != 0)
		{
			ps = ps->next;
		}
		if (strcmp(ps->date.name, name) == 0)
		{
			cout << "请输入修改后的信息：" << endl;
			int id = ps->date.id;
			ps->date = { 0 };
			int a = shurustu1(ps, id);
			if (a == 1)
			{
				return;
			}
			cout << "修改成功！" << endl;
		}
	}
	else
	{
		cout << "已退出修改" << endl;
		return;
	}
}

//7.删除
void Delete(sys** ps)
{
	if (*ps == NULL)
	{
		cout << "系统中还没有学生信息，赶紧去录入吧！" << endl;
		return;
	}
	sys* pf = *ps;
	sys* pd = *ps;
	cout << "请输入选择删除学生方式（1.学号  2.姓名  0.退出）：";
	char n;
	cin >> n;
	if (n == '1')
	{
		cout << "请输入要删除学生信息的学号：";
		int id;
		cin >> id;
		while (pd != NULL && pd->date.id != id)
		{
			pf = pd;
			pd = pd->next;
		}
		if (pd->date.id == id)
		{
			if (pf == pd)
			{
				*ps = (*ps)->next;
				free(pd);
			}
			else
			{
				pf->next = pd->next;
				free(pd);
			}
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "并没有找到你想要删除的人" << endl;
		}
	}
	else if (n == '2')
	{
		cout << "请输入要删除学生信息的姓名：";
		char name[NAME];
		cin >> name;
		while (pd != NULL && strcmp(pd->date.name, name) != 0)
		{
			pf = pd;
			pd = pd->next;
		}
		if (strcmp(pd->date.name, name) == 0)
		{
			if (pf == pd)
			{
				*ps = (*ps)->next;
				free(pd);
			}
			else
			{
				pf->next = pd->next;
				free(pd);
			}
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "并没有找到你想要删除的人" << endl;
		}
	}

}

//8.插入
void insert(sys** ps, sys* p)
{
	if (p == NULL)
	{
		cout << "系统还没有信息，快去录入学生信息吧" << endl;
		return;
	}
	cout << "请输入选择学生方式（1.学号  2.姓名  0.退出）：";
	char n;
	cin >> n;
	if (n == '1')
	{
		cout << "请输入要插入学生信息的位置（学号）：";
		int id;
		cin >> id;
		int a = find(p, id);
		sys* pf = p;
		sys* pd = p;
		if (a == 1)
		{
			cout << "请输入要将信息插入到该位置的哪里（u.上方  d.下方）：";
			char ch;
			cin >> ch;
			sys* pc = (sys*)calloc(1, sizeof(sys));
			pc->next = NULL;
			int a = shurustu(pc);
			if (a == 1)			//判断输入的学号是否重复
			{
				return;
			}
			while (pd->date.id != id)
			{
				pf = pd;
				pd = pd->next;
			}
			if (ch == 'u' || ch == 'U')
			{
				if (pf == pd)
				{
					*ps = pc;
					pc->next = pf;
				}
				else
				{
					pf->next = pc;
					pc->next = pd;
				}
			}
			else if (ch == 'd' || ch == 'D')
			{
				if (pf == pd)
				{
					sys* pl = pf->next;
					pf->next = pc;
					pc->next = pl;
				}
				else
				{
					sys* pl = pd->next;
					pd->next = pc;
					pc->next = pl;
				}
			}
			else
			{
				cout << "输入不合法，已退出插入" << endl;
				return;
			}
			cout << "插入成功！" << endl;
		}
		else
		{
			cout << "找不到这个学号，是不是输入错了？" << endl;
			return;
		}
	}
	else if (n == '2')
	{
		cout << "请输入要插入学生信息的位置（姓名）：";
		char name[NAME];
		cin >> name;
		int a = find(p, name);
		sys* pf = p;
		sys* pd = p;
		if (a == 1)
		{
			cout << "请输入要将信息插入到该位置的哪里（u.上方  d.下方）：";
			char ch;
			cin >> ch;
			sys* pc = (sys*)calloc(1, sizeof(sys));
			pc->next = NULL;
			int a = shurustu(pc);		//判断是否重复
			if (a == 1)
			{
				return;
			}
			while (strcmp(pd->date.name, name) != 0)
			{
				pf = pd;
				pd = pd->next;
			}
			if (ch == 'u' || ch == 'U')
			{
				if (pf == pd)
				{
					*ps = pc;
					pc->next = pf;
				}
				else
				{
					pf->next = pc;
					pc->next = pd;
				}
			}
			else if (ch == 'd' || ch == 'D')
			{
				if (pf == pd)
				{
					sys* pl = pf->next;
					pf->next = pc;
					pc->next = pl;
				}
				else
				{
					sys* pl = pd->next;
					pd->next = pc;
					pc->next = pl;
				}
			}
			else
			{
				cout << "输入不合法，已退出插入" << endl;
				return;
			}
			cout << "插入成功！" << endl;
		}
		else
		{
			cout << "找不到这个学号，是不是输入错了？" << endl;
			return;
		}
	}
	else
	{
		cout << "已退出插入" << endl;
		return;
	}
}

//9.保存
void save(sys* ps)
{
	FILE* pfwrite = fopen("stusys.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("save");
		return;
	}
	if (ps == NULL)
	{
		cout << "保存成功！" << endl;
		fclose(pfwrite);
		pfwrite = NULL;
		return;
	}
	while (ps != NULL)
	{
		fwrite(&ps->date, sizeof(stu), 1, pfwrite);
		ps = ps->next;
	}
	cout << "保存成功！" << endl;
	fclose(pfwrite);
	pfwrite = NULL;
}

//c.清屏
void clean()
{
	cout << "\033c";
}

//d.清空系统数据
void alldelete(sys** ps)
{
	sys* p = *ps;
	while (p != NULL)
	{
		sys* pd = p;
		p = p->next;
		free(pd);
	}
	*ps = p;
	cout << "清除成功！" << endl;
}



//菜单
void menu()
{
	cout << "------------------------------------------学生成绩管理系统---------------------------------------------------" << endl;
	cout << "1.录入     2.显示     3.查找     4.排序     5.统计     6.修改     7.删除     8.插入     9.保存     0.退出" << endl;
	cout << "c.清屏     d.清空系统 " << endl;
	cout << "-------------------------------------------------------------------------------------------------------------" << endl;
}

//主函数-------------------------------------------------------------------------------------------------
int main()
{
	cout << "请输入学生成绩管理系统密码（你只有三次机会)：";
	char IPN[20];
	cin >> IPN;
	int q = 0;
	while (strcmp(IPN, "woshi541hehe") != 0)
	{
		q++;
		if (q == 3)
		{
			cout << "你已经输入错误三次，系统已自动退出！！！" << endl;
			return 0;
		}
		cout << "密码错误，请重新输入：";
		cin >> IPN;
	}
	loadsys(head);		//加载信息
	menu();				//菜单
	cout << endl << "请选择功能：";
	int flag = 1;
	int flag1 = 1;
	char input;
	while (1)
	{
		if (flag == 0)
		{
			cout << "请再次选择功能：";
		}
		flag = 0;
		cin >> input;
		if (input == '1')
		{
			addsys(head);
			int flag1 = 1;
		}
		else if (input == '2')
		{
			showsys(head);
			int flag1 = 1;
		}
		else if (input == '3')
		{
			search(head);
			int flag1 = 1;
		}
		else if (input == '4')
		{
			sort(head);
			int flag1 = 1;
		}
		else if (input == '5')
		{
			statistic(head);
			int flag1 = 1;
		}
		else if (input == '6')
		{
			modify(head);
			int flag1 = 1;
		}
		else if (input == '7')
		{
			Delete(&head);
			int flag1 = 1;
		}
		else if (input == '8')
		{
			insert(&head, head);
			int flag1 = 1;
		}
		else if (input == '9')
		{
			save(head);
			flag1 = 0;
		}
		else if (input == 'c')
		{
			clean();
			menu();
		}
		else if (input == 'd')
		{
			alldelete(&head);
			int flag1 = 1;
		}
		else if (input == '0')
		{
			//提醒是否要保存
			if (flag1 == 1)
			{
				char ch;
				cout << "退出前是否要保存?(y/n):";
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					save(head);
				}
			}
			cout << "拜拜~" << endl;
			break;
		}
		else
		{
			cout << "? ? ? ! ! ! ! ! ! ! ,你tm在选什么？" << endl;
		}
	}
	return 0;
}
