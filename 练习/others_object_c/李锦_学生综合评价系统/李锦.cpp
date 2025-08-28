#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;


typedef struct Chengji
{
	int chinese, math, english, hu, pinde, teacher, z_ming;
	float average, ceping;
}Chengji;


typedef struct Data
{
	long long number;
	char name[10];
	char sex[10];
	char postsion[50];
	char phone[15];
	Chengji chengji;
}Data;


typedef struct student
{
	Data data;
	struct student* next;
}xin_s;



typedef struct xstudent
{
	long long number;
	char name[100];
	char sex[10];
	char postsion[100];
	char phone[15];

}shu_s;

typedef struct Sort
{
	Data* data;
	int count;
}Sort;



xin_s* head = NULL;
xin_s* tail = NULL;


//shu_s* h = (shu_s*)malloc(sizeof(shu_s));
void zhucaidan();
void xinxichuli();
void shujuchuli();
xin_s* duqu();//打开文件
void baocun(xin_s* p);//保存信息
void liulan(xin_s* p);//浏览信息
void xuan2(xin_s* p);
void xuan3(xin_s* p);
void in_xin1();
void charu(xin_s* p);
void shan(xin_s* p);
void QSort(xin_s* p);
int com_par(const void* e1, const void* e2);
void Load(xin_s* p);


//主菜单
void zhucaidan()
{
	printf("-----------------------欢迎来到学生综合评价系统------------------------\n");
	printf("*                      1.学生信息处理                                 *\n");
	printf("*                      2.学生数据处理                                 *\n");
	printf("*                      3.学生综合数据查询                             *\n");
	printf("*                      0.退出                                         *\n");
}


//信息处理
void xinxichuli()
{
	printf("学生信息处理\n");
	printf("1.输入学生信息\n");
	printf("2.插入学生信息\n");
	printf("3.删除学生信息\n");
	printf("4.浏览学生信息\n");
	printf("5.排序\n");
	printf("请选择：\n");
}




//
void xuan2(xin_s* p)
{
	int choice;
	printf("请输入相应的序号选择操作：");
	scanf("%d", &choice);
	if (choice == 0)
	{
		system("cls");
		zhucaidan();
	}
	switch (choice)
	{
	case 1:system("cls"); in_xin1(); system("cls"); break;
	case 2:system("cls"); charu(p); baocun(p); system("cls"); break;
	case 3:system("cls"); shan(p); baocun(p); system("cls"); break;
	case 4:system("cls"); liulan(p); system("pause"); system("cls"); break;
	case 5:system("cls"); QSort(p); break;
	default:printf("输入有误！\n"); break;
	}
}



//数据处理
void shujuchuli()
{
	printf("学生数据处理");
	printf("1.输入学生数据");
	printf("2.重新计算排名");
	printf("3.修改学生信息");
	printf("4.学生数据查询");
	printf("5.返回主菜单");
}



void xuan3(xin_s* head)
{

}
/*void duqu()//打开并读取文件
{
	FILE* file;
	file = fopen("信息.txt", "a+");
	if (file == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}
}*/


void in_xin1()
{
	/*FILE* file;
	file = fopen("xinxi.txt", "a+");
	if (file == NULL) {
		printf("文件打开失败\n");
		exit(0);
	}*/
	//file=fopen()


	int n;
	xin_s* q;
	printf("请输入存储学生的数量");
	scanf("%d", &n);
	if (n == 0)
	{
		exit(0);
	}

	for (int i = 0; i < n; i++)
	{
		q = (xin_s*)malloc(sizeof(xin_s));
		q->next = NULL;

		scanf("%lld%s%s%s%s", &q->data.number, q->data.name, q->data.sex, q->data.postsion, q->data.phone);
		if (head == NULL)
		{
			head = q;
		}
		else
		{
			tail->next = q;
		}
		tail = q;
	}



	//q = head;
	//printf("请输入学生的学号，姓名，性别，家庭住址和电话号码\n");
	//for (int i = 0; i < n; i++)//meixiewan
	//{
	//	p = (xin_s*)malloc(sizeof(xin_s));
	//	scanf("%lld%s%s%s%s", &p->number, p->name, p->sex, p->postsion, p->phone);
	//	q->next = p;
	//	p->next = NULL;
	//	q = p;
	//}
	//temp = (xin_s*)malloc(sizeof(xin_s));
	//for (int j = 1; j < n; j++)				//冒泡排序
	//{
	//	p = head->next;						//每次冒泡过程完毕后，必须返回结点1
	//	for (int i = n - 1; i >= j; i--)	//一次冒泡过程
	//	{
	//		if ((p->number) > (p->next->number))	//从小到大排序
	//		{
	//			temp = p->next;
	//			p->next = p->next->next;
	//			p->next->next = temp;
	//		}
	//		p = p->next;
	//	}
	//	c = head;
	//	while (c != NULL)
	//	{
	//		fprintf(file, "\t%lld\t \t%s\t \t%s\t \t%s\t \t%s\t", c->number, c->name, c->sex, c->postsion, c->phone);
	//		c = c->next;
	//	}
	//	fclose(file);
	//	printf("输入成功！");
	//	system("pause");
	//}
}




void charu(xin_s* head)
{
	xin_s* a = (xin_s*)malloc(sizeof(xin_s));
	xin_s* b = (xin_s*)malloc(sizeof(xin_s));
	a = head;
	printf("请输入插入学生的学号，姓名，性别，家庭住址和电话号码\n");
	scanf("%lld%s%s%s%s", &b->data.number, b->data.name, b->data.sex, b->data.postsion, b->data.phone);
	while (a != NULL)
	{
		if ((b->data.number) > (a->next->data.number) && (b->data.number) < (a->next->next->data.number))
		{
			b->next = NULL;
			b->next = a->next->next;
			a->next = b;
			break;
		}
		a = a->next;
	}
	while (a != NULL)
	{
		printf("\t%lld\t \t%s\t \t%s\t \t%s\t \t\t%s\t\r\n", a->data.number, a->data.name, a->data.sex, a->data.postsion, a->data.phone);
		a = a->next;
	}
}
/*void liulan(xin_s* head)
{
	FILE* f;
	char shu[1000];
	if ((f = fopen("信息.txt", "r")) == NULL) {                  	                  //判断
		printf("\n\t没有学生信息!");
		printf("\n\n\t\t");
		system("pause");
		return;
	}
	else
	{
		printf(" \t学号\t\t姓名\t\t性别\t\t家庭住址\t\t联系电话\n");                     //输出学生信息
		while (fgets(shu, 100, f))
		{
			printf("%s", shu);
		}
	}
	printf("\n\n\t\t");
	system("pause");
}*/
xin_s* duqu()
{
	FILE* fp;
	xin_s* c, * c1, * c2 = NULL;
	c = (xin_s*)malloc(sizeof(xin_s));
	c1 = (xin_s*)malloc(sizeof(xin_s));
	if ((fp = fopen("xinxi.txt", "r+")) == NULL)
	{
		printf("\n没有学生信息！\n");
		system("pause");
		return c2;
		exit(0);
	}
	else
	{
		//	fscanf(fp, "\t%lld\t \t%s\t \t%s\t \t%s\t \t%s\t", &c->number, c->name, c->sex, c->postsion, c->phone);
		head = c;
		while (!feof(fp))
		{
			fscanf(fp, "\t%lld\t \t%s\t \t%s\t \t%s\t \t%s\t", &c->data.number, c->data.name, c->data.sex, c->data.postsion, c->data.phone);
			c = c->next;
		}
	}
	fclose(fp);
	return head;
}








//浏览
void liulan(xin_s* p)
{
	if (p == NULL)
	{
		printf("链表还没数据");
		return;
	}

	printf(" \t学号\t\t姓名\t\t性别\t\t家庭住址\t\t联系电话\n");
	while (p != NULL)
	{
		printf("\t%lld\t \t%s\t \t%s\t \t%s\t \t\t%s\t\r\n", p->data.number, p->data.name, p->data.sex, p->data.postsion, p->data.phone);
		p = p->next;
	}

}


void shan(xin_s* head)
{
	xin_s* b, * d;
	b = (xin_s*)malloc(sizeof(xin_s));
	d = (xin_s*)malloc(sizeof(xin_s));
	printf("请输入需要删除的学生的学号");
	scanf("%lld", &b->data.number);
	d = head;
	if (d->data.number == b->data.number)
	{
		head->next = d->next->next;//被删的下一个还是可以连
	}
	else {
		while (d != NULL)
		{
			if (d->next->data.number == b->data.number)
			{
				d->next = d->next->next;//被删的下一个还是可以接
			}
		}

	}
	printf(" \t学号\t\t姓名\t\t性别\t\t家庭住址\t\t联系电话\n");
	while (d != NULL)
	{
		printf("\t%lld\t \t%s\t \t%s\t \t%s\t \t\t%s\t\r\n", d->data.number, d->data.name, d->data.sex, d->data.postsion, d->data.phone);
		if (d->next != NULL)
			d = d->next;
	}
}

int com_par(const void* e1, const void* e2)
{
	return (int)(((Data*)e1)->number - ((Data*)e2)->number);
}
//排序
void QSort(xin_s* p)
{
	xin_s* p1 = p;
	xin_s* p2 = p;
	Sort s = { 0 };
	s.count = 0;
	while (p1 != NULL)
	{
		s.data = (Data*)realloc(s.data, (s.count + 1) * sizeof(Data));
		s.data[s.count] = p1->data;
		s.count++;
		p1 = p1->next;
	}
	qsort(s.data, s.count, sizeof(Data), com_par);

	int i = 0;
	while (p2 != NULL)
	{
		p2->data = s.data[i];
		p2 = p2->next;
		i++;
	}
}

//保存
void baocun(xin_s* p)//保存信息，从头保存
{
	FILE* fp;
	fp = fopen("xinxi.txt", "wb");
	if (fp == NULL)
	{
		perror("baocun");
		return;
	}

	while (p != NULL)
	{
		fwrite(&p->data, sizeof(Data), 1, fp);
		p = p->next;
	}

	printf("保存成功\n");
	fclose(fp);
	fp = NULL;
}

//加载
void Load()
{
	FILE* pread = fopen("xinxi.txt", "rb");
	if (pread == NULL)
	{
		perror("Load");
		return;
	}

	xin_s* p;
	p = (xin_s*)malloc(sizeof(xin_s));
	while (fread(&p->data, sizeof(Data), 1, pread))
	{
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;

		p = (xin_s*)calloc(1, sizeof(xin_s));
	}
	free(p);

	fclose(pread);
	pread = NULL;

}



int main()
{
	Load();
	system("pause");

	while (1)
	{
		zhucaidan();
		printf("请选择对应的模式：");
		int choice;
		printf("请输入序号选择操作：");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:system("cls"); exit(0); break;
		case 1:system("cls"); xinxichuli(); xuan2(head); break;
		case 2:system("cls"); shujuchuli(); xuan3(head); break;
		case 3:system("cls"); break;
		case 4:system("cls"); baocun(head); break;
		default: printf("输入有误!自动退出!"); exit(0);
		}
	}
	return 0;
}