//3.������ʽ
//���һ���㷨��1-9��˳���ܱ䣩����֮�����+��-��ʲô�������룬ʹ�ü���������100�ĳ��򣬲�������еĿ����ԡ�

#include <iostream>
#include <vector> 

using namespace std;

#define N 9

int a[N];
vector<string> ans;  // ��Ŵ� 
char x[N];  // ������

// ���������������
// sum: ��ǰ���ʽ�ļ�����
// prev: ��һ�����������������ڴ����������ֺϲ��������
// i: ��ǰ���������ֵ��±�
//void dfs(int sum, int prev, int i) {
//    if (i == N) {  // ����һ��Ҷ�ӽ��
//        if (sum == 100) {  // �ҵ�һ����
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
//        x[i] = '+';  // λ��i����'+'
//        sum += a[i];  // ������
//        dfs(sum, a[i], i + 1);
//        sum -= a[i];  // ����
//
//        x[i] = '-';  // λ��i����'-'
//        sum -= a[i];  // ������
//        dfs(sum, -a[i], i + 1);
//        sum += a[i];  // ����
//
//        x[i] = ' ';  // λ��i����' '
//        sum -= prev;  // �ȼ�ȥǰ���Ԫ��ֵ
//        int tmp;  // �����ºϲ�ֵ
//        if (prev > 0)
//            tmp = prev * 10 + a[i];  // ��prev=2,a[i]=3,���Ϊ23
//        else
//            tmp = prev * 10 - a[i];  // ��prev=-2,a[i]=3,���Ϊ-23
//        sum += tmp;  // ����ϲ����
//        dfs(sum, tmp, i + 1);
//        sum -= tmp;  // ����sum
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


// ������ʽ���������ĺ���
void express() {
    for (int i = 0; i < N; i++)  // Ϊa��ֵΪ1,2��...,9
        a[i] = i + 1;
    dfs(a[0], a[0], 1);  // ����λ��i��1��ʼ
    cout << "�����" << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << "  (" << i + 1 << ") " << ans[i] << endl;
}

int main() {
    express();
    return 0;
}
