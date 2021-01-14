#include <iostream>
#include <queue>
using namespace std;
#define MAXN 1005
int n, m, k;
char grid[MAXN][MAXN];
int sx, sy, ex, ey;
queue< pair<int, int> > ord;
bool vis[MAXN][MAXN][4];
int dist[MAXN][MAXN];
bool done[MAXN][MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
			dist[i][j] = 1e8;
		}
	}
	cin >> sx >> sy >> ex >> ey;
	sx--; sy--; ex--; ey--;
	ord.push(make_pair(sx, sy));
	vis[sx][sy][0] = vis[sx][sy][1] = vis[sx][sy][2] = vis[sx][sy][3] = true;
	dist[sx][sy] = 0;
	while (ord.size() > 0) {
		pair<int, int> cur = ord.front();
		ord.pop();
		if (done[cur.first][cur.second]) continue;
		done[cur.first][cur.second] = true;
		if (cur.first == ex && cur.second == ey) {
			cout << dist[ex][ey] << endl;
			return 0;
		}
		for (int i=cur.first+1; i<=min(n-1, cur.first+k); i++) {
			if (vis[i][cur.second][0] || grid[i][cur.second] == '#') break;
			vis[i][cur.second][0] = true;
			dist[i][cur.second] = min(dist[i][cur.second], dist[cur.first][cur.second]+1);
			ord.push(make_pair(i, cur.second));
		}
		for (int i=cur.first-1; i>=max(0, cur.first-k); i--) {
			if (vis[i][cur.second][1] || grid[i][cur.second] == '#') break;
			vis[i][cur.second][1] = true;
			dist[i][cur.second] = min(dist[i][cur.second], dist[cur.first][cur.second]+1);
			ord.push(make_pair(i, cur.second));
		}
		for (int j=cur.second+1; j<=min(m-1, cur.second+k); j++) {
			if (vis[cur.first][j][2] || grid[cur.first][j] == '#') break;
			vis[cur.first][j][2] = true;
			dist[cur.first][j] = min(dist[cur.first][j], dist[cur.first][cur.second]+1);
			ord.push(make_pair(cur.first, j));
		}
		for (int j=cur.second-1; j>=max(0, cur.second-k); j--) {
			if (vis[cur.first][j][3] || grid[cur.first][j] == '#') break;
			vis[cur.first][j][3] = true;
			dist[cur.first][j] = min(dist[cur.first][j], dist[cur.first][cur.second]+1);
			ord.push(make_pair(cur.first, j));
		}
	}
	cout << -1 << endl;
}