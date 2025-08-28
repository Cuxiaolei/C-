5. ���0/1��������
//����n����Ʒ��һ������������������ΪW ������Ʒi��������wi�����ֵΪvi��ÿ����ƷҪô����װ�뱳����Ҫô��װ�����ܲ�װ����Ӧ���ѡ��װ�뱳������Ʒ��ʹ��װ�뱳���е���Ʒ��������������W���ܼ�ֵ���?

//�������ֵ�����Ž�
#include <stdio.h>

// ����꣬���ڻ�ȡ�������еĽϴ�ֵ
#define max(x, y) ((x) > (y)? (x) : (y))
// ���������Ʒ��
#define MAXN 20
// ���������������
#define MAXW 100

// �����ʾ
int n = 5, W = 10;  // 5����Ʒ����������������10
int w[MAXN] = {0, 2, 2, 6, 5, 4};  // �±�0����
int v[MAXN] = {0, 6, 3, 5, 4, 6};  // �±�0����

// �������ʾ
int dp[MAXN][MAXW];
int x[MAXN];
int maxv;  // ������Ž���ܼ�ֵ

// ��̬�滮����0/1��������
//void Knap() {
//    int i, r;
//    // �ñ߽�����dp[i][0]=0
//    for (i = 0; i <= n; i++) {
//        dp[i][0] = 0;
//    }
//    // �ñ߽�����dp[0][r]=0
//    for (r = 0; r <= W; r++) {
//        dp[0][r] = 0;
//    }
//    // ���dp����
//    for (i = 1; i <= n; i++) {
//        for (r = 1; r <= W; r++) {
//            if (r < w[i]) {
//                dp[i][r] = dp[i - 1][r];
//            } else {
//                dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
//            }
//        }
//    }
//}

void Knap(){
	for(int i = 1; i <= n; i++)
	{
		for(int r = 1; r <= W;r++)
		{
			if(r < w[i]){
				dp[i][r] = dp[i - 1][r];
			}else{
				dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
			}
		}
	}
}

// ���������Ž�
void Buildx() {
    int i = n, r = W;
    maxv = 0;
    // �ж�ÿ����Ʒ
    while (i >= 0) {
        if (dp[i][r] != dp[i - 1][r]) {
            x[i] = 1;  // ѡȡ��Ʒi
            maxv += v[i];  // �ۼ��ܼ�ֵ
            r = r - w[i];
        } else {
            x[i] = 0;  // ��ѡȡ��Ʒi
        }
        i--;
    }
}

int main() {
    Knap();
    Buildx();
    printf("�����(���ŷ���)\n");  // ������
    printf("    ѡȡ����Ʒ: ");
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("    �ܼ�ֵ=%d\n", maxv);
    return 0;
}

