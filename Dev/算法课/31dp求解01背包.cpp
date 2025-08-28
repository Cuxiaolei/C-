5. 求解0/1背包问题
//给定n种物品和一背包，背包的载重量为W 。设物品i的重量是wi，其价值为vi。每件物品要么整体装入背包，要么不装，不能拆开装。问应如何选择装入背包的物品，使得装入背包中的物品的总重量不超过W、总价值最大?

//求出最优值和最优解
#include <stdio.h>

// 定义宏，用于获取两个数中的较大值
#define max(x, y) ((x) > (y)? (x) : (y))
// 定义最多物品数
#define MAXN 20
// 定义最大限制重量
#define MAXW 100

// 问题表示
int n = 5, W = 10;  // 5种物品，限制重量不超过10
int w[MAXN] = {0, 2, 2, 6, 5, 4};  // 下标0不用
int v[MAXN] = {0, 6, 3, 5, 4, 6};  // 下标0不用

// 求解结果表示
int dp[MAXN][MAXW];
int x[MAXN];
int maxv;  // 存放最优解的总价值

// 动态规划法求0/1背包问题
//void Knap() {
//    int i, r;
//    // 置边界条件dp[i][0]=0
//    for (i = 0; i <= n; i++) {
//        dp[i][0] = 0;
//    }
//    // 置边界条件dp[0][r]=0
//    for (r = 0; r <= W; r++) {
//        dp[0][r] = 0;
//    }
//    // 填充dp数组
//    for (i = 1; i <= n; i++) {
//        for (r = 1; r <= W; r++) {
//            if (r < w[i]) {
//                dp[i][r] = dp[i - 1][r];
//            } else {
//                dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
//            }
//        }
//    }
//}

void Knap(){
	for(int i = 1; i <= n; i++)
	{
		for(int r = 1; r <= W;r++)
		{
			if(r < w[i]){
				dp[i][r] = dp[i - 1][r];
			}else{
				dp[i][r] = max(dp[i - 1][r], dp[i - 1][r - w[i]] + v[i]);
			}
		}
	}
}

// 回推求最优解
void Buildx() {
    int i = n, r = W;
    maxv = 0;
    // 判断每个物品
    while (i >= 0) {
        if (dp[i][r] != dp[i - 1][r]) {
            x[i] = 1;  // 选取物品i
            maxv += v[i];  // 累计总价值
            r = r - w[i];
        } else {
            x[i] = 0;  // 不选取物品i
        }
        i--;
    }
}

int main() {
    Knap();
    Buildx();
    printf("求解结果(最优方案)\n");  // 输出结果
    printf("    选取的物品: ");
    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("    总价值=%d\n", maxv);
    return 0;
}

