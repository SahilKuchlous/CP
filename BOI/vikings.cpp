#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m;
char grid[700][700];
int sx, sy;
int ex, ey;
int vx, vy;
int v_dist[700][700];
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
queue< pair<int, int> > bfs;
int blk[700][700];
int s_dist[700][700];
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'Y') {
				sx = i; sy = j;
			}
			if (grid[i][j] == 'T') {
				ex = i; ey = j;
			}
			if (grid[i][j] == 'V') {
				vx = i; vy = j;
			}
			v_dist[i][j] = -1;
			blk[i][j] = 1e8;
			s_dist[i][j] = -1;
		}
	}
	v_dist[vx][vy] = 0;
	bfs.push(make_pair(vx, vy));
	while (bfs.size() > 0) {
		pair<int, int> cur = bfs.front();
		bfs.pop();
		for (int i=0; i<4; i++) {
			int nx = cur.first+dx[i];
			int ny = cur.second+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || v_dist[nx][ny] > -1 || grid[nx][ny] == 'I') continue;
			v_dist[nx][ny] = v_dist[cur.first][cur.second]+1;
			bfs.push(make_pair(nx, ny));
		}
	}
	for (int i=0; i<n; i++) {
		int cur_min = 1e8;
		for (int j=0; j<m; j++) {
			if (v_dist[i][j] == -1) {
				blk[i][j] = -1;
				cur_min = 1e8;
				continue;
			}
			cur_min = min(cur_min, v_dist[i][j]);
			blk[i][j] = min(blk[i][j], cur_min);
		}
	}
	for (int i=0; i<n; i++) {
		int cur_min = 1e8;
		for (int j=m-1; j>=0; j--) {
			if (v_dist[i][j] == -1) {
				blk[i][j] = -1;
				cur_min = 1e8;
				continue;
			}
			cur_min = min(cur_min, v_dist[i][j]);
			blk[i][j] = min(blk[i][j], cur_min);
		}
	}
	for (int j=0; j<m; j++) {
		int cur_min = 1e8;
		for (int i=0; i<n; i++) {
			if (v_dist[i][j] == -1) {
				blk[i][j] = -1;
				cur_min = 1e8;
				continue;
			}
			cur_min = min(cur_min, v_dist[i][j]);
			blk[i][j] = min(blk[i][j], cur_min);
		}
	}
	for (int j=0; j<m; j++) {
		int cur_min = 1e8;
		for (int i=n-1; i>=0; i--) {
			if (v_dist[i][j] == -1) {
				blk[i][j] = -1;
				cur_min = 1e8;
				continue;
			}
			cur_min = min(cur_min, v_dist[i][j]);
			blk[i][j] = min(blk[i][j], cur_min);
		}
	}
	s_dist[sx][sy] = 0;
	bfs.push(make_pair(sx, sy));
	while (bfs.size() > 0) {
		pair<int, int> cur = bfs.front();
		if (cur.first == ex && cur.second == ey) {
			cout << "YES" << endl;
			return 0;
		}
		bfs.pop();
		for (int i=0; i<4; i++) {
			int nx = cur.first+dx[i];
			int ny = cur.second+dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || s_dist[nx][ny] > -1 || blk[nx][ny] <= s_dist[cur.first][cur.second]+1) continue;
			s_dist[nx][ny] = s_dist[cur.first][cur.second]+1;
			bfs.push(make_pair(nx, ny));
		}
	}
	cout << "NO" << endl;
}