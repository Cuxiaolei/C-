#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int main()
{
	Animal* sp1 = new Cat;
	Animal* sp2 = new Dog;

	sp1->voice();
	sp2->voice();

	//会先触发父类的虚析构，再触发子类的虚析构
	delete sp1;
	delete sp2;

	return 0;
}


