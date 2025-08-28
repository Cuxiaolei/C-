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
xin_s* duqu();//���ļ�
void baocun(xin_s* p);//������Ϣ
void liulan(xin_s* p);//�����Ϣ
void xuan2(xin_s* p);
void xuan3(xin_s* p);
void in_xin1();
void charu(xin_s* p);
void shan(xin_s* p);
void QSort(xin_s* p);
int com_par(const void* e1, const void* e2);
void Load(xin_s* p);


//���˵�
void zhucaidan()
{
	printf("-----------------------��ӭ����ѧ���ۺ�����ϵͳ------------------------\n");
	printf("*                      1.ѧ����Ϣ����                                 *\n");
	printf("*                      2.ѧ�����ݴ���                                 *\n");
	printf("*                      3.ѧ���ۺ����ݲ�ѯ                             *\n");
	printf("*                      0.�˳�                                         *\n");
}


//��Ϣ����
void xinxichuli()
{
	printf("ѧ����Ϣ����\n");
	printf("1.����ѧ����Ϣ\n");
	printf("2.����ѧ����Ϣ\n");
	printf("3.ɾ��ѧ����Ϣ\n");
	printf("4.���ѧ����Ϣ\n");
	printf("5.����\n");
	printf("��ѡ��\n");
}




//
void xuan2(xin_s* p)
{
	int choice;
	printf("��������Ӧ�����ѡ�������");
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
	default:printf("��������\n"); break;
	}
}



//���ݴ���
void shujuchuli()
{
	printf("ѧ�����ݴ���");
	printf("1.����ѧ������");
	printf("2.���¼�������");
	printf("3.�޸�ѧ����Ϣ");
	printf("4.ѧ�����ݲ�ѯ");
	printf("5.�������˵�");
}



void xuan3(xin_s* head)
{

}
/*void duqu()//�򿪲���ȡ�ļ�
{
	FILE* file;
	file = fopen("��Ϣ.txt", "a+");
	if (file == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}
}*/


void in_xin1()
{
	/*FILE* file;
	file = fopen("xinxi.txt", "a+");
	if (file == NULL) {
		printf("�ļ���ʧ��\n");
		exit(0);
	}*/
	//file=fopen()


	int n;
	xin_s* q;
	printf("������洢ѧ��������");
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
	//printf("������ѧ����ѧ�ţ��������Ա𣬼�ͥסַ�͵绰����\n");
	//for (int i = 0; i < n; i++)//meixiewan
	//{
	//	p = (xin_s*)malloc(sizeof(xin_s));
	//	scanf("%lld%s%s%s%s", &p->number, p->name, p->sex, p->postsion, p->phone);
	//	q->next = p;
	//	p->next = NULL;
	//	q = p;
	//}
	//temp = (xin_s*)malloc(sizeof(xin_s));
	//for (int j = 1; j < n; j++)				//ð������
	//{
	//	p = head->next;						//ÿ��ð�ݹ�����Ϻ󣬱��뷵�ؽ��1
	//	for (int i = n - 1; i >= j; i--)	//һ��ð�ݹ���
	//	{
	//		if ((p->number) > (p->next->number))	//��С��������
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
	//	printf("����ɹ���");
	//	system("pause");
	//}
}




void charu(xin_s* head)
{
	xin_s* a = (xin_s*)malloc(sizeof(xin_s));
	xin_s* b = (xin_s*)malloc(sizeof(xin_s));
	a = head;
	printf("���������ѧ����ѧ�ţ��������Ա𣬼�ͥסַ�͵绰����\n");
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
	if ((f = fopen("��Ϣ.txt", "r")) == NULL) {                  	                  //�ж�
		printf("\n\tû��ѧ����Ϣ!");
		printf("\n\n\t\t");
		system("pause");
		return;
	}
	else
	{
		printf(" \tѧ��\t\t����\t\t�Ա�\t\t��ͥסַ\t\t��ϵ�绰\n");                     //���ѧ����Ϣ
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
		printf("\nû��ѧ����Ϣ��\n");
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








//���
void liulan(xin_s* p)
{
	if (p == NULL)
	{
		printf("����û����");
		return;
	}

	printf(" \tѧ��\t\t����\t\t�Ա�\t\t��ͥסַ\t\t��ϵ�绰\n");
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
	printf("��������Ҫɾ����ѧ����ѧ��");
	scanf("%lld", &b->data.number);
	d = head;
	if (d->data.number == b->data.number)
	{
		head->next = d->next->next;//��ɾ����һ�����ǿ�����
	}
	else {
		while (d != NULL)
		{
			if (d->next->data.number == b->data.number)
			{
				d->next = d->next->next;//��ɾ����һ�����ǿ��Խ�
			}
		}

	}
	printf(" \tѧ��\t\t����\t\t�Ա�\t\t��ͥסַ\t\t��ϵ�绰\n");
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
//����
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

//����
void baocun(xin_s* p)//������Ϣ����ͷ����
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

	printf("����ɹ�\n");
	fclose(fp);
	fp = NULL;
}

//����
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
		printf("��ѡ���Ӧ��ģʽ��");
		int choice;
		printf("���������ѡ�������");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:system("cls"); exit(0); break;
		case 1:system("cls"); xinxichuli(); xuan2(head); break;
		case 2:system("cls"); shujuchuli(); xuan3(head); break;
		case 3:system("cls"); break;
		case 4:system("cls"); baocun(head); break;
		default: printf("��������!�Զ��˳�!"); exit(0);
		}
	}
	return 0;
}