//5. 求解0/1背包问题(掌握左剪枝)
//【问题描述】有n个重量分别为{w1，w2，…，wn}的物品，它们的价值分别为{v1，v2，…，vn}，给定一个容量为W的背包。
//    设计从这些物品中选取一部分物品放入该背包的方案，每个物品要么选中要么不选中，要求选中的物品不仅能够放到背包中，而且满足重量限制具有最大的价值。

#include <stdio.h>

#define MAXN 20  // 最多物品数

// 问题表示
int n = 4;      // 4种物品
int W = 6;      // 限制重量为6
int w[] = {0, 5, 3, 2, 1};  // 存放4个物品重量，不用下标0元素
int v[] = {0, 4, 4, 3, 1};  // 存放4个物品价值，不用下标0元素

// 求解结果表示
int x[MAXN];    // 存放最终解
int maxv;       // 存放最优解的总价值

//// 考虑第i个物品
//void dfs(int i, int tw, int tv, int op[]) {
//    if (i > n) {  // 找到一个叶子结点
//        if (tv > maxv) {  // 找到一个满足条件的更优解，保存它
//            maxv = tv;
//            for (int j = 1; j <= n; j++) {
//                x[j] = op[j];
//            }
//        }
//    } else {  // 尚未找完所有物品
//        for (int j = 1; j >= 0; j--) {
//            op[i] = j;
//            if (tw + w[i] * j <= W) {
//                dfs(i + 1, tw + w[i] * op[i], tv + v[i] * op[i], op);
//            }
//        }
//    }
//}

void dfs(int i, int tw, int tv, int op[]){
	if(i > n){
		if(tv > maxv){
			maxv = tv;
			for(int j = 1; j <= n; j++)
			{
				x[j] = op[j];
			}
		}
	}else{
		for(int j = 1; j >= 0; j--){
			op[i] = j;
			if(tw + w[i] * j <= W){
				dfs(i + 1, tw + w[i] * op[i], tv + v[i] * op[i], op);
			} 
		}
	}
}

// 输出最优解
void dispasolution() {
    int i;
    printf("最佳装填方案是:\n");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("  选取第%d个物品\n", i);
        }
    }
    printf("总重量=%d,总价值=%d\n", W, maxv);
}

int main() {
    int op[MAXN];  // 存放临时解
    dfs(1, 0, 0, op);
    dispasolution();
    return 0;
}
