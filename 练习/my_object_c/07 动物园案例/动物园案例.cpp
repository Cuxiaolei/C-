#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
	Animal* sp1 = new Cat;
	Animal* sp2 = new Dog;

	sp1->voice();
	sp2->voice();

	//���ȴ�����������������ٴ��������������
	delete sp1;
	delete sp2;

	return 0;
}


