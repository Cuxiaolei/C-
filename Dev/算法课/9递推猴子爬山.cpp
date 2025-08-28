//3. 猴子爬山
// 猴子爬山n级，一步跨1级或3级台阶
#include <stdio.h>

int main() {
    int k, n;
    long f[1000];

    printf("请输入台阶总数n:");
    scanf("%d", &n);

    f[1] = 1;
    f[2] = 1;
    f[3] = 2;  // 确定递推初始条件

//    for (k = 4; k <= n; k++) {
//        f[k] = f[k - 1] + f[k - 3];  // 按递推关系实施递推
//    }
	
	for(int k = 4; k <= n; k++){
		f[k] = f[k - 1] + f[k - 3];
	}
    printf("s=%ld", f[n]);

    return 0;
}
