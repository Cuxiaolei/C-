#include <iostream>
using namespace std;

int main()
{ long a,b,d,n,t,k;
 scanf("%ld",&n);
/********* Begin *********/
k = 0;
for(long i = n - 1; i >= 1; i--)
{
    a = i;
    b = n - i;
    t = 10;
    int t2 = 1;
    while(t > a)
    {
        d = a / t * t2 + a % t2;
        if(d == b)
        {
            cout << "(" << i << "," << b << ") ";
            k++;
        }
        t *= 10;
        t2 *= 10;   
    }
}



/********* end *********/
printf("\n   %ld共有以上%ld个解\n",n,k);
}