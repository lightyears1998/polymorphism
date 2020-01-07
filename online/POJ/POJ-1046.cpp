#include <cstdio>
#include <cmath>

struct color
{
	int r, g, b;
} clors[16];

double square(double c)
{
	return c * c;
}

double dis(color a, color b)
{
	return sqrt(square(a.r-b.r) + square(a.g-b.g) + square(a.b-b.b));
}

int main()
{
	for (int i = 0; i < 16; ++i)
		scanf("%d%d%d", &clors[i].r, &clors[i].g, &clors[i].b);
		
	color c;
	while (scanf("%d%d%d", &c.r, &c.g, &c.b) == 3 && ~c.r)
	{
		double amin = dis(c, clors[0]); int idx = 0;
		for (int i = 1; i < 16; ++i)
		{
			if (amin > dis(c, clors[i])) {
				amin = dis(c, clors[i]), idx = i;
			}
		}
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", c.r, c.g, c.b, clors[idx].r, clors[idx].g, clors[idx].b); 
	} 
} 

