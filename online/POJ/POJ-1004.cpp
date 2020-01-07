#include <cstdio>
#include <vector>
#include <numeric>
using namespace std;

int main()
{
	vector<double> num(12);
	for (int i = 0; i < 12; ++i)
	{
		scanf("%lf", &num[i]);
	}

	double average = accumulate(num.begin(), num.end(), 0.0) / 12;
	printf("$%.02f\n", average);
}

