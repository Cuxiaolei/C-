//4. 求解编辑距离问题
//设A和B是两个字符串。现在要用最少的字符操作次数，将字符串A转换为字符串B。这里所说的字符操作共有3种：
//    （1）删除一个字符。
//    （2）插入一个字符。
//    （3）将一个字符替换另一个字符。
//例如，A=“sfdqxbw”，B=“gfdgw”，结果为4。

#include <iostream>
#include <string>
using namespace std;

// 定义宏用于求两个数中的最小值
#define min(x, y) ((x) < (y)? (x) : (y))
// 定义最大长度
#define MAX 201

// 问题表示
string a = "sfdqxbw";
string b = "gfdgw";

// 求解结果表示
int dp[MAX][MAX];

// 求dp数组，计算编辑距离
//void solve() {
//    int i, j;
//    // 把a的i个字符全部删除转换为b
//    for (i = 1; i <= a.length(); i++) {
//        dp[i][0] = i;
//    }
//    // 在a中插入b的全部字符转换为b
//    for (j = 1; j <= b.length(); j++) {
//        dp[0][j] = j;
//    }
//    // 填充dp数组
//    for (i = 1; i <= a.length(); i++) {
//        for (j = 1; j <= b.length(); j++) {
//            if (a[i - 1] == b[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            } else {
//                // 取删除、插入、替换三种操作的最小值加1
//                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
//            }
//        }
//    }
//}

void solve()
{
	for(int i = 1; i <= a.length(); i++){
		dp[i][0] = i;
	}
	for(int j = 1; j <= b.length(); j++){
		dp[0][j] = j;
	}
	for(int i = 1; i <= a.length(); i++)
	{
		for(int j = 1; j <= b.length(); j++)
		{
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
}



int main() {
    solve();
    cout << "求解结果" << endl;
    cout << "    最少的字符操作次数: " << dp[a.length()][b.length()] << endl;
    return 0;
}
