//3. ������
//��b��������aȥ��һ�����ֺ�������������ڸ�����������n��Ѱ�������ʽa+b=n��������������a,b����

#include <stdio.h>

int main() {
    long a, b, d, n, t, k;

    printf("  ����������n: ");
    scanf("%ld", &n);

    k = 0;
    for (a = n / 2; a <= n - 1; a++) {
        b = n - a;
        t = 1;
        // Ӧ��t����ȥ����ѭ������
        while (a > t) {
            // dΪa��һ��ȥ������
            d = a / (t * 10) * t + a % t;
            if (d == b) {
                k++;
                printf(" (%ld,%ld)", a, b);
                break;
            }
            t = t * 10;
        }
    }
    printf("\n   %ld��������%ld����\n", n, k);
    return 0;
}
