//1. ��������
//����˼�룺�ڴ������n��Ԫ������ȡһ��Ԫ�أ�ͨ��ȡ��һ��Ԫ�أ���Ϊ��׼���Ѹ�Ԫ�ط�������λ�ú������������б���׼�ָ�����������У�����С�ڻ�׼��Ԫ�ط�����ǰ�������У����д��ڻ�׼��Ԫ�ط����ں��������У����ѻ�׼���������������е��м䣬������̳������֡�Ȼ������������зֱ��ظ��������̣�ֱ��ÿ����������ֻ��һ����¼���Ϊֹ��
//

#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;  // �ۼƻ��ִ���

// ���a[s..t]Ԫ��
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

//// �����㷨2(��������)
//vector<int> partition(vector<int>& a, int s, int t) {
//    int i = s, j = t;
//    int base = a[(i + j) / 2];  // ѡ���м�λ��Ԫ��Ϊ��׼
//    printf("��%d�λ��� ��׼=%2d,���ֽ��:", ++cnt, base);
//
//    while (i <= j) {
//        while (i <= j && a[i] < base) {  // ������������С��base��Ԫ��
//            i++;  // iָ����ڵ���base��Ԫ��
//        }
//
//        while (i <= j && a[j] > base) {  // ����������������base��Ԫ��
//            j--;  // jָ��С�ڵ���base��Ԫ��
//        }
//
//        if (i <= j) {
//            swap(a[i], a[j]);  // a[i]��a[j]����
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
//// ��a[s..t]���п�������
//void quicksort(vector<int>& a, int s, int t) {
//    if (s < t) {  // a[s..t]�����ٴ���2��Ԫ��
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


// ��a��������
void quicksort(vector<int>& a) {
    int n = a.size();
    printf("���                        ");
    for (int i = 0; i < n; i++) {
        printf("%3d", i);
    }
    printf("\n");
    printf("����ǰ:                    ");
    disp(a, 0, n - 1);
    printf("\n");
    quicksort(a, 0, n - 1);
    printf("�����:                     ");
    disp(a, 0, n - 1);
    printf("\n");
}

int main() {
    vector<int> a = {1, 5, 3, 2, 3, 4};
    quicksort(a);
    return 0;
}
