#include "employee.h"
#include "Technician.h"
#include "Manager.h"
#include "Salesman.h"
#include "SalesManager.h"
int main()
{
#if 0
	Employee* emp = new Technician();

	emp->getPay();
	emp->Uplevel();
	emp->displayStatus();

	delete emp;
#endif
#if 0
	Employee* man = new Manager;

	man->getPay();
	man->displayStatus();
	man->Uplevel();
	man->Uplevel();
	man->getPay();
	man->displayStatus();
	
#endif

#if 0
	Employee* sm = new SalesManager;

	sm->init();
	sm->getPay();
	sm->displayStatus();
	
	delete sm;

#endif

	Employee* array[] = { new Technician,new Manager,new Salesman,new SalesManager };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		array[i]->init();
		array[i]->Uplevel();
		array[i]->getPay();
		array[i]->displayStatus();
	}

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		delete array[i];
	}




	return 0;
}