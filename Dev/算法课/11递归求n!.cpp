#include <stdio.h>

long f(int x) {
    long g;
    if (x <= 0) {
        printf("x<=0, �������");
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
    y = f(n);  // ���ú���f(n)
    printf("  %d!=%ld \n", n, y);
    return 0;
}
