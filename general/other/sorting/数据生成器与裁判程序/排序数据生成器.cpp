#include <bits/stdc++.h>
using namespace std;

// 排序数据生成器
// 参数t - 数据组数
// 参数n - 数据大小

int n = 50, t = 100;
long long arr[1000]; 

int main()
{
	FILE *in = fopen("stdin.txt", "w");
	FILE *out = fopen("stdout.txt", "w");
	
	fprintf(in, "%d\n", t); 
	while (t--)
	{ 
		fprintf(in, "%d\n", n); 
		for (int i=0; i<n; ++i) {
			arr[i] = rand()*rand();
			if (i) fprintf(in, " ");
			fprintf(in, "%lld", arr[i]); 
		}
		fprintf(in, "\n"); 
		
		sort(arr, arr+n); 
		for (int i=0; i<n; ++i) {
			if (i) fprintf(out, " ");
			fprintf(out, "%lld", arr[i]); 
		}
		fprintf(out, "\n"); 
	} 
	
	fclose(in), fclose(out); 
}
