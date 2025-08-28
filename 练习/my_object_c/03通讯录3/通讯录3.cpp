#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define NAME 20
#define TELE 20
#define Count 3		//��ʼ�ռ�
#define Capacity 3  //ÿ�����ӵĿռ�
#define AGE 20
//#define
//#define
//#define
using namespace std;

//��Ϣ�ṹ��
struct xinxi
{
	char name[NAME];
	char age[AGE];
	char tele[TELE];

};

//ͨѶ¼
struct tongxunlu
{
	struct xinxi* date;
	int count;		//��ǰ����
	int capacity;	//��ǰ����
};

//�ж�+���ݣ�����ʾ�棩
void CheckIncrease1(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->capacity == pc->count)
	{
		struct xinxi* p = (struct xinxi*)realloc(pc->date, (pc->capacity + Capacity) * sizeof(struct xinxi));
		if (p == NULL)
		{
			cout << "����ʧ��" << endl;
			perror("CheckIncrease");
			return;
		}
		pc->date = p;
		pc->capacity += Capacity;
	}
}

//����ͨѶ¼��Ϣ
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

//��ʼ��
void Init(struct tongxunlu* pc)
{
	assert(pc);
	pc->count = 0;
	pc->date = (struct xinxi*)calloc(Count, sizeof(struct xinxi));
	pc->capacity = Count;
	//����ͨѶ¼��Ϣ
	Loadtongxunlu(pc);
}






//��������------------------------------------------------------

//�ж�+����
void CheckIncrease(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->capacity == pc->count)
	{
		struct xinxi* p = (struct xinxi*)realloc(pc->date, (pc->capacity + Capacity) * sizeof(struct xinxi));
		if (p == NULL)
		{
			cout << "����ʧ��" << endl;
			perror("CheckIncrease");
			return;
		}
		pc->date = p;
		pc->capacity += Capacity;
		cout << "�ռ䲻�㣬���ݳɹ�" << endl;
	}
}

//������ϵ�ˣ������±�,�Ҳ�������-1��
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

//������
int cmp_xinxi(const void* e1, const void* e2)
{
	return strcmp(((struct xinxi*)e1)->name, ((struct xinxi*)e2)->name);
}






//���ܺ���-------------------------------------------------------------

//1.��ӡͨѶ¼
void Show(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "�㻹û�����Ѱɣ���Ц��" << endl;
		return;
	}
	else
	{
		cout << endl;
		cout << setw(20) << left << "����";
		cout << setw(20) << left << "����";
		cout << setw(20) << left << "�绰";
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

//2.�����ϵ��
void Addtongxunlu(struct tongxunlu* pc)
{
	assert(pc);		//����
	if (pc == NULL)
	{
		perror("Addtongxunlu");
		return;
	}
	CheckIncrease(pc);
	cout << "��������Ҫ��ӵ���ϵ�˵���Ϣ��" << endl;
	cout << "��������ϵ��������";
	cin >> pc->date[pc->count].name;
	cout << "��������ϵ�����䣺";
	cin >> pc->date[pc->count].age;
	cout << "��������ϵ�˵绰��";
	cin >> pc->date[pc->count].tele;
	pc->count++;
	cout << endl << "��ӳɹ���" << endl;
}

//3.ɾ����ϵ��
void Deltongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "�㻹û�����ѿ�������ɾ����" << endl;
		return;
	}
	char name[NAME];
	cout << "����������Ҫɾ�����˵����֣�";
	cin >> name;
	int a = Find(pc, name);
	if (a == -1)
	{
		cout << "û���ҵ������Ŷ~���ǲ����������������";
		return;
	}
	else
	{
		for (int i = a; i < pc->count - 1; i++)
		{
			pc->date[a] = pc->date[a + 1];
		}
		cout << "ɾ���ɹ���" << endl;
		pc->count--;
	}
}

//4.������ϵ��
void Searchtongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "����������Ҫ���ҵ��˵����֣�";
	char name[NAME];
	cin >> name;
	int a = Find(pc, name);
	if (a == -1)
	{
		cout << "�����û��������أ��ǲ�������д���ˣ�" << endl;
		return;
	}
	else
	{
		cout << setw(20) << left << "����";
		cout << setw(20) << left << "����";
		cout << setw(20) << left << "�绰";
		cout << endl;
		cout << setw(20) << left << pc->date[a].name;
		cout << setw(20) << left << pc->date[a].age;
		cout << setw(20) << left << pc->date[a].tele;
		cout << endl;
	}
}

//5.�޸���Ϣ
void Modifytongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	cout << "����Ҫ�޸�˭����Ϣ��";
	char name[NAME];
	cin >> name;
	int a = Find(pc, name);
	if (a == -1)
	{
		cout << "���޴���" << endl;
		return;
	}
	else
	{
		pc->date[a] = { 0 };
		cout << "���޸�" << endl;
		cout << "�������޸ĺ�����֣�";
		cin >> pc->date[a].name;
		cout << "�������޸ĺ�����䣺";
		cin >> pc->date[a].age;
		cout << "�������޸ĺ�ĵ绰��";
		cin >> pc->date[a].tele;
		cout << "�޸ĳɹ���";
	}
}

//6.����
void Sorttongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	if (pc->count == 0)
	{
		cout << "���ͨѶ¼���ǿյ�������ʲô����" << endl;
		return;
	}
	qsort(pc->date, pc->count, sizeof(struct xinxi), cmp_xinxi);
	cout << "����ɹ�" << endl;
}

//7.����
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
	cout << "����ɹ�����" << endl;
	*flag = 1;
}

//8.���ͨѶ¼
void Cleantongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
	pc->count = 0;
	pc->capacity = Count;
	cout << "����ɹ�";
}






//��������-------------------------------------------------------------

//�˵�
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

//����ͨѶ¼
void Destroytongxunlu(struct tongxunlu* pc)
{
	assert(pc);
	free(pc->date);
	pc->date = NULL;
}

//ö��
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
		cout << "��ѡ��";
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
				cout << "�Ƿ񱣴棺��y/n��";
				char c;
				cin >> c;
				if (c == 'y' || c == 'Y')
				{
					Savetongxunlu(&txl, &flag);
				}
			}
			Destroytongxunlu(&txl);
			cout << endl << "�ݰ�`" << endl;
			break;
		}
		else
		{
			cout << endl << "�����û���ѡ�����" << endl;
		}
	}
	return 0;
}