//ì³²¨ÄÉÆõÊıÁĞ
#include<stdio.h>
int main() {
    int i, n, f[3000];

    printf("please input n:");
    scanf("%d", &n);

	f[0] = 1;
    f[1] = 1;
    f[2] = 2;

    for (i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }

    printf("%d\n", f[n - 1]);
    return 0;
}


