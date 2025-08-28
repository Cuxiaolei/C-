#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//Ó¢ÐÛÀà
class Hero
{
public:
	virtual int getAd()
	{
		return 10;
	}
};

class advHero :public Hero
{
public:
	virtual int getAd()
	{
		return 10000;
	}
};


//¹ÖÊÞÀà
class Monster
{
public:
	int getAd()
	{
		return 1000;
	}
};

void playerFight(Hero* hp, Monster* mp)
{
	if (hp->getAd() > mp->getAd())
	{
		cout << "Ó¢ÐÛÊ¤Àû£¬¹ÖÊÞ±»´òËÀ" << endl;
	}

	else
	{
		cout << "Ó¢ÐÛÊ§°Ü£¬¹ÖÊÞÊ¤Àû" << endl;
	}

}

class BugHero :public Hero
{
public:
	virtual int getAd()
	{
		return 99999999;
	}
};

int main()
{
	Hero h;
	Monster m;
	playerFight(&h, &m);
	advHero advh;
	playerFight(&advh, &m);
	BugHero bh;
	playerFight(&bh, &m);


	return 0;
}