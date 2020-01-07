#include <bits/stdc++.h>
using namespace std;

// It works but it's ugly.

// 与乘法和除法有关的英语单词
// 乘法 - multiplication
// 除法 - division
// 被乘数 乘数 积 - multiplier multiplicand (factor) product
// 被除数 除数 商 - dividend divisor quotient
// 分子 分母 - numerator denominator

char org[1010];
char ans[1010], fac[1010];

bool judge(int bgn)
{
	for (int i = bgn; ans[i]; ++i)
		if (ans[i] != '1') return false;
	return true;
}

int main()
{
	scanf("%s", org); int len = strlen(org);
	reverse(org, &org[len]);
	
	ans[0] = '0';
	for (int i = 0; !judge(i); ++i)
	{
		int acur = ans[i]-'0', org0 = org[0]-'0';
		for (int fcur = 0; fcur < 10; ++fcur)
		{
			if ((fcur*org0+acur)%10==1) 
			{
				fac[i] = fcur + '0';
				
				int enroll = 0;
				for (int k=0; k<len; ++k)
				{
					int orgk = org[k]-'0';
					int ansk = ans[i+k] ? ans[i+k]-'0' : 0;
					int rslt = orgk*fcur+ansk+enroll;
					ansk = rslt % 10, enroll = rslt / 10;
					ans[i+k] = ansk+'0';
				}
				if (enroll) ans[i+len] = enroll+'0';
			}
		}
	}
	
	int faclen = strlen(fac), anslen = strlen(ans);
	for (int i=faclen-1; i>=0; --i) printf("%c", fac[i]);
	printf(" %d\n", anslen);
}
