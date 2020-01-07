// 可以改进的地方
// 如何优雅地表示向量三角形？

#include <iostream>
#include <map>
using namespace std;

int n;
int awin, draw, alose;

map<string, int> awinc, bwinc;

int awinbyB, awinbyC, awinbyJ;
int bwinbyB, bwinbyC, bwinbyJ;

// 返回真，如果a击败b
bool win(const string &a, const string &b)
{
	if (a == "C" && b == "J") return true;
	if (a == "J" && b == "B") return true;
	if (a == "B" && b == "C") return true;
	return false;
}

signed main()
{
	cin >> n;

	string a, b;
	while (n--)
	{
		cin >> a >> b;
		if (win(a, b)) ++awin, ++awinc[a];
		else if (win(b, a)) ++alose, ++bwinc[b];
		else ++draw;
	}
	cout << awin << ' ' << draw << ' ' << alose << endl;
	cout << alose << ' ' << draw <<  ' ' << awin << endl;

	// 可以改进的地方
	if (awinc["B"] >= awinc["C"] && awinc["B"] >= awinc["J"])
		cout << "B";
	else if (awin["C"] >= awin["J"])
		cout << "C";
	else cout << "J";
	cout << ' ';
	if (bwinc["B"] >= bwinc["C"] && bwinc["B"] >= bwinc["J"])
		cout << "B";
	else if (bwinc["C"] >= bwinc["J"])
		cout << "C";
	else cout << "J";
	cout << endl;
}