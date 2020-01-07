#include <bits/stdc++.h>
using namespace std;

struct node 
{
	string name;
	int num, cnt;
	bool operator <(const node b) const 
	{
		if (num != b.num) return num > b.num;
		return cnt < b.cnt;
	} 
};

string line;
set<int> tag;
priority_queue<node> ranklist;

void print()
{
	string name = ranklist.top().name; ranklist.pop();
	if (ranklist.size()) 
		print();
	else {
		cout << name; return;
	}
	cout << " " << name;
} 

int main()
{
	int n; cin >> n;
	while (n--) {
		tag.clear(); 
		
		string name; cin >> name;
		int cnt; cin >> cnt;
		
		int id; 
		for (int i=0; i<cnt; ++i) 
			cin >> id, tag.insert(id);
		ranklist.push({name, (int)tag.size(), cnt});
		if (ranklist.size() > 3U) ranklist.pop();
	} 
	
	int holder = 3-ranklist.size();
	print();
	while (holder--) cout << " -";
	cout << endl;
}
