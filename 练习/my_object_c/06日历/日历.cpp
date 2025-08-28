#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

typedef struct Thing
{
	char thing[100];


}Thing;

typedef struct BackLog
{
	int i;
	Thing thing[10];
}BackLog;

typedef struct Day
{
	int day;
	BackLog Log;
}Day;

typedef struct Month
{
	int month;
	int sumday;
	Day* day;
}Month;

typedef struct Year
{
	int year;
	Month* month;
	Year* next;
}Year;

typedef struct Link
{
	Year* head;
	Year* tail;
}Link;


//��������
const char* InitFestival(int month, int day)
{
	const char* festival = (char*)calloc(150, sizeof(char));
	festival = "�ǹ�������";
	if (month == 1)
	{
		if (day == 1)festival = "Ԫ��";
		else if (day == 6)festival = "С��";
		else if (day == 8)festival = "�ܶ�������������";
		else if (day == 10)festival = "ȫ��110������ + ȫ�����񾯲����";
		else if (day == 14)festival = "�ռ����˽�";
		else if (day == 20)festival = "��";
		else if (day == 26)festival = "���ʺ�����";
		else if (day == 27)festival = "���ʴ���ɱ������";
		else if (day == 28)festival = "��������";
	}

	else if (month == 2)
	{
		if (day == 2)festival = "����ʪ����";
		else if (day == 4)festival = "���� + ���翹����";
		else if (day == 7)festival = "������Ԯ�Ϸ���";
		else if (day == 10)festival = "���������";
		else if (day == 13)festival = "�������ߵ���";
		else if (day == 14)festival = "�������˽�";
		else if (day == 17)festival = "���紩ɽ����";
		else if (day == 19)festival = "��ˮ + ��Сƽ����������";
		else if (day == 20)festival = "������ṫ����";
		else if (day == 21)festival = "����ĸ����";
		else if (day == 24)festival = "��������������";
	}

	else if (month == 3)
	{
		if (day == 1)festival = "��������� + ���ʺ�����";
		else if (day == 3)festival = "����Ұ����ֲ���� + ȫ��������";
		else if (day == 5)festival = "���� + ����־Ը�߷����� + ѧ�׷������";
		else if (day == 6)festival = "�����������";
		else if (day == 7)festival = "Ů����";
		else if (day == 8)festival = "��Ů��";
		else if (day == 9)festival = "����ĸ�׺���";
		else if (day == 12)festival = "ֲ���� + ����ɽ����������";
		else if (day == 14)festival = "���������� + ���練ˮ���� + ��ɫ���˽� + Բ������";
		else if (day == 15)festival = "������Ȩ����";
		else if (day == 16)festival = "���ʳ��Ž� + ��������ϵƶ��С���ȫ��ͳһ�ж���";
		else if (day == 17)festival = "�й���ҽ��";
		else if (day == 18)festival = "�Ƽ��˲Ż�� + ȫ��������";
		else if (day == 20)festival = "���� + ���������� + �����Ҹ���";
		else if (day == 21)festival = "��������� + ����ʫ���� + �����������ӹ����� + ����ɭ���� + ����˯����";
		else if (day == 22)festival = "����ˮ��";
		else if (day == 23)festival = "����������";
		else if (day == 24)festival = "������ν�˲���";
		else if (day == 25)festival = "ȫ����Сѧ����ȫ������";
		else if (day == 27)festival = "����Ϸ����";
		else if (day == 29)festival = "�й��ƻ�����ʮ����ʿѳ�Ѽ�����";
		else if (day == 30)festival = "����һСʱ��";
	}

	else if (month == 4)
	{
		if (day == 1)festival = "ȫ�����������˶���(����) + ���ʰ����� + ���˽� + ˰��������(����)";
		else if (day == 2)festival = "�����Ա�֢�� + ������ͷ��ս�� + ���ʶ�ͯͼ����";
		else if (day == 4)festival = "���� + ���ʵ����ж���";
		else if (day == 7)festival = "����������";
		else if (day == 8)festival = "������ϡ���ﱣ����";
		else if (day == 9)festival = "���ʻ�θ��";
		else if (day == 11)festival = "��������ɭ����";
		else if (day == 12)festival = "���纽����";
		else if (day == 13)festival = "��ˮ��";
		else if (day == 14)festival = "��ɫ���˽�";
		else if (day == 15)festival = "ȫ����Ұ�ȫ������";
		else if (day == 16)festival = "����ɤ����";
		else if (day == 17)festival = "���������Ƕ��� + ����Ѫ�Ѳ���";
		else if (day == 18)festival = "���ʹż���ַ��";
		else if (day == 19)festival = "����";
		else if (day == 20)festival = "���ʴ����� + ����������";
		else if (day == 21)festival = "ȫ����ҵ�һ��";
		else if (day == 22)festival = "���編���� + ���������";
		else if (day == 23)festival = "���������";
		else if (day == 24)festival = "�й������� + ���ʵ�äȮ�� + �Ƿ����Ź����߽� + �������귴��ֳ��������";
		else if (day == 25)festival = "��ͯԤ������������ + �������ű����";
		else if (day == 26)festival = "ȫ��ű���� + ����֪ʶ��Ȩ��";
		else if (day == 27)festival = "����ƽ������� + ������ҽ��";
		else if (day == 28)festival = "���簲ȫ�����뽡����";
		else if (day == 29)festival = "��ѧս�ܺ��߼����� + �����赸��";
		else if (day == 30)festival = "���ʲ���С���� + ȫ����ͨ��ȫ��˼��";
	}

	else if (month == 5)
	{
		if (day == 1)festival = "�Ͷ���";
		else if (day == 2)festival = "�����ǹ����";
		else if (day == 3)festival = "΢�̽� + ��������������";
		else if (day == 4)festival = "��������� + �Ƽ�������";
		else if (day == 5)festival = "���� + ��������ʿ��";
		else if (day == 6)festival = "�й�����������";
		else if (day == 7)festival = "�����������";
		else if (day == 8)festival = "�����ѳ����� + ����΢Ц�� + �����ʮ����";
		else if (day == 10)festival = "�й�Ʒ����";
		else if (day == 11)festival = "������η�����";
		else if (day == 12)festival = "ĸ�׽� + ��ʿ�� + ����ƶ��ĸ���� + ȫ�����ּ�����";
		else if (day == 14)festival = "õ�����˽�";
		else if (day == 15)festival = "��ȱ���������� + ���ʼ�ͥ��";
		else if (day == 17)festival = "�����Ѫѹ�� + ���������";
		else if (day == 18)festival = "���ʲ������";
		else if (day == 19)festival = "�����ͥҽ���� + ȫ�������� + �й�������";
		else if (day == 20)festival = "С�� + ��������� + ����İ���˽� + �����۷��� + ȫ��ѧ��Ӫ���� + ȫ��ĸ��ι�������� + �������˽�";
		else if (day == 21)festival = "�����Ļ���չ��";
		else if (day == 22)festival = "���������������";
		else if (day == 23)festival = "���纣����";
		else if (day == 25)festival = "����ʧ�ٶ�ͯ�� + ����Ԥ���з���";
		else if (day == 26)festival = "����������������ս��";
		else if (day == 28)festival = "ȫ��������";
		else if (day == 29)festival = "���糦�������� + ����ά����Ա��";
		else if (day == 30)festival = "ȫ���Ƽ��������� + �й�����ئ���˶�������";
		else if (day == 31)festival = "����������";
	}

	else if (month == 6)
	{
		if (day == 1)festival = "��ͯ�� + ����ţ����";
		else if (day == 3)festival = "�������г���";
		else if (day == 5)festival = "â�� + ���绷����";
		else if (day == 6)festival = "�й��ֻ��� + ȫ��������";
		else if (day == 7)festival = "�߿�";
		else if (day == 8)festival = "�Ļ�����Ȼ�Ų��� + ���纣����";
		else if (day == 9)festival = "���ʵ����� + �����Ͽ���";
		else if (day == 11)festival = "�й��˿���";
		else if (day == 12)festival = "������ͯ����";
		else if (day == 14)festival = "�������˽� + ������Ѫ����";
		else if (day == 15)festival = "������ʳ��";
		else if (day == 16)festival = "���׽� + ���ʷ��޶�ͯ��";
		else if (day == 17)festival = "���λ�Į���͸ɺ���";
		else if (day == 20)festival = "����������";
		else if (day == 21)festival = "���� + ����Ϩ���� + �����٤�� + ���罥������";
		else if (day == 22)festival = "��ͯ���ƻ��";
		else if (day == 23)festival = "���ʰ���ƥ���� + ����������";
		else if (day == 25)festival = "ȫ��������";
		else if (day == 26)festival = "֧Ԯ�����ܺ����� + ���ʽ����� + ����������";
		else if (day == 27)festival = "��С΢��ҵ��";
		else if (day == 30)festival = "��������������";
	}

	else if (month == 7)
	{
		if (day == 1)festival = "������ + ��ۻع������";
		else if (day == 2)festival = "��������������";
		else if (day == 6)festival = "С�� + ������������� + ���ʺ����� + ���ʽ�����";
		else if (day == 7)festival = "���������� + �����±������";
		else if (day == 8)festival = "��������Լ�����";
		else if (day == 11)festival = "�����˿��� + �й�������";
		else if (day == 14)festival = "��ɫ���˽�";
		else if (day == 16)festival = "���ʱ�����";
		else if (day == 17)festival = "������������ + ����������";
		else if (day == 18)festival = "������������";
		else if (day == 20)festival = "����������";
		else if (day == 22)festival = "����";
		else if (day == 23)festival = "��๤��";
		else if (day == 25)festival = "������";
		else if (day == 26)festival = "�����ﴴ����";
		else if (day == 28)festival = "���������";
		else if (day == 29)festival = "�ع����������� + ���簮����";
		else if (day == 30)festival = "����������";
	}

	else if (month == 8)
	{
		if (day == 1)festival = "������";
		else if (day == 3)festival = "���˽�";
		else if (day == 5)festival = "����˹����������";
		else if (day == 7)festival = "����";
		else if (day == 8)festival = "�ְֽ� + ����è���� + ȫ������";
		else if (day == 9)festival = "������������";
		else if (day == 11)festival = "ȫ��֫���˻��";
		else if (day == 12)festival = "��������� + ���������";
		else if (day == 13)festival = "������Ʋ����";
		else if (day == 14)festival = "��ɫ���˽�";
		else if (day == 15)festival = "�ձ�������Ͷ����";
		else if (day == 18)festival = "�й�������Դ��";
		else if (day == 19)festival = "�й�ҽʦ�� + �����˵������� + ������Ӱ��";
		else if (day == 20)festival = "����������";
		else if (day == 22)festival = "����";
		else if (day == 26)festival = "ȫ����ʦ��ѯ��";
		else if (day == 29)festival = "ȫ����淨������";
	}

	else if (month == 9)
	{
		if (day == 1)festival = "ȫ�񽡿����ʽ�� + ȫ����Сѧ����ѧ��";
		else if (day == 3)festival = "��ҽ�� + ����ս��ʤ��������";
		else if (day == 5)festival = "�л�������";
		else if (day == 7)festival = "��¶";
		else if (day == 8)festival = "����ɨä�� + �������Ź�������";
		else if (day == 9)festival = "ȫ���ܾ��Ƽ��� + ë������������";
		else if (day == 10)festival = "����Ԥ����ɱ�� + ��ʦ��";
		else if (day == 12)festival = "�й�Ԥ������ȱ����";
		else if (day == 14)festival = "�й������ + ��Ƭ���˽� + ���缱���� + �����ٵ����գ�������";
		else if (day == 15)festival = "ȫ�������� + ���������� + �����Ļ���";
		else if (day == 16)festival = "�������簲ȫ������ + �й��Խ����� + ���ʳ����㱣����";
		else if (day == 17)festival = "�л�����մ��� + ����������";
		else if (day == 18)festival = "��һ���±������";
		else if (day == 20)festival = "ȫ�������� + ȫ�������� + �������������";
		else if (day == 21)festival = "������������ + ���簢���ĺ�Ĭ���� + ȫ����������� + ���ʺ�ƽ��";
		else if (day == 22)festival = "��� + �������˽� + �й�ũ����ս� + �����޳��� + ������è��";
		else if (day == 26)festival = "���������";
		else if (day == 27)festival = "����������";
		else if (day == 28)festival = "���ӵ��������� + �����Ȯ����";
		else if (day == 29)festival = "���粽���� + ����������";
		else if (day == 30)festival = "��ʿ������ + ���ʷ�����";
	}

	else if (month == 10)
	{
		if (day == 1)festival = "����� + ������������ + ���������� + ������ʳ��";
		else if (day == 2)festival = "���ʺ�ƽ���������ɶ����� + ���ʷǱ�����";
		else if (day == 4)festival = "���綯����";
		else if (day == 5)festival = "�����ʦ��";
		else if (day == 7)festival = "����ס���� + ���罨����";
		else if (day == 8)festival = "��¶ + ȫ����Ѫѹ��";
		else if (day == 9)festival = "����������";
		else if (day == 10)festival = "���羫�������� + ������������� + �����Ӿ��� + ��������������";
		else if (day == 11)festival = "������ʹ�� + ����Ůͯ�� + ���ʳ�����";
		else if (day == 12)festival = "����ؽ�����";
		else if (day == 13)festival = "�й������ȷ�ӵ����� + ���ʱ�׼ʱ���� + ���ʼ�����Ȼ�ֺ��� + ���籣����";
		else if (day == 14)festival = "���Ѿ����˽� + �����׼��";
		else if (day == 15)festival = "ȫ��ϴ���� + ����ä�˽�";
		else if (day == 16)festival = "������ʳ��";
		else if (day == 17)festival = "��ƶ�� + ��������ƶ����";
		else if (day == 18)festival = "��������ڹػ���";
		else if (day == 20)festival = "�����ʦ�� + ����ͳ���� + �������������";
		else if (day == 22)festival = "���ʿڳ��� + ���紫ͳҽҩ��";
		else if (day == 23)festival = "˪�� + ����ѩ����";
		else if (day == 24)festival = "���緢չ��Ϣ�� + ����Ա�� + ���Ϲ���";
		else if (day == 25)festival = "�����컨������ + ����Ԯ��������";
		else if (day == 26)festival = "�������˽�";
		else if (day == 28)festival = "���綯���� + �������Խ�����";
		else if (day == 29)festival = "����������";
		else if (day == 31)festival = "��������� + �����ڼ��� + ��ʥҹ";
	}

	else if (month == 11)
	{
		if (day == 1)festival = "��ʥ��";
		else if (day == 5)festival = "���纣Х��";
		else if (day == 7)festival = "���� + ʮ������������������";
		else if (day == 8)festival = "���߽�";
		else if (day == 9)festival = "ȫ��������";
		else if (day == 10)festival = "���������";
		else if (day == 11)festival = "���ʿ�ѧ���ƽ�� + ˫ʮһ����񻶽� + ����� + �վ�������";
		else if (day == 14)festival = "����˹�����¼�� + ��Ӱ���˽� + ����������";
		else if (day == 15)festival = "���й�����ȫ��";
		else if (day == 16)festival = "���ʿ�����";
		else if (day == 17)festival = "���ʷΰ��� + ��������� + ���ʴ�ѧ����";
		else if (day == 19)festival = "���������";
		else if (day == 20)festival = "�������������Էβ��� + �Ĺ������� + �����ͯ��";
		else if (day == 21)festival = "����ɽ���������� + �����ʺ��� + ���������";
		else if (day == 22)festival = "Сѩ";
		else if (day == 25)festival = "������ʳ�� + �����Ը�Ů�ı�����";
		else if (day == 28)festival = "�ж���";
		else if (day == 29)festival = "�й������� + ������Ԯ����˹̹������";
	}

	else if (month == 12)
	{
		if (day == 1)festival = "���簬�̲���";
		else if (day == 2)festival = "ȫ����ͨ��ȫ��";
		else if (day == 3)festival = "����м�����";
		else if (day == 4)festival = "ȫ������������";
		else if (day == 5)festival = "����־Ը��Ա�� + ���������� + ����������ʿ��";
		else if (day == 6)festival = "��ѩ";
		else if (day == 7)festival = "��������";
		else if (day == 8)festival = "ɳ��С�Խ� + ���ʶ�ͯ���ӹ㲥��";
		else if (day == 9)festival = "���ʷ������� + ���������� + һ�������˶�������";
		else if (day == 10)festival = "������Ȩ��";
		else if (day == 11)festival = "����ɽ����";
		else if (day == 12)festival = "�����±������";
		else if (day == 13)festival = "���ҹ�����";
		else if (day == 14)festival = "ӵ�����˽�";
		else if (day == 15)festival = "����ǿ��������";
		else if (day == 18)festival = "������������";
		else if (day == 20)festival = "���Żع������";
		else if (day == 21)festival = "���� + ����������";
		else if (day == 24)festival = "ƽ��ҹ";
		else if (day == 25)festival = "ʥ����";
		else if (day == 26)festival = "ë�󶫵���������";
	}
	return festival;
}

//ÿ���µ�������ʼ��
Day* InitDay(int month, int sumday)
{
	Day* p = (Day*)calloc(sumday, sizeof(Day));
	for (int i = 0; i < sumday; i++)
	{
		p[i].day = i + 1;
		p[i].Log.i = 0;
	}
	return p;
}

//ÿ���������ʼ��
Month* InitMonth(int year)
{
	Month* p = (Month*)calloc(12, sizeof(Month));
	int day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int i = 0; i < 12; i++)
	{
		if ((i + 1) == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				day[1] = 29;
			}
		}
		p[i].month = i + 1;
		p[i].day = InitDay(p[i].month, day[i]);
		p[i].sumday = day[i];
	}
	return p;
}

//1940-2040�����ʼ��
void Init(Link* p)
{
	p->head = NULL;
	p->tail = NULL;
	for (int i = 1940; i <= 2040; i++)
	{
		Year* cur = (Year*)calloc(1, sizeof(Year));	//��һ��ռ�
		cur->year = i;
		cur->month = InitMonth(i);
		cur->next = NULL;
		if (p->head == NULL)
		{
			p->head = cur;
		}
		else
		{
			p->tail->next = cur;
		}
		p->tail = cur;
	}
}

//����ĳһ��ĵ�һ��Ϊ���ڼ�
int TheYearFirstDay(int year)
{
	int sum = 0;
	//1934���һ��Ϊ����һ���ʴ�1905������
	for (int i = 1934; i < year; i++)
	{
		//����366��
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
		{
			sum += 366;
		}
		else
		{
			sum += 365;
		}
	}
	return (sum % 7) + 1;
}

//��ӡĳ�µı�ͷ
void ShowMonthHead(Year* p, int month)
{
	cout << setw(2) << right << p->month[month].month << "��" << " ";
	cout << setw(4) << left << "Mon";
	cout << setw(4) << left << "Tue";
	cout << setw(4) << left << "Wed";
	cout << setw(4) << left << "Thu";
	cout << setw(4) << left << "Fri";
	cout << setw(4) << left << "Sat";
	cout << setw(4) << left << "Sun";
}

//��ӡĳ���µ������������ã�
void ShowMonthDate1(Year* p, int month, int firstday)
{
	//�����һ���������գ���ô��������firstday �� 0
	if (firstday == 0)
	{
		cout << "                        ";
	}
	cout << "     ";
	//��ÿ���µĵ�һ��֮ǰ��ӡ�ո�
	for (int t = 0; t < firstday - 1; t++)
	{
		cout << "    ";
	}
	//��ӡ����µ�ÿһ��
	for (int i = 0; i < p->month[month].sumday; i++)
	{
		cout << setw(4) << left << p->month[month].day[i].day;
		firstday++;

		//ÿ�δ�ӡ�������վͻ���
		if ((firstday - 1) % 7 == 0)
		{
			cout << endl;
			cout << "     ";
		}
	}
	cout << endl;
}

//��ӡĳһ�������
void ShowYear(Link* link)
{
	Year* p = link->head;
	int year;
	cout << "��Ҫ�鿴��һ���������";
	cin >> year;
	//������һ���һ�����ڼ�
	int firstday = TheYearFirstDay(year);
	//�ҵ���һ��Ľڵ�
	while (p != NULL && p->year != year)
	{
		p = p->next;
	}
	int i, j, k;
	if (p == NULL)
	{
		cout << "�������" << endl;
		return;
	}

	//���������ʽ
	cout << "===============================================" << year << "����==================================================" << endl;
	for (i = 0, j = 1, k = 2; i < 12; i += 3, j += 3, k += 3)
	{
		cout << "|";
		ShowMonthHead(p, i);
		cout << "  ";
		ShowMonthHead(p, j);
		cout << "  ";
		ShowMonthHead(p, k);
		cout << "|";
		cout << endl;
		//��¼ÿ���µ�һ�������ڼ�
		int firstday1 = firstday;
		int firstday2 = (firstday + p->month[i].sumday) % 7;
		int firstday3 = (firstday + p->month[i].sumday + p->month[j].sumday) % 7;

		int t1 = 0;
		int t2 = 0;
		int t3 = 0;

		int f1 = 0;
		int f2 = 0;
		int f3 = 0;
		while (t1 < p->month[i].sumday || t2 < p->month[j].sumday || t3 < p->month[k].sumday)
		{
			//1��4��7��10��
			//��ÿ���µĵ�һ��֮ǰ��ӡ�ո�
			cout << "|     ";
			//ÿ���¿�ʼʱ�����������գ���������firstdayΪ0
			if (firstday1 == 0)
				cout << "                        ";
			for (int t = 0; t < firstday1 - 1; t++)
				cout << "    ";

			for (int n1 = t1; n1 < p->month[i].sumday; n1++)
			{
				cout << setw(4) << left << p->month[i].day[n1].day;
				firstday1 += 1;///2 3 4 5 6 7 8
				t1++;			//1 2 3 4 5 6 7
				if ((firstday1 - 1) % 7 == 0)
				{
					firstday1 = firstday1 % 7;
					break;
				}
			}
			//�����ÿ���������һ��Ҫ�ճ�ÿ�������һ�еĿո�
			if (t1 == p->month[i].sumday)
			{
				if (firstday1 == 1)
				{
					if (f1 == 1)
						cout << "                            ";
				}
				//ÿ��firstday1Ϊ 1 �����������3�죬��firstday1Ϊ4����Ҫ��7-��4-1���οո�
				if (firstday1 != 1)
				{
					for (int s = 0; s < (7 - firstday1 + 1); s++)
					{
						cout << "    ";
					}
				}
				f1 = 1;
			}

			//2��5��8��11��
			cout << "  ";
			cout << "     ";
			if (firstday2 == 0)
				cout << "                        ";
			for (int t = 0; t < firstday2 - 1; t++)
				cout << "    ";
			for (int n2 = t2; n2 < p->month[j].sumday; n2++)
			{
				cout << setw(4) << left << p->month[j].day[n2].day;
				firstday2 += 1;
				t2++;
				if ((firstday2 - 1) % 7 == 0)
				{
					firstday2 = firstday2 % 7;
					break;
				}
			}
			//�����ÿ���������һ��Ҫ�ճ�ÿ�������һ�еĿո�
			if (t2 == p->month[j].sumday)
			{
				if (firstday2 == 1)
				{
					if (f2 == 1)
						cout << "                            ";//������ĸ��ո�
				}
				if (firstday2 != 1)
				{
					for (int s = 0; s < (7 - firstday2 + 1); s++)
					{
						cout << "    ";
					}
				}
				//�ڵ����ڶ��������֮����һ��
				f2 = 1;
			}


			//3��6��9��12��
			cout << "  ";
			cout << "     ";
			if (firstday3 == 0)
				cout << "                        ";
			for (int t = 0; t < firstday3 - 1; t++)
				cout << "    ";
			for (int n3 = t3; n3 < p->month[k].sumday; n3++)
			{
				cout << setw(4) << left << p->month[i].day[n3].day;
				firstday3 += 1;
				t3++;
				if ((firstday3 - 1) % 7 == 0)
				{
					firstday3 = firstday3 % 7;
					break;
				}
			}
			//�����ÿ���������һ��Ҫ�ճ�ÿ�������һ�еĿո�
			if (t3 == p->month[k].sumday)
			{
				if (firstday3 == 1)
				{
					if (f3 == 1)
						cout << "                            ";//������ĸ��ո�
				}
				if (firstday3 != 1)
				{
					for (int s = 0; s < (7 - firstday3 + 1); s++)
					{
						cout << "    ";
					}
				}
				//�ڵ����ڶ��������֮����һ��
				f3 = 1;
			}

			cout << "|";
			cout << endl;
		}
		//ÿ����������һ�������µĵ�һ�����ڼ�
		firstday = (firstday + p->month[i].sumday + p->month[j].sumday + p->month[k].sumday) % 7;
	}
	cout << "=========================================================================================================" << endl;
}


//��ӡĳ���µ�����
void ShowMonthDate(Link* link)
{
	Year* p = link->head;
	int year, month;
	cout << "������Ҫ������������£�";
	cin >> year >> month;
	if (month > 12 || month < 1)
	{
		cout << "�����" << month << "�°�������";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}

	int firstday = TheYearFirstDay(year);

	if (p->year == year)
	{

		for (int i = 0; i < month - 1; i++)
		{
			firstday = (firstday + p->month[i].sumday) % 7;
		}
		ShowMonthHead(p, month - 1);
		cout << endl;
		ShowMonthDate1(p, month - 1, firstday);
	}
	else
	{
		cout << "�������˲���ȷ������" << endl;
	}
}

//��ѯĳ�������
void FindSomeday(Link* link)
{
	Year* p = link->head;
	cout << "��������Ҫ��ѯ�������գ�";
	int year, month, day;
	cin >> year >> month >> day;

	//��λ����ǰ�ڵ�
	if (month > 12 || month < 1)
	{
		cout << "�����" << month << "�°�������";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "���" << year << "��" << month << "����" << day << "�찡��������" << endl;
		return;
	}




	//��ǰʱ��
	int i;
	time_t time0;
	time0 = time(NULL);
	struct tm* systemtime = localtime(&time0);
	int curyear = systemtime->tm_year + 1900;
	int curmonth = systemtime->tm_mon + 1;
	int curday = systemtime->tm_mday;

	int sum = 0;

	if (year < curyear)
	{
		for (i = year; i < curyear; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) sum += 366;	//�����366��
			else sum += 365;												//�����365��
		}

		if (month < curmonth)
		{
			//ѭ�����������������Ӧ������
			for (i = month; i < curmonth; i++)sum += p->month[i - 1].sumday;

			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month == curmonth)
		{
			//������������
			if (day < curday) sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month > curmonth)
		{
			//ѭ����ȥ�����������Ӧ������(��ȥ��Ҫ��ѯ��һ��ĵ�������)
			for (i = curmonth; i < month; i++)sum -= p->month[i - 1].sumday;

			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}
	}

	if (year == curyear)
	{
		if (month < curmonth)
		{
			//ѭ�����������������Ӧ������
			for (i = month; i < curmonth; i++)sum += p->month[i - 1].sumday;

			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month == curmonth)
		{
			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month > curmonth)
		{
			//ѭ����ȥ�����������Ӧ������(��ȥ��Ҫ��ѯ��һ��ĵ�������)
			for (i = curmonth; i < month; i++)sum -= p->month[i - 1].sumday;

			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}
	}

	if (year > curyear)
	{
		for (i = curyear; i < year; i++)
		{
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) sum -= 366;	//�����366��
			else sum -= 365;												//�����365��
		}

		if (month < curmonth)
		{
			//ѭ�����������������Ӧ������
			for (i = month; i < curmonth; i++)sum += p->month[i - 1].sumday;

			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month == curmonth)
		{
			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}

		else if (month > curmonth)
		{
			//ѭ����ȥ�����������Ӧ������(��ȥ��Ҫ��ѯ��һ��ĵ�������)
			for (i = curmonth; i < month; i++)sum -= p->month[i - 1].sumday;

			//������������
			if (day < curday)sum += (curday - day);
			else if (day == curday) sum = sum;
			else if (day > curday)sum = sum - (day - curday);
		}
	}

	if (sum >= 0)
	{
		cout << "������Ѿ���ȥ" << sum << "����" << endl;
	}
	else
	{
		cout << "�����" << -sum << "��" << endl;
	}

	//��ǰ���ڼ�
	int firstday = TheYearFirstDay(year) - 1;
	for (int i = 0; i < month - 1; i++)
	{
		firstday = firstday + p->month[i].sumday;
	}

	firstday += day;
	firstday = firstday % 7;
	if (firstday == 1)cout << "����һ";
	else if (firstday == 2)cout << "���ڶ�";
	else if (firstday == 3)cout << "������";
	else if (firstday == 4)cout << "������";
	else if (firstday == 5)cout << "������";
	else if (firstday == 6)cout << "������";
	else if (firstday == 0)cout << "������";
	cout << endl;
	const char* festival = InitFestival(month, day);
	cout << festival << endl;
}

//���Ӵ���
void AddBackLog(Link* link)
{
	Year* p = link->head;
	cout << "������Ҫ���Ӵ��������:";
	int year, month, day;
	cin >> year >> month >> day;
	//��λ����ǰ�ڵ�
	if (month > 12 || month < 1)
	{
		cout << "�����" << month << "�°�������";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "���" << year << "��" << month << "����" << day << "�찡��������" << endl;
		return;
	}
	cout << "�����������¼�������0�˳���:";
	int t = 0;
	int i = p->month[month - 1].day[day - 1].Log.i;
	while (1)
	{
		cin >> p->month[month - 1].day[day - 1].Log.thing[i].thing;
		if (strcmp(p->month[month - 1].day[day - 1].Log.thing[i].thing, "0") == 0)
		{
			if (t == 1)
			{
				cout << "��ӳɹ�!!" << endl;
				return;
			}
			else
			{
				cout << "���˳�";
				return;
			}
		}
		p->month[month - 1].day[day - 1].Log.i++;
		t = 1;
		i++;
	}
}

//ɾ������
void DeleBackLog(Link* link)
{
	Year* p = link->head;
	cout << "������Ҫɾ�����������:";
	int year, month, day;
	cin >> year >> month >> day;
	//��λ����ǰ�ڵ�
	if (month > 12 || month < 1)
	{
		cout << "�����" << month << "�°�������";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "���" << year << "��" << month << "����" << day << "�찡��������" << endl;
		return;
	}

	p->month[month - 1].day[day - 1].Log.i = 0;
	cout << "ɾ���ɹ�����" << endl;
}

//�޸Ĵ���
void MondifyBackLog(Link* link)
{
	Year* p = link->head;
	cout << "������Ҫ�޸Ĵ��������:";
	int year, month, day;
	cin >> year >> month >> day;
	//��λ����ǰ�ڵ�
	if (month > 12 || month < 1)
	{
		cout << "�����" << month << "�°�������";
		return;
	}
	while (p->next != NULL && p->year != year)
	{
		p = p->next;
	}
	if (day > p->month[month - 1].sumday || day < 0)
	{
		cout << "���" << year << "��" << month << "����" << day << "�찡��������" << endl;
		return;
	}

	p->month[month - 1].day[day - 1].Log.i = 0;
	cout << "���޸ĸ���Ĵ����¼�������0�˳���:";
	int t = 0;
	int i = 0;
	while (1)
	{
		cin >> p->month[month - 1].day[day - 1].Log.thing[i].thing;
		if (strcmp(p->month[month - 1].day[day - 1].Log.thing[i].thing, "0") == 0)
		{
			if (t == 1)
			{
				cout << "��ӳɹ�!!" << endl;
				return;
			}
			else
			{
				cout << "���˳�";
				return;
			}
		}
		p->month[month - 1].day[day - 1].Log.i++;
		t = 1;
		i++;
	}
	cout << "�޸ĳɹ�����" << endl;
}

//��ѯ����
void FindBackLog(Link* link)
{
	Year* p = link->head;
	char input;
	cout << "������Ҫ��ѯ�ķ�ʽ��1.��ѯĳ����� 2.��ѯĳ���µĴ��죺��:";
	cin >> input;
	if (input == '1')
	{
		//cout << "��������Ҫ��ѯ��������:";
		int year, month, day;
		cin >> year >> month >> day;

		//��λ����ǰ�ڵ�
		if (month > 12 || month < 1)
		{
			cout << "�����" << month << "�°�������";
			return;
		}
		while (p->next != NULL && p->year != year)
		{
			p = p->next;
		}
		if (day > p->month[month - 1].sumday || day < 0)
		{
			cout << "���" << year << "��" << month << "����" << day << "�찡��������" << endl;
			return;
		}

		//��ѯ
		if (p->month[month - 1].day[day - 1].Log.i == 0)
		{
			cout << "�޴���" << endl;
		}
		else
		{
			for (int i = 0; i < p->month[month - 1].day[day - 1].Log.i; i++)
			{
				cout << i + 1 << ".";
				cout << p->month[month - 1].day[day - 1].Log.thing[i].thing << endl;
			}
		}
		cout << endl;
	}
	else if (input == '2')
	{
		cout << "��������Ҫ��ѯ�����£�";
		int year, month;
		cin >> year >> month;

		//��λ����ǰ�ڵ�
		if (month > 12 || month < 1)
		{
			cout << "�����" << month << "�°�������";
			return;
		}
		while (p->next != NULL && p->year != year)
		{
			p = p->next;
		}
		for (int i = 0; i < p->month[month - 1].sumday; i++)
		{
			cout << "��" << setw(2) << i + 1 << "��" << "�� ";
			if (p->month[month - 1].day[i].Log.i == 0)
			{
				cout << "�޴���" << endl;
			}
			else
			{
				for (int j = 0; j < p->month[month - 1].day[i].Log.i; j++)
				{
					cout << j + 1 << ".";
					cout << p->month[month - 1].day[i].Log.thing[j].thing << "     ";
				}
				cout << endl;
			}
		}
	}
	else
	{
		cout << "���벻�Ϸ�" << endl;
		return;
	}
}

//����
void Save(Link* link)
{
	Year* p = link->head;
	FILE* pfwrite = fopen("����.txt", "wb");
	if (pfwrite == NULL)
	{
		perror("Save");
		return;
	}
	while (p != NULL)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < p->month[i].sumday; j++)
			{
				fwrite(&p->month[i].day[j].Log, sizeof(BackLog), 1, pfwrite);
			}
		}
		p = p->next;
	}
	cout << "����ɹ�" << endl;
	fclose(pfwrite);
	pfwrite = NULL;
}

//����
void Load(Link* link)
{
	Year* p = link->head;
	FILE* pfread = fopen("����.txt", "rb");
	if (pfread == NULL)
	{
		perror("Load");
		return;
	}
	while (p != NULL)
	{
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < p->month[i].sumday; j++)
			{
				fread(&p->month[i].day[j].Log, sizeof(BackLog), 1, pfread);
			}
		}
		p = p->next;
	}
	fclose(pfread);
	pfread = NULL;
}

//����
void Clean()
{
	cout << "\033c";
}







void menu()
{
	cout << "                 |======================================================================|" << endl;
	cout << "                 |-----------------------------1.��ѯ����-------------------------------|" << endl;
	cout << "                 |-----------------------------2.��ѯ����-------------------------------|" << endl;
	cout << "                 |--------3.��ѯĳ������ݣ��������죬���ڼ����Ƿ������գ�----------|" << endl;
	cout << "                 |-----------------------------4.���Ӵ���-------------------------------|" << endl;
	cout << "                 |-----------------------------5.ɾ������-------------------------------|" << endl;
	cout << "                 |-----------------------------6.�޸Ĵ���-------------------------------|" << endl;
	cout << "                 |-----------------------------7.��ѯ����-------------------------------|" << endl;
	cout << "                 |----------------     e.�˳�    s.����   c.����     -------------------|" << endl;
	cout << "                 |======================================================================|" << endl;
}


int main()
{
	ios::sync_with_stdio(false);
	Link link;
	//�����ʼ��
	Init(&link);
	//������Ϣ
	Load(&link);
	//�˵�
	menu();
	char input;
	while (1)
	{
		cout << "��ѡ���ܣ�";
		cin >> input;

		if (input == '1')
		{
			ShowYear(&link);	//��ӡĳһ�������
		}
		else if (input == '2')
		{
			ShowMonthDate(&link);	//��ӡĳ��ĳ�µ�����
		}
		else if (input == '3')
		{
			FindSomeday(&link);
		}
		else if (input == '4')
		{
			AddBackLog(&link);
		}
		else if (input == '5')
		{
			DeleBackLog(&link);
		}
		else if (input == '6')
		{
			MondifyBackLog(&link);
		}
		else if (input == '7')
		{
			FindBackLog(&link);
		}
		else if (input == 'e')
		{
			cout << "лл������" << endl;
			return 1 - 1;
		}
		else if (input == 's')
		{
			Save(&link);
		}
		else if (input == 'c')
		{
			Clean();
			menu();
		}
		else
		{
			cout << "��������ȷ��ѡ���������" << endl;
		}
	}
	return 0;
}