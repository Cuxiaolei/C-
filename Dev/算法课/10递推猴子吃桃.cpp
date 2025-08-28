//4.猴子吃桃
#include<stdio.h>
int main() {
    int i;
    int a[11] = {0};
    a[10] = 1;

    for (i = 9; i >= 1; i--) {
        a[i] = 2 * (a[i + 1] + 1);
    }

    printf("第10天吃了%d个桃子!\n", a[i + 1]);
    return 0;
}
