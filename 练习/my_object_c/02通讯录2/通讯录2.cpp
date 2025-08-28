#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define NAME 20
#define AGE 20
#define TEL 20
//#define
//#define
//#define
//#define
using namespace std;





//----------------------------------------------------------------------------
//信息
typedef struct xinxi
{
	char name[NAME];
	char age[AGE];
	char tel[TEL];

}xinxi;

//链表单元
typedef struct tongxunlu
{
	xinxi date;
	tongxunlu* next;

}tongxunlu;

//头尾
tongxunlu* head = NULL;
tongxunlu* tail = NULL;


//辅助函数-------------------------------------------------------------------------
//打印表头
void biaotou()
{
	cout << setw(20) << left << "姓名";
	cout << setw(20) << left << "年龄";
	cout << setw(20) << left << "电话";
	cout << endl;
}

//打印联系人信息
void dayinlxr(tongxunlu* pc)
{
	cout << setw(20) << left << pc->date.name;
	cout << setw(20) << left << pc->date.age;
	cout << setw(20) << left << pc->date.tel;
	cout << endl;
}

//输入联系人信息
void shurulxr(tongxunlu* pc)
{
	cout << "请输入姓名:";
	cin >> pc->date.name;
	cout << "请输入年龄:";
	cin >> pc->date.age;
	cout << "请输入电话:";
	cin >> pc->date.tel;
}

//记录人数
int Count(tongxunlu* pc)
{
	int count = 0;
	while (pc != NULL)
	{
		count++;
		pc = pc->next;
	}
	return count;
}







//功能函数------------------------------------------------------------------------------------------

//1.打印通讯录
void showtongxunlu(tongxunlu* pc)
{
	if (pc == NULL)
	{
		cout << "你还没有朋友可以展示哦（哈哈）" << endl;
		return;
	}
	biaotou();			//表头	
	while (pc != NULL)
	{
		dayinlxr(pc);	//打印信息
		pc = pc->next;
	}
}

//2.添加联系人
void addtongxunlu(tongxunlu* pc)
{
	pc = (tongxunlu*)calloc(1, sizeof(tongxunlu));
	shurulxr(pc);
	pc->next = NULL;
	if (head == NULL)
	{
		head = pc;
	}
	else
	{
		tail->next = pc;
	}
	tail = pc;
	cout << "添加成功" << endl;
}

//3.删除联系人
void deltongxunlu(tongxunlu** pc)
{
	tongxunlu* pf = *pc;
	tongxunlu* pd = *pc;
	char name[NAME] = { 0 };
	if (*pc == NULL)
	{
		cout << "你的通讯录还是空的哦，没有朋友吧~（坏笑）" << endl;
		return;
	}
	cout << "请输入你想要删除的人的名字：";
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
			*pc = (*pc)->next;
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
		cout << "并没有找到你想要删除的人，是不是名字写错了？";
	}
}

//4.搜索联系人
void searchtongxunlu(tongxunlu* pc)
{
	if (pc == NULL)
	{
		cout << "你的通讯录还是空的，并没有人可以让你搜索哦~" << endl;
		return;
	}
	char name[NAME] = { 0 };
	int flag = 1;
	cout << "请输入你想要搜索的人的名字：";
	cin >> name;

	while (pc != NULL)
	{
		while (strcmp(pc->date.name, name) != 0)
		{
			pc = pc->next;
		}
		if (strcmp(pc->date.name, name) == 0)
		{
			if (flag)
			{
				biaotou();
			}
			dayinlxr(pc);
			pc = pc->next;
			flag = 0;
		}
	}
	if (flag == 0)
	{
		cout << "没有找到此人！" << endl;
	}

}

//5.修改联系人信息
void modifytongxunlu(tongxunlu* pc)
{
	if (pc == NULL)
	{
		cout << "你的通讯录还是空的，并没有人的信息可以让你修改哦~" << endl;
		return;
	}
	char name[NAME] = { 0 };
	int flag = 1;
	cout << "你想要修改谁的信息：";
	cin >> name;
	while (pc != NULL && strcmp(pc->date.name, name) != 0)
	{
		pc = pc->next;
	}
	if (strcmp(pc->date.name, name) == 0)
	{
		pc->date = { 0 };
		cout << "修改吧" << endl;
		shurulxr(pc);
		cout << "修改成功!" << endl;
	}
	else
	{
		cout << "没有找到这个人哦~" << endl;
	}
}

//6.插入联系人信息
void inserttongxunlu(tongxunlu** pc)
{
	if (*pc == NULL)
	{
		cout << "你的通讯录还是空的，并没有哪个位置可以插入信息哦~" << endl;
		return;
	}
	tongxunlu* pf = *pc;
	tongxunlu* pd = *pc;
	tongxunlu* pa = *pc;
	tongxunlu* p = (tongxunlu*)calloc(1, sizeof(tongxunlu));
	p->next = NULL;
	char name[NAME];
	char d;
	cout << "想要在谁的位置插入信息：";
	cin >> name;
	//查找是否有这个人
	while (strcmp(pa->date.name, name) != 0)
	{
		pa = pa->next;
		if (pa == NULL)
		{
			cout << "找不到这个人我怎么插入信息！" << endl;
			return;
		}
	}

	cout << "想要插在下方还是上方（u/d)：";
	//判断输入是否合法
	while (1)
	{
		cin >> d;
		if (d != 'u' && d != 'U' && d != 'd' && d != 'D')
		{
			cout << "请认真输入！！" << endl;
			continue;
		}
		break;
	}

	cout << "请输入要插入的信息：" << endl;
	shurulxr(p);
	while (pd != NULL && strcmp(pd->date.name, name) != 0)
	{
		pf = pd;
		pd = pd->next;
	}
	if (strcmp(pd->date.name, name) == 0)
	{
		if (pf == pd)
		{
			if (d == 'u' || d == 'U')
			{
				*pc = p;
				p->next = pf;
			}
			else if (d == 'd' || d == 'D')
			{
				tongxunlu* ph2 = pd->next;
				pf->next = p;
				p->next = ph2;
			}
		}
		else
		{
			if (d == 'u' || d == 'U')
			{
				pf->next = p;
				p->next = pd;
			}
			else if (d == 'd' || d == 'D')
			{
				tongxunlu* ph = pd->next;
				pd->next = p;
				p->next = ph;
			}
		}
	}
	cout << "插入成功" << endl;
}

//7.清空联系人
void cleantongxunlu(tongxunlu** pc)
{
	tongxunlu* p = *pc;
	while (p != NULL)
	{
		tongxunlu* pd = p;
		p = p->next;
		free(pd);
	}
	(*pc) = p;
	cout << "成功清空" << endl;
}

//8.保存
void savetongxunlu(tongxunlu* pc)
{
	FILE* pfwrite = fopen("tongxunlu.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("savetongxunlu");
		return;
	}
	int n = Count(pc);
	for (int i = 0; i < n; i++)
	{
		fwrite(&pc->date, sizeof(xinxi), 1, pfwrite);
		pc = pc->next;
	}
	fclose(pfwrite);
	pfwrite = NULL;
	cout << "保存成功" << endl;
}

//c.清屏
void clean()
{
	cout << "\033c";
}




//其他函数-----------------------------------------------------------------------------------

//菜单
void menu()
{
	cout << "                                   菜      单                                                                  " << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "1.show		2.add		3.del		4.search	5.modify	6.insert		0.exit" << endl;
	cout << "7.clean		8.save		c.清屏" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

//加载文件
void loadtongxunlu(tongxunlu* pc)
{
	FILE* pfread = fopen("tongxunlu.txt", "rb");
	if (pfread == NULL)
	{
		perror("loadtongxunlu");
		return;
	}
	pc = (tongxunlu*)calloc(1, sizeof(tongxunlu));
	pc->next = NULL;
	while (fread(&pc->date, sizeof(xinxi), 1, pfread))
	{
		if (head == NULL)
		{
			head = pc;
		}
		else
		{
			tail->next = pc;
		}
		tail = pc;
		pc = (tongxunlu*)calloc(1, sizeof(tongxunlu));
		pc->next = NULL;
	}
	fclose(pfread);
	pfread = NULL;
}

//销毁通讯录
void destroytongxunlu(tongxunlu* pc)
{
	free(pc);
	pc = NULL;
}






//主函数-----------------------------------------------------------
int main()
{

	loadtongxunlu(head);	//加载文件
	menu();
	char input;
	int flag = 0;
	int flag1 = 1;
	char tem;
	cout << "请选择功能：";
	while (1)
	{
		if (flag)
			cout << endl << "请再次选择功能：";
		cin >> input;
		if (input == '1')//打印
		{
			showtongxunlu(head);
			flag = 1;
		}
		else if (input == '2')//添加
		{
			addtongxunlu(head);
			flag = 1;
		}
		else if (input == '3')//删除
		{
			deltongxunlu(&head);
			flag = 1;
		}
		else if (input == '4')//查找
		{
			searchtongxunlu(head);
			flag = 1;
		}
		else if (input == '5')//修改
		{
			modifytongxunlu(head);
			flag = 1;
		}
		else if (input == '6')//插入
		{
			inserttongxunlu(&head);
			flag = 1;
		}
		else if (input == '7')//清空通讯录
		{
			cleantongxunlu(&head);
			flag = 1;
		}
		else if (input == '8')//保存
		{
			savetongxunlu(head);
			flag = 1;
			flag1 = 0;

		}
		else if (input == 'c')//清屏
		{
			clean();
			menu();
			flag = 1;
		}
		else if (input == '0')
		{
			if (flag1)
			{
				cout << "是否要保存：(y/n)";
				cin >> tem;
				if (tem == 'y' || tem == 'Y')
				{
					savetongxunlu(head);
				}
			}
			cout << "拜拜~" << endl;
			destroytongxunlu(head);
			break;
		}
		else if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
		{
			cout << "他妈的你选的是选项吗，又不是让你做选择题！！" << endl;
			flag = 1;
		}
		else
		{
			cout << "他妈的你好好看清楚，没有这个选项" << endl;
			flag = 1;
		}

	}
	return 0;
}
