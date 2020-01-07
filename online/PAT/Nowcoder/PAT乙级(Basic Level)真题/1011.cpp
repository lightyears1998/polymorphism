// 个位数统计

#include <iostream>
#include <string>
using namespace std;

int cnt[10];

signed main()
{
  string num; cin >> num;
  for (auto ch : num)
    cnt[ch-'0']++;

  for (int i = 0; i < 10; ++i)
  {
    if (cnt[i])
    {
      cout << i << ':' << cnt[i] << endl;
    }
  }
}
