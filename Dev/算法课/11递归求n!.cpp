#include <stdio.h>

long f(int x) {
    long g;
    if (x <= 0) {
        printf("x<=0, 输入错误！");
    } else if (x == 1) {
        g = 1;
    } else {
        g = x * f(x - 1);
    }
    return g;
}

int main() {
    int n;
    long y;
    scanf("%d", &n);
    y = f(n);  // 调用函数f(n)
    printf("  %d!=%ld \n", n, y);
    return 0;
}
