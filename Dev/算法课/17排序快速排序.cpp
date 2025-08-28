//1. 快速排序
//基本思想：在待排序的n个元素中任取一个元素（通常取第一个元素）作为基准，把该元素放入最终位置后，整个数据序列被基准分割成两个子序列，所有小于基准的元素放置在前子序列中，所有大于基准的元素放置在后子序列中，并把基准排在这两个子序列的中间，这个过程称作划分。然后对两个子序列分别重复上述过程，直至每个子序列内只有一个记录或空为止。
//

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;  // 累计划分次数

// 输出a[s..t]元素
void disp(vector<int>& a, int s, int t) {
    for (int i = 0; i < s; i++) {
        printf("   ");
    }
    printf("[");
    for (int i = s; i <= t; i++) {
        printf("%3d", a[i]);
    }
    printf("]");
    for (int i = t + 1; i < a.size(); i++) {
        printf("   ");
    }
}

//// 划分算法2(递增排序)
//vector<int> partition(vector<int>& a, int s, int t) {
//    int i = s, j = t;
//    int base = a[(i + j) / 2];  // 选择中间位置元素为基准
//    printf("第%d次划分 基准=%2d,划分结果:", ++cnt, base);
//
//    while (i <= j) {
//        while (i <= j && a[i] < base) {  // 从左向右跳过小于base的元素
//            i++;  // i指向大于等于base的元素
//        }
//
//        while (i <= j && a[j] > base) {  // 从右向左跳过大于base的元素
//            j--;  // j指向小于等于base的元素
//        }
//
//        if (i <= j) {
//            swap(a[i], a[j]);  // a[i]和a[j]交换
//            i++;
//            j--;
//        }
//    }
//
//    disp(a, s, t);
//    printf("  j=%d,i=%d\n", j, i);
//    return {j, i};
//}
//
//// 对a[s..t]进行快速排序
//void quicksort(vector<int>& a, int s, int t) {
//    if (s < t) {  // a[s..t]中至少存在2个元素
//        vector<int> ps = partition(a, s, t);
//        int j = ps[0], i = ps[1];
//        quicksort(a, s, j);
//        quicksort(a, i, t);
//    }
//}

vector<int> partition(vector<int>& a, int left, int right){
	int mid = a[(left + right) / 2];
	while(left <= right)
	{
		while(a[left] < mid && left <= right){
			left++;
		}
		while(a[right] > mid && left <= right){
			right--;
		}
		
		if(left <= right)
		{
			swap(a[left], a[right]);
			left++;
			right--;
		}
	}
	return {right, left};
}

void quicksort(vector<int>& a, int left, int right)
{
	if(left < right)
	{
		vector<int> ps = partition(a, left, right);
		int i = ps[0], j = ps[1];
		quicksort(a, left, i); 
		quicksort(a, j, right); 
	}
 } 


// 对a快速排序
void quicksort(vector<int>& a) {
    int n = a.size();
    printf("序号                        ");
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
    }
    printf("\n");
    printf("排序前:                    ");
    disp(a, 0, n - 1);
    printf("\n");
    quicksort(a, 0, n - 1);
    printf("排序后:                     ");
    disp(a, 0, n - 1);
    printf("\n");
}

int main() {
    vector<int> a = {1, 5, 3, 2, 3, 4};
    quicksort(a);
    return 0;
}
