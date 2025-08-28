//5. 求解三角形最小路径问题
//给定高度为n的一个整数三角形，找出从顶部到底部的最小路径和，只能向先移动相邻的结点。首先输入n，接下来的1～n行，第i行输入i个整数，输出分为2行，第一行为最小路径，第2行为最小路径和。
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

#define MAXN 100

// 问题表示
int a[MAXN][MAXN];
int n;

// 求解结果表示
int ans = 0;
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

// 求最小和路径ans
int Search() {
    int i, j;
    // 初始化顶部元素的路径和
    dp[0][0] = a[0][0];

    // 处理第1列的边界情况
    for (i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        pre[i][0] = i - 1;
    }

    // 处理对角线的边界情况
    for (i = 1; i < n; i++) {
        dp[i][i] = a[i][i] + dp[i - 1][i - 1];
        pre[i][i] = i - 1;
    }

    // 处理其他有两条到达路径的结点
    for (i = 2; i < n; i++) {
        for (j = 1; j < i; j++) {
            if (dp[i - 1][j - 1] < dp[i - 1][j]) {
                pre[i][j] = j - 1;
                dp[i][j] = a[i][j] + dp[i - 1][j - 1];
            } else {
                pre[i][j] = j;
                dp[i][j] = a[i][j] + dp[i - 1][j];
            }
        }
    }

    // 初始化最小路径和为最后一行第1列的值
    ans = dp[n - 1][0];
    int k = 0;

    // 遍历最后一行，找到最小路径和及其对应的列号
    for (j = 1; j < n; j++) {
        if (ans > dp[n - 1][j]) {
            ans = dp[n - 1][j];
            k = j;
        }
    }

    return k;
}

// 输出最小和路径
void Disppath(int k) {
    int i = n - 1;
    vector<int> path; // 存放逆路径向量path

    // 从（n-1,k）结点反推求出反向路径
    while (i >= 0) {
        path.push_back(a[i][k]);
        k = pre[i][k]; // 最小路径在前一行中的列号
        i--; // 在前一行查找
    }

    vector<int>::reverse_iterator it; // 定义反向迭代器

    // 反向输出构成正向路径
    for (it = path.rbegin(); it != path.rend(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");
}

int main() {
    int k;
    // 初始化pre和dp数组为0
    memset(pre, 0, sizeof(pre));
    memset(dp, 0, sizeof(dp));

    // 输入三角形的高度
    scanf("%d", &n);

    // 输入三角形的元素
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    k = Search(); // 求最小路径和
    Disppath(k); // 输出正向路径
    printf("%d\n", ans); // 输出最小路径和

    return 0;
}
