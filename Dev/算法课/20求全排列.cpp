//2 求所有全排列~解空间为排列树
//有一个含n个整数的数组a，所有元素均不相同，求其所有元素的全排列。

#include <stdio.h>

// 交换x、y
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// 输出一个解
void dispasolution(int a[], int n) {
    printf("  (");
    for (int i = 0; i < n - 1; i++) {
        printf("%d,", a[i]);
    }
    printf("%d)", a[n - 1]);
}

//// 求a[0..n-1]的全排列
//void dfs(int a[], int n, int i) {
//    if (i >= n) {  // 递归出口
//        dispasolution(a, n);
//    } else {
//        for (int j = i; j < n; j++) {
//            swap(&a[i], &a[j]);  // 交换a[i]与a[j]
//            dfs(a, n, i + 1);
//            swap(&a[i], &a[j]);  // 交换a[i]与a[j]：恢复
//        }
//    }
//}

void dfs(int a[], int n, int i)
{
	if(i >= n) dispasolution(a, n);
	else{
		for(int j = i; j < n; j++){
			swap(&a[i], &a[j]);
			dfs(a, n, i+1);
			swap(&a[i], &a[j]);
		}
	}
}

int main() {
    int a[] = {1, 2, 3};
    int n = 3;
    printf("a的全排列\n");
    dfs(a, n, 0);
    printf("\n");
    return 0;
}

