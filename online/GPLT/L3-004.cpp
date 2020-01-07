#include <bits/stdc++.h>
using namespace std;
using node = tuple<int, int, int>;

int M, N, L, T;
int pic[2048][512][128];
int cur, rslt;
queue<node> que;

const int dir[6][3] {1,0,0, -1,0,0, 0,1,0, 0,-1,0, 0,0,1, 0,0,-1};

bool legal(int x, int y, int z) {
	return x>=0&&x<M && y>=0&&y<N && z>=0&&z<L;
}

void godeep(int x, int y, int z) {
	pic[x][y][z] = 0;
	que.push(make_tuple(x, y, z));
	
	while (!que.empty()) 
	{
		++cur; node now = que.front(); que.pop();
		int x = get<0>(now), y = get<1>(now), z = get<2>(now);

		for (int i=0; i<6; ++i) {
			int nx = x+dir[i][0], ny = y+dir[i][1], nz = z+dir[i][2];
			if (legal(nx, ny, nz) && pic[nx][ny][nz]) {
				pic[nx][ny][nz] = 0;
				que.push(make_tuple(nx, ny, nz));
			}
		}
	}
}

void search() {
	for (int i=0; i<L; ++i) {
		for (int j=0; j<M; ++j) {
			for (int k=0; k<N; ++k) 
			{
				if (pic[j][k][i]) { 
					godeep(j, k, i);
					if (cur >= T) rslt += cur;
					cur = 0;
				}
			}
		}
	}
}

int main()
{
	cin >> M >> N >> L >> T;
	
	for (int i=0; i<L; ++i) {
		for (int j=0; j<M; ++j) {
			for (int k=0; k<N; ++k) {
				cin >> pic[j][k][i];
			}
		}
	}
	
	search();
	cout << rslt << endl;
}
