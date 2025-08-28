// 求解n皇后问题
void Queens(int n)
{   
	int i = 1;
    q[i] = 0;
    while(i >= 1) {
        q[i] ++;
        while(q[i] <= n && !place(i))   
            q[i] ++;
        if(q[i] <= n){
            if(i == n)
                dispasolution(n);
            else {
                i++;
                q[i] = 0;
             }
         }
        else i--;
    }
}

