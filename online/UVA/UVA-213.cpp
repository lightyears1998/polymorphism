#include <bits/stdc++.h>
using namespace std;

int codes[8][1<<8];

int readmsg()
{
	int ch, len = 1, pos = 0;
	while ((ch = getchar()))
	{
		if (ch == '\n') {
			if (len==1&&pos==0) continue;
			return len;
		}
		if (ch == EOF) return 0;
		codes[len][pos++] = ch;
		if (pos+1==(1<<len)) pos = 0, ++len;
	}
	return len;
} 

int readint()
{
	int ch;
	do {
		ch = getchar();
	} while (ch == '\n');
	return ch-'0';
}

int readpos(int len)
{
	int pos = 0;
	for (int i=0; i<len; ++i) 
		pos = pos*2+readint();
	return pos;
}

int readlen()
{
	int len = 0;
	for (int i=0; i<3; ++i) 
		len=len*2+readint();
	return len;
}

signed main()
{
	while (readmsg())
	{
		int len;
		while ((len = readlen()))
		{
			int pos;
			while ((pos = readpos(len)) != (1<<len)-1)
				putchar(codes[len][pos]);
		}
		putchar('\n');
	}
}

