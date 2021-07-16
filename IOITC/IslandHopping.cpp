#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300
int n;
char grid[MAXN][MAXN];
int sx, sy;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
int cnt;
bool vis[MAXN][MAXN];
vector< vector< pair<int, int> > > islands;
int id[MAXN][MAXN];
int dist[MAXN][MAXN];
vector< pair<int, int> > border;
vector< pair<int, int> > temp;
int edges[MAXN][MAXN];
int cost[MAXN];
int upd[MAXN];
int o[MAXN];
void init () {
	cnt = 0;
	for (int i=0; i<n; i++) {
		cost[i] = 1e8;
		o[i] = 0;
		for (int j=0; j<n; j++) {
			vis[i][j] = false;
			id[i][j] = -1;
			dist[i][j] = 0;
		}
	}
	islands.clear();
}
void dfs1 (int x, int y) {
	vis[x][y] = true;
	islands[cnt].push_back(make_pair(x, y));
	id[x][y] = cnt;
	for (int i=0; i<4; i++) {
		if (x+dx[i] < 0 || x+dx[i] >= n || y+dy[i] < 0 || y+dy[i] >= n || grid[x+dx[i]][y+dy[i]] == '0' || vis[x+dx[i]][y+dy[i]]) continue;
		dfs1(x+dx[i], y+dy[i]);
	}
}
void bfs1 (int st) {
	for (int d = 1; d<n*n; d++) {
		temp.clear();
		for (auto i: border) {
			int x = i.first, y = i.second;
			for (int j=0; j<4; j++) {
				if (x+dx[j] < 0 || x+dx[j] >= n || y+dy[j] < 0 || y+dy[j] >= n || vis[x+dx[j]][y+dy[j]]) continue;
				temp.push_back(make_pair(x+dx[j], y+dy[j]));
				vis[x+dx[j]][y+dy[j]] = true;
				if (id[x+dx[j]][y+dy[j]] != -1 && dist[st][id[x+dx[j]][y+dy[j]]] == 0) {
					dist[st][id[x+dx[j]][y+dy[j]]] = d;
				}
			}
		}
		border.clear();
		if (temp.size() == 0) break;
		for (auto i: temp) {
			border.push_back(i);
		}
		temp.clear();
	}

}
void solve () {
	cin >> n;
	init();
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	cin >> sx >> sy;
	sx--; sy--;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (grid[i][j] == '1' && !vis[i][j]) {
				islands.push_back({});
				dfs1(i, j);
				cnt++;
			}
		}
	}
	for (int i=0; i<cnt; i++) {
		for (int j=0; j<n; j++) {
			for (int k=0; k<n; k++) {
				vis[j][k] = false;
			}
		}
		for (auto j: islands[i]) {
			vis[j.first][j.second] = true;
			border.push_back(j);
		}
		bfs1(i);
	}
	int root = id[sx][sy];
	cost[root] = 0;
	for (int i=1; i<=2*n; i++) {
		for (int j=0; j<cnt; j++) {
			upd[j] = 1e8;
			for (int k=0; k<cnt; k++) {
				if (j == k) continue;
				upd[j] = min(upd[j], cost[k]+dist[j][k]);
			}
		}
		for (int j=0; j<cnt; j++) {
			if (upd[j] <= dist[root][j]) o[j] = i;
			cost[j] = upd[j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (grid[i][j] == '1') {
				cout << o[id[i][j]] << " ";
			} else {
				cout << 0 << " ";
			}
		}
		cout << '\n';
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
/*
2
7
1011101
0000000
0000000
0000000
0000000
0000000
0000000
1 1
9
111111101
100000000
100000000
100000000
100000000
100000000
100000000
100000000
111111101
9 9
*/