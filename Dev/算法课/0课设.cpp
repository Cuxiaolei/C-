#include<bits/stdc++.h>
using namespace std;

// 广告结构体：开始时间、结束时间、收益
struct Ad {
    int start;
    int end;
    int value;
};

// 按结束时间排序的比较函数
bool cmp(const Ad& a, const Ad& b) {
    return a.end < b.end;
}

// 用于accumulate计算总价值的函数
int add(int sum, const Ad& ad) {
    return sum + ad.value;
}

// 1. 动态规划法
int dpAlgorithm(vector<Ad>& ads) {
    int n = ads.size();
    if (n == 0) return 0;
    
    // 按结束时间排序
    sort(ads.begin(), ads.end(), cmp);
    
    // 预处理结束时间数组
    vector<int> endTimes(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        endTimes[i] = ads[i-1].end;
    }
    
    // DP数组：dp[i]表示前i个广告的最大收益
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        int s = ads[i-1].start;
        int v = ads[i-1].value;
        
        // 二分查找最后一个结束时间 <= s的广告
        int left = 0, right = i - 1;
        int j = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (endTimes[mid] <= s) {
                j = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // 状态转移：选或不选第i个广告
        dp[i] = max(dp[i-1], v + dp[j]);
    }
    
    return dp[n];
}

// 2. 递归回溯法（带剪枝）
int backtracking(vector<Ad>& ads, int index, int lastEnd, int currentValue, int bestValue) {
    if (index == ads.size()) {
        return max(bestValue, currentValue);
    }
    
    // 不选第index个广告
    bestValue = backtracking(ads, index + 1, lastEnd, currentValue, bestValue);
    
    // 选第index个广告（如果不冲突）
    if (ads[index].start >= lastEnd) {
        bestValue = backtracking(ads, index + 1, ads[index].end, currentValue + ads[index].value, bestValue);
    }
    
    // 剪枝：如果当前价值 + 剩余广告总价值 <= 已知最优解，提前终止
    int remaining = 0;
    for (int i = index; i < ads.size(); ++i) {
        remaining += ads[i].value;
    }
    if (currentValue + remaining <= bestValue) {
        return bestValue;
    }
    
    return bestValue;
}

int recursiveBacktracking(vector<Ad>& ads) {
    if (ads.empty()) return 0;
    
    // 按结束时间排序以提高剪枝效率
    sort(ads.begin(), ads.end(), cmp);
    
    // 计算总价值用于剪枝
    int totalValues = accumulate(ads.begin(), ads.end(), 0, add);
    
    return backtracking(ads, 0, 0, 0, 0);
}

// 3. 贪心算法（三种策略）
int greedyAlgorithm(vector<Ad> ads, string strategy = "earliest_end") {
    if (ads.empty()) return 0;
    
    // 根据不同策略排序
    if (strategy == "earliest_end") {
        sort(ads.begin(), ads.end(), cmp);
    } else if (strategy == "highest_value") {
        sort(ads.begin(), ads.end(), [](const Ad& a, const Ad& b) {
            return a.value > b.value;
        });
    } else if (strategy == "shortest_duration") {
        sort(ads.begin(), ads.end(), [](const Ad& a, const Ad& b) {
            return (a.end - a.start) < (b.end - b.start);
        });
    }
    
    // 贪心选择
    int selectedValue = 0;
    int lastEnd = 0;
    
    for (const auto& ad : ads) {
        if (ad.start >= lastEnd) {
            selectedValue += ad.value;
            lastEnd = ad.end;
        }
    }
    
    return selectedValue;
}

int bruteForceAlgorithm(vector<Ad>& ads) {
    int n = ads.size();
    int maxProfit = 0;
    
    // 枚举所有可能的子集（2^n种组合）
    for (int mask = 1; mask < (1 << n); ++mask) {
        int currentProfit = 0;
        int lastEnd = 0;
        bool isConflict = false;
        
        // 检查当前组合是否合法（无时间冲突）
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // 选中第i个广告
                if (ads[i].start < lastEnd) {
                    isConflict = true;
                    break;
                }
                currentProfit += ads[i].value;
                lastEnd = ads[i].end;
            }
        }
        
        // 更新最大收益
        if (!isConflict && currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }
    
    return maxProfit;
}


int main() {
    int n;
    cout << "请输入广告数量: ";
    cin >> n;
    
    vector<Ad> ads(n);
    cout << "请输入每个广告的开始时间、结束时间和收益（用空格分隔）:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "广告 #" << i+1 << ": ";
        cin >> ads[i].start >> ads[i].end >> ads[i].value;
    }
    
//    // 1. 动态规划结果
//    int dpResult = dpAlgorithm(ads);
//    cout << "动态规划最优收益: " << dpResult << endl;
    
    // 2. 递归回溯结果
//    int btResult = recursiveBacktracking(ads);
//    cout << "递归回溯最优收益: " << btResult << endl;
//    
//    // 3. 贪心算法结果（三种策略）
//    int greedyEE = greedyAlgorithm(ads, "earliest_end");
//    int greedyHV = greedyAlgorithm(ads, "highest_value");
//    int greedySD = greedyAlgorithm(ads, "shortest_duration");
//    
//    cout << "贪心算法(最早结束)收益: " << greedyEE << endl;
//    cout << "贪心算法(最高价值)收益: " << greedyHV << endl;
//    cout << "贪心算法(最短时长)收益: " << greedySD << endl;

 	if (n <= 20) { // 限制n≤20，避免计算量过大
        int bruteResult = bruteForceAlgorithm(ads);
        cout << "暴力遍历最优收益: " << bruteResult << endl;
    } else {
        cout << "警告：广告数量较大，暴力遍历可能超时，跳过计算。" << endl;
    }
    
    return 0;
}    
