//��ŵ����Ϸ�������ŵ���ľ����ƶ����̡�
#include <stdio.h>

double g(int m) {
    double s;
    if (m == 1) {
        s = 1;
    } else {
        s = 2 * g(m - 1) + 1;
    }
    return s;
}

void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        printf("����Ƭ%d:��%c�ᵽ%c\n", n, x, z);
    } else {
        hanoi(n - 1, x, z, y);
        printf("����Ƭ%d����%c�ᵽ%c\n", n, x, z);
        hanoi(n - 1, y, x, z);
    }
}

int main() {
    int n;
    printf("��������Ƭ��n:");
    scanf("%d", &n);

    if (n <= 40) {
        printf("%d�̵��ƶ�����Ϊ��%.0f\n", n, g(n));
    } else {
        printf("%d�̵��ƶ�����Ϊ��%.4e\n", n, g(n));
    }

    hanoi(n, 'A', 'B', 'C');
    return 0;
}
