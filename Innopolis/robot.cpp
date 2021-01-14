#include <iostream>
#include <vector>
using namespace std;
int main () {
	int n, m, q;
	cin >> m >> n >> q;
	int bx, by;
	cin >> by >> bx;
	vector<int> dx = {0, -1, 0, 1};
	vector<int> dy = {1, 0, -1, 0};
	while (q--) {
		int px, py;
		char inp;
		cin >> py >> px >> inp;
		int dir;
		if (inp == 'E') dir = 0;
		if (inp == 'S') dir = 1;
		if (inp == 'W') dir = 2;
		if (inp == 'N') dir = 3;
		bool grid[n+2][m+2];
		for (int i=0; i<=n+1; i++) {
			for (int j=0; j<=m+1; j++) {
				grid[i][j] = true;
			}
		}
		for (int i=0; i<=n+1; i++) {
			grid[i][0] = false;
			grid[i][m+1] = false;
		}
		for (int j=0; j<=m+1; j++) {
			grid[0][j] = false;
			grid[n+1][j] = false;
		}
		grid[bx][by] = false;
		int o = 0;
		while (true) {
			grid[px][py] = false;
			o++;
			if (!grid[px+dx[dir]][py+dy[dir]]) {
				dir = (dir+1)%4;
				if (!grid[px+dx[dir]][py+dy[dir]]) break;
			}
			px += dx[dir];
			py += dy[dir];
		}
		cout << o << endl;
	}
}