//5. 常规排队-递归和递推
//一场球赛开始前，售票工作正在紧张进行中。每张球票为50元，有m+n个人排队等待购票，其中有m 个人手持50元的钞票，另外n个人手持100元的钞票。求出这m+n个人排队购票，使售票处不至出现找不开钱的局面的不同排队种数 。（约定：开始售票时售票处没有零钱，拿同样面值钞票的人对换位置为同一种排队。）
//
//方法一：递归实现购票排队
#include <stdio.h>

//long f(int j, int i) {
//    long y;
//    if (i == 0) {
//        y = 1;
//    } else if (j < i) {
//        y = 0;  // 确定初始条件
//    } else {
//        y = f(j - 1, i) + f(j, i - 1);  // 实施递归
//    }
//    return y;
//}

long f(int m, int n)
{
	long y;
	if(n == 0){
		y = 1;
	}else if(m < y)
	{
		y = 0;
	}else{
		y = f(m - 1, n) + f(m, n - 1);
	}
	return y;
}


int main() {  // 主函数调用
    int m, n;
    printf(" input m,n: ");
    scanf("%d,%d", &m, &n);
    printf("  f(%d,%d)=%ld\n", m, n, f(m, n));
    return 0;
}
