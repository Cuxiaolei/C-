//2. �ҵ�K����СԪ��-�ò��ֿ���������ʵ��
//��̣�����������k��������(�������ҳ���k����С��������1<=k<=n)��Ҫ���ò��ֿ���������ʵ��

#include <iostream>
using namespace std;

// ��������������ֵ
void swap(int &x, int &y) {
    int z;
    z = x;
    x = y;
    y = z;
}

// ���ֺ��������ڿ��������еĻ��ֲ���
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

// ѡ���kСԪ�صĺ���
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

