//1.求解可拆背包问题
//【问题描述】设有编号为1、2、…、n的n个物品，它们的重量分别为w1、w2、…、wn，价值分别为v1、v2、…、vn，其中wi、vi（1≤i≤n）均为正数。
//　　有一个背包可以携带的最大重量不超过W。求解目标：在不超过背包负重的前提下，使背包装入的总价值最大（即效益最大化），与0/1背包问题的区别是，这里的每个物品可以取一部分装入背包。

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 51

// 问题表示
int n = 5;
double W = 100;  // 限重

// 物品结构体，包含重量、价值、单位重量价值以及比较函数
struct NodeType {
    double w;
    double v;
    double p;  // p = v / w
    // 重载小于运算符，用于按单位重量价值递减排序
    bool operator<(const NodeType& s) const {
        return p > s.p;
    }
};

// 物品数组，下标0不用
NodeType A[] = { {0}, {10, 20}, {20, 30}, {30, 66}, {40, 40}, {50, 60} };

// 求解结果表示
double V;  // 最大价值
double x[MAXN];

// 求解背包问题并返回总价值
void Knap() {
    V = 0;  // V初始化为0
    double weight = W;  // 背包中能装入的余下重量
    memset(x, 0, sizeof(x));  // 初始化x向量
    int i = 1;
    // 物品i能够全部装入时循环
    while (A[i].w < weight) {
        x[i] = 1;  // 装入物品i
        weight -= A[i].w;  // 减少背包中能装入的余下重量
        V += A[i].v;  // 累计总价值
        i++;  // 继续循环
    }
    // 当余下重量大于0
    if (weight > 0) {
        x[i] = weight / A[i].w;  // 将物品i的一部分装入
        V += x[i] * A[i].v;  // 累计总价值
    }
}

// 输出物品信息，包括重量、价值和单位重量价值
void dispA() {
    int i;
    printf("\tW\tV\tV/W\n");
    for (i = 1; i <= n; i++) {
        printf("\t%g\t%g\t%3.1f\n", A[i].w, A[i].v, A[i].p);
    }
}

int main() {
    printf("求解过程\n");
    // 计算每个物品的单位重量价值
    for (int i = 1; i <= n; i++) {
        A[i].p = A[i].v / A[i].w;
    }
    printf("(1)排序前\n");
    dispA();
    // 对物品按单位重量价值递减排序
    sort(A + 1, A + n + 1);
    printf("(2)排序后:\n");
    dispA();
    Knap();
    printf("(3)求解结果\n");  // 输出结果
    printf("    x: [");
    for (int j = 1; j < n; j++) {
        printf("%g, ", x[j]);
    }
    printf("%g]\n", x[n]);
    printf("    总价值=%g\n", V);
    return 0;
}
