//1.求解整数拆分问题的算法~递推式
//【问题描述】求将正整数n无序拆分成最大数为k（称为n的k拆分）的拆分方案个数，要求所有的拆分方案不重复。

//动态规划自底向上的求解
#include <stdio.h>

// 定义最大的正整数和拆分最大数，用于数组大小
#define MAXN 500

// 动态规划数组，dp[i][j] 表示将正整数 i 拆分成最大数为 j 的拆分方案个数
int dp[MAXN][MAXN];

//// 求解将正整数 n 拆分成最大数为 k 的拆分方案个数的函数
//void Split(int n, int k) {
//    // 外层循环遍历正整数 1 到 n
//    for (int i = 1; i <= n; i++) {
//        // 内层循环遍历最大拆分数字 1 到 k
//        for (int j = 1; j <= k; j++) {
//            // 当 i 为 1 或者 j 为 1 时，拆分方案只有一种
//            if (i == 1 || j == 1) {
//                dp[i][j] = 1;
//            } 
//            // 当 i 小于 j 时，最大拆分数字只能是 i，所以等同于将 i 拆分成最大数为 i 的情况
//            else if (i < j) {
//                dp[i][j] = dp[i][i];
//            } 
//            // 当 i 等于 j 时，拆分方案数等于不包含 j 的拆分方案数加上包含一个 j 的拆分方案（即 1 种）
//            else if (i == j) {
//                dp[i][j] = dp[i][j - 1] + 1;
//            } 
//            // 当 i 大于 j 时，拆分方案数等于不包含 j 的拆分方案数加上包含至少一个 j 的拆分方案
//            else {
//                dp[i][j] = dp[i][j - 1] + dp[i - j][j];
//            }
//        }
//    }
//}

void Split(int n, int k){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++){
			if(i == 1 || j == 1){
				dp[i][j] = 1;
			}
			else if(i < j){
				dp[i][j] = dp[i][i];
			}
			else if(i == j){
				dp[i][j] = dp[i][j - 1] + 1;
			}else{
				dp[i][j] = dp[i][j - 1] + dp[i - j][j];
			}
		}
	}
}

int main() {
    // 定义要拆分的正整数 n 和最大拆分数字 k
    int n = 5, k = 5;
    // 调用 Split 函数计算拆分方案个数
    Split(n, k);
    // 输出结果
    printf("(%d,%d)=%d\n", n, k, dp[n][k]);

    return 0;
}
