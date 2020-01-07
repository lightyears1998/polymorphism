// 福尔摩斯的约会
// Warning.

#include <bits/stdc++.h>
using namespace std;

string a, b, c, d, ans;

const string days[] = {
  "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

signed main()
{
  cin >> a >> b >> c >> d;

  for (unsigned i = 0, cnt = 0; i < min(a.length(), b.length()); ++i)
  {
    if (cnt == 0 && isupper(a[i]) && a[i] == b[i])
    {
      ans += days[a[i] - 'A'] + " "; ++cnt;
      continue;
    }
    if (cnt == 1 && a[i] == b[i])
    {
      if (isdigit(a[i])) {
        ans += string("0") + a[i];
        // 这里不能写成 ans += "0" + a[i]，赋值号右边不能确认类型，string::append报错
      }
      else {
        char ch = toupper(a[i]);
        int clock = ch - 'A' + 10;
        ans += to_string(clock);
      }
      break;
    }
  }
  
  ans += ":";

  for (unsigned i = 0; i < min(c.length(), d.length()); ++i)
  {
    if (isalpha(c[i]) && c[i] == d[i]) {
      if (i < 10)
        ans += "0";
      ans += to_string(i);
      break;
    }
  }

  cout << ans << endl;
}
