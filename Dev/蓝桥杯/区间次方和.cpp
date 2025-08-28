#include <bits/stdc++.h>
using namespace std;

const long long N = 1e9 + 10;
long long a[N];


int main()
{
  int n; cin>>n;
  for(int i = 1; i <= n; ++ i) cin >> a[i];

  sort(a + 1, a + 1 + n);

  long long ans = a[2] - a[1];

  for(int i = 2; i <= n; ++ i) ans = min(ans, a[i] - a[i - 1]);
	cout << ans;

  return 0;
}
