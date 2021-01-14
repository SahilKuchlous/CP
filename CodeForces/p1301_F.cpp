#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;
int grid[1010][1010];
int dist[1010][1010][50];
vector< pair<int, int> > grps[50];
bool done[50];
queue< pair<int, int> > q;
void calc (int col) {
	for (auto i: grps[col]) {
		dist[i.first][i.second][col] = 0;
		q.push(i);
	}
	for (int i=0; i<k; i++) {
		done[i] = false;
	}
	while (q.size() > 0) {
		pair<int, int> cur = q.front();
		q.pop();
		if (!done[grid[cur.first][cur.second]]) {
			for (auto i: grps[grid[cur.first][cur.second]]) {
				if (dist[i.first][i.second][col] == -1) {
					dist[i.first][i.second][col] = dist[cur.first][cur.second][col]+1;
					q.push(i);
				}
			}
			done[grid[cur.first][cur.second]] = true;
		}
		for (int i=0; i<4; i++) {
			if (cur.first+dx[i] >= 0 && cur.first+dx[i] < n && cur.second+dy[i] >= 0 && cur.second+dy[i] < m && dist[cur.first+dx[i]][cur.second+dy[i]][col] == -1) {
				dist[cur.first+dx[i]][cur.second+dy[i]][col] = dist[cur.first][cur.second][col]+1;
				q.push(make_pair(cur.first+dx[i], cur.second+dy[i]));
			}
		}
	}
}
int main () {
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
			grid[i][j]--;
			grps[grid[i][j]].push_back(make_pair(i, j));
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			for (int c=0; c<k; c++) {
				dist[i][j][c] = -1;
			}
		}
	}
	for (int i=0; i<k; i++) {
		calc(i);
	}
	int q;
	cin >> q;
	int r1, c1, r2, c2;
	for (int i=0; i<q; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		int o = abs(r2-r1)+abs(c2-c1);
		for (int j=0; j<k; j++) {
			o = min(o, dist[r1][c1][j]+dist[r2][c2][j]+1);
		}
		cout << o << endl;
	}
}