#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
const ll = 1e9 + 7;

//带备忘录的递归
ll dp[N];

ll fib(int n)
{
	if(dp[n]) return dp[n];
	if(n <= 2) return 1;
	return dp[n] = (fib(n - 1) + fib(n - 2)) % p;
}

int main()
{
	int n; cin >> n;
	for(int i = 1; i <= n; ++ i)
	{
		cout << fib(i) << ednl;
	}
	return 0;
}