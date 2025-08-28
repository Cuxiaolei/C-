#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int p2;
    int p5;
    int s=0;
    scanf("%d", &n);
    int m[n];
    m[1] = 1;
    p2 = 1;
    p5 = 1;
   for(int i = 2; i <= n; i++){
	    if(2*m[p2] + 1 < 5*m[p5] - 1){
	        m[i] = 2*m[p2] + 1;
	        p2++;
	    } else if(2*m[p2] + 1 > 5*m[p5] - 1) {
	        m[i] = 5*m[p5] - 1;
	        p5++;
	    } else {
	        // 当 2*m[p2] + 1 等于 5*m[p5] - 1 时，两个指针都后移
	        m[i] = 2*m[p2] + 1;
	        p2++;
	        p5++;
	    }
    	s += m[i]; // 累加当前元素到总和
	}
    //时间复杂度为  O(n) 
    cout << m[n] << "," << s;

f(4) = 3 = ' 4 = 1+3' 4 = 1+1+1+1 4 = 3+1


    return 0;
} 



初始值：f1 = 1;
f2:1+1,2 = 2
f3:1+1+1,1+2,2+1,3 = 4
f4:1+1+1+1,1+1+2,1+2=1,2+1+1,2+2,1+3,3+1 = 7 

f = 






