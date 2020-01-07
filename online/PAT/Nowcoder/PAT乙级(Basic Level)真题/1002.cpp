#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL val[6];
int cnt[6];

signed main()
{
  int n; cin >> n;
  int sign = 1;

  while (n--){
    LL num; cin >> num;
    switch(num % 5)
    {
      case 0: {
        if (num % 2 == 0) {
          val[1] += num;
          cnt[1] = true;
        }
        break;
      }
      case 1: {
        val[2] += sign * num;
        sign = -sign;
        cnt[2] = true;
        break;
      }
      case 2: {
        val[3]++;
        cnt[3] = true;
        break;
      }
      case 3: {
        val[4] += num;
        cnt[4]++;
        break;
      }
      case 4: {
        val[5] = max(val[5], num);
        cnt[5] = true;
        break;
      }
    }
  }

  for (int i=1; i<=5; ++i)
  {
    if (i != 1) cout << ' ';
    if (cnt[i]) {
      if (i != 4)
        cout << val[i];
      else {
        cout.precision(1);
        cout.flags(ios::fixed);
        cout << (double(val[i])/cnt[i]);
      }
    }
    else
      cout << 'N';
  }
  cout << endl;
}
