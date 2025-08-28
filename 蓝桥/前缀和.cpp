// 

// prefix[i][j]为a[i]的前j项和
for(int i = 1; i <= 5; ++ i)
{
	for(int j = 1; j <= n; ++ j)
	{
	  prefix[i][j] = prefix[i][j - 1] + a[i][j];
	}
}

//通过prefix[k][r] - prefix[k][l - 1]可以计算出a[k][l]到a[k][r]的区间和
while(m--)
{
	int l,r,k;
	cin>>l>>r>>k;
	cout << (prefix[k][r] - prefix[k][l - 1] + p) % p << endl;
}