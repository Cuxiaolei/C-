#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define NAME 20
#define TELE 20
#define Count 3		//初始空间
#define Capacity 3  //每次增加的空间
#define AGE 20
//#define
//#define
//#define
using namespace std;

//信息结构体
struct xinxi
{
	char name[NAME];
	char age[AGE];
	char tele[TELE];

};

//通讯录
struct tongxunlu
{
	struct xinxi* date;
	int count;		//当前人数
	int capacity;	//当前容量
};

//判断+增容（无提示版）
void CheckIncrease1(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->capacity == pc->count)
	{
		struct xinxi* p = (struct xinxi*)realloc(pc->date, (pc->capacity + Capacity) * sizeof(struct xinxi));
		if (p == NULL)
		{
			cout << "增容失败" << endl;
			perror("CheckIncrease");
			return;
		}
		pc->date = p;
		pc->capacity += Capacity;
	}
}

//加载通讯录信息
void Loadtongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	FILE* pfread = fopen("tongxunlu.txt", "rb");
	if (pfread == NULL)
	{
		perror("Loadtongxunlu");
		return;
	}
	struct xinxi tem = { 0 };
	while (fread(&tem, sizeof(struct xinxi), 1, pfread))
	{
		CheckIncrease1(pc);
		pc->date[pc->count] = tem;
		pc->count++;
	}
}

//初始化
void Init(struct tongxunlu* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = (struct xinxi*)calloc(Count, sizeof(struct xinxi));
	pc->capacity = Count;
	//加载通讯录信息
	Loadtongxunlu(pc);
}






//辅助函数------------------------------------------------------

//判断+增容
void CheckIncrease(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->capacity == pc->count)
	{
		struct xinxi* p = (struct xinxi*)realloc(pc->date, (pc->capacity + Capacity) * sizeof(struct xinxi));
		if (p == NULL)
		{
			cout << "增容失败" << endl;
			perror("CheckIncrease");
			return;
		}
		pc->date = p;
		pc->capacity += Capacity;
		cout << "空间不足，增容成功" << endl;
	}
}

//查找联系人（返回下标,找不到返回-1）
int Find(struct tongxunlu* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->date[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//排序函数
int cmp_xinxi(const void* e1, const void* e2)
{
	return strcmp(((struct xinxi*)e1)->name, ((struct xinxi*)e2)->name);
}






//功能函数-------------------------------------------------------------

//1.打印通讯录
void Show(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "你还没有朋友吧（坏笑）" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << setw(20) << left << "姓名";
		cout << setw(20) << left << "年龄";
		cout << setw(20) << left << "电话";
		cout << endl;
		for (int i = 0; i < pc->count; i++)
		{
			cout << setw(20) << left << pc->date[i].name;
			cout << setw(20) << left << pc->date[i].age;
			cout << setw(20) << left << pc->date[i].tele;
			cout << endl;
		}
	}
}

//2.添加联系人
void Addtongxunlu(struct tongxunlu* pc)
{
	assert(pc);		//断言
	if (pc == NULL)
	{
		perror("Addtongxunlu");
		return;
	}
	CheckIncrease(pc);
	cout << "请输入需要添加的联系人的信息：" << endl;
	cout << "请输入联系人姓名：";
	cin >> pc->date[pc->count].name;
	cout << "请输入联系人年龄：";
	cin >> pc->date[pc->count].age;
	cout << "请输入联系人电话：";
	cin >> pc->date[pc->count].tele;
	pc->count++;
	cout << endl << "添加成功！" << endl;
}

//3.删除联系人
void Deltongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "你还没有朋友可以让你删除！" << endl;
		return;
	}
	char name[NAME];
	cout << "请输入你想要删掉的人的名字：";
	cin >> name;
	int a = Find(pc, name);
	if (a == -1)
	{
		cout << "没有找到这个人哦~，是不是名字输入错了呢";
		return;
	}
	else
	{
		for (int i = a; i < pc->count - 1; i++)
		{
			pc->date[a] = pc->date[a + 1];
		}
		cout << "删除成功！" << endl;
		pc->count--;
	}
}

//4.查找联系人
void Searchtongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "请输入你想要查找的人的名字：";
	char name[NAME];
	cin >> name;
	int a = Find(pc, name);
	if (a == -1)
	{
		cout << "你好像没这个朋友呢，是不是名字写错了？" << endl;
		return;
	}
	else
	{
		cout << setw(20) << left << "姓名";
		cout << setw(20) << left << "年龄";
		cout << setw(20) << left << "电话";
		cout << endl;
		cout << setw(20) << left << pc->date[a].name;
		cout << setw(20) << left << pc->date[a].age;
		cout << setw(20) << left << pc->date[a].tele;
		cout << endl;
	}
}

//5.修改信息
void Modifytongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "你想要修改谁的信息：";
	char name[NAME];
	cin >> name;
	int a = Find(pc, name);
	if (a == -1)
	{
		cout << "查无此人" << endl;
		return;
	}
	else
	{
		pc->date[a] = { 0 };
		cout << "请修改" << endl;
		cout << "请输入修改后的名字：";
		cin >> pc->date[a].name;
		cout << "请输入修改后的年龄：";
		cin >> pc->date[a].age;
		cout << "请输入修改后的电话：";
		cin >> pc->date[a].tele;
		cout << "修改成功！";
	}
}

//6.排序
void Sorttongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "你的通讯录还是空的诶，拿什么排序" << endl;
		return;
	}
	qsort(pc->date, pc->count, sizeof(struct xinxi), cmp_xinxi);
	cout << "排序成功" << endl;
}

//7.保存
void Savetongxunlu(struct tongxunlu* pc, int* flag)
{
	assert(pc);
	FILE* pfwrite = fopen("tongxunlu.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("Savetongxunlu");
		return;
	}
	fwrite(pc->date, sizeof(struct xinxi), pc->count, pfwrite);

	fclose(pfwrite);
	pfwrite = NULL;
	cout << "保存成功！！" << endl;
	*flag = 1;
}

//8.清空通讯录
void Cleantongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
	pc->count = 0;
	pc->capacity = Count;
	cout << "清除成功";
}






//基本函数-------------------------------------------------------------

//菜单
void menu()
{
	cout << "***************************************************" << endl;
	cout << "***********  1.show           2.add    ************" << endl;
	cout << "***********  3.del            4.search ************" << endl;
	cout << "***********  5.modify         6.sort   ************" << endl;
	cout << "***********  7.save           8.clean  ************" << endl;
	cout << "***********                            ************" << endl;
	cout << "***********                            ************" << endl;
	cout << "***********                   0.exit   ************" << endl;
	cout << "***************************************************" << endl;
	cout << endl;
}

//销毁通讯录
void Destroytongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
}

//枚举
enum object
{
	EXIT,
	SHOW,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SAVE,
	CLEAN
};


int main()
{
	menu();
	struct tongxunlu txl;
	Init(&txl);
	int input = 0;
	int flag = 0;
	while (1)
	{
		cout << endl;
		cout << "请选择：";
		cin >> input;
		if (input == SHOW)
		{
			Show(&txl);
		}
		else if (input == ADD)
		{
			Addtongxunlu(&txl);
		}
		else if (input == DEL)
		{
			Deltongxunlu(&txl);
		}
		else if (input == SEARCH)
		{
			Searchtongxunlu(&txl);
		}
		else if (input == MODIFY)
		{
			Modifytongxunlu(&txl);
		}
		else if (input == SORT)
		{
			Sorttongxunlu(&txl);
		}
		else if (input == SAVE)
		{
			Savetongxunlu(&txl, &flag);
		}
		else if (input == CLEAN)
		{
			Cleantongxunlu(&txl);
		}
		else if (input == EXIT)
		{
			if (flag == 0)
			{
				cout << "是否保存：（y/n）";
				char c;
				cin >> c;
				if (c == 'y' || c == 'Y')
				{
					Savetongxunlu(&txl, &flag);
				}
			}
			Destroytongxunlu(&txl);
			cout << endl << "拜拜`" << endl;
			break;
		}
		else
		{
			cout << endl << "他妈的没这个选项！！！" << endl;
		}
	}
	return 0;
}