// 十进制转换为任意进制
ll x; cin >> x;
int cnt = 0; //转换后的位数
while(x)
{
	a[++ cnt] = x % k;
	x /= k;
}
reverse(a + 1, a + 1 + cnt);


//任意进制转换为十进制
ll x = 0;
int k; cin >> k;//将k进制的数转换为10进制（k进制的数为一个数组a[n])
for(int i = 1;i <= n; ++ i)
{
	x = x * k + a[i];
}
cout << x;