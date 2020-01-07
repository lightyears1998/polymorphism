// 德才论

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 100100;

int N, L, H; 
int OK;  // 上线人数

struct student
{
	string id;
	int de, cai;  // 德才
	int type;     // 类型 0未上线 1其他上线类型 2尚有得胜才 3得胜才 4德才兼备

	bool operator < (const student &oth) const
	{
		if (type != oth.type) return type > oth.type;
		if (de + cai != oth.de + oth.cai) return de+cai > oth.de+oth.cai;
		if (de != oth.de) return de > oth.de;
		return id < oth.id;
	}
} stu[MAXN];

void judge(student & stu)
{
	if (stu.de < L || stu.cai < L) stu.type = 0;
	else if (stu.de >= H && stu.cai >= H) stu.type = 4;
	else if (stu.de >= H) stu.type = 3;
	else if (stu.de >= stu.cai) stu.type = 2;  // WA1) 不低于即>=
	else stu.type = 1;

	if (stu.type > 0) ++OK;
}

signed main()
{
	cin >> N >> L >> H;
	for (int i=0; i<N; ++i)
	{
		cin >> stu[i].id;
		cin >> stu[i].de >> stu[i].cai;
		judge(stu[i]);
	}
	sort(stu, stu+N);

	cout << OK << endl;
	for (int i=0; i<OK; ++i)
	{
		cout << stu[i].id << ' ' << stu[i].de << ' ' << stu[i].cai << endl;
	}
}