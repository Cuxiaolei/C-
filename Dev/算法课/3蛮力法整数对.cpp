//3. 整数对
//设b是正整数a去掉一个数字后的正整数，对于给出的正整数n，寻求满足和式a+b=n的所有正整数对a,b。　

#include <stdio.h>

int main() {
    long a, b, d, n, t, k;

    printf("  请输入整数n: ");
    scanf("%ld", &n);

    k = 0;
    for (a = n / 2; a <= n - 1; a++) {
        b = n - a;
        t = 1;
        // 应用t控制去数字循环次数
        while (a > t) {
            // d为a的一个去数字数
            d = a / (t * 10) * t + a % t;
            if (d == b) {
                k++;
                printf(" (%ld,%ld)", a, b);
                break;
            }
            t = t * 10;
        }
    }
    printf("\n   %ld共有以上%ld个解\n", n, k);
    return 0;
}
