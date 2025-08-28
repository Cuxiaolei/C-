//5. ���0/1��������(�������֦)
//��������������n�������ֱ�Ϊ{w1��w2������wn}����Ʒ�����ǵļ�ֵ�ֱ�Ϊ{v1��v2������vn}������һ������ΪW�ı�����
//    ��ƴ���Щ��Ʒ��ѡȡһ������Ʒ����ñ����ķ�����ÿ����ƷҪôѡ��Ҫô��ѡ�У�Ҫ��ѡ�е���Ʒ�����ܹ��ŵ������У����������������ƾ������ļ�ֵ��

#include <stdio.h>

#define MAXN 20  // �����Ʒ��

// �����ʾ
int n = 4;      // 4����Ʒ
int W = 6;      // ��������Ϊ6
int w[] = {0, 5, 3, 2, 1};  // ���4����Ʒ�����������±�0Ԫ��
int v[] = {0, 4, 4, 3, 1};  // ���4����Ʒ��ֵ�������±�0Ԫ��

// �������ʾ
int x[MAXN];    // ������ս�
int maxv;       // ������Ž���ܼ�ֵ

//// ���ǵ�i����Ʒ
//void dfs(int i, int tw, int tv, int op[]) {
//    if (i > n) {  // �ҵ�һ��Ҷ�ӽ��
//        if (tv > maxv) {  // �ҵ�һ�����������ĸ��Ž⣬������
//            maxv = tv;
//            for (int j = 1; j <= n; j++) {
//                x[j] = op[j];
//            }
//        }
//    } else {  // ��δ����������Ʒ
//        for (int j = 1; j >= 0; j--) {
//            op[i] = j;
//            if (tw + w[i] * j <= W) {
//                dfs(i + 1, tw + w[i] * op[i], tv + v[i] * op[i], op);
//            }
//        }
//    }
//}

void dfs(int i, int tw, int tv, int op[]){
	if(i > n){
		if(tv > maxv){
			maxv = tv;
			for(int j = 1; j <= n; j++)
			{
				x[j] = op[j];
			}
		}
	}else{
		for(int j = 1; j >= 0; j--){
			op[i] = j;
			if(tw + w[i] * j <= W){
				dfs(i + 1, tw + w[i] * op[i], tv + v[i] * op[i], op);
			} 
		}
	}
}

// ������Ž�
void dispasolution() {
    int i;
    printf("���װ�����:\n");
    for (i = 1; i <= n; i++) {
        if (x[i] == 1) {
            printf("  ѡȡ��%d����Ʒ\n", i);
        }
    }
    printf("������=%d,�ܼ�ֵ=%d\n", W, maxv);
}

int main() {
    int op[MAXN];  // �����ʱ��
    dfs(1, 0, 0, op);
    dispasolution();
    return 0;
}
