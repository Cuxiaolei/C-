//3.构造表达式
//设计一个算法在1-9（顺序不能变）数字之间插入+或-或什么都不插入，使得计算结果总是100的程序，并输出所有的可能性。

#include <iostream>
#include <vector> 

using namespace std;

#define N 9

int a[N];
vector<string> ans;  // 存放答案 
char x[N];  // 解向量

// 深度优先搜索函数
// sum: 当前表达式的计算结果
// prev: 上一个参与计算的数（用于处理连续数字合并的情况）
// i: 当前处理到的数字的下标
//void dfs(int sum, int prev, int i) {
//    if (i == N) {  // 到达一个叶子结点
//        if (sum == 100) {  // 找到一个解
//            string s = to_string(a[0]);
//            for (int j = 1; j < N; j++) {
//                if (x[j] != ' ') s += x[j];
//                s += to_string(a[j]);
//            }
//            s += "=100";
//            ans.push_back(s);
//        }
//    }
//    else {
//        x[i] = '+';  // 位置i插入'+'
//        sum += a[i];  // 计算结果
//        dfs(sum, a[i], i + 1);
//        sum -= a[i];  // 回溯
//
//        x[i] = '-';  // 位置i插入'-'
//        sum -= a[i];  // 计算结果
//        dfs(sum, -a[i], i + 1);
//        sum += a[i];  // 回溯
//
//        x[i] = ' ';  // 位置i插入' '
//        sum -= prev;  // 先减去前面的元素值
//        int tmp;  // 计算新合并值
//        if (prev > 0)
//            tmp = prev * 10 + a[i];  // 如prev=2,a[i]=3,结果为23
//        else
//            tmp = prev * 10 - a[i];  // 如prev=-2,a[i]=3,结果为-23
//        sum += tmp;  // 计算合并结果
//        dfs(sum, tmp, i + 1);
//        sum -= tmp;  // 回溯sum
//        sum += prev;
//    }
//}

void dfs(int sum, int prev, int i)
{
	if(i == N){
		if(sum == 100){
			string s = to_string(a[0]);
			for(int j = 1; j < N; j++)
			{
				if(x[j] != ' ') s += x[j];
				s += to_string(a[j]);
			}
			s += "=100";
			ans.push_back(s);
		}
	}else{
		x[i] = '+';
		sum += a[i];
		dfs(sum, a[i], i + 1);
		sum -= a[i];
		
		x[i] = '-';
		sum -= a[i];
		dfs(sum, -a[i], i+1);
		sum += a[i];
		
		x[i] = ' ';
		sum -= prev;
		int temp;
		if(prev > 0){
			temp = prev * 10 + a[i];
		}else{
			temp = prev * 10 - a[i];
		}
		sum += temp;
		dfs(sum, temp, i + 1);
		sum -= temp;
		sum += prev;
		
	}
}


// 构造表达式并输出结果的函数
void express() {
    for (int i = 0; i < N; i++)  // 为a赋值为1,2，...,9
        a[i] = i + 1;
    dfs(a[0], a[0], 1);  // 插入位置i从1开始
    cout << "求解结果" << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << "  (" << i + 1 << ") " << ans[i] << endl;
}

int main() {
    express();
    return 0;
}
