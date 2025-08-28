#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//------------�����------------------
class CPU
{
public:
	virtual void caculate() = 0;
};


class Card
{
public:
	virtual void display() = 0;
};


class Memory
{
public:
	virtual void storage() = 0;
};


class Computer
{
public:
	Computer(CPU* cpu, Card* card, Memory* mem)
	{
		this->cpu = cpu;
		this->card = card;
		this->mem = mem;
	}

	void Work()
	{
		this->cpu->caculate();
		this->card->display();
		this->mem->storage();
	}
private:
	CPU* cpu;
	Card* card;
	Memory* mem;
};
//-------------------------------------






//------------ʵ�ֲ�-------------------
class IntelCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Intel CPU��ʼ������" << endl;
	}
};


class IntelCard :public Card
{
public:
	virtual void display()
	{
		cout << "Intel Card��ʼ��ʾ��" << endl;
	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel Memory��ʼ�洢��" << endl;
	}
};

class VivoCPU :public CPU
{
public:
	virtual void caculate()
	{
		cout << "Vivo CPU��ʼ������" << endl;
	}
};

class VivoCard :public Card
{
public:
	virtual void display ()
	{
		cout << "Vivo Card��ʼ��ʾ��" << endl;
	}
};

class VivoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Vivo Memory��ʼ�洢��" << endl;
	}
};

//----------------ҵ���----------------
int main()
{
	//1��װ��һ̨intelϵ�е���
	CPU* intelcpu = new IntelCPU;
	Card* intelcard = new IntelCard;
	Memory* intelmemory = new IntelMemory;

	Computer* com1 = new Computer(intelcpu, intelcard, intelmemory);
	com1->Work();


	CPU* vivocpu = new VivoCPU;
	Card* vivocard = new VivoCard;
	Memory* vivomemory = new VivoMemory;

	Computer* com2 = new Computer(vivocpu, vivocard, vivomemory);
	com2->Work();

	return 0;


}


