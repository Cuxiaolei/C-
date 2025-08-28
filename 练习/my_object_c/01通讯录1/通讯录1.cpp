#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#define Default_size 3
#define Zengrong 2
#define people 100
#define max_name 20
#define max_sex 10
#define max_tele 12
#define max_addr 30
using namespace std;

//人的信息
struct xinxi
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tele[max_tele];
	char addr[max_addr];
};

//通讯录
//静态
//struct tongxunlu
//{
//	struct xinxi date[people];	//当前通讯录的信息
//	int count;					//记录当前通讯录的人数
//};

//动态通讯录
struct tongxunlu
{
	struct xinxi* date;		//存放信息
	int count;				//记录当前人数
	int capacity;			//当前通讯录的容量
};

//检查增容
void zengrong(struct tongxunlu* pc)
{
	if (pc->count == pc->capacity)
	{
		struct xinxi* p = (struct xinxi*)realloc(pc->date, (pc->capacity + Zengrong) * sizeof(struct xinxi));
		if (p == NULL)
		{
			perror("Addtongxunlu");
			return;
		}
		else
		{
			pc->date = p;
			pc->capacity += Zengrong;
			cout << endl << "空间不够，增容成功" << endl;
		}
	}
}

//加载通讯录
void Loadtongxunlu(struct tongxunlu* pc)
{
	FILE* pfread = fopen("tongxunlu.txt", "rb");
	if (pfread == NULL)
	{
		perror("Loadtongxunlu");
		return;
	}
	//读文件
	struct xinxi tmp = { 0 };

	while ((fread(&tmp, sizeof(struct xinxi), 1, pfread)) == 1)
	{
		zengrong(pc);

		pc->date[pc->count] = tmp;
		pc->count++;
	}


	fclose(pfread);
	pfread = NULL;
}

//动态初始化
int chushihua(struct tongxunlu* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = (struct xinxi*)calloc(Default_size, sizeof(struct xinxi));
	if (pc->date == NULL)
	{
		perror("chushihua");
		return 1;
	}
	pc->capacity = Default_size;

	//加载文件的信息到通讯录中
	Loadtongxunlu(pc);
	return 0;
}

//销毁通讯录
void Destorytongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
}

//静态初始化
//void chushihua(struct tongxunlu* pc)
//{
//	assert(pc);
//	pc->count = 0; 
//	memset(pc->date, 0, sizeof(pc->date));
//}		

//查找函数
int findlianxiren(struct tongxunlu* pc, char name[])
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

//比较函数
int cmp_xinxi_by_name(const void* e1, const void* e2)
{
	return strcmp(((xinxi*)e1)->name, ((xinxi*)e2)->name);
}

//1.打印通讯录
void show(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "你好像没有朋友吧" << endl;
		return;
	}
	int i;
	cout << setw(20) << left << "姓名"
		<< setw(10) << left << "年龄"
		<< setw(10) << left << "性别"
		<< setw(15) << left << "电话"
		<< setw(20) << left << "地址"
		<< endl;
	for (i = 0; i < pc->count; i++)
	{
		cout << setw(20) << left << pc->date[i].name
			<< setw(10) << left << pc->date[i].age
			<< setw(10) << left << pc->date[i].sex
			<< setw(15) << left << pc->date[i].tele
			<< setw(20) << left << pc->date[i].addr << endl;
	}
}

//2.添加联系人（静态版本）
//void Addtongxunlu(struct tongxunlu* pc)
//{
//	
//	assert(pc);		//断言
//	if (pc->count == max_name)	//判断
//	{
//		cout << "你的通讯录已经满了哦" << endl;
//		return;
//	}
//	cout << "请输入名字：";
//	cin >> pc->date[pc->count].name;
//	cout << "请输入年龄：";
//	cin >> pc->date[pc->count].age;
//	cout << "请输入性别：";
//	cin >> pc->date[pc->count].sex;
//	cout << "请输入电话：";
//	cin >> pc->date[pc->count].tele;
//	cout << "请输入地址：";
//	cin >> pc->date[pc->count].addr;
//	pc->count++;
//	cout << "添加成功" << endl;
//}

//2.添加联系人（动态版本）
void Addtongxunlu(struct tongxunlu* pc)
{
	assert(pc);		//断言
	zengrong(pc);
	cout << "请输入名字：";
	cin >> pc->date[pc->count].name;
	cout << "请输入年龄：";
	cin >> pc->date[pc->count].age;
	cout << "请输入性别：";
	cin >> pc->date[pc->count].sex;
	cout << "请输入电话：";
	cin >> pc->date[pc->count].tele;
	cout << "请输入地址：";
	cin >> pc->date[pc->count].addr;
	pc->count++;
	cout << endl << "添加成功" << endl;
}

//3.删除联系人
void deltongxunlu(struct tongxunlu* pc)
{
	assert(pc);	//断言
	cout << "你想把哪个家伙删了：";
	char name[max_name];
	cin >> name;
	if (pc->count == 0)	//判断通讯录是否为空；
	{
		cout << "你应该没有朋友吧" << endl;
		return;
	}
	//查找	
	int a = findlianxiren(pc, name);	//找到的话返回下标，找不到返回-1；
	if (a == -1)
	{
		cout << "查无此人" << endl;
		return;
	}
	for (int i = a; i < pc->count - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	cout << endl << "删除成功" << endl;

}

//4.查找联系人
void searchtongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "请输入要查找人的名字：";
	char name[max_name];
	cin >> name;
	int a = findlianxiren(pc, name);
	if (a == -1)
	{
		cout << "查无此人" << endl;
		return;
	}
	cout << setw(10) << left << "姓名"
		<< setw(10) << left << "年龄"
		<< setw(10) << left << "性别"
		<< setw(15) << left << "电话"
		<< setw(10) << left << "地址"
		<< endl;
	cout << setw(10) << left << pc->date[a].name
		<< setw(10) << left << pc->date[a].age
		<< setw(10) << left << pc->date[a].sex
		<< setw(15) << left << pc->date[a].tele
		<< setw(10) << left << pc->date[a].addr << endl;
}

//5.修改
void xiugaitongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "请输入要修改人的名字：";
	char name[max_name];
	cin >> name;
	int a = findlianxiren(pc, name);
	if (a == -1)
	{
		cout << "查无此人" << endl;
		return;
	}
	cout << "请修改";
	pc->date[a] = { 0 };
	cout << "请输入名字：";
	cin >> pc->date[a].name;
	cout << "请输入年龄：";
	cin >> pc->date[a].age;
	cout << "请输入性别：";
	cin >> pc->date[a].sex;
	cout << "请输入电话：";
	cin >> pc->date[a].tele;
	cout << "请输入地址：";
	cin >> pc->date[a].addr;
	cout << endl << "修改成功" << endl;
}

//6.排序
void sorttongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	qsort(pc->date, pc->count, sizeof(xinxi), cmp_xinxi_by_name);	//qsort(首地址，排序长度，每个元素的字节，比较函数）
	cout << endl << "排序成功" << endl;
}

//8.清空通讯录
void Clean(struct tongxunlu* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = { 0 };
	cout << endl << "清除成功" << endl;
}

//保存
void savetongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	FILE* pfwrite = fopen("tongxunlu.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("savetongxunlu");
		return;
	}
	for (int i = 0; i < pc->count; i++)
	{
		fwrite(&pc->date[i], sizeof(struct xinxi), 1, pfwrite);
	}
	cout << "保存成功！" << endl;
	fclose(pfwrite);
	pfwrite = NULL;
}

//菜单
void menu()
{
	cout << "***************************************************" << endl;
	cout << "************  1.show          2.add    ************" << endl;
	cout << "************  3.del           4.search ************" << endl;
	cout << "************  5.modify        6.sort   ************" << endl;
	cout << "************  7.save          8.clean  ************" << endl;
	cout << "************  0.exit                   ************" << endl;
	cout << "************                           ************" << endl;
	cout << "************                           ************" << endl;
	cout << "***************************************************" << endl;
}

//枚举
enum option
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
	int input = 0;
	struct tongxunlu txl;	//创建通讯录；
	chushihua(&txl);		//初始化通讯录
	menu();
	do
	{
		cout << "请选择:";
		cin >> input;
		switch (input)
		{
		case SHOW:
			show(&txl);	//打印
			break;

		case ADD:
			Addtongxunlu(&txl);	//添加
			break;

		case DEL:
			deltongxunlu(&txl);	//删除
			break;

		case SEARCH:
			searchtongxunlu(&txl);	//查找
			break;

		case MODIFY:
			xiugaitongxunlu(&txl);	//修改
			break;

		case SORT:
			sorttongxunlu(&txl);	//排序
			break;

		case SAVE:
			savetongxunlu(&txl);
			break;
		case CLEAN:
			Clean(&txl);
			break;
		case EXIT:
			Destorytongxunlu(&txl);
			cout << "好的拜拜~" << endl;
			break;

		default:
			cout << "他妈的没这个选项！" << endl;
			break;
		}
	} while (input);

	return 0;
}