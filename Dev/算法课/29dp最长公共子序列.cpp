//3.求解最长公共子序列问题
//【问题描述】字符序列的子序列是指从给定字符序列中随意地（不一定连续）去掉若干个字符（可能一个也不去掉）后所形成的字符序列。给定两个字符序列A和B，如果字符序列Z既是A的子序列，又是B的子序列，则称序列Z是A和B的公共子序列。该问题是求两序列A和B的最长公共子序列（LCS）。

#include <iostream>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

// 定义宏，用于获取两个数中的较大值
#define max(x, y) ((x) > (y)? (x) : (y))
// 定义序列中最多的字符个数
#define MAX 51

// 问题表示
int m, n;
string a, b;

// 求解结果表示
int dp[MAX][MAX];  // 动态规划数组
vector<char> subs; // 存放最长公共子序列（LCS）

//// 计算最长公共子序列的长度，并填充动态规划数组dp
//void LCSlength() {
//    int i, j;
//    // 将dp[i][0]置为0，处理边界条件
//    for (i = 0; i <= m; i++) {
//        dp[i][0] = 0;
//    }
//    // 将dp[0][j]置为0，处理边界条件
//    for (j = 0; j <= n; j++) {
//        dp[0][j] = 0;
//    }
//    // 两重for循环处理字符串a和b的所有字符
//    for (i = 1; i <= m; i++) {
//        for (j = 1; j <= n; j++) {
//            // 情况(1)：如果a[i-1]和b[j-1]相等
//            if (a[i - 1] == b[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            } 
//            // 情况(2)：如果a[i-1]和b[j-1]不相等
//            else {
//                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//            }
//        }
//    }
//}

void LCSlength(){
	for(int i = 0; i <= m; i++){
		dp[i][0] = 0;
	}
	for(int j = 0; j <= n; j++){
		dp[0][j] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
}


// 根据动态规划数组dp构造最长公共子序列subs
void Buildsubs() {
    int k = dp[m][n]; // k为a和b的最长公共子序列长度
    int i = m;
    int j = n;
    // 在subs中放入最长公共子序列（反向）
    while (k > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } 
        else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } 
        else {
            subs.push_back(a[i - 1]); // subs中添加a[i-1]
            i--; 
            j--; 
            k--;
        }
    }
}

int main() {
    a = "abcbdb";
    b = "acbbabdbb";
    m = a.length(); // m为a的长度
    n = b.length(); // n为b的长度

    LCSlength(); // 求出动态规划数组dp
    Buildsubs(); // 求出最长公共子序列LCS

    cout << "求解结果" << endl;
    cout << "    a: " << a << endl;
    cout << "    b: " << b << endl;
    cout << "    最长公共子序列: ";
    vector<char>::reverse_iterator rit;
    for (rit = subs.rbegin(); rit != subs.rend(); ++rit) {
        cout << *rit;
    }
    cout << endl;
    cout << "    长度: " << dp[m][n] << endl;

    return 0;
}
