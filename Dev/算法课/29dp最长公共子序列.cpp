//3.������������������
//�������������ַ����е���������ָ�Ӹ����ַ�����������أ���һ��������ȥ�����ɸ��ַ�������һ��Ҳ��ȥ���������γɵ��ַ����С����������ַ�����A��B������ַ�����Z����A�������У�����B�������У��������Z��A��B�Ĺ��������С�����������������A��B������������У�LCS����

#include <iostream>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

// ����꣬���ڻ�ȡ�������еĽϴ�ֵ
#define max(x, y) ((x) > (y)? (x) : (y))
// ���������������ַ�����
#define MAX 51

// �����ʾ
int m, n;
string a, b;

// �������ʾ
int dp[MAX][MAX];  // ��̬�滮����
vector<char> subs; // �������������У�LCS��

//// ��������������еĳ��ȣ�����䶯̬�滮����dp
//void LCSlength() {
//    int i, j;
//    // ��dp[i][0]��Ϊ0������߽�����
//    for (i = 0; i <= m; i++) {
//        dp[i][0] = 0;
//    }
//    // ��dp[0][j]��Ϊ0������߽�����
//    for (j = 0; j <= n; j++) {
//        dp[0][j] = 0;
//    }
//    // ����forѭ�������ַ���a��b�������ַ�
//    for (i = 1; i <= m; i++) {
//        for (j = 1; j <= n; j++) {
//            // ���(1)�����a[i-1]��b[j-1]���
//            if (a[i - 1] == b[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1] + 1;
//            } 
//            // ���(2)�����a[i-1]��b[j-1]�����
//            else {
//                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
//            }
//        }
//    }
//}

void LCSlength(){
	for(int i = 0; i <= m; i++){
		dp[i][0] = 0;
	}
	for(int j = 0; j <= n; j++){
		dp[0][j] = 0;
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
}


// ���ݶ�̬�滮����dp���������������subs
void Buildsubs() {
    int k = dp[m][n]; // kΪa��b������������г���
    int i = m;
    int j = n;
    // ��subs�з�������������У�����
    while (k > 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            i--;
        } 
        else if (dp[i][j] == dp[i][j - 1]) {
            j--;
        } 
        else {
            subs.push_back(a[i - 1]); // subs�����a[i-1]
            i--; 
            j--; 
            k--;
        }
    }
}

int main() {
    a = "abcbdb";
    b = "acbbabdbb";
    m = a.length(); // mΪa�ĳ���
    n = b.length(); // nΪb�ĳ���

    LCSlength(); // �����̬�滮����dp
    Buildsubs(); // ��������������LCS

    cout << "�����" << endl;
    cout << "    a: " << a << endl;
    cout << "    b: " << b << endl;
    cout << "    �����������: ";
    vector<char>::reverse_iterator rit;
    for (rit = subs.rbegin(); rit != subs.rend(); ++rit) {
        cout << *rit;
    }
    cout << endl;
    cout << "    ����: " << dp[m][n] << endl;

    return 0;
}
