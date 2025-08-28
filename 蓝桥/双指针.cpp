//美丽区间

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
  int n,s;
  cin >> n >> s;
  for(int i = 1; i <= n; i ++ )
  {
    cin >> a[i];
  }

  ////固定写法
  int ans = n + 1;
  for(int i = 1, j = 0, sum = 0; i <= n; i ++ )
  {

    ///// 非常重要
    while(i > j || (j + 1 <= n && sum < s)) sum += a[++j];
    if(sum >= s)
    {
      ans = min(ans,j - i + 1);
    }
    sum -= a[i];
  }

  cout << ((ans < n + 1) ? ans : 0);

  return 0;
}