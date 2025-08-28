//模板

//找到升序数组a中的x第一次出现的位置

int l =0,r = 1e9;
//注意这里的判断条件，这样可以保证1，r最终一定收敛到分界点
while(l + 1 != r)
{
	int mid = (l + r) / 2;

	//如果a为升序，说明mid偏大了，需要减小mid，就只能将r变小，即r =mid
	if(a[min] >= x) r = min;
	else l = mid;
}



/// 二分答案
bool check(int mid)
{
	bool res = true;

	return res;
}

int main()
{
	int l = 0, r = 1e9;
	while(l + 1 ！= r)
	{
		int mid = (r + l) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}



//跳石头364（二分答案）
#include <iostream>
using namespace std;
const int N = 1e5 + 1;
int a[N];
int l,n,m;

int check(int mid)
{
  int res = 0, lst = 0;
  for(int i = 1; i <= n; i ++)
  {
    if(a[i] - a[lst] < mid) res ++;
    else lst = i;
  }
  if(l - a[lst] < mid) res ++;
  return res;
}



int main()
{
  cin >> l >> n >> m;
  for(int i = 1; i <= n; i ++) cin >> a[i];
  int l = 0;
  int r = 1e9 + 10;

  while(l + 1 != r)
  {
    int mid = (l + r) / 2;

    if(check(mid) <= m) l = mid;
    else r = mid;
  }

  cout << l;

  return 0;
}
