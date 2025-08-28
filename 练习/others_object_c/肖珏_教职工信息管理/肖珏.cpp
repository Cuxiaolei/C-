#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{
	int teacher_number;
	char name[20];
	char gender[10];
	char zhicheng[20];
	char class_name[20];
	char class1[20];
	int class_number;
	int time_lilun;
	int time_shiyan;
	double zong;
}Data;


typedef struct teacher {
	Data data;
	struct teacher* next;
} tea; //定义结构体



tea* head = NULL;
tea* tail = NULL;



//函数声明；
void caidan();
void input();
void find();
//tea* head();
tea* zhizhen(int teacher_number, char name[20], char gender[10], char zhicheng[20], char class_name[20],
	char class1[20],
	int class_number, int time_lilun, int time_shiyan, double zong);
void charu(tea* head, int teacher_number, char name[20], char gender[10], char zhicheng[20], char class_name[20],
	char class1[20],
	int class_number, int time_lilun, int time_shiyan, double zong);
tea* lianbiao();
void shuchu();
void change();
void dele();
void Save();

//创造头指针
//tea* head() {
//	tea* head = (tea*)malloc(sizeof(tea));
//	head->next = NULL;
//	return head;
//}

//写入指针
tea* zhizhen(int teacher_number, char name[20], char gender[10], char zhicheng[20], char class_name[20], char class1[20], int class_number, int time_lilun, int time_shiyan, double zong) {
	tea* zhizhen = (tea*)malloc(sizeof(tea));
	zhizhen->data.teacher_number = teacher_number;
	strcpy(zhizhen->data.name, name);
	strcpy(zhizhen->data.gender, gender);
	strcpy(zhizhen->data.zhicheng, zhicheng);
	strcpy(zhizhen->data.class_name, class_name);
	strcpy(zhizhen->data.class1, class1);
	zhizhen->data.class_number = class_number;
	zhizhen->data.time_lilun = time_lilun;
	zhizhen->data.time_shiyan = time_shiyan;
	zhizhen->data.zong = zong;
	return zhizhen;
}

//插入指针
void charu(tea* head, int teacher_number, char name[20], char gender[10], char zhicheng[20], char class_name[20], char class1[20], int class_number, int time_lilun, int time_shiyan, double zong) {
	tea* charu = zhizhen(teacher_number, name, gender, zhicheng, class_name,
		class1, class_number, time_lilun, time_shiyan, zong);
	charu->next = head->next;
	head->next = charu;
}



void caidan() {
	printf("###################################################\n");
	printf("#             教师信息主菜单                      #\n");
	printf("#             1. 增加教师授课教学信息             #\n");
	printf("#             2. 修改教师授课教学信息             #\n");
	printf("#             3. 删除教师授课教学信息             #\n");
	printf("#             4. 查询教师授课教学信息             #\n");
	printf("#             5. 输出所有教师信息                 #\n");
	printf("#             6. 保存                             #\n");
	printf("#             0. 退出                             #\n");
	printf("###################################################\n");
	printf("#             请选择操作：                        #\n");
}


void gongneng() {
	int choice;
	do {
		caidan();
		scanf("%d", &choice);
		switch (choice) {
		case 1://增加教师授课教学信息
			input();
			break;
		case 2://修改教师授课教学信息
			change();
			break;
		case 3://删除教师授课教学信息
			dele();
			break;
		case 4://查询教师授课教学信息
			find();
			break;
		case 5://输出所有教师信息
			shuchu();
			break;
		case 6:
			Save();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("无效的选择\n");
		}
	} while (choice != 0);

}

void input() {
	//FILE* fp;
	//int n;
	//printf("请输入需录入系统的教师的人数：");
	//scanf("%d", &n);
	tea* p;
	p = (tea*)calloc(1, sizeof(tea));
	p->next = NULL;
	printf("请输入教师号：");
	scanf("%d", &p->data.teacher_number);
	//getchar();
	printf("请输入姓名：");
	scanf("%s", p->data.name);
	printf("请输入性别：");
	scanf("%s", p->data.gender);
	printf("请输入职称：");
	scanf("%s", p->data.zhicheng);
	printf("请输入任教课程：");
	scanf("%s", p->data.class_name);
	printf("请输入班级：");
	scanf("%s", p->data.class1);
	printf("请输入班级数目：");
	scanf("%d", &p->data.class_number);
	printf("请输入理论课时：");
	scanf("%d", &p->data.time_lilun);
	printf("请输入实验课时：");
	scanf("%d", &p->data.time_shiyan);
	p->data.zong = (p->data.time_lilun + p->data.time_shiyan) * p->data.class_number;

	if (head == NULL)
	{
		head = p;
	}
	else
	{
		tail->next = p;
	}
	tail = p;





	//for (p = head; p; p = p->next) {
	//	fwrite(&p, sizeof(tea), 1, fp);
	//}
	printf("录入成功！\n");
	///*free(p);
	//if (fclose(fp)) {
	//	printf("不能关闭文件！");
	//	exit(0);
	//}*/
	return;
}

//将文件编成链表
tea* lianbiao() {
	FILE* fp = fopen("jiaoshi", "rb");
	tea* p;
	if ((fp = fopen("jiaoshi", "rb")) == NULL) {
		printf("不能打开文件！");
		exit(0);
	}
	//tea* head1 = head();
	while (1) {
		fread(&p, sizeof(tea), 1, fp);
		charu(head, p->data.teacher_number, p->data.name, p->data.gender, p->data.zhicheng, p->data.class_name,
			p->data.class1, p->data.class_number, p->data.time_lilun, p->data.time_shiyan, p->data.zong);
		if (feof(fp)) {
			break;
		}
	}
	fclose(fp);
	return head;
}

tea* enhance() {
	FILE* fp = fopen("jiaoshi", "ab");
	tea* head, * p, * pt;
	p = (tea*)malloc(sizeof(tea));
	int n;
	head = lianbiao();
	p = head->next;
	if ((fp = fopen("jiaoshi", "ab")) == NULL) {
		printf("不能打开文件！");
		exit(0);
	}
	do {

		while (p->next != NULL)
			p = p->next;
		p = (tea*)malloc(sizeof(tea));
		printf("\n请输入教师号：");
		scanf("%d", &p->data.teacher_number);
		printf("请输入姓名：");
		scanf("%s", p->data.name);
		printf("请输入性别：");
		scanf("%s", p->data.gender);
		printf("请输入职称：");
		scanf("%s", p->data.zhicheng);
		printf("请输入任教课程：");
		scanf("%s", p->data.class_name);
		printf("请输入班级：");
		scanf("%s", p->data.class1);
		printf("请输入班级数目：");
		scanf("%d", &p->data.class_number);
		printf("请输入理论课时：");
		scanf("%d", &p->data.time_lilun);
		printf("请输入实验课时：");
		scanf("%d", &p->data.time_shiyan);
		pt = p;
		pt->next = p;
		p->next = NULL;
		fwrite(&p, sizeof(tea), 1, fp);
		printf("录入成功！\n");
		free(p);
		if (fclose(fp)) {
			printf("不能关闭文件！");
			exit(0);
		}
		printf("1.继续录入/2.退出录入");
		scanf("%d", &n);
	} while (n == 1);
	return head;
}

void find() {
	int a;

	printf("请输入要查询教师的教师号：");
	scanf("%d", &a);

	tea* p = head;
	for (p = head; p; p = p->next) {
		if (p->data.teacher_number == a)
			break;
	}
	if (p == NULL)
	{
		printf("未查询到该数据！\n");
		return;
	}
	else {
		printf("%-8s%-8s%-8s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "教师号", "姓名", "性别", "职称", "任教课程", "班级",
			"班级数目", "理论课时", "实验课时", "总课时");
		printf("%-8d%-8s%-8s%-10s%-10s%-10s%-10d%-10d%-10d%-10.2lf\n", p->data.teacher_number, p->data.name, p->data.gender, p->data.zhicheng,
			p->data.class_name, p->data.class1, p->data.class_number, p->data.time_lilun, p->data.time_shiyan, p->data.zong);
	}
	return;
}

//删除
void dele() {
	int n;

	printf("请输入要删除教师的教师号：");
	scanf("%d", &n);
	tea* pf = head;
	tea* pd = head;

	while (pd != NULL && pd->data.teacher_number != n)
	{
		pf = pd;
		pd = pd->next;
	}
	if (pd == NULL)
	{
		printf("没找到\n");
		return;
	}
	else
	{
		if (pf == pd)
		{
			head = head->next;
			free(pf);
		}
		else
		{
			pf->next = pd->next;
			free(pd);
		}
	}
	return;
}

//输出
void shuchu() {
	tea* p;
	p = head;
	printf("%-8s%-8s%-8s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "教师号", "姓名", "性别", "职称", "任教课程", "班级",
		"班级数目", "理论课时", "实验课时", "总课时");
	/*for (p = head; p; p = p->next) {
		printf("%-8d%-8s%-8s%-10s%-10s%-10s%-10d%-10d%-10d%-10.2lf\n", p->teacher_number, p->name, p->gender, p->zhicheng,
			p->class_name, p->class1, p->class_number, p->time_lilun, p->time_shiyan, p->zong);
	}*/

	while (p != NULL)
	{
		printf("%-8d%-8s%-8s%-10s%-10s%-10s%-10d%-10d%-10d%-10.2lf\n", p->data.teacher_number, p->data.name, p->data.gender, p->data.zhicheng,
			p->data.class_name, p->data.class1, p->data.class_number, p->data.time_lilun, p->data.time_shiyan, p->data.zong);
		p = p->next;
	}
}

//修改
void change() {
	int n;
	printf("请输入要修改教师的教师号：");
	scanf("%d", &n);
	tea* p;
	for (p = head; p; p = p->next)
	{
		if (p->data.teacher_number == n)
			break;
	}
	if (p->data.teacher_number == n)
	{
		int a;
		int b;
		char s[20];
		printf("请输入要修改的部分选项：1.班级，2.班级数目，3.理论课时，4.实验课时");
		scanf("%d", &a);
		printf("请输入修改内容");
		if (a == 1) {
			scanf("%s", s);
			strcpy(p->data.class1, s);
		}
		else {
			scanf("%d", &b);
			if (a == 2)
			{
				p->data.class_number = b;
				printf("修改成功\n");
			}
			else if (a == 3)
			{
				p->data.time_lilun = b;
				printf("修改成功\n");
			}
			else if (a == 4)
			{
				p->data.time_shiyan = b;
				printf("修改成功\n");
			}
			else
				printf("输入无效");

		}
	}
	else if (p == NULL)
	{
		printf("没有找到！\n");
		return;
	}
	return;
}

//保存
void Save()
{
	FILE* pwrite = fopen("23408000420_肖珏_计算机类2304_教师工作量管理系统.txt", "wb");
	if (pwrite == NULL)
	{
		perror("Save");
		return;
	}
	tea* p = head;

	while (p != NULL)
	{
		fwrite(&p->data, sizeof(Data), 1, pwrite);
		p = p->next;
	}


	printf("保存成功\n");
	fclose(pwrite);
	pwrite = NULL;

}

//加载
void Load()
{
	FILE* fp;
	if ((fp = fopen("23408000420_肖珏_计算机类2304_教师工作量管理系统.txt", "rb")) == NULL) {
		printf("不能打开文件！");
		exit(0);
	}
	tea* p = (tea*)malloc(sizeof(tea));

	while (fread(&p->data, sizeof(Data), 1, fp) != 0)
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
		p = (tea*)calloc(1, sizeof(tea));
	}
	fclose(fp);
	fp = NULL;
}


int main(void) {
	Load();
	gongneng();
	return 0;
}

