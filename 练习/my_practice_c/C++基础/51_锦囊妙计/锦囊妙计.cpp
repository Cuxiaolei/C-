#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//定义拆开锦囊方法的类型
typedef void(Tips)(void);

//定义锦囊
struct tip
{
	char from[64];
	char to[64];
	//锦囊的内容
	Tips* tp;//相当于抽象类的纯虚函数
};


//需要一个打开锦囊的构架函数
void open_tips(struct tip* tip_p)
{
	cout << "打开了锦囊" << endl;
	cout << "此锦囊是由" << tip_p->from << "写给" << tip_p->to << "的。" << endl;
	cout << "此锦囊的内容是:";
	tip_p->tp();
}
struct tip* creat_tips(const char* from, const char* to, Tips* tp)
{
	struct tip* temp = (struct tip*)malloc(sizeof(struct tip));
	if (temp == NULL)
	{
		return NULL;
	}
	strcpy(temp->from, from);
	strcpy(temp->to, to);
	temp->tp = tp;
	return temp;
}

void destory_tip(struct tip* tp)
{
	if (tp != NULL)
	{
		free(tp);
		tp = NULL;
	}
}
//实现层
void tip1_func(void)
{
	cout << "一到东吴就拜见乔国老" << endl;
}
void tip2_func(void)
{
	cout << "如果主公乐不思蜀，就骗他" << endl;
}
void tip3_func(void)
{
	cout << "如果被孙权追杀，就找老婆" << endl;
}
int main()
{
	struct tip* tip1 = creat_tips("诸葛亮", "赵云", tip1_func);
	struct tip* tip2 = creat_tips("诸葛亮", "赵云", tip2_func);
	struct tip* tip3 = creat_tips("诸葛亮", "赵云", tip3_func);

	cout << "情况1" << endl;
	open_tips(tip1);
	cout << "情况2" << endl;
	open_tips(tip2);
	cout << "情况3" << endl;
	open_tips(tip3);


	destory_tip(tip1);
	destory_tip(tip2);
	destory_tip(tip3);

	return 0;
}