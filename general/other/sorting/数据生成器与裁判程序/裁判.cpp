#include <bits/stdc++.h>
using namespace std;
const int maxN = 1008611; 

// 裁判程序 
// 参数standard - 标准答案 
// 参数subject  - 用户答案  

int main()
{
	FILE *standard = fopen("stdout.txt", "r");
	FILE *subject  = fopen("out.txt", "r"); 
	
	bool ok = true; int kase = 0; 
	while (true)
	{
		char std[maxN], sub[maxN]; 
		if (fgets(std, maxN, standard) == NULL) {
			break;
		}
		if (fgets(sub, maxN, subject) == NULL) {
			ok = false;
			break; 
		} 
		if (strcmp(std, sub) != 0) {
			ok = false;
			break;
		} 
		++kase; 
	}
	
	if (ok) {
		printf("Accepted\n"); 
	} 
	else {
		printf("Wrong Answer on Test %d\n", kase+1); 
	} 
	
	getchar(); 
}

