#include <iostream>
#include <queue>
using namespace std;
int n, m, q;
int grid[1100][1100];
bool vis[1100][1100];
int grp[1100][1100];
int size[1100*1100];
int cnt = 0;
int timer[1100][1100];
void dfs (int x, int y, int col) {
	if (x < 0 || x > n-1 || y < 0 || y > m-1) return;
	if (vis[x][y]) return;
	if (grid[x][y] != col) return;
	vis[x][y] = true;
	grp[x][y] = cnt;
	size[cnt]++;
	dfs(x+1, y, col);
	dfs(x-1, y, col);
	dfs(x, y+1, col);
	dfs(x, y-1, col);
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> q;
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> inp;
			grid[i][j] = inp-'0';
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!vis[i][j]) {
				dfs(i, j, grid[i][j]);
				cnt++;
			}
		}
	}
	queue< pair<int, int> > bfs;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (size[grp[i][j]] == 1) {
				timer[i][j] = -1;
			} else {
				timer[i][j] = 0;
				bfs.push(make_pair(i, j));
			}
		}
	}
	while (bfs.size() > 0) {
		pair<int, int> cur = bfs.front();
		bfs.pop();
		if (cur.first < n-1 && timer[cur.first+1][cur.second] == -1) {
			timer[cur.first+1][cur.second] = timer[cur.first][cur.second]+1;
			bfs.push(make_pair(cur.first+1, cur.second));
		}
		if (cur.first > 0 && timer[cur.first-1][cur.second] == -1) {
			timer[cur.first-1][cur.second] = timer[cur.first][cur.second]+1;
			bfs.push(make_pair(cur.first-1, cur.second));
		}
		if (cur.second < m-1 && timer[cur.first][cur.second+1] == -1) {
			timer[cur.first][cur.second+1] = timer[cur.first][cur.second]+1;
			bfs.push(make_pair(cur.first, cur.second+1));
		}
		if (cur.second > 0 && timer[cur.first][cur.second-1] == -1) {
			timer[cur.first][cur.second-1] = timer[cur.first][cur.second]+1;
			bfs.push(make_pair(cur.first, cur.second-1));
		}
	}
	int ai, bi;
	long long ci;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		if (ci < timer[ai][bi] || timer[ai][bi] == -1) {
			cout << grid[ai][bi] << endl;
		} else {
			cout << (grid[ai][bi] + ((ci-timer[ai][bi])%2))%2 << endl;
		}
	}
}