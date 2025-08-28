//图的m着色问题
//【问题描述】给定无向连通图G和m种不同的颜色。用这些颜色为图G的各顶点着色，每个顶点着一种颜色。如果有一种着色法使G中每条边的两个顶点着不同颜色，则称这个图是m可着色的。图的m着色问题是对于给定图G和m种颜色，找出所有不同的着色法，并输出所有的着色方案。
//【输入格式】第1行有3个正整数n、k和m，表示给定的图G有n个顶点和k条边，m种颜色。顶点编号为1，2，…，n。接下来的k行中，每行有两个正整数u、v，表示图G的一条边（u，v）。
//【输出格式】程序运行结束时，将计算出的不同的着色方案数输出。如果不能着色，程序输出-1。
//
//【输入样例】
//5 8 4
//1 2
//1 3
//1 4
//2 3
//2 4
//2 5
//3 4
//4 5
//【输出样例】
//48

//求解有多少种着色方案和具体的着色方案
#include <stdio.h>
#include <string.h>
#define MAXN 20					//图最多的顶点个数
//问题表示
int n,k,m;
int a[MAXN][MAXN];
//求解结果表示
int count=0;				//全局变量，累计解个数
int x[MAXN];				//全局变量，x[i]表示顶点i的着色
/*******************begin************************/
//
//bool Same(int i)
//{
//    for(int j = 1; j <= n; j++)
//    {
//        if(a[i][j] == 1 && x[i] == x[j])
//            return false;
//    }
//    return true;
//}
//
//void dispasolution()			//输出一种着色方案
//{
//	printf("第%d个着色方案: ",count);
//	for (int j=1;j<=n;j++)
//		printf("%d ",x[j]);
//	printf("\n");
//}
//
//void dfs(int i)
//{
//    if(i > n) {
//    	count ++;
//    	dispasolution();
//	}
//    else{
//        for(int j = 1; j <= m; j++)
//        {
//            x[i] = j;
//            if(Same(i)) dfs(i + 1);
//            x[i] = 0;
//        }
//    }
//}

bool Same(int i)
{
	for(int j = 1; j <= n; j++){
		if(a[i][j] == 1 && x[i] == x[j]) return false;
	}
	return true;
}

void dfs(int i)
{
	if(i > n){
		count++;
	} 
	else{
		for(int j = 1; j <= m; j++){
			x[i] = j;
			if(Same(i)) dfs(i + 1);
			x[i] = 0;
		}
	}
}


/********************end*************************/
int main()
{
	memset(a,0,sizeof(a));		//a初始化
	memset(x,0,sizeof(x));		//x初始化
	int x,y;
	scanf("%d%d%d",&n,&k,&m);	//输入n,k,m
	for (int j=1;j<=k;j++)
	{
		scanf("%d%d",&x,&y);	//输入一条边的两个顶点
		a[x][y]=1;				//无向图的边对称
		a[y][x]=1;
	}
	dfs(1);						//从顶点1开始搜索
	if (count>0)				//输出结果
		printf("%d\n",count);
	else
		printf("-1\n");
	return 0;
}
