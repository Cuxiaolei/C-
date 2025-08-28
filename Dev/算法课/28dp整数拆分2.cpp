//2.求解整数拆分问题的算法~备忘录方法
//【问题描述】求将正整数n无序拆分成最大数为k（称为n的k拆分）的拆分方案个数，要求所有的拆分方案不重复。

////动态规划的变形~自顶向下的求解（带备忘录方法的递归）
#include <stdio.h>
#include <string.h>

#define MAXN 500

// 动态规划数组，用于存储已经计算过的结果，dp[n][k]表示将正整数n拆分成最大数为k的拆分方案个数
int dp[MAXN][MAXN];

// 递归函数，使用带备忘录的方法计算将正整数n拆分成最大数为k的拆分方案个数
int dpf(int n, int k) {
    // 如果已经计算过dp[n][k]，直接返回结果
    if (dp[n][k] != 0) return dp[n][k];

    // 当n为1或者k为1时，拆分方案只有一种
    if (n == 1 || k == 1) {
        dp[n][k] = 1;
        return dp[n][k];
    } 
    // 当n小于k时，最大拆分数字只能是n，所以等同于将n拆分成最大数为n的情况
    else if (n < k) {
        dp[n][k] = dpf(n, n);
        return dp[n][k];
    } 
    // 当n等于k时，拆分方案数等于不包含k的拆分方案数加上包含一个k的拆分方案（即1种）
    else if (n == k) {
        dp[n][k] = dpf(n, k - 1) + 1;
        return dp[n][k];
    } 
    // 当n大于k时，拆分方案数等于不包含k的拆分方案数加上包含至少一个k的拆分方案
    else {
        dp[n][k] = dpf(n, k - 1) + dpf(n - k, k);
        return dp[n][k];
    }
}

int main() {
    int n = 5, k = 5;
    // 将动态规划数组初始化为0
    memset(dp, 0, sizeof(dp));
    // 调用dpf函数计算并输出结果
    printf("dpf(%d,%d)=%d\n", n, k, dpf(n, k));

    return 0;
}
