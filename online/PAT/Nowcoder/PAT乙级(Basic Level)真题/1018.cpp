// 人口普查

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct People
{
	string name;
	int year, month, day;

	bool operator < (const People oth) const
	{
		if (year != oth.year) return year < oth.year;
		if (month != oth.month) return month < oth.month;
		return day < oth.day;
	}
};

People future { "Now", 2014, 9, 7 };
People past { "Past", 1814, 9, 5 };

int ok;
vector<People> vec;

signed main()
{
	cin >> n; 
	vec.resize(n);
	
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i].name;

		string str; cin >> str;
		vec[i].year = stol(str.substr(0, 4));
		vec[i].month = stol(str.substr(5, 2));
		vec[i].day = stol(str.substr(8, 2));
	}

	sort(vec.begin(), vec.end());

	for (unsigned i = 0; i < vec.size(); ++i)
	{
		if (past < vec[i] && vec[i] < future) ++ok;
	}
	cout << ok << ' ';

	for (int i = 0; i < int(vec.size()); ++i)
	{
		if (past < vec[i]) {
			cout << vec[i].name << ' ';
			break;
		}
	}

	for (int i = vec.size()-1; i >= 0; --i)
	{
		if (vec[i] < future) {
			cout << vec[i].name << endl;
			break;
		}
	}
}