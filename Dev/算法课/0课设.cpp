#include<bits/stdc++.h>
using namespace std;

// ���ṹ�壺��ʼʱ�䡢����ʱ�䡢����
struct Ad {
    int start;
    int end;
    int value;
};

// ������ʱ������ıȽϺ���
bool cmp(const Ad& a, const Ad& b) {
    return a.end < b.end;
}

// ����accumulate�����ܼ�ֵ�ĺ���
int add(int sum, const Ad& ad) {
    return sum + ad.value;
}

// 1. ��̬�滮��
int dpAlgorithm(vector<Ad>& ads) {
    int n = ads.size();
    if (n == 0) return 0;
    
    // ������ʱ������
    sort(ads.begin(), ads.end(), cmp);
    
    // Ԥ�������ʱ������
    vector<int> endTimes(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        endTimes[i] = ads[i-1].end;
    }
    
    // DP���飺dp[i]��ʾǰi�������������
    vector<int> dp(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        int s = ads[i-1].start;
        int v = ads[i-1].value;
        
        // ���ֲ������һ������ʱ�� <= s�Ĺ��
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
        
        // ״̬ת�ƣ�ѡ��ѡ��i�����
        dp[i] = max(dp[i-1], v + dp[j]);
    }
    
    return dp[n];
}

// 2. �ݹ���ݷ�������֦��
int backtracking(vector<Ad>& ads, int index, int lastEnd, int currentValue, int bestValue) {
    if (index == ads.size()) {
        return max(bestValue, currentValue);
    }
    
    // ��ѡ��index�����
    bestValue = backtracking(ads, index + 1, lastEnd, currentValue, bestValue);
    
    // ѡ��index����棨�������ͻ��
    if (ads[index].start >= lastEnd) {
        bestValue = backtracking(ads, index + 1, ads[index].end, currentValue + ads[index].value, bestValue);
    }
    
    // ��֦�������ǰ��ֵ + ʣ�����ܼ�ֵ <= ��֪���Ž⣬��ǰ��ֹ
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
    
    // ������ʱ����������߼�֦Ч��
    sort(ads.begin(), ads.end(), cmp);
    
    // �����ܼ�ֵ���ڼ�֦
    int totalValues = accumulate(ads.begin(), ads.end(), 0, add);
    
    return backtracking(ads, 0, 0, 0, 0);
}

// 3. ̰���㷨�����ֲ��ԣ�
int greedyAlgorithm(vector<Ad> ads, string strategy = "earliest_end") {
    if (ads.empty()) return 0;
    
    // ���ݲ�ͬ��������
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
    
    // ̰��ѡ��
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
    
    // ö�����п��ܵ��Ӽ���2^n����ϣ�
    for (int mask = 1; mask < (1 << n); ++mask) {
        int currentProfit = 0;
        int lastEnd = 0;
        bool isConflict = false;
        
        // ��鵱ǰ����Ƿ�Ϸ�����ʱ���ͻ��
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) { // ѡ�е�i�����
                if (ads[i].start < lastEnd) {
                    isConflict = true;
                    break;
                }
                currentProfit += ads[i].value;
                lastEnd = ads[i].end;
            }
        }
        
        // �����������
        if (!isConflict && currentProfit > maxProfit) {
            maxProfit = currentProfit;
        }
    }
    
    return maxProfit;
}


int main() {
    int n;
    cout << "������������: ";
    cin >> n;
    
    vector<Ad> ads(n);
    cout << "������ÿ�����Ŀ�ʼʱ�䡢����ʱ������棨�ÿո�ָ���:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "��� #" << i+1 << ": ";
        cin >> ads[i].start >> ads[i].end >> ads[i].value;
    }
    
//    // 1. ��̬�滮���
//    int dpResult = dpAlgorithm(ads);
//    cout << "��̬�滮��������: " << dpResult << endl;
    
    // 2. �ݹ���ݽ��
//    int btResult = recursiveBacktracking(ads);
//    cout << "�ݹ������������: " << btResult << endl;
//    
//    // 3. ̰���㷨��������ֲ��ԣ�
//    int greedyEE = greedyAlgorithm(ads, "earliest_end");
//    int greedyHV = greedyAlgorithm(ads, "highest_value");
//    int greedySD = greedyAlgorithm(ads, "shortest_duration");
//    
//    cout << "̰���㷨(�������)����: " << greedyEE << endl;
//    cout << "̰���㷨(��߼�ֵ)����: " << greedyHV << endl;
//    cout << "̰���㷨(���ʱ��)����: " << greedySD << endl;

 	if (n <= 20) { // ����n��20���������������
        int bruteResult = bruteForceAlgorithm(ads);
        cout << "����������������: " << bruteResult << endl;
    } else {
        cout << "���棺��������ϴ󣬱����������ܳ�ʱ���������㡣" << endl;
    }
    
    return 0;
}    
