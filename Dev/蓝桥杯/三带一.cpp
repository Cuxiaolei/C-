#include <bits/stdc++.h>
using namespace std;

map<char,int> a; 
a['A'] = 0;
a['2'] = 0;
a['3'] = 0;
a['4'] = 0;
a['5'] = 0;
a['6'] = 0;
a['7'] = 0;
a['8'] = 0;
a['9'] = 0;
a['X'] = 0;
a['J'] = 0;
a['Q'] = 0;
a['K'] = 0;




void solve()
{
  string s;
  cin >> s;
  for(int i = 0; i < 4; i ++)
  {
    a[s[i]] ++;
  }
  for(auto pair : a){
    if(pair.second == 3){
      cout << "Yes" << endl;
      return;
    }
  }
  cout << "No" <<endl;
  return;


}




int main()
{
  // 请在此输入您的代码
  int n; cin >> n;
  while(n--)
  {
    solve();
  }
  return 0;
}
