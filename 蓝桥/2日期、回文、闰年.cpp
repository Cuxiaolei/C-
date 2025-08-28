// 字符串转整数
int s2i(string s)
{
  int res = 0;
  for(const auto &i : s)
  {
    res = res * 10 + i - '0';
  }
  return res;
}


// 整数转字符串
string i2s(int x, int k)
{
  string res;
  while(x)
  {
    res += x % 10 + '0';
    x /= 10;
  }

  if(res.length() < k)res += '0';
  reverse(res.begin(), res.end());
  return res;
}


//是否是闰年
bool isRun(int year)
{
  if(year/4 == 0 && year/100 != 0 || year/400 == 0) return true;
  return false;
}


//是否符合日期格式
bool isok(int year, int month, int day)
{
  int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if(isRun(year)) days[2] = 29;
  if(day <= days[month]) return true;
  return false;
}


//是否是回文数
bool ishui(int year, int month, int day)
{
  string res = i2s(year, 4) + i2s(month, 2) + i2s(day, 2);
  for(int i = 0; i < res.length() / 2; ++ i)
  {
    if(res[i] != res[res.length() - 1 - i]) return false;
  }
  return true;
}


