//4. ���༭��������
//��A��B�������ַ���������Ҫ�����ٵ��ַ��������������ַ���Aת��Ϊ�ַ���B��������˵���ַ���������3�֣�
//    ��1��ɾ��һ���ַ���
//    ��2������һ���ַ���
//    ��3����һ���ַ��滻��һ���ַ���
//���磬A=��sfdqxbw����B=��gfdgw�������Ϊ4��

#include <iostream>
#include <string>
using namespace std;

// ������������������е���Сֵ
#define min(x, y) ((x) < (y)? (x) : (y))
// ������󳤶�
#define MAX 201

// �����ʾ
string a = "sfdqxbw";
string b = "gfdgw";

// �������ʾ
int dp[MAX][MAX];

// ��dp���飬����༭����
//void solve() {
//    int i, j;
//    // ��a��i���ַ�ȫ��ɾ��ת��Ϊb
//    for (i = 1; i <= a.length(); i++) {
//        dp[i][0] = i;
//    }
//    // ��a�в���b��ȫ���ַ�ת��Ϊb
//    for (j = 1; j <= b.length(); j++) {
//        dp[0][j] = j;
//    }
//    // ���dp����
//    for (i = 1; i <= a.length(); i++) {
//        for (j = 1; j <= b.length(); j++) {
//            if (a[i - 1] == b[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1];
//            } else {
//                // ȡɾ�������롢�滻���ֲ�������Сֵ��1
//                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
//            }
//        }
//    }
//}

void solve()
{
	for(int i = 1; i <= a.length(); i++){
		dp[i][0] = i;
	}
	for(int j = 1; j <= b.length(); j++){
		dp[0][j] = j;
	}
	for(int i = 1; i <= a.length(); i++)
	{
		for(int j = 1; j <= b.length(); j++)
		{
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
			}
		}
	}
}



int main() {
    solve();
    cout << "�����" << endl;
    cout << "    ���ٵ��ַ���������: " << dp[a.length()][b.length()] << endl;
    return 0;
}
