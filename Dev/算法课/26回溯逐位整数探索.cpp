//思考2：逐位整除数探索
//n位逐位整除数：从其高位开始，高1位能被1整除（显然）, 高2位能被2整除，…，整个n位数能被n整除。输入n，试探索所有的n位逐位整除数并输出。
//
//例如：102450就是一个6位逐位整除数。
#include <stdio.h>

// 全局变量，a数组用于存储逐位整除数的每一位数字，n表示位数，sum用于统计满足条件的数的个数
int a[200];
int n, sum = 0;

// 回溯函数声明
void backtrack(int t);
void backtrack(int t){
	int i, j ,r;
	if(t > n){
		sum++;
		for(int i = 1; i <= n; i++){
			printf("%d", a[i]);
		}
		printf("\n");
	}else if(t == 1){
		for(int i = 1; i <= 9; i++){
			a[t] = i;
			backtrack(t + 1);
		}
	}else{
		for(int i = 0; i <= 9; i++){
			a[t] = i;
			r = 0;
			for(int j = 1; j <= t; j++)
			{
				r = r * 10 + a[j];
			}
			if(r%t == 0) backtrack(t + 1);
		}
	}
}
int main() {
    // 提示用户输入位数n
    printf("Please input n:");
    scanf("%d", &n);
    // 从第1位开始进行回溯搜索
    backtrack(1);
    // 如果没有找到满足条件的数，输出提示信息
    if (sum == 0) {
        printf("Not Found!\n");
    }
    return 0;
}

//// 回溯函数，用于生成和检查逐位整除数
//void backtrack(int t) {
//    int i, j, r;
//    // 如果已经处理完了n位数字，说明找到了一个满足条件的逐位整除数
//    if (t > n) {
//        sum++;
//        // 输出满足条件的数的序号
//        printf("%6d:", sum);
//        for (i = 1; i <= n; i++) {
//            // 输出该逐位整除数的每一位数字
//            printf("%d", a[i]);
//        }
//        printf("\n");
//    }
//    // 如果是处理第1位数字，因为第1位不能为0，所以从1到9进行尝试
//    else if (t == 1) {
//        for (i = 1; i <= 9; i++) {
//            a[t] = i;
//            // 继续处理下一位数字
//            backtrack(t + 1);
//        }
//    }
//    // 处理其他位数字，从0到9进行尝试
//    else {
//        for (i = 0; i <= 9; i++) {
//            a[t] = i;
//            r = 0;
//            for (j = 1; j <= t; j++) {
//                // 计算当前前j位组成的数，并对j取模，判断是否能被j整除
//                r = r * 10 + a[j];
//                r = r % t;
//            }
//            // 如果前t位组成的数能被t整除，则继续处理下一位数字
//            if (r == 0) {
//                backtrack(t + 1);
//            }
//        }
//    }
//}
