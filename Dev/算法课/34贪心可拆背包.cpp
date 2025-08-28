//1.���ɲ𱳰�����
//���������������б��Ϊ1��2������n��n����Ʒ�����ǵ������ֱ�Ϊw1��w2������wn����ֵ�ֱ�Ϊv1��v2������vn������wi��vi��1��i��n����Ϊ������
//������һ����������Я�����������������W�����Ŀ�꣺�ڲ������������ص�ǰ���£�ʹ����װ����ܼ�ֵ��󣨼�Ч����󻯣�����0/1��������������ǣ������ÿ����Ʒ����ȡһ����װ�뱳����

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAXN 51

// �����ʾ
int n = 5;
double W = 100;  // ����

// ��Ʒ�ṹ�壬������������ֵ����λ������ֵ�Լ��ȽϺ���
struct NodeType {
    double w;
    double v;
    double p;  // p = v / w
    // ����С������������ڰ���λ������ֵ�ݼ�����
    bool operator<(const NodeType& s) const {
        return p > s.p;
    }
};

// ��Ʒ���飬�±�0����
NodeType A[] = { {0}, {10, 20}, {20, 30}, {30, 66}, {40, 40}, {50, 60} };

// �������ʾ
double V;  // ����ֵ
double x[MAXN];

// ��ⱳ�����Ⲣ�����ܼ�ֵ
void Knap() {
    V = 0;  // V��ʼ��Ϊ0
    double weight = W;  // ��������װ�����������
    memset(x, 0, sizeof(x));  // ��ʼ��x����
    int i = 1;
    // ��Ʒi�ܹ�ȫ��װ��ʱѭ��
    while (A[i].w < weight) {
        x[i] = 1;  // װ����Ʒi
        weight -= A[i].w;  // ���ٱ�������װ�����������
        V += A[i].v;  // �ۼ��ܼ�ֵ
        i++;  // ����ѭ��
    }
    // ��������������0
    if (weight > 0) {
        x[i] = weight / A[i].w;  // ����Ʒi��һ����װ��
        V += x[i] * A[i].v;  // �ۼ��ܼ�ֵ
    }
}

// �����Ʒ��Ϣ��������������ֵ�͵�λ������ֵ
void dispA() {
    int i;
    printf("\tW\tV\tV/W\n");
    for (i = 1; i <= n; i++) {
        printf("\t%g\t%g\t%3.1f\n", A[i].w, A[i].v, A[i].p);
    }
}

int main() {
    printf("������\n");
    // ����ÿ����Ʒ�ĵ�λ������ֵ
    for (int i = 1; i <= n; i++) {
        A[i].p = A[i].v / A[i].w;
    }
    printf("(1)����ǰ\n");
    dispA();
    // ����Ʒ����λ������ֵ�ݼ�����
    sort(A + 1, A + n + 1);
    printf("(2)�����:\n");
    dispA();
    Knap();
    printf("(3)�����\n");  // ������
    printf("    x: [");
    for (int j = 1; j < n; j++) {
        printf("%g, ", x[j]);
    }
    printf("%g]\n", x[n]);
    printf("    �ܼ�ֵ=%g\n", V);
    return 0;
}
