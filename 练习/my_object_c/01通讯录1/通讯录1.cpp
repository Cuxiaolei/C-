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

//�˵���Ϣ
struct xinxi
{
	char name[max_name];
	int age;
	char sex[max_sex];
	char tele[max_tele];
	char addr[max_addr];
};

//ͨѶ¼
//��̬
//struct tongxunlu
//{
//	struct xinxi date[people];	//��ǰͨѶ¼����Ϣ
//	int count;					//��¼��ǰͨѶ¼������
//};

//��̬ͨѶ¼
struct tongxunlu
{
	struct xinxi* date;		//�����Ϣ
	int count;				//��¼��ǰ����
	int capacity;			//��ǰͨѶ¼������
};

//�������
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
			cout << endl << "�ռ䲻�������ݳɹ�" << endl;
		}
	}
}

//����ͨѶ¼
void Loadtongxunlu(struct tongxunlu* pc)
{
	FILE* pfread = fopen("tongxunlu.txt", "rb");
	if (pfread == NULL)
	{
		perror("Loadtongxunlu");
		return;
	}
	//���ļ�
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

//��̬��ʼ��
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

	//�����ļ�����Ϣ��ͨѶ¼��
	Loadtongxunlu(pc);
	return 0;
}

//����ͨѶ¼
void Destorytongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
}

//��̬��ʼ��
//void chushihua(struct tongxunlu* pc)
//{
//	assert(pc);
//	pc->count = 0; 
//	memset(pc->date, 0, sizeof(pc->date));
//}		

//���Һ���
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

//�ȽϺ���
int cmp_xinxi_by_name(const void* e1, const void* e2)
{
	return strcmp(((xinxi*)e1)->name, ((xinxi*)e2)->name);
}

//1.��ӡͨѶ¼
void show(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "�����û�����Ѱ�" << endl;
		return;
	}
	int i;
	cout << setw(20) << left << "����"
		<< setw(10) << left << "����"
		<< setw(10) << left << "�Ա�"
		<< setw(15) << left << "�绰"
		<< setw(20) << left << "��ַ"
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

//2.�����ϵ�ˣ���̬�汾��
//void Addtongxunlu(struct tongxunlu* pc)
//{
//	
//	assert(pc);		//����
//	if (pc->count == max_name)	//�ж�
//	{
//		cout << "���ͨѶ¼�Ѿ�����Ŷ" << endl;
//		return;
//	}
//	cout << "���������֣�";
//	cin >> pc->date[pc->count].name;
//	cout << "���������䣺";
//	cin >> pc->date[pc->count].age;
//	cout << "�������Ա�";
//	cin >> pc->date[pc->count].sex;
//	cout << "������绰��";
//	cin >> pc->date[pc->count].tele;
//	cout << "�������ַ��";
//	cin >> pc->date[pc->count].addr;
//	pc->count++;
//	cout << "��ӳɹ�" << endl;
//}

//2.�����ϵ�ˣ���̬�汾��
void Addtongxunlu(struct tongxunlu* pc)
{
	assert(pc);		//����
	zengrong(pc);
	cout << "���������֣�";
	cin >> pc->date[pc->count].name;
	cout << "���������䣺";
	cin >> pc->date[pc->count].age;
	cout << "�������Ա�";
	cin >> pc->date[pc->count].sex;
	cout << "������绰��";
	cin >> pc->date[pc->count].tele;
	cout << "�������ַ��";
	cin >> pc->date[pc->count].addr;
	pc->count++;
	cout << endl << "��ӳɹ�" << endl;
}

//3.ɾ����ϵ��
void deltongxunlu(struct tongxunlu* pc)
{
	assert(pc);	//����
	cout << "������ĸ��һ�ɾ�ˣ�";
	char name[max_name];
	cin >> name;
	if (pc->count == 0)	//�ж�ͨѶ¼�Ƿ�Ϊ�գ�
	{
		cout << "��Ӧ��û�����Ѱ�" << endl;
		return;
	}
	//����	
	int a = findlianxiren(pc, name);	//�ҵ��Ļ������±꣬�Ҳ�������-1��
	if (a == -1)
	{
		cout << "���޴���" << endl;
		return;
	}
	for (int i = a; i < pc->count - 1; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->count--;
	cout << endl << "ɾ���ɹ�" << endl;

}

//4.������ϵ��
void searchtongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "������Ҫ�����˵����֣�";
	char name[max_name];
	cin >> name;
	int a = findlianxiren(pc, name);
	if (a == -1)
	{
		cout << "���޴���" << endl;
		return;
	}
	cout << setw(10) << left << "����"
		<< setw(10) << left << "����"
		<< setw(10) << left << "�Ա�"
		<< setw(15) << left << "�绰"
		<< setw(10) << left << "��ַ"
		<< endl;
	cout << setw(10) << left << pc->date[a].name
		<< setw(10) << left << pc->date[a].age
		<< setw(10) << left << pc->date[a].sex
		<< setw(15) << left << pc->date[a].tele
		<< setw(10) << left << pc->date[a].addr << endl;
}

//5.�޸�
void xiugaitongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "������Ҫ�޸��˵����֣�";
	char name[max_name];
	cin >> name;
	int a = findlianxiren(pc, name);
	if (a == -1)
	{
		cout << "���޴���" << endl;
		return;
	}
	cout << "���޸�";
	pc->date[a] = { 0 };
	cout << "���������֣�";
	cin >> pc->date[a].name;
	cout << "���������䣺";
	cin >> pc->date[a].age;
	cout << "�������Ա�";
	cin >> pc->date[a].sex;
	cout << "������绰��";
	cin >> pc->date[a].tele;
	cout << "�������ַ��";
	cin >> pc->date[a].addr;
	cout << endl << "�޸ĳɹ�" << endl;
}

//6.����
void sorttongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	qsort(pc->date, pc->count, sizeof(xinxi), cmp_xinxi_by_name);	//qsort(�׵�ַ�����򳤶ȣ�ÿ��Ԫ�ص��ֽڣ��ȽϺ�����
	cout << endl << "����ɹ�" << endl;
}

//8.���ͨѶ¼
void Clean(struct tongxunlu* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = { 0 };
	cout << endl << "����ɹ�" << endl;
}

//����
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
	cout << "����ɹ���" << endl;
	fclose(pfwrite);
	pfwrite = NULL;
}

//�˵�
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

//ö��
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
	struct tongxunlu txl;	//����ͨѶ¼��
	chushihua(&txl);		//��ʼ��ͨѶ¼
	menu();
	do
	{
		cout << "��ѡ��:";
		cin >> input;
		switch (input)
		{
		case SHOW:
			show(&txl);	//��ӡ
			break;

		case ADD:
			Addtongxunlu(&txl);	//���
			break;

		case DEL:
			deltongxunlu(&txl);	//ɾ��
			break;

		case SEARCH:
			searchtongxunlu(&txl);	//����
			break;

		case MODIFY:
			xiugaitongxunlu(&txl);	//�޸�
			break;

		case SORT:
			sorttongxunlu(&txl);	//����
			break;

		case SAVE:
			savetongxunlu(&txl);
			break;
		case CLEAN:
			Clean(&txl);
			break;
		case EXIT:
			Destorytongxunlu(&txl);
			cout << "�õİݰ�~" << endl;
			break;

		default:
			cout << "�����û���ѡ�" << endl;
			break;
		}
	} while (input);

	return 0;
}