//2. 找第K个最小元素-用部分快速排序来实现
//编程：输入正整数k，在数组(无序）中找出第k个最小的数。（1<=k<=n)，要求：用部分快速排序来实现

#include <iostream>
using namespace std;

// 交换两个整数的值
void swap(int &x, int &y) {
    int z;
    z = x;
    x = y;
    y = z;
}

// 划分函数，用于快速排序中的划分操作
int partition(int *a, int p, int r) {
    int i = p, j = r + 1;
    int x = a[p];
    while (true) {
        while ((a[++i] < x) && i < r);
        while (a[--j] > x);
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    a[p] = a[j];
    a[j] = x;
    return j;
}

// 选择第k小元素的函数
int select(int *a, int p, int r, int k) {
    int i = partition(a, p, r);
    int j = i - p + 1;
    if (k < j) {
        return select(a, p, i - 1, k);
    } else if (k == j) {
        return a[i];
    } else {
        return select(a, i + 1, r, k - j);
    }
}

int main() {
    int b[10] = {23, 1, 12, 78, 68, 10, 34, 900, 23, 12};
    for (int i = 0; i < 10; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    int begin = 0, end = 9, num = 8;
    int result = select(b, begin, end, num);
    cout << "the eighth least number is: " << result << endl;
    return 0;
}

