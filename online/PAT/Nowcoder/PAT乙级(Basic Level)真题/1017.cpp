// 打印沙漏

#include <iostream>
using namespace std;

int main()
{
  int num; char ch; cin >> num >> ch;

  int edge = 1, line = 1, tot = 1;  // 边界上的符号数量，行数，使用的符号数量
  while (tot + (edge+2)*2 <= num)
  {
    edge += 2, line += 2, tot += edge*2;
  }

  int sign = edge, space = 0, vec = -2;
  while (line--)
  {
    space = (edge - sign) / 2;
    for (int i = 0; i < space; ++i) cout << ' ';
    for (int i = 0; i < sign; ++i) cout << ch;
    cout << endl;

    sign += vec;
    if (sign < 0)
      vec = -vec, sign += 2 * vec;
  }
  cout << num - tot << endl;
}
