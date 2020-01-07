// 完美数列

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using LL = long long;

LL N, p;
vector<LL> nums;


int main()
{
	cin >> N >> p;

	while (N--)
	{
		LL idle; cin >> idle;
		nums.push_back(idle);
	}

	sort(nums.begin(), nums.end());

	LL ans = 1;
	for (unsigned i = 0; i < nums.size(); ++i)
	{
		LL tail = nums[i] * p;
		LL cnt = upper_bound(nums.begin(), nums.end(), tail) - nums.begin() - i;
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}