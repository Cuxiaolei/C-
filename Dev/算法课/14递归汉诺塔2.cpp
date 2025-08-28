//汉诺塔游戏：输出汉诺塔的具体移动过程。
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
        printf("将盘片%d:从%c搬到%c\n", n, x, z);
    } else {
        hanoi(n - 1, x, z, y);
        printf("将盘片%d：从%c搬到%c\n", n, x, z);
        hanoi(n - 1, y, x, z);
    }
}

int main() {
    int n;
    printf("请输入盘片数n:");
    scanf("%d", &n);

    if (n <= 40) {
        printf("%d盘的移动次数为：%.0f\n", n, g(n));
    } else {
        printf("%d盘的移动次数为：%.4e\n", n, g(n));
    }

    hanoi(n, 'A', 'B', 'C');
    return 0;
}
