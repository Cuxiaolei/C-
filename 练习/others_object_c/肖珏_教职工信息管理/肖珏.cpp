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
} tea; //����ṹ��



tea* head = NULL;
tea* tail = NULL;



//����������
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

//����ͷָ��
//tea* head() {
//	tea* head = (tea*)malloc(sizeof(tea));
//	head->next = NULL;
//	return head;
//}

//д��ָ��
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

//����ָ��
void charu(tea* head, int teacher_number, char name[20], char gender[10], char zhicheng[20], char class_name[20], char class1[20], int class_number, int time_lilun, int time_shiyan, double zong) {
	tea* charu = zhizhen(teacher_number, name, gender, zhicheng, class_name,
		class1, class_number, time_lilun, time_shiyan, zong);
	charu->next = head->next;
	head->next = charu;
}



void caidan() {
	printf("###################################################\n");
	printf("#             ��ʦ��Ϣ���˵�                      #\n");
	printf("#             1. ���ӽ�ʦ�ڿν�ѧ��Ϣ             #\n");
	printf("#             2. �޸Ľ�ʦ�ڿν�ѧ��Ϣ             #\n");
	printf("#             3. ɾ����ʦ�ڿν�ѧ��Ϣ             #\n");
	printf("#             4. ��ѯ��ʦ�ڿν�ѧ��Ϣ             #\n");
	printf("#             5. ������н�ʦ��Ϣ                 #\n");
	printf("#             6. ����                             #\n");
	printf("#             0. �˳�                             #\n");
	printf("###################################################\n");
	printf("#             ��ѡ�������                        #\n");
}


void gongneng() {
	int choice;
	do {
		caidan();
		scanf("%d", &choice);
		switch (choice) {
		case 1://���ӽ�ʦ�ڿν�ѧ��Ϣ
			input();
			break;
		case 2://�޸Ľ�ʦ�ڿν�ѧ��Ϣ
			change();
			break;
		case 3://ɾ����ʦ�ڿν�ѧ��Ϣ
			dele();
			break;
		case 4://��ѯ��ʦ�ڿν�ѧ��Ϣ
			find();
			break;
		case 5://������н�ʦ��Ϣ
			shuchu();
			break;
		case 6:
			Save();
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("��Ч��ѡ��\n");
		}
	} while (choice != 0);

}

void input() {
	//FILE* fp;
	//int n;
	//printf("��������¼��ϵͳ�Ľ�ʦ��������");
	//scanf("%d", &n);
	tea* p;
	p = (tea*)calloc(1, sizeof(tea));
	p->next = NULL;
	printf("�������ʦ�ţ�");
	scanf("%d", &p->data.teacher_number);
	//getchar();
	printf("������������");
	scanf("%s", p->data.name);
	printf("�������Ա�");
	scanf("%s", p->data.gender);
	printf("������ְ�ƣ�");
	scanf("%s", p->data.zhicheng);
	printf("�������ν̿γ̣�");
	scanf("%s", p->data.class_name);
	printf("������༶��");
	scanf("%s", p->data.class1);
	printf("������༶��Ŀ��");
	scanf("%d", &p->data.class_number);
	printf("���������ۿ�ʱ��");
	scanf("%d", &p->data.time_lilun);
	printf("������ʵ���ʱ��");
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
	printf("¼��ɹ���\n");
	///*free(p);
	//if (fclose(fp)) {
	//	printf("���ܹر��ļ���");
	//	exit(0);
	//}*/
	return;
}

//���ļ��������
tea* lianbiao() {
	FILE* fp = fopen("jiaoshi", "rb");
	tea* p;
	if ((fp = fopen("jiaoshi", "rb")) == NULL) {
		printf("���ܴ��ļ���");
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
		printf("���ܴ��ļ���");
		exit(0);
	}
	do {

		while (p->next != NULL)
			p = p->next;
		p = (tea*)malloc(sizeof(tea));
		printf("\n�������ʦ�ţ�");
		scanf("%d", &p->data.teacher_number);
		printf("������������");
		scanf("%s", p->data.name);
		printf("�������Ա�");
		scanf("%s", p->data.gender);
		printf("������ְ�ƣ�");
		scanf("%s", p->data.zhicheng);
		printf("�������ν̿γ̣�");
		scanf("%s", p->data.class_name);
		printf("������༶��");
		scanf("%s", p->data.class1);
		printf("������༶��Ŀ��");
		scanf("%d", &p->data.class_number);
		printf("���������ۿ�ʱ��");
		scanf("%d", &p->data.time_lilun);
		printf("������ʵ���ʱ��");
		scanf("%d", &p->data.time_shiyan);
		pt = p;
		pt->next = p;
		p->next = NULL;
		fwrite(&p, sizeof(tea), 1, fp);
		printf("¼��ɹ���\n");
		free(p);
		if (fclose(fp)) {
			printf("���ܹر��ļ���");
			exit(0);
		}
		printf("1.����¼��/2.�˳�¼��");
		scanf("%d", &n);
	} while (n == 1);
	return head;
}

void find() {
	int a;

	printf("������Ҫ��ѯ��ʦ�Ľ�ʦ�ţ�");
	scanf("%d", &a);

	tea* p = head;
	for (p = head; p; p = p->next) {
		if (p->data.teacher_number == a)
			break;
	}
	if (p == NULL)
	{
		printf("δ��ѯ�������ݣ�\n");
		return;
	}
	else {
		printf("%-8s%-8s%-8s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "��ʦ��", "����", "�Ա�", "ְ��", "�ν̿γ�", "�༶",
			"�༶��Ŀ", "���ۿ�ʱ", "ʵ���ʱ", "�ܿ�ʱ");
		printf("%-8d%-8s%-8s%-10s%-10s%-10s%-10d%-10d%-10d%-10.2lf\n", p->data.teacher_number, p->data.name, p->data.gender, p->data.zhicheng,
			p->data.class_name, p->data.class1, p->data.class_number, p->data.time_lilun, p->data.time_shiyan, p->data.zong);
	}
	return;
}

//ɾ��
void dele() {
	int n;

	printf("������Ҫɾ����ʦ�Ľ�ʦ�ţ�");
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
		printf("û�ҵ�\n");
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

//���
void shuchu() {
	tea* p;
	p = head;
	printf("%-8s%-8s%-8s%-10s%-10s%-10s%-10s%-10s%-10s%-10s\n", "��ʦ��", "����", "�Ա�", "ְ��", "�ν̿γ�", "�༶",
		"�༶��Ŀ", "���ۿ�ʱ", "ʵ���ʱ", "�ܿ�ʱ");
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

//�޸�
void change() {
	int n;
	printf("������Ҫ�޸Ľ�ʦ�Ľ�ʦ�ţ�");
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
		printf("������Ҫ�޸ĵĲ���ѡ�1.�༶��2.�༶��Ŀ��3.���ۿ�ʱ��4.ʵ���ʱ");
		scanf("%d", &a);
		printf("�������޸�����");
		if (a == 1) {
			scanf("%s", s);
			strcpy(p->data.class1, s);
		}
		else {
			scanf("%d", &b);
			if (a == 2)
			{
				p->data.class_number = b;
				printf("�޸ĳɹ�\n");
			}
			else if (a == 3)
			{
				p->data.time_lilun = b;
				printf("�޸ĳɹ�\n");
			}
			else if (a == 4)
			{
				p->data.time_shiyan = b;
				printf("�޸ĳɹ�\n");
			}
			else
				printf("������Ч");

		}
	}
	else if (p == NULL)
	{
		printf("û���ҵ���\n");
		return;
	}
	return;
}

//����
void Save()
{
	FILE* pwrite = fopen("23408000420_Ф��_�������2304_��ʦ����������ϵͳ.txt", "wb");
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


	printf("����ɹ�\n");
	fclose(pwrite);
	pwrite = NULL;

}

//����
void Load()
{
	FILE* fp;
	if ((fp = fopen("23408000420_Ф��_�������2304_��ʦ����������ϵͳ.txt", "rb")) == NULL) {
		printf("���ܴ��ļ���");
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

