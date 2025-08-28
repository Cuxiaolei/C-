// 求1 ~ n 的全排列

int a[N];
bool vis[N];

void dfs(int dep)
{
	if(dep == n + 1)
	{
		for(int i = 1; i <= n ++ i) cout << a[i] << " ";
		cout << endl;
		return;
	}
	for(int i = 1; i<= n;i++)
	{
		// 排除不合法路径
		if(vis[i]) continue;

		// 修改状态
		vis[i] = true;
		a[dep] = i;

		// 下一层
		dfs(dep + 1)
		
		// 恢复现场
		vis[i] = false;
		// a[dep] = 0 可以省略
	}
}


using ll = long long;

int vis[N][N];
int n, ans;

void dfs(int dep)
{
	if(dep == n + 1)
	{
		ans ++;
		return;
	}

	for(int i = 1; i <= n; i++)
	{
		if(vis[dep][i]) continue;

		// 修改状态
		for(int j = 1; j <= n; j++) vis[j][i] ++;
		for(int j = dep, k = i; j <= n, k <= n; j++, k++) vis[j][k] ++;
		for(int j = dep, k = i; j <= n, k <= n; j--, k++) vis[j][k] ++;
		for(int j = dep, k = i; j >= 1, k >= 1; j--, k--) vis[j][k] ++;
		for(int j = dep, k = i; j >= 1, k >= 1; j++, k--) vis[j][k] ++;

		dfs(dep + 1)

		// 恢复现场
		for(int j = 1; j <= n; j++) vis[j][i] --;
		for(int j = dep, k = i; j <= n, k <= n; j++, k++) vis[j][k] --;
		for(int j = dep, k = i; j <= n, k <= n; j--, k++) vis[j][k] --;
		for(int j = dep, k = i; j >= 1, k >= 1; j--, k--) vis[j][k] --;
		for(int j = dep, k = i; j >= 1, k >= 1; j++, k--) vis[j][k] --;
	}
}