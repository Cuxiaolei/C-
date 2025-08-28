#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char a[N];


int main()
{
  int n,x;
  cin >> n >> x;
  cin >> a + 1;

  sort(a + 1, a + 1 + n);
  if(a[1] == a[n])
  {
    for(int i = 1; i <= n / x + (n % x ? 1 : 0); ++ i) cout << a[i];
  }else if(a[1] == a[x])
  {
    for(int i = x; i <= n; ++ i) cout << a[i];
  }else 
  {
    cout << a[x];
  }

  return 0;
}