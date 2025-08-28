//3. 汉诺塔游戏-递归和递推
//（1）有三根桩子A、B、C。A桩上有n个圆盘，最大的一个圆盘在底下，其余圆盘一个比一个小，依次叠上去。
//（2）每次只移动一块圆盘，规定小盘的只能叠放在大盘的上面，而大盘不能叠放在小盘的上面。  
//（3）目标是把所有n个圆盘从A桩全部移到C桩上，如图4-4所示。
//试求解n个圆盘从A桩全部移到C桩上的移动次数。
//
//方法一：递归实现
#include <stdio.h>

//double g(int m) {
//    double s;
//    if (m == 1) {
//        s = 1;
//    } else {
//        s = 2 * g(m - 1) + 1;
//    }
//    return s;
//}

double g(int m)
{
	double s;
	if(m == 1){
		s = 1;
	}else{
		s = 2 * g(m - 1) + 1;
	}
	return s;
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
    return 0;
}
