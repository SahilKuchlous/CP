#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> adj1[100100], adj2[100100];
bool root1[100100], root2[100100];
int timer = 0;
int in_t[100100], out_t[100100];
vector<int> tour;
void dfs1 (int x) {
	in_t[x] = timer;
	tour.push_back(x);
	timer++;
	for (auto i: adj2[x]) {
		dfs1(i);
	}
	out_t[x] = timer-1;
}
int segtree[400100][2];
void init (int x, int l, int r) {
	segtree[x][0] = r-l+1;
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
}
void update (int x, int l, int r, int a, int b, int v) {
	if (r < a || l > b) {
		return;
	}
	if (a <= l && r <= b) {
		segtree[x][1] += v;
		if (segtree[x][1] > 0) {
			segtree[x][0] = 0;
		} else {
			if (l < r) {
				segtree[x][0] = segtree[2*x+1][0]+segtree[2*x+2][0];
			} else {
				segtree[x][0] = 1;
			}
		}
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	if (segtree[x][1] == 0) {
		segtree[x][0] = segtree[2*x+1][0]+segtree[2*x+2][0];
	} else {
		segtree[x][0] = 0;
	}
}
int query () {
	return segtree[0][0];
}
long long ttl = 0;
bool vis[100100];
void dfs2 (int x) {
	vis[x] = true;
	update(0, 0, tour.size()-1, in_t[x], out_t[x], 1);
	ttl += query();
	for (auto i: adj1[x]) {
		dfs2(i);
	}
	update(0, 0, tour.size()-1, in_t[x], out_t[x], -1);
}
int main () {
	cin >> n >> m;
	char grid[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	int vals[n][m];
	int cnt = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] == 'U') {
				vals[i][j] = vals[i+1][j] = cnt;
				cnt++;
			}
			if (grid[i][j] == 'L') {
				vals[i][j] = vals[i][j+1] = cnt;
				cnt++;
			}
		}
	}
	for (int i=0; i<cnt; i++) {
		root1[i] = root2[i] = true;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if ((i+j)%2 == 0) {
				if (grid[i][j] == 'U' && i+2 < n) {
					adj1[vals[i+2][j]].push_back(vals[i][j]);
					root1[vals[i][j]] = false;
				}
				if (grid[i][j] == 'D' && i-2 >= 0) {
					adj1[vals[i-2][j]].push_back(vals[i][j]);
					root1[vals[i][j]] = false;
				}
				if (grid[i][j] == 'L' && j+2 < m) {
					adj1[vals[i][j+2]].push_back(vals[i][j]);
					root1[vals[i][j]] = false;
				}
				if (grid[i][j] == 'R' && j-2 >= 0) {
					adj1[vals[i][j-2]].push_back(vals[i][j]);
					root1[vals[i][j]] = false;
				}
			} else {
				if (grid[i][j] == 'U' && i+2 < n) {
					adj2[vals[i+2][j]].push_back(vals[i][j]);
					root2[vals[i][j]] = false;
				}
				if (grid[i][j] == 'D' && i-2 >= 0) {
					adj2[vals[i-2][j]].push_back(vals[i][j]);
					root2[vals[i][j]] = false;
				}
				if (grid[i][j] == 'L' && j+2 < m) {
					adj2[vals[i][j+2]].push_back(vals[i][j]);
					root2[vals[i][j]] = false;
				}
				if (grid[i][j] == 'R' && j-2 >= 0) {
					adj2[vals[i][j-2]].push_back(vals[i][j]);
					root2[vals[i][j]] = false;
				}
			}
		}
	}
	for (int i=0; i<cnt; i++) {
		if (root2[i]) {
			dfs1(i);
		}
	}
	init(0, 0, tour.size()-1);
	for (int i=0; i<cnt; i++) {
		if (root1[i]) {
			dfs2(i);
		}
	}
	cout << 1ll*n*m*n*m/4 - ttl << endl;
}