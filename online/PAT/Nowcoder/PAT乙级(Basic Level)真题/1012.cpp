// A+B的D进制数

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
using LL = long long;

string ans;

signed main()
{
  LL a, b; cin >> a >> b;
  int d; cin >> d;

  LL sum = a + b;
  while (sum) {
    ans += char('0' + sum%d);
    sum /= d;
  }
  if (!ans.length()) ans = "0";
  reverse(ans.begin(), ans.end());

  cout << ans << endl;
}
