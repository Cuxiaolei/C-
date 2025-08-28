//6. n�ʺ�����
//��n��n��������Ϸ��ñ˴˲��ܹ�����n���ʺ󡣰��չ�������Ĺ��򣬻ʺ���Թ�����֮����ͬһ�л�ͬһ�л�ͬһб���ϵ����ӡ�n�ʺ�����ȼ�����n��n��������Ϸ���n���ʺ��κ�2���ʺ��ܷ���ͬһ�л�ͬһ�л�ͬһб���ϡ����ж����ְڷŷ�ʽ��ÿ�ַ�ʽ�ľ���ڷ���

#include <stdio.h>
#include <stdlib.h>
#define N 20  // ���ʺ����

int q[N];  // ��Ÿ��ʺ����ڵ��к�,��(i,q[i])Ϊһ���ʺ�λ��
int count = 0;  // �ۼƽ����

// ���n�ʺ������һ����
void dispasolution(int n) {
    printf("    ��%d���⣺", ++count);
    for (int i = 1; i <= n; i++) {
        printf("(%d,%d) ", i, q[i]);
    }
    printf("\n");
}

// ����(i,j)λ���ܷ�ڷŻʺ�
bool place(int i, int j) {
    if (i == 1) return true;  // ��һ���ʺ����ǿ��Է���
    int k = 1;
    while (k < i) {  // k=1��i-1���ѷ����˻ʺ����
        if ((q[k] == j) || (abs(q[k] - j) == abs(i - k))) {
            return false;
        }
        k++;
    }
    return true;
}

//// ����1��i�Ļʺ�
//void queen(int i, int n) {
//    if (i > n) {
//        dispasolution(n);  // ���лʺ���ý���
//    } else {
//        for (int j = 1; j <= n; j++) {  // �ڵ�i������̽ÿһ����j
//            if (place(i, j)) {  // �ڵ�i�����ҵ�һ������λ��(i,j)
//                q[i] = j;
//                queen(i + 1, n);
//            }
//        }
//    }
//}

void queen(int i, int n){
	if(i > n){
		dispasolution(n);
	}
	else{
		for(int j = 1; j <= n; j++)
		{
			if(place(i, j)){
				q[i] = j;
				queen(i + 1, n);
			}
		}
	}
}

int main() {
    int n;  // nΪ���ʵ�ʻʺ����
    printf(" �ʺ�����(n<20) n=");
    scanf("%d", &n);
    if (n > 20) {
        printf("nֵ̫��,�������\n");
    } else {
        printf("%d�ʺ�����������£�\n", n);
        queen(1, n);  // ����1��i�Ļʺ�
    }
    return 0;
}
