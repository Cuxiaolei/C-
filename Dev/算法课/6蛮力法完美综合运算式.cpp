//思考题：完美综合运算式 
#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c, d, e, f, k, t, m, n, x, z, g[10];
    n = 0;
    printf("  请输入式右非负数字f:");
    scanf("%d", &f);

    for (a = 2; a <= 9; a++) {
        for (b = 2; b <= 9; b++) {
            for (c = 2; c <= 9; c++) {
                for (d = 102; d <= 987; d++) {  // 实施枚举
                    for (e = 2; e <= 9; e++) {
                        for (t = 1, k = 1; k <= b; k++) {  // 计算乘方a^b
                            t = t * a;
                        }
                        z = (d * e + f - t) * c;
                        if (z < 10 || z > 98) {
                            continue;
                        }
                        for (x = 0; x <= 9; x++) {
                            g[x] = 0;
                        }
                        g[a]++;
                        g[b]++;
                        g[c]++;
                        g[e]++;
                        g[f]++;  // g数组统计
                        g[d % 10]++;
                        g[d / 100]++;
                        m = (d / 10) % 10;
                        g[m]++;
                        g[z % 10]++;
                        g[z / 10]++;
                        for (t = 0, x = 0; x <= 9; x++) {
                            if (g[x] != 1) {
                                t = 1;
                                break;
                            }
                        }
                        if (t == 0) {
                            n++;  // 统计并输出一个解
                            printf("%2d: %d^%d+%d/%d", n, a, b, z, c);
                            printf("-%d*%d=%d  \n", d, e, f);
                        }
                    }
                }
            }
        }
    }
    if (n == 0) {
        printf("No perfect expression.\n");
    }
    return 0;
}
