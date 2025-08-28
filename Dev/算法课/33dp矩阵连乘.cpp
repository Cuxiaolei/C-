//6. 矩阵连乘问题
//给定n个矩阵｛A1,A2,…,An｝，其中Ai与Ai+1是可乘的，i=1 ,…,n-1。如何确定计算矩阵连乘积的次序，使得依此次序计算矩阵连乘积需要的数乘次数最少。
#include <iostream>
using namespace std;

// 矩阵维度数组，p[i-1] 和 p[i] 分别表示矩阵 Ai 的行数和列数
int p[] = {30, 35, 15, 5, 10, 20, 25};
// m[i][j] 表示矩阵 Ai 到 Aj 连乘的最少乘法次数
// s[i][j] 记录矩阵 Ai 到 Aj 连乘时最优分割点的位置
static int m[7][7], s[7][7];

// 矩阵链乘法问题的动态规划求解函数
void matrixchain(int *p, int n) {
    // 单个矩阵的乘法次数为 0
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    // r 表示矩阵链的长度，从 2 到 n
    for (int r = 2; r <= n; r++) {
        // 遍历所有可能的矩阵链起始位置 i
        for (int i = 1; i <= n - r + 1; i++) {
            // 计算矩阵链的结束位置 j
            int j = i + r - 1;
            // 初始化 m[i][j] 为一种分割方式下的乘法次数
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            // 记录当前分割点
            s[i][j] = i;
            // 尝试所有可能的分割点 k
            for (int k = i + 1; k < j; k++) {
                // 计算以 k 为分割点时的乘法次数
                int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                // 如果新的分割方式乘法次数更少，则更新 m[i][j] 和 s[i][j]
                if (t < m[i][j]) {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}

// 回溯函数，用于输出矩阵链的最优计算次序
void traceback(int i, int j) {
    // 当 i 等于 j 时，只有一个矩阵，无需继续分割
    if (i == j) {
        return;
    }
    // 递归处理左半部分矩阵链
    traceback(i, s[i][j]);
    // 递归处理右半部分矩阵链
    traceback(s[i][j] + 1, j);
    // 输出当前分割的两个矩阵链的范围
    cout << "multiply A(" << i << "," << s[i][j] << ")";
    cout << " and A(" << (s[i][j] + 1) << "," << j << ")" << endl;
}

int main() {
    // 调用 matrixchain 函数计算最少乘法次数和最优分割点
    matrixchain(p, 6);
    // 输出矩阵 A1 到 A6 连乘的最少乘法次数
    cout << "The least times of multiplication is:" << m[1][6] << endl;
    // 调用 traceback 函数输出最优计算次序
    traceback(1, 6);
    return 0;
}

