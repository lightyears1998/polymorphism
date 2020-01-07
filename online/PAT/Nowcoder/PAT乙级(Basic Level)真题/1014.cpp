// 科学计数法

#include <iostream>
#include <string>
using namespace std;

string str, num;

signed main()
{
  cin >> str;

  cout << (str[0] == '-' ? "-" : "");  // 处理符号
  num += str[1];  // 处理整数数位

  int now = 3;  // 跳过小数点
  while (isdigit(str[now]))  // 收集小数位
    num += str[now], ++now;
  ++now;  // 跳过字母e

  int exp = atoi(str.substr(now).c_str());  // 收集幂

  if (exp < 0)
    cout << "0." << string(-exp-1, '0') << num << endl;
  else
  {
    if (num.length() > exp+1)
    {
      cout << num.substr(0, exp+1) << '0' << num.substr(exp+1) << endl;
    }
    else
    {
      cout << num << string(exp - num.length() + 1, '0') << endl;
    }
  }
}
