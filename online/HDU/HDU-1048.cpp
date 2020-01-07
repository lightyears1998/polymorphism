#include <bits/stdc++.h>
using namespace std;

string cipher = "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
string plain  = "V W X Y Z A B C D E F G H I J K L M N O P Q R S T U";

void decrypt(string& text)
{
	for (unsigned i = 0; i < text.size(); ++i)
	{
		unsigned pos = cipher.find(text[i]);
		if (~pos) cout << plain[pos];
		else cout << text[i];
	}
	cout << endl;
}

int main()
{
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	string s; 
	while (getline(cin, s))
	{
		if (s == "START") while (getline(cin, s))
		{
			if (s == "END") break;
			decrypt(s);
		}
	}
}

