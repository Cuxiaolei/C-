#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2000;

priority_queue<ll, vector<ll>, greater<ll> > pq;

int main()
{
  int n; cin >> n;
  for(int i = 1; i <= n; ++ i)
  {
    ll x; cin>>x;
    pq.push(x);
  }

  ll ans = 0;
  while(pq.size() > 1)
  {
    ll a = pq.top(); pq.pop();
    ll b = pq.top(); pq.pop();
    ans += a + b;
    pq.push(a + b);
  }
  cout << ans;
  return 0;
}