//4.���ӳ���
#include<stdio.h>
int main() {
    int i;
    int a[11] = {0};
    a[10] = 1;

    for (i = 9; i >= 1; i--) {
        a[i] = 2 * (a[i + 1] + 1);
    }

    printf("��10�����%d������!\n", a[i + 1]);
    return 0;
}
