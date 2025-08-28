//2 ������ȫ����~��ռ�Ϊ������
//��һ����n������������a������Ԫ�ؾ�����ͬ����������Ԫ�ص�ȫ���С�

#include <stdio.h>

// ����x��y
void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// ���һ����
void dispasolution(int a[], int n) {
    printf("  (");
    for (int i = 0; i < n - 1; i++) {
        printf("%d,", a[i]);
    }
    printf("%d)", a[n - 1]);
}

//// ��a[0..n-1]��ȫ����
//void dfs(int a[], int n, int i) {
//    if (i >= n) {  // �ݹ����
//        dispasolution(a, n);
//    } else {
//        for (int j = i; j < n; j++) {
//            swap(&a[i], &a[j]);  // ����a[i]��a[j]
//            dfs(a, n, i + 1);
//            swap(&a[i], &a[j]);  // ����a[i]��a[j]���ָ�
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
    printf("a��ȫ����\n");
    dfs(a, n, 0);
    printf("\n");
    return 0;
}

