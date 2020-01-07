// 旧键盘

#include <iostream>
#include <map>
using namespace std;

string a, b;
map<char, bool> discovered;

int main()
{
  cin >> a >> b;

  unsigned pos = 0;
  for (auto ch : a)
  {
    if (pos < b.length() && b[pos] == ch)
      ++pos;
    else
    {
      if (!discovered[toupper(ch)])
        cout << char(toupper(ch));
      discovered[toupper(ch)] = true;
    }
  }
  cout << endl;
}
