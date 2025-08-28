#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
class Animal
{
public:
	//让子类继承并实现
	virtual void voice() = 0;

	//加上虚析构
	virtual ~Animal();
};

