#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dx = {1, 1, 1, 0, -1, -1, -1, 0};
vector<int> dy = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m;
int height[2005][2005];
vector< pair< int, pair<int, int> > > ord;
bool vis[2005][2005];
int peak[2005][2005];
int cnt = -1;
vector< pair<int, int> > o;
int par[2005*2005];
int high[2005*2005];
vector<int> top[2005*2005];
bool is_peak[2005][2005];
vector< pair<int, int> > grp;
bool dfs1 (int x, int y) {
	vis[x][y] = true;
	grp.push_back(make_pair(x, y));
	for (int i=0; i<8; i++) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (height[nx][ny] > height[x][y]) is_peak[x][y] = false;
		if (height[nx][ny] != height[x][y] || vis[nx][ny]) continue;
		if (!dfs1(nx, ny)) is_peak[x][y] = false;
	}
	return is_peak[x][y];
}
int root (int x) {
	while (x != par[x]) {
		par[x] = par[par[x]];
		x = par[x];
	}
	return x;
}
void merge (int r1, int r2) {
	if (high[r2] > high[r1] || (high[r1] == high[r2] && top[r1].size() < top[r2].size())) swap(r1, r2);
	par[r2] = r1;
	if (high[r1] == high[r2]) {
		for (auto k: top[r2]) top[r1].push_back(k);
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> height[i][j];
			ord.push_back(make_pair(-height[i][j], make_pair(i, j)));
			vis[i][j] = false;
			peak[i][j] = -1;
			par[i*m+j] = i*m+j;
			high[i*m+j] = 0;
			is_peak[i][j] = true;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (!vis[i][j]) {
				if (dfs1(i, j)) {
					cnt++;
					o.push_back(make_pair(height[i][j], 0));
					for (auto k: grp) {
						int x = k.first, y = k.second;
						peak[x][y] = cnt;
						high[x*m+y] = height[x][y];
						top[x*m+y] = {cnt};
					}
				}
				grp.clear();
			}
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			vis[i][j] = false;
		}
	}
	sort(ord.begin(), ord.end());
	for (auto i: ord) {
		int x = i.second.first, y = i.second.second;
		vis[x][y] = true;
		for (int j=0; j<8; j++) {
			int nx = x+dx[j], ny = y+dy[j];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || !vis[nx][ny]) continue;
			int r1 = root(x*m+y), r2 = root(nx*m+ny);
			if (r1 == r2) continue;
			if (high[r1] > high[r2]) {
				for (auto k: top[r2]) o[k].second = max(o[k].second, height[x][y]);
			}
			if (high[r2] > high[r1]) {
				for (auto k: top[r1]) o[k].second = max(o[k].second, height[x][y]);
			}
			merge(r1, r2);
		}
	}
	sort(o.begin(), o.end(), greater< pair<int, int> >());
	cout << o.size() << '\n';
	for (auto i: o) {
		cout << i.first << " " << i.second << '\n';
	}
}