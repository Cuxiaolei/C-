//2.求解田忌赛马问题
//【问题描述】二千多年前的战国时期，齐威王与大将田忌赛马。双方约定每人各出300匹马，并且在上、中、下三个等级中各选一匹进行比赛，由于齐威王每个等级的马都比田忌的马略强，比赛的结果可想而知。现在双方各n匹马，依次派出一匹马进行比赛，每一轮获胜的一方将从输的一方得到200银币，平局则不用出钱，田忌已知所有马的速度值并可以安排出场顺序，问他如何安排比赛获得的银币最多。
//    输入：输入包含多个测试用例，每个测试用例的第一行正整数n（n≤1000）马的数量，后两行分别是n个整数，表示田忌和齐威王的马的速度值。输入n=0结束。
//    输出：每个测试用例输出一行，表示田忌获得的最多银币数。
//
//输入样例：
//3
//92 83 71
//95 87 74
//2
//20 20
//20 20
//2
//20 19
//22 18
//0
//样例输出：
//200
//0
//0
//

#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 1001

// 问题表示
int n;
int a[MAX];  // 存储田忌的马的速度值
int b[MAX];  // 存储齐威王的马的速度值

// 求解结果表示
int ans;

// 求解算法
void solve() {
    // 对田忌的马的速度值进行递增排序
    sort(a, a + n);
    // 对齐威王的马的速度值进行递增排序
    sort(b, b + n);

    ans = 0;
    int lefta = 0, leftb = 0;
    int righta = n - 1, rightb = n - 1;

    // 比赛直到结束
    while (lefta <= righta) {
        // 田忌最快的马比齐威王最快的马快，两者比赛
        if (a[righta] > b[rightb]) {
            ans += 200;
            righta--;
            rightb--;
        } 
        // 田忌最快的马比齐威王最快的马慢，选择田忌最慢的马与齐威王最快的马比赛
        else if (a[righta] < b[rightb]) {
            ans -= 200;
            lefta++;
            rightb--;
        } 
        // 田忌最快的马与齐威王最快的马的速度相同
        else {
            // 田忌最慢的马比齐威王最慢的马快
            if (a[lefta] > b[leftb]) {
                ans += 200;
                lefta++;
                leftb++;
            } 
            else {
                // 用田忌最慢的马与齐威王最快的马比赛
                if (a[lefta] < b[rightb]) {
                    ans -= 200;
                }
                lefta++;
                rightb--;
            }
        }
    }
}

int main() {
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[j]);
        }
        solve();
        printf("%d\n", ans);
    }
    return 0;
}
