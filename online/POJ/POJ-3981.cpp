#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	while (getline(cin, s))
	{
		int pos;
		while (~(pos = s.find("you")))
		{
			s.replace(pos, 3, "we");
		}
		cout << s << endl;
	} 
}

