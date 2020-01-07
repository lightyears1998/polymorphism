#include <bits/stdc++.h>
using namespace std;

const int maxN = 1010;

int ar, ac, br, bc;
int a[maxN][maxN];
int b[maxN][maxN];
int c[maxN][maxN];

int main()
{
	cin >> ar >> ac;
	for (int i=0; i<ar; ++i) {
		for (int j=0; j<ac; ++j) {
			cin >> a[i][j];
		} 
	}
	
	cin >> br >> bc;
	for (int i=0; i<br; ++i) {
		for (int j=0; j<bc; ++j) {
			cin >> b[i][j];
		} 
	}
	
	if (ac != br) {
		printf("Error: %d != %d\n", ac, br);
	}
	else {
		for (int i=0; i<ar; ++i) {
			for (int j=0; j<bc; ++j) {
				for (int k=0; k<ac; ++k) {
					c[i][j] += a[i][k]*b[k][j];
				}
			}
		}
		cout << ar << ' ' << bc << endl;
		for (int i=0; i<ar; ++i) {
			for (int j=0; j<bc; ++j) {
				if (j) cout << ' ';
				cout << c[i][j];
			}
			cout << endl;
		}
	}
}
