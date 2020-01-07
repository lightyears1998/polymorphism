// 程序运行时间

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int t1, t2; cin >> t1 >> t2;
  int diff = int(double(abs(t1 - t2)) / 100 + 0.5);

  int hh, mm, ss;
  ss = diff % 60; diff /= 60;
  mm = diff % 60; diff /= 60;
  hh = diff % 60; diff /= 60;
  printf("%02d:%02d:%02d\n", hh, mm, ss);
}
