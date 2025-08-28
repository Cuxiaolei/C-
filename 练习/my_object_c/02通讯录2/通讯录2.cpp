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
//��Ϣ
typedef struct xinxi
{
	char name[NAME];
	char age[AGE];
	char tel[TEL];

}xinxi;

//����Ԫ
typedef struct tongxunlu
{
	xinxi date;
	tongxunlu* next;

}tongxunlu;

//ͷβ
tongxunlu* head = NULL;
tongxunlu* tail = NULL;


//��������-------------------------------------------------------------------------
//��ӡ��ͷ
void biaotou()
{
	cout << setw(20) << left << "����";
	cout << setw(20) << left << "����";
	cout << setw(20) << left << "�绰";
	cout << endl;
}

//��ӡ��ϵ����Ϣ
void dayinlxr(tongxunlu* pc)
{
	cout << setw(20) << left << pc->date.name;
	cout << setw(20) << left << pc->date.age;
	cout << setw(20) << left << pc->date.tel;
	cout << endl;
}

//������ϵ����Ϣ
void shurulxr(tongxunlu* pc)
{
	cout << "����������:";
	cin >> pc->date.name;
	cout << "����������:";
	cin >> pc->date.age;
	cout << "������绰:";
	cin >> pc->date.tel;
}

//��¼����
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







//���ܺ���------------------------------------------------------------------------------------------

//1.��ӡͨѶ¼
void showtongxunlu(tongxunlu* pc)
{
	if (pc == NULL)
	{
		cout << "�㻹û�����ѿ���չʾŶ��������" << endl;
		return;
	}
	biaotou();			//��ͷ	
	while (pc != NULL)
	{
		dayinlxr(pc);	//��ӡ��Ϣ
		pc = pc->next;
	}
}

//2.�����ϵ��
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
	cout << "��ӳɹ�" << endl;
}

//3.ɾ����ϵ��
void deltongxunlu(tongxunlu** pc)
{
	tongxunlu* pf = *pc;
	tongxunlu* pd = *pc;
	char name[NAME] = { 0 };
	if (*pc == NULL)
	{
		cout << "���ͨѶ¼���ǿյ�Ŷ��û�����Ѱ�~����Ц��" << endl;
		return;
	}
	cout << "����������Ҫɾ�����˵����֣�";
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
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "��û���ҵ�����Ҫɾ�����ˣ��ǲ�������д���ˣ�";
	}
}

//4.������ϵ��
void searchtongxunlu(tongxunlu* pc)
{
	if (pc == NULL)
	{
		cout << "���ͨѶ¼���ǿյģ���û���˿�����������Ŷ~" << endl;
		return;
	}
	char name[NAME] = { 0 };
	int flag = 1;
	cout << "����������Ҫ�������˵����֣�";
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
		cout << "û���ҵ����ˣ�" << endl;
	}

}

//5.�޸���ϵ����Ϣ
void modifytongxunlu(tongxunlu* pc)
{
	if (pc == NULL)
	{
		cout << "���ͨѶ¼���ǿյģ���û���˵���Ϣ���������޸�Ŷ~" << endl;
		return;
	}
	char name[NAME] = { 0 };
	int flag = 1;
	cout << "����Ҫ�޸�˭����Ϣ��";
	cin >> name;
	while (pc != NULL && strcmp(pc->date.name, name) != 0)
	{
		pc = pc->next;
	}
	if (strcmp(pc->date.name, name) == 0)
	{
		pc->date = { 0 };
		cout << "�޸İ�" << endl;
		shurulxr(pc);
		cout << "�޸ĳɹ�!" << endl;
	}
	else
	{
		cout << "û���ҵ������Ŷ~" << endl;
	}
}

//6.������ϵ����Ϣ
void inserttongxunlu(tongxunlu** pc)
{
	if (*pc == NULL)
	{
		cout << "���ͨѶ¼���ǿյģ���û���ĸ�λ�ÿ��Բ�����ϢŶ~" << endl;
		return;
	}
	tongxunlu* pf = *pc;
	tongxunlu* pd = *pc;
	tongxunlu* pa = *pc;
	tongxunlu* p = (tongxunlu*)calloc(1, sizeof(tongxunlu));
	p->next = NULL;
	char name[NAME];
	char d;
	cout << "��Ҫ��˭��λ�ò�����Ϣ��";
	cin >> name;
	//�����Ƿ��������
	while (strcmp(pa->date.name, name) != 0)
	{
		pa = pa->next;
		if (pa == NULL)
		{
			cout << "�Ҳ������������ô������Ϣ��" << endl;
			return;
		}
	}

	cout << "��Ҫ�����·������Ϸ���u/d)��";
	//�ж������Ƿ�Ϸ�
	while (1)
	{
		cin >> d;
		if (d != 'u' && d != 'U' && d != 'd' && d != 'D')
		{
			cout << "���������룡��" << endl;
			continue;
		}
		break;
	}

	cout << "������Ҫ�������Ϣ��" << endl;
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
	cout << "����ɹ�" << endl;
}

//7.�����ϵ��
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
	cout << "�ɹ����" << endl;
}

//8.����
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
	cout << "����ɹ�" << endl;
}

//c.����
void clean()
{
	cout << "\033c";
}




//��������-----------------------------------------------------------------------------------

//�˵�
void menu()
{
	cout << "                                   ��      ��                                                                  " << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << "1.show		2.add		3.del		4.search	5.modify	6.insert		0.exit" << endl;
	cout << "7.clean		8.save		c.����" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}

//�����ļ�
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

//����ͨѶ¼
void destroytongxunlu(tongxunlu* pc)
{
	free(pc);
	pc = NULL;
}






//������-----------------------------------------------------------
int main()
{

	loadtongxunlu(head);	//�����ļ�
	menu();
	char input;
	int flag = 0;
	int flag1 = 1;
	char tem;
	cout << "��ѡ���ܣ�";
	while (1)
	{
		if (flag)
			cout << endl << "���ٴ�ѡ���ܣ�";
		cin >> input;
		if (input == '1')//��ӡ
		{
			showtongxunlu(head);
			flag = 1;
		}
		else if (input == '2')//���
		{
			addtongxunlu(head);
			flag = 1;
		}
		else if (input == '3')//ɾ��
		{
			deltongxunlu(&head);
			flag = 1;
		}
		else if (input == '4')//����
		{
			searchtongxunlu(head);
			flag = 1;
		}
		else if (input == '5')//�޸�
		{
			modifytongxunlu(head);
			flag = 1;
		}
		else if (input == '6')//����
		{
			inserttongxunlu(&head);
			flag = 1;
		}
		else if (input == '7')//���ͨѶ¼
		{
			cleantongxunlu(&head);
			flag = 1;
		}
		else if (input == '8')//����
		{
			savetongxunlu(head);
			flag = 1;
			flag1 = 0;

		}
		else if (input == 'c')//����
		{
			clean();
			menu();
			flag = 1;
		}
		else if (input == '0')
		{
			if (flag1)
			{
				cout << "�Ƿ�Ҫ���棺(y/n)";
				cin >> tem;
				if (tem == 'y' || tem == 'Y')
				{
					savetongxunlu(head);
				}
			}
			cout << "�ݰ�~" << endl;
			destroytongxunlu(head);
			break;
		}
		else if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
		{
			cout << "�������ѡ����ѡ�����ֲ���������ѡ���⣡��" << endl;
			flag = 1;
		}
		else
		{
			cout << "�������úÿ������û�����ѡ��" << endl;
			flag = 1;
		}

	}
	return 0;
}
