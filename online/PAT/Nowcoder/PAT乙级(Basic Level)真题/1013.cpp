// 组最小个数

#include <iostream>
#include <algorithm>
using namespace std;

int cnt[10];

signed main()
{
  for (int i = 0; i < 10; ++i)
  {
    int num; cin >> num;
    cnt[i] = num;
  }

  for (int i = 1; i < 10; ++i) {
    if (cnt[i]) {
      cout << i, --cnt[i];
      break;
    }
  }

  for (int i = 0; i < 10; ++i) {
    while (cnt[i]) {
      cout << i, --cnt[i];
    }
  }
  cout << endl;
}
