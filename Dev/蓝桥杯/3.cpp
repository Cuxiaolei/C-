#include <iostream>
using namespace std;

int bi[] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


bool check(int year, int month, int day)
{
  int sum = 0;
  while(year > 0)
  {
    sum += bi[year%10];
    year /= 10;
  }
  sum += bi[month%10];
  sum += bi[day%10];
  month /= 10;
  day /= 10;
  sum += bi[month];
  sum += bi[day];

  if(sum > 50) return true;
  else return false;  
}


int main()
{
  // 请在此输入您的代码
  int ans = 0;
  for(int year = 2000; year <= 2023; year++)
  {
    d[2] = 28;
    for(int month = 1; month <= 12; month++)
    {
      if(month == 2)
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
          d[month] = 29;
      for(int day = 1; day <= d[month]; day++)
      {
        if(check(year, month, day)) ans++;
      }
    }
  }
  int year = 2024;
  d[2] = 28;
  for(int month = 1; month <= 3; month++)
  {
    if(month == 2)
      if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        d[month] = 29;
    for(int day = 1; day <= d[month]; day++)
    {
      if(check(year, month, day)) ans++;
    }
  }
  int month = 4;
  for(int day = 1; day <= 13; day++)
  {
    if(check(year, month, day)) ans++;
  }
  cout << ans;
  return 0;
}
