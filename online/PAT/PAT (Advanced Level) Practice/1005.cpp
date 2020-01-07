#include <iostream>
#include <string>
using namespace std;

string spell[] = {
  "zero", "one", "two", "three", "four", "five",
  "six", "seven", "eight", "nine", "ten"
};

int32_t main()
{
  string number; cin >> number;

  int tot = 0;
  for (const char &ch : number)
    tot += ch-'0';
  string ans = to_string(tot);
  for (unsigned i = 0; i < ans.length(); ++i)
  {
    if (i) cout << ' ';
    cout << spell[(ans[i] - '0')];
  }
  cout << endl;
}
