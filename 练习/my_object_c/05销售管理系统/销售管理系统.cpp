#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string>
#include<iomanip>
#define SALER 10	//销售人输出长度
#define SALES 15	//销售额输出长度
#define SSALES 15	//销售总额输出长度
#define FU '-'		//边框形式
using namespace std;

//结构体   -----------------------------------------------------------------------------------

//链表1（保存每天的数据）
//产品数据（产品编号+产品销售额）
typedef struct Protect
{
	int code_p;
	long long sales;
}Protect;
//每个销售员的数据
typedef struct Note
{
	int code_c;
	Protect pro1;
	Protect pro2;
	Protect pro3;
	Protect pro4;
	Protect pro5;
}Note;
//每天四个销售员的数据
typedef struct Day
{
	Note man1;
	Note man2;
	Note man3;
	Note man4;
	Day* next;
}Day;
Day* head = NULL;
Day* tail = NULL;
//汇总
typedef struct Sum
{
	//每种产品销售额汇总
	long long spro1 = 0;
	long long spro2 = 0;
	long long spro3 = 0;
	long long spro4 = 0;
	long long spro5 = 0;
	//每个人的每种产品销售额汇总
	long long sman1_1 = 0;
	long long sman1_2 = 0;
	long long sman1_3 = 0;
	long long sman1_4 = 0;
	long long sman1_5 = 0;

	long long sman2_1 = 0;
	long long sman2_2 = 0;
	long long sman2_3 = 0;
	long long sman2_4 = 0;
	long long sman2_5 = 0;

	long long sman3_1 = 0;
	long long sman3_2 = 0;
	long long sman3_3 = 0;
	long long sman3_4 = 0;
	long long sman3_5 = 0;

	long long sman4_1 = 0;
	long long sman4_2 = 0;
	long long sman4_3 = 0;
	long long sman4_4 = 0;
	long long sman4_5 = 0;
	//每个人的总销售额汇总
	long long sman1 = 0;
	long long sman2 = 0;
	long long sman3 = 0;
	long long sman4 = 0;
}Sum;
Sum s;



//成员数据(编号+各种产品销售额)
typedef struct ManDate
{
	int code;
	long long spro_1;
	long long spro_2;
	long long spro_3;
	long long spro_4;
	long long spro_5;
	long long sman;
}ManDate;
//数组1
typedef struct ArrMan
{
	ManDate* dateman;  //为了方便排序，需要将数据放在一个结构体中
}ArrMan;

//产品数据（编号+每种产品的总销售额）
typedef struct ProtectDate
{
	int ProtectCode;
	long long SumProtect;
}ProtectDate;
//数组2
typedef struct ArrProtect
{
	ProtectDate* dateprotect;	//为了方便排序，需要将数据放在一个结构体中
}Arr1;



//辅助函数 --------------------------------------------------------------------------

//初始化
void Init(Day* p)
{
	p->man1.code_c = 1;
	p->man2.code_c = 2;
	p->man3.code_c = 3;
	p->man4.code_c = 4;

	p->man1.pro1.code_p = 1;
	p->man1.pro2.code_p = 2;
	p->man1.pro3.code_p = 3;
	p->man1.pro4.code_p = 4;
	p->man1.pro5.code_p = 5;

	p->man2.pro1.code_p = 1;
	p->man2.pro2.code_p = 2;
	p->man2.pro3.code_p = 3;
	p->man2.pro4.code_p = 4;
	p->man2.pro5.code_p = 5;

	p->man3.pro1.code_p = 1;
	p->man3.pro2.code_p = 2;
	p->man3.pro3.code_p = 3;
	p->man3.pro4.code_p = 4;
	p->man3.pro5.code_p = 5;

	p->man4.pro1.code_p = 1;
	p->man4.pro2.code_p = 2;
	p->man4.pro3.code_p = 3;
	p->man4.pro4.code_p = 4;
	p->man4.pro5.code_p = 5;
}

//统计天数
int Count()
{
	Day* p = head;
	int count = 0;
	while (p != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

//汇总
void sum(Day* p)
{
	Day* ps = p;
	//初始化（防止每次计算叠加）
	s.sman1 = 0; s.sman1_1 = 0; s.sman1_2 = 0; s.sman1_3 = 0; s.sman1_4 = 0; s.sman1_5 = 0;
	s.sman2 = 0; s.sman2_1 = 0; s.sman2_2 = 0; s.sman2_3 = 0; s.sman2_4 = 0; s.sman2_5 = 0;
	s.sman2 = 0; s.sman3_1 = 0; s.sman3_2 = 0; s.sman3_3 = 0; s.sman3_4 = 0; s.sman3_5 = 0;
	s.sman4 = 0; s.sman4_1 = 0; s.sman4_2 = 0; s.sman4_3 = 0; s.sman4_4 = 0; s.sman4_5 = 0;
	//每个人的每种产品的总销售额
	while (ps != NULL)
	{
		s.sman1_1 += ps->man1.pro1.sales;
		s.sman1_2 += ps->man1.pro2.sales;
		s.sman1_3 += ps->man1.pro3.sales;
		s.sman1_4 += ps->man1.pro4.sales;
		s.sman1_5 += ps->man1.pro5.sales;

		s.sman2_1 += ps->man2.pro1.sales;
		s.sman2_2 += ps->man2.pro2.sales;
		s.sman2_3 += ps->man2.pro3.sales;
		s.sman2_4 += ps->man2.pro4.sales;
		s.sman2_5 += ps->man2.pro5.sales;

		s.sman3_1 += ps->man3.pro1.sales;
		s.sman3_2 += ps->man3.pro2.sales;
		s.sman3_3 += ps->man3.pro3.sales;
		s.sman3_4 += ps->man3.pro4.sales;
		s.sman3_5 += ps->man3.pro5.sales;

		s.sman4_1 += ps->man4.pro1.sales;
		s.sman4_2 += ps->man4.pro2.sales;
		s.sman4_3 += ps->man4.pro3.sales;
		s.sman4_4 += ps->man4.pro4.sales;
		s.sman4_5 += ps->man4.pro5.sales;
		ps = ps->next;
	}
	//每种产品的总销售额
	s.spro1 = s.sman1_1 + s.sman2_1 + s.sman3_1 + s.sman4_1;
	s.spro2 = s.sman1_2 + s.sman2_2 + s.sman3_2 + s.sman4_2;
	s.spro3 = s.sman1_3 + s.sman2_3 + s.sman3_3 + s.sman4_3;
	s.spro4 = s.sman1_4 + s.sman2_4 + s.sman3_4 + s.sman4_4;
	s.spro5 = s.sman1_5 + s.sman2_5 + s.sman3_5 + s.sman4_5;

	//每个销售员的总销售额；
	s.sman1 = s.sman1_1 + s.sman1_2 + s.sman1_3 + s.sman1_4 + s.sman1_5;
	s.sman2 = s.sman2_1 + s.sman2_2 + s.sman2_3 + s.sman2_4 + s.sman2_5;
	s.sman3 = s.sman3_1 + s.sman3_2 + s.sman3_3 + s.sman3_4 + s.sman3_5;
	s.sman4 = s.sman4_1 + s.sman4_2 + s.sman4_3 + s.sman4_4 + s.sman4_5;
}

//表头
void biaotou()
{
	cout << setw(10) << left << "销售员";
	cout << setw(SALES) << left << "产品1(元)";
	cout << setw(SALES) << left << "产品2(元)";
	cout << setw(SALES) << left << "产品3(元)";
	cout << setw(SALES) << left << "产品4(元)";
	cout << setw(SALES) << left << "产品5(元)";
}

//表头1（只有产品12345）
void biaotou1()
{
	cout << setw(SALES) << left << "产品1(元)";
	cout << setw(SALES) << left << "产品2(元)";
	cout << setw(SALES) << left << "产品3(元)";
	cout << setw(SALES) << left << "产品4(元)";
	cout << setw(SALES) << left << "产品5(元)";
}

//输入
void shuru(Day* p)
{
	cout << "请输入第一个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man1.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man1.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man1.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man1.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man1.pro5.sales;

	cout << "请输入第二个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man2.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man2.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man2.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man2.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man2.pro5.sales;

	cout << "请输入第三个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man3.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man3.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man3.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man3.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man3.pro5.sales;

	cout << "请输入第四个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man4.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man4.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man4.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man4.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man4.pro5.sales;
}

//修改（销售员1）
void shuru1(Day* p)
{
	cout << "请修改第一个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man1.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man1.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man1.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man1.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man1.pro5.sales;
}
//修改（销售员2）
void shuru2(Day* p)
{
	cout << "请修改第二个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man2.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man2.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man2.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man2.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man2.pro5.sales;
}
//修改（销售员3）
void shuru3(Day* p)
{
	cout << "请修改第三个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man3.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man3.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man3.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man3.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man3.pro5.sales;
}
//修改（销售员4）
void shuru4(Day* p)
{
	cout << "请修改第四个销售员的便条：" << endl;
	cout << "产品1的销售额：";
	cin >> p->man4.pro1.sales;
	cout << "产品2的销售额：";
	cin >> p->man4.pro2.sales;
	cout << "产品3的销售额：";
	cin >> p->man4.pro3.sales;
	cout << "产品4的销售额：";
	cin >> p->man4.pro4.sales;
	cout << "产品5的销售额：";
	cin >> p->man4.pro5.sales;
}

//输出
void shuchu(Day* p)
{
	cout << setw(SALER) << left << p->man1.code_c;
	cout << setw(SALES) << left << p->man1.pro1.sales;
	cout << setw(SALES) << left << p->man1.pro2.sales;
	cout << setw(SALES) << left << p->man1.pro3.sales;
	cout << setw(SALES) << left << p->man1.pro4.sales;
	cout << setw(SALES) << left << p->man1.pro5.sales;
	cout << endl;

	cout << setw(SALER) << left << p->man2.code_c;
	cout << setw(SALES) << left << p->man2.pro1.sales;
	cout << setw(SALES) << left << p->man2.pro2.sales;
	cout << setw(SALES) << left << p->man2.pro3.sales;
	cout << setw(SALES) << left << p->man2.pro4.sales;
	cout << setw(SALES) << left << p->man2.pro5.sales;
	cout << endl;

	cout << setw(SALER) << left << p->man3.code_c;
	cout << setw(SALES) << left << p->man3.pro1.sales;
	cout << setw(SALES) << left << p->man3.pro2.sales;
	cout << setw(SALES) << left << p->man3.pro3.sales;
	cout << setw(SALES) << left << p->man3.pro4.sales;
	cout << setw(SALES) << left << p->man3.pro5.sales;
	cout << endl;

	cout << setw(SALER) << left << p->man4.code_c;
	cout << setw(SALES) << left << p->man4.pro1.sales;
	cout << setw(SALES) << left << p->man4.pro2.sales;
	cout << setw(SALES) << left << p->man4.pro3.sales;
	cout << setw(SALES) << left << p->man4.pro4.sales;
	cout << setw(SALES) << left << p->man4.pro5.sales;
	cout << endl;
}

//qsort排序函数
int com_ManDate(const void* e1, const void* e2)
{
	//return (int)(((ManDate*)e2)->sman - ((ManDate*)e1)->sman);
	if (((ManDate*)e2)->sman > ((ManDate*)e1)->sman)
		return 1;
	if (((ManDate*)e2)->sman == ((ManDate*)e1)->sman)
		return 0;
	if (((ManDate*)e2)->sman < ((ManDate*)e1)->sman)
		return -1;
	return 0;
}
int com_ProtectDate(const void* e1, const void* e2)
{
	//return (int)(((ProtectDate*)e2)->SumProtect - ((ProtectDate*)e1)->SumProtect);
	if (((ProtectDate*)e2)->SumProtect > ((ProtectDate*)e1)->SumProtect)
		return 1;
	if (((ProtectDate*)e2)->SumProtect == ((ProtectDate*)e1)->SumProtect)
		return 0;
	if (((ProtectDate*)e2)->SumProtect < ((ProtectDate*)e1)->SumProtect)
		return -1;
	return 0;
}







//功能函数  ----------------------------------------------------------------------------
//1.读取销售情况
void ShowEveryday(Day* p)
{
	if (p == NULL)
	{
		cout << "你的系统数据为空，赶紧去录如信息吧！！" << endl;
		return;
	}
	int i = 1;
	int count = Count();
	cout << "目前已录入" << count << "天信息，如下" << endl;
	while (p != NULL)
	{
		cout << endl << "第" << i << "天具体销售额：" << endl;
		for (int j = 0; j < SALER + 5 * SALES - 3; j++)
		{
			cout << FU;
		}
		cout << endl;
		i++;
		biaotou();
		cout << endl;
		shuchu(p);
		for (int j = 0; j < SALER + 5 * SALES - 3; j++)
		{
			cout << FU;
		}
		cout << endl;
		p = p->next;
	}
	cout << endl;
}

//2.便条信息录入
void Add()
{
	Day* ps;
	cout << "请输入加入的便条：" << endl;
	ps = (Day*)calloc(1, sizeof(Day));
	Init(ps);		//初始化p,销售员，产品
	shuru(ps);		//输入提示信息+输入
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
	cout << "录入成功！！" << endl << endl;
}

//3.计算每个人每种产品的销售额
void Calculate_Sort(Day* p)
{
	sum(p);
	ArrMan arr1;
	arr1.dateman = (ManDate*)calloc(4, sizeof(ManDate));
	arr1.dateman[0].code = 1;
	arr1.dateman[0].spro_1 = s.sman1_1;
	arr1.dateman[0].spro_2 = s.sman1_2;
	arr1.dateman[0].spro_3 = s.sman1_3;
	arr1.dateman[0].spro_4 = s.sman1_4;
	arr1.dateman[0].spro_5 = s.sman1_5;
	arr1.dateman[0].sman = s.sman1;

	arr1.dateman[1].code = 2;
	arr1.dateman[1].spro_1 = s.sman2_1;
	arr1.dateman[1].spro_2 = s.sman2_2;
	arr1.dateman[1].spro_3 = s.sman2_3;
	arr1.dateman[1].spro_4 = s.sman2_4;
	arr1.dateman[1].spro_5 = s.sman2_5;
	arr1.dateman[1].sman = s.sman2;

	arr1.dateman[2].code = 3;
	arr1.dateman[2].spro_1 = s.sman3_1;
	arr1.dateman[2].spro_2 = s.sman3_2;
	arr1.dateman[2].spro_3 = s.sman3_3;
	arr1.dateman[2].spro_4 = s.sman3_4;
	arr1.dateman[2].spro_5 = s.sman3_5;
	arr1.dateman[2].sman = s.sman3;

	arr1.dateman[3].code = 4;
	arr1.dateman[3].spro_1 = s.sman4_1;
	arr1.dateman[3].spro_2 = s.sman4_2;
	arr1.dateman[3].spro_3 = s.sman4_3;
	arr1.dateman[3].spro_4 = s.sman4_4;
	arr1.dateman[3].spro_5 = s.sman4_5;
	arr1.dateman[3].sman = s.sman4;
	qsort(arr1.dateman, 4, sizeof(ManDate), com_ManDate);
	for (int i = 0; i < 2 * SALER + 5 * SALES - 5 + SSALES; i++)
	{
		cout << FU;
	}
	cout << endl;
	biaotou();
	cout << setw(SSALES) << left << "总销售额(元)";
	cout << setw(SALER) << left << "排名" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(SALER) << left << arr1.dateman[i].code;
		cout << setw(SALES) << left << arr1.dateman[i].spro_1;
		cout << setw(SALES) << left << arr1.dateman[i].spro_2;
		cout << setw(SALES) << left << arr1.dateman[i].spro_3;
		cout << setw(SALES) << left << arr1.dateman[i].spro_4;
		cout << setw(SALES) << left << arr1.dateman[i].spro_5;
		cout << setw(SSALES) << left << arr1.dateman[i].sman;
		cout << setw(SALER) << left << i + 1;
		cout << endl;
	}
	for (int i = 0; i < 2 * SALER + 5 * SALES - 5 + SSALES; i++)
	{
		cout << FU;
	}
	cout << endl;
}

//4.查找某个销售员每天的便条
void SearchSomebodyEveryDay(Day* p)
{
	cout << "请输入要查找的销售员：";
	char ch;
	cin >> ch;
	if (ch == '1')
	{
		cout << "销售员1的便条：" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "第" << i << setw(SALER - 3) << left << "天";
			cout << setw(SALES) << left << p->man1.pro1.sales;
			cout << setw(SALES) << left << p->man1.pro2.sales;
			cout << setw(SALES) << left << p->man1.pro3.sales;
			cout << setw(SALES) << left << p->man1.pro4.sales;
			cout << setw(SALES) << left << p->man1.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else if (ch == '2')
	{
		cout << "销售员2的便条：" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "第" << i << setw(SALER - 3) << left << "天";
			cout << setw(SALES) << left << p->man2.pro1.sales;
			cout << setw(SALES) << left << p->man2.pro2.sales;
			cout << setw(SALES) << left << p->man2.pro3.sales;
			cout << setw(SALES) << left << p->man2.pro4.sales;
			cout << setw(SALES) << left << p->man2.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else if (ch == '3')
	{
		cout << "销售员3的便条：" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "第" << i << setw(SALER - 3) << left << "天";
			cout << setw(SALES) << left << p->man3.pro1.sales;
			cout << setw(SALES) << left << p->man3.pro2.sales;
			cout << setw(SALES) << left << p->man3.pro3.sales;
			cout << setw(SALES) << left << p->man3.pro4.sales;
			cout << setw(SALES) << left << p->man3.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else if (ch == '4')
	{
		cout << "销售员4的便条：" << endl;
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		cout << setw(SALER) << left << "Day\\pro";
		biaotou1();
		cout << endl;
		int i = 1;
		while (p != NULL)
		{
			cout << "第" << i << setw(SALER - 3) << left << "天";
			cout << setw(SALES) << left << p->man4.pro1.sales;
			cout << setw(SALES) << left << p->man4.pro2.sales;
			cout << setw(SALES) << left << p->man4.pro3.sales;
			cout << setw(SALES) << left << p->man4.pro4.sales;
			cout << setw(SALES) << left << p->man4.pro5.sales;
			cout << endl;
			p = p->next;
			i++;
		}
		for (int i = 0; i < SALER + 5 * SALES - 3; i++)
		{
			cout << FU;
		}
		cout << endl;
		return;
	}
	else
	{
		cout << "输入不合法！！" << endl;
		return;
	}
}

//5.查找某一天的便条
void SearchSomeday(Day* p)
{
	cout << "请输入要查找的那一天：";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "输入不合法，天数可没有负数哦~" << endl;
		return;
	}
	for (int i = 1; i <= Count(); i++)
	{
		if (n == i)
		{
			cout << "第" << i << "天便条：" << endl;
			for (int j = 0; j < SALER + 5 * SALES - 3; j++)
			{
				cout << FU;
			}
			cout << endl;
			biaotou();
			cout << endl;
			shuchu(p);
			for (int j = 0; j < SALER + 5 * SALES - 3; j++)
			{
				cout << FU;
			}
			cout << endl;
			return;
		}
		p = p->next;
	}
	cout << "并没有这一天的便条哦~,再等几天吧" << endl;
	return;
}

//6.删除某一天的便条
void DeleteSomeday(Day** p)
{
	Day* pd = *p;
	Day* pf = *p;
	cout << "请输入要删除的那一天：";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "输入不合法，天数可没有负数哦~" << endl;
		return;
	}
	if (n == 1)
	{
		*p = (*p)->next;
		free(pd);
		cout << "删除成功！" << endl;
		return;
	}
	for (int i = 1; i <= Count(); i++)
	{
		if (i == n)
		{
			pf->next = pd->next;
			free(pd);
			cout << "删除成功！" << endl;
			return;
		}
		pf = pd;
		pd = pd->next;
	}
	cout << "并没有这一天的便条哦~,再等几天吧" << endl;
	return;
}

//7.修改某一天的便条信息
void ModifySomeday(Day* p)
{
	cout << "请输入要修改的那一天：";
	int n;
	cin >> n;
	if (n < 1)
	{
		cout << "输入不合法，天数可没有负数哦~" << endl;
		return;
	}
	for (int i = 1; i <= Count(); i++)
	{
		if (i == n)
		{
			cout << "请选择（0.全部修改  1.修改销售员1的便条  2.修改销售员2的便条  3.修改销售员3的便条  4.修改销售员4的便条)：" << endl;
			int ch;
			cin >> ch;
			cout << "请修改";
			if (ch == 0)
			{
				shuru(p);
			}
			else if (ch == 1)
			{
				shuru1(p);
			}
			else if (ch == 2)
			{
				shuru2(p);
			}
			else if (ch == 3)
			{
				shuru3(p);
			}
			else if (ch == 4)
			{
				shuru4(p);
			}
			cout << "修改成功" << endl;
			return;
		}
		p = p->next;
	}
	cout << "并没有这一天的便条哦~,再等几天吧" << endl;
	return;

}

//8.统计每种产品销售额并排序
void Statistic_EveryProtect_Sort(Day* p)
{
	sum(p);
	ArrProtect arr2;
	arr2.dateprotect = (ProtectDate*)calloc(5, sizeof(ProtectDate));
	arr2.dateprotect[0].ProtectCode = 1;
	arr2.dateprotect[0].SumProtect = s.spro1;
	arr2.dateprotect[1].ProtectCode = 2;
	arr2.dateprotect[1].SumProtect = s.spro2;
	arr2.dateprotect[2].ProtectCode = 3;
	arr2.dateprotect[2].SumProtect = s.spro3;
	arr2.dateprotect[3].ProtectCode = 4;
	arr2.dateprotect[3].SumProtect = s.spro4;
	arr2.dateprotect[4].ProtectCode = 5;
	arr2.dateprotect[4].SumProtect = s.spro5;

	qsort(arr2.dateprotect, 5, sizeof(ProtectDate), com_ProtectDate);
	cout << "五种产品总销售额排名如下：" << endl;
	for (int j = 0; j < 2 * SALER + SSALES - 5; j++)
	{
		cout << FU;
	}
	cout << endl;
	cout << setw(SALER) << left << "产品";
	cout << setw(SSALES) << left << "总销售额(元)";
	cout << setw(SALER) << left << "排名" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "产品";
		cout << setw(SALER - 4) << left << arr2.dateprotect[i].ProtectCode;
		cout << setw(SSALES) << left << arr2.dateprotect[i].SumProtect;
		cout << setw(SALER) << left << i + 1;
		cout << endl;
	}
	for (int j = 0; j < 2 * SALER + SSALES - 5; j++)
	{
		cout << FU;
	}
	cout << endl;
}

//c.清屏
void Clean()
{
	cout << "\033c";
}

//d.清空数据
void Alldele(Day** ps)
{
	Day* p = *ps;
	while (p != NULL)
	{
		Day* pd = p;
		p = p->next;
		free(pd);
	}
	*ps = p;
	cout << "系统数据已清空！" << endl;
}

//s.保存
void Save(Day* p)
{
	FILE* pfwrite = fopen("system.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("save");
		return;
	}
	while (p != NULL)
	{
		fwrite(&p->man1, 1, sizeof(Note), pfwrite);
		fwrite(&p->man2, 1, sizeof(Note), pfwrite);
		fwrite(&p->man3, 1, sizeof(Note), pfwrite);
		fwrite(&p->man4, 1, sizeof(Note), pfwrite);
		p = p->next;
	}
	cout << "保存成功！！";
	fclose(pfwrite);
	pfwrite = NULL;
}








//菜单
void menu()
{
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
	cout << "    *   |    *   |   *   1.读取所有天数的具体销售额             2.录入四个人一天的便条     *   |   *   |   *    " << endl;
	cout << "     *  |   * *  |  *    3.计算销售额并对销售员排序             4.查询某个销售员每天的便条  *  |  * *  |  *     " << endl;
	cout << "      * |  *   * | *     5.查询某一天的便条信息                 6.删除便条信息               * | *   * | *      " << endl;
	cout << "       * *      * *      7.修改便条信息                         8.统计每种产品的销售额并排序  * *     * *       " << endl;
	cout << "        |        |       9.                                     0.                             |       |        " << endl;
	cout << "        *        *   c(clear).清屏   d(delete).清空数据   s(save).保存   e(exit).退出系统      *       *        " << endl;
	cout << "----------------------------------------------------------------------------------------------------------------" << endl;
}

//加载文件
void Load(Day* p)
{
	FILE* pfread = fopen("system.txt", "rb");
	if (pfread == NULL)
	{
		perror("Load");
		return;
	}
	int i = 0;
	p = (Day*)calloc(1, sizeof(Day));
	while (fread(&p->man1, sizeof(Note), 1, pfread) != 0)
	{
		i = 1;
		p->next = NULL;
		fread(&p->man2, sizeof(Note), 1, pfread);
		fread(&p->man3, sizeof(Note), 1, pfread);
		fread(&p->man4, sizeof(Note), 1, pfread);
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
		p = (Day*)calloc(1, sizeof(Day));
	}
	free(p);
	fclose(pfread);
	pfread = NULL;
}

//主函数--------------------------------------------------------------------------------------------------------------

int main()
{
	Load(head);		//加载文件
	menu();			//打印菜单		
	char input;		//输入以字符方式输入，防止输入错误时系统报错
	int flag = 0;
	cout << "请选择功能：";
	cin >> input;
	while (1)
	{
		if (input == '1')
		{
			ShowEveryday(head);
		}
		else if (input == '2')
		{
			Add();
		}
		else if (input == '3')
		{
			Calculate_Sort(head);
		}
		else if (input == '4')
		{
			SearchSomebodyEveryDay(head);
		}
		else if (input == '5')
		{
			SearchSomeday(head);
		}
		else if (input == '6')
		{
			DeleteSomeday(&head);
		}
		else if (input == '7')
		{
			ModifySomeday(head);
		}
		else if (input == '8')
		{
			Statistic_EveryProtect_Sort(head);
		}
		else if (input == 's')
		{
			Save(head);
			flag = 1;
		}
		else if (input == 'c')
		{
			Clean();			//清屏之后打印菜单
			menu();
		}
		else if (input == 'd')
		{
			Alldele(&head);
		}
		else if (input == 'e')
		{
			//判断是否保存（y.保存）输入其他不保存
			if (flag == 0)
			{
				cout << "是否保存(y/n)：";
				char ch;
				cin >> ch;
				if (ch == 'y' || ch == 'Y')
				{
					Save(head);
				}
			}
			cout << endl << "拜拜~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			return 0;
		}
		else
		{
			cout << "你tm选的这个是什么，赶紧重选！！！！" << endl;
		}
		cout << "请再次选择功能：";
		cin >> input;
	}
	return 0;
}

