//2. 象棋算式
//在象棋算式里，不同的棋子代表不同的数，有以下算式，设计一个算法求这些棋子各代表哪些数字。

#include <stdio.h>
void fun()
{	
	int a,b,c,d,e,m,n,s;
	for (a=1;a<=9;a++)
		for (b=0;b<=9;b++)
			for (c=0;c<=9;c++)
				for (d=0;d<=9;d++)
					for (e=1;e<=9;e++)
						if (a==b || a==c || a==d || a==e || b==c || b==d || b==e || c==d || c==e || d==e) 
		   					continue;
						else
						{	
							m=a*1000+b*100+c*10+d;
							n=a*1000+b*100+e*10+d;
							s=e*10000+d*1000+c*100+a*10+d;
							if (m+n==s)
								printf("兵:%d 炮:%d 马:%d 卒:%d 车:%d\n",a,b,c,d,e);
						}
}
int main()
{
	fun();
}
