#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//评委打分案例（sort 算法排序）
//创建5个选手（姓名，得分），10个评委对5个选手进行打分
//得分规则：去除最高分，去除最低分，取出平均分
//按得分对5名选手排名

class Player
{
public:
	Player()
	{

	}
	Player(string name, int score)
	{
		this->mname = name;
		this->mscore = score;
	}
public:
	string mname;
	int mscore;
};
//创建选手
void Creat_Player(vector<Player>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		Player p;
		p.mname = "选手";
		p.mname += nameSeed[i];
		p.mscore = 0;

		v.push_back(p);
	}
}

//打分
void Set_Score(vector<Player>& v)
{
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		//当前学生进行打分
		deque<int> dScore;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			dScore.push_back(score);
		}

		//对十个分数进行排序 默认从小到大
		sort(dScore.begin(), dScore.end());

		//去除做高分，去除最低分
		dScore.pop_back();
		dScore.pop_front();

		//求平均分
		int sum = 0;
		for (deque<int>::iterator dit = dScore.begin(); dit != dScore.end(); dit++)
		{
			sum += (*dit);
		}
		int ave = sum / dScore.size();
		//保存分数
		(*it).mscore = ave;
	}
}

//排序规则
bool myCompare(Player& p1, Player& p2)
{
	return p1.mscore > p2.mscore;
}

//根据分数排名
void Print_Rank(vector<Player>& v)
{
	//排序
	sort(v.begin(), v.end(), myCompare);
	//打印
	for (vector<Player>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << (*it).mname << "   " << "得分：" << (*it).mscore << endl;
	}
}
int main()
{
	//定义vector容器，保存选手信息
	vector<Player> v;
	Creat_Player(v);
	Set_Score(v);
	Print_Rank(v);



	return 0;
}