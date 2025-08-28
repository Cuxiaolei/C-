//4. 最小连续m个合数
//对于指定的正整数m(1<=m<=200),在正整数中搜索最小的连续m个合数，输出该区间的起始数与终止数。
//例如：m=5，最小连续5个合数为：24~28
//第2种方法：从4开始判断每个数是否为合数
#include <stdio.h>
#include <math.h>

// 判断 i 是否是合数，若是，则返回 1
//int composite(int i) {  // 判断i是否是合数，若是，则返回1 
//    int j;
//    for (j = 2; j <= sqrt(i); j += 1) {
//        if (i % j == 0) {
//            return 1;
//        }
//    }
//    return 0;
//}

int composite(int i)
{
	int j;
	for(int j = 2; j <= sqrt(i); j++)
	{
		if(i % j == 0){
			return 1;
		}
	}
	return 0;
}

int main() {
    long i, j, f, t, m, count = 0;
    printf("  请输入 m:");
    scanf("%ld", &m);
    printf("  最小的连续%ld个合数为:", m);
    i = f = 2;
//    while (1) {
//        if (composite(i) == 1) {
//            count++;
//        } else {
//            count = 0;
//            f = i + 1;
//        }
//        if (count >= m) {
//            printf("%ld,%ld", f, f + m - 1);
//            break;
//        }
//        i++;
//    }
	while(1)
	{
		if(composite(i) == 1)
		{
			count++;
		}else{
			count = 0;
			f = i + 1;
		}
		if(count >= m)
		{
			cout << f << f + m - 1;
			break;
		}
		i++;
	}
    return 0;
}
