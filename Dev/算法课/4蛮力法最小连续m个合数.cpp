//4. ��С����m������
//����ָ����������m(1<=m<=200),����������������С������m��������������������ʼ������ֹ����
//���磺m=5����С����5������Ϊ��24~28
//��2�ַ�������4��ʼ�ж�ÿ�����Ƿ�Ϊ����
#include <stdio.h>
#include <math.h>

// �ж� i �Ƿ��Ǻ��������ǣ��򷵻� 1
//int composite(int i) {  // �ж�i�Ƿ��Ǻ��������ǣ��򷵻�1 
//    int j;
//    for (j = 2; j <= sqrt(i); j += 1) {
//        if (i % j == 0) {
//            return 1;
//        }
//    }
//    return 0;
//}

int composite(int i)
{
	int j;
	for(int j = 2; j <= sqrt(i); j++)
	{
		if(i % j == 0){
			return 1;
		}
	}
	return 0;
}

int main() {
    long i, j, f, t, m, count = 0;
    printf("  ������ m:");
    scanf("%ld", &m);
    printf("  ��С������%ld������Ϊ:", m);
    i = f = 2;
//    while (1) {
//        if (composite(i) == 1) {
//            count++;
//        } else {
//            count = 0;
//            f = i + 1;
//        }
//        if (count >= m) {
//            printf("%ld,%ld", f, f + m - 1);
//            break;
//        }
//        i++;
//    }
	while(1)
	{
		if(composite(i) == 1)
		{
			count++;
		}else{
			count = 0;
			f = i + 1;
		}
		if(count >= m)
		{
			cout << f << f + m - 1;
			break;
		}
		i++;
	}
    return 0;
}
