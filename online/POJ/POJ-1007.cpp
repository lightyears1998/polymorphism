#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct DNA
{
	int sortness;
	string dna;
	bool operator < (const DNA oth) const
	{
		return sortness < oth.sortness;
	}
} item[105];

int main()
{
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> item[i].dna;
		for (unsigned j = 0; j < item[i].dna.size(); ++j)
		{
			for (unsigned k = j+1; k < item[i].dna.size(); ++k)
			{
				if (item[i].dna[j] > item[i].dna[k]) 
					++item[i].sortness;
			}
		}
	}
	sort(item, item+m);
	for (int i = 0; i < m; ++i)
	{
		cout << item[i].dna << endl;
	}
}

