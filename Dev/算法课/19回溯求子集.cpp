//1. 求所有子集~解空间为子集树
//有一个含n个整数的数组a，所有元素均不相同，设计一个算法求其所有子集（幂集）。

#include <stdio.h>
#include <string.h>

#define MAXN 100

// 输出一个解
void printResult(int a[], int n, int x[]) {
    printf("   {");
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            printf("%d", a[i]);
        }
    }
    printf("}");
}

//// 回溯算法
//void dfs(int a[], int n, int i, int x[]) {
//    if (i >= n) {
//        printResult(a, n, x);
//    } else {
//        x[i] = 0;
//        dfs(a, n, i + 1, x);  // 不选择a[i]
//        x[i] = 1;
//        dfs(a, n, i + 1, x);  // 选择a[i]
//    }
//}

void dfs(int a[], int n, int i, int x[]){
	if(i >= n)
		printResult(a, n, x);
	else{
		x[i] = 0;
		dfs(a, n, i + 1, x);
		x[i] = 1;
		dfs(a, n, i + 1, x);
	}
}


int main() {
    int a[] = {1, 2, 3};  // s[0..n-1]为给定的字符串,设置为全局变量
    int n = 3;
    int x[MAXN];  // 解向量
    memset(x, 0, sizeof(x));  // 解向量初始化
    printf("求解结果\n");
    dfs(a, n, 0, x);
    printf("\n");
    return 0;
}
