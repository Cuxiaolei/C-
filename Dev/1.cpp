#include<bits/stdc++.h>
using namespace std;

bool cmp(int& a,int& b)
{
	return a<b;
}

int main()
{
	int L,n;
	int min_L=0,max_L=0;
	cin>>L>>n;
	if(n == 0)
	{
		cout<<"0 0";
		return 0;
	}
	vector<int> v;
	int tem;
	for(int i =0;i<n;i++)
	{
		cin>>tem;
		v.push_back(tem);
	}
	sort(v.begin(),v.end(),cmp);
	max_L = max(L-v[0]+1,v[n-1]);
	for(int i = 0;i<n;i++)
	{
		min_L = max(min(v[i],L-v[i]+1),min_L);
	}
	cout<<min_L<<" "<<max_L;
	
	
  return 0;
}

