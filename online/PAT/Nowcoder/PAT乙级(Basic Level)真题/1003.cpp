#include <bits/stdc++.h>
using namespace std;

int prime[10010];
int cnt = 1;

bool IsPrime(int number)
{
  int range = int(sqrt(number) + 1);
  for (int i=2; i<=range; ++i) {
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

signed main()
{
  prime[cnt++] = 2;
  for (int num=3; cnt<10010; ++num)
  {
    if (IsPrime(num))
      prime[cnt++] = num;
  }

  int m, n; cin >> m >> n;
  for (int i=m, used=0; i<=n; ++i) {
    if (used % 10 != 0) cout << ' ';
    cout << prime[i], used++;
    if (used % 10 == 0) cout << endl;
  }
  cout << endl;
}
