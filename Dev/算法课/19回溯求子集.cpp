//1. �������Ӽ�~��ռ�Ϊ�Ӽ���
//��һ����n������������a������Ԫ�ؾ�����ͬ�����һ���㷨���������Ӽ����ݼ�����

#include <stdio.h>
#include <string.h>

#define MAXN 100

// ���һ����
void printResult(int a[], int n, int x[]) {
    printf("   {");
    for (int i = 0; i < n; i++) {
        if (x[i] == 1) {
            printf("%d", a[i]);
        }
    }
    printf("}");
}

//// �����㷨
//void dfs(int a[], int n, int i, int x[]) {
//    if (i >= n) {
//        printResult(a, n, x);
//    } else {
//        x[i] = 0;
//        dfs(a, n, i + 1, x);  // ��ѡ��a[i]
//        x[i] = 1;
//        dfs(a, n, i + 1, x);  // ѡ��a[i]
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
    int a[] = {1, 2, 3};  // s[0..n-1]Ϊ�������ַ���,����Ϊȫ�ֱ���
    int n = 3;
    int x[MAXN];  // ������
    memset(x, 0, sizeof(x));  // ��������ʼ��
    printf("�����\n");
    dfs(a, n, 0, x);
    printf("\n");
    return 0;
}
