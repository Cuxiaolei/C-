#include <iostream>
using namespace std;
int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
  // 请在此输入您的代码
  int a[] = {
    0, 5, 6, 8, 6, 9, 1, 6, 1, 2, 4, 9, 1, 9, 8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8 ,7 ,5 ,8 ,1 ,5, 8, 6, 1, 8, 3, 0, 3, 7, 9, 2,
    7, 0, 5, 8, 8, 5, 7, 0, 9, 9, 1, 9, 4, 4, 6, 8, 6, 3, 3, 8, 5, 1, 6, 3, 4, 6 ,7 ,0 ,7 ,8 ,2, 7, 6, 8, 9, 5, 6, 5, 6, 1, 4, 0, 1,
    0, 0, 9, 4, 8, 0, 9, 1, 2, 8, 5, 0, 2, 5, 3, 3
  };
  int year[] = {0,2,0,2,3};
  int ans = 0;
  int j = 1;
  int i = 1;
  for(i; i <= 100; i++){
    if(a[i] == year[j]) j++;
  }
  for(int month = 1; month <= 12; month++)
  {
    for(int day = 1; day <= d[month]; day++)
    {
      int temp[5];
      if(month < 10){
        temp[1] = 0;
        temp[2] = month;
      }else{
        temp[1] = month/10;
        temp[2] = month%10;
      }
      if(day < 10){
        temp[3] = 0;
        temp[4] = day;
      }else{
        temp[3] = day/10;
        temp[4] = day%10;
      }
      int k = 1;
      for(int t = i; t <= 100; t++)
      {   
        if(a[t] == temp[k]) k++;
        if(k == 5) break;
      }
      if(k == 5){
        ans ++;
      }
    }
  }

  cout << ans;
  return 0;
}
