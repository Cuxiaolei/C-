#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int nums[9] = {0}; // 存储当前排列
bool used[10] = {false};
int solutions[100][9]; // 存储所有解
int solution_count = 0;

// 计算分数值
double frac(int a, int b, int c) {
    return (double)a / (10 * b + c);
}

// 检查解是否重复
bool is_duplicate(int idx) {
    for(int i=0; i<solution_count; i++) {
        // 比较两种排列方式
        if(
            (nums[0]==solutions[i][0] && nums[1]==solutions[i][1] && nums[2]==solutions[i][2] && 
             nums[3]==solutions[i][3] && nums[4]==solutions[i][4] && nums[5]==solutions[i][5]) ||
            
            (nums[0]==solutions[i][3] && nums[1]==solutions[i][4] && nums[2]==solutions[i][5] && 
             nums[3]==solutions[i][0] && nums[4]==solutions[i][1] && nums[5]==solutions[i][2])
        ) {
            return true;
        }
    }
    return false;
}

void backtrack(int pos) {
    if(pos == 9) {
        double left = frac(nums[0], nums[1], nums[2]) + frac(nums[3], nums[4], nums[5]);
        double right = frac(nums[6], nums[7], nums[8]);
        
        if(fabs(left - right) < 1e-6) {
            if(!is_duplicate(pos)) {
                for(int i=0; i<9; i++) solutions[solution_count][i] = nums[i];
                solution_count++;
            }
        }
        return;
    }

    for(int i=1; i<=9; i++) {
        if(!used[i]) {
            used[i] = true;
            nums[pos] = i;
            backtrack(pos + 1);
            used[i] = false;
        }
    }
}

int main() {
    backtrack(0);
    
    printf("共找到 %d 个解：", solution_count);
    for(int i=0; i<solution_count; i++) {
        printf("%d: %d/%d%d+%d/%d%d=%d/%d%d",
               i+1,
               solutions[i][0], solutions[i][1], solutions[i][2],
               solutions[i][3], solutions[i][4], solutions[i][5],
               solutions[i][6], solutions[i][7], solutions[i][8]);
    }
    return 0;
}
