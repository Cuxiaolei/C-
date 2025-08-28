//6. n皇后问题
//在n×n格的棋盘上放置彼此不受攻击的n个皇后。按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。n皇后问题等价于在n×n格的棋盘上放置n个皇后，任何2个皇后不能放在同一行或同一列或同一斜线上。求有多少种摆放方式，每种方式的具体摆法？

#include <stdio.h>
#include <stdlib.h>
#define N 20  // 最多皇后个数

int q[N];  // 存放各皇后所在的列号,即(i,q[i])为一个皇后位置
int count = 0;  // 累计解个数

// 输出n皇后问题的一个解
void dispasolution(int n) {
    printf("    第%d个解：", ++count);
    for (int i = 1; i <= n; i++) {
        printf("(%d,%d) ", i, q[i]);
    }
    printf("\n");
}

// 测试(i,j)位置能否摆放皇后
bool place(int i, int j) {
    if (i == 1) return true;  // 第一个皇后总是可以放置
    int k = 1;
    while (k < i) {  // k=1～i-1是已放置了皇后的行
        if ((q[k] == j) || (abs(q[k] - j) == abs(i - k))) {
            return false;
        }
        k++;
    }
    return true;
}

//// 放置1～i的皇后
//void queen(int i, int n) {
//    if (i > n) {
//        dispasolution(n);  // 所有皇后放置结束
//    } else {
//        for (int j = 1; j <= n; j++) {  // 在第i行上试探每一个列j
//            if (place(i, j)) {  // 在第i行上找到一个合适位置(i,j)
//                q[i] = j;
//                queen(i + 1, n);
//            }
//        }
//    }
//}

void queen(int i, int n){
	if(i > n){
		dispasolution(n);
	}
	else{
		for(int j = 1; j <= n; j++)
		{
			if(place(i, j)){
				q[i] = j;
				queen(i + 1, n);
			}
		}
	}
}

int main() {
    int n;  // n为存放实际皇后个数
    printf(" 皇后问题(n<20) n=");
    scanf("%d", &n);
    if (n > 20) {
        printf("n值太大,不能求解\n");
    } else {
        printf("%d皇后问题求解如下：\n", n);
        queen(1, n);  // 放置1～i的皇后
    }
    return 0;
}
