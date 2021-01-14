#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int n, m;
char grid[501][501];
vector<int> dx = {1, 1, -1, -1};
vector<int> dy = {1, -1, 1, -1};
vector<int> px = {0, 0, -1, -1};
vector<int> py = {0, -1, 0, -1};
vector<char> req = {'\\', '/', '/', '\\'};
deque< pair<int, int> > ord;
int dist[501][501];
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			dist[i][j] = 1e8;
		}
	}
	ord.push_back(make_pair(0, 0));
	dist[0][0] = 0;
	while (ord.size() > 0) {
		pair<int, int> cur = ord.front();
		ord.pop_front();
		if (cur.first == n && cur.second == m) {
			cout << dist[cur.first][cur.second] << endl;
			return 0;
		}
		for (int i=0; i<4; i++) {
			int nx = cur.first+dx[i];
			int ny = cur.second+dy[i];
			int wt = (grid[cur.first+px[i]][cur.second+py[i]] != req[i]);
			if (nx < 0 || ny < 0 || nx > n || ny > m || dist[nx][ny] <= dist[cur.first][cur.second]+wt) continue;
			dist[nx][ny] = dist[cur.first][cur.second]+wt;
			if (wt == 0) {
				ord.push_front(make_pair(nx, ny));
			} else {
				ord.push_back(make_pair(nx, ny));
			}
		}
	}
	cout << "NO SOLUTION" << endl;
}