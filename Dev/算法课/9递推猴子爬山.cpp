//3. ������ɽ
// ������ɽn����һ����1����3��̨��
#include <stdio.h>

int main() {
    int k, n;
    long f[1000];

    printf("������̨������n:");
    scanf("%d", &n);

    f[1] = 1;
    f[2] = 1;
    f[3] = 2;  // ȷ�����Ƴ�ʼ����

//    for (k = 4; k <= n; k++) {
//        f[k] = f[k - 1] + f[k - 3];  // �����ƹ�ϵʵʩ����
//    }
	
	for(int k = 4; k <= n; k++){
		f[k] = f[k - 1] + f[k - 3];
	}
    printf("s=%ld", f[n]);

    return 0;
}
