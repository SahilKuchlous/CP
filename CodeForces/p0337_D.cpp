#include <iostream>
#include <set>
using namespace std;
int n, m, d;
bool evil[100100];
set<int> adj[100100];
int down[100100];
int up[100100];
int max1[100100];
int max2[100100];
void dfs_down (int x, int p) {
	max1[x] = max2[x] = -1e9;
	if (adj[x].size() == 1 && *adj[x].begin() == p) {
		down[x] = -1e8;
		if (evil[x]) down[x] = 0;
		return;
	}
	down[x] = -1e8;
	if (evil[x]) down[x] = max(down[x], 0);
	for (auto i: adj[x]) {
		if (i != p) {
			dfs_down(i, x);
			down[x] = max(down[x], down[i]+1);
			if (down[i] > max1[x]) {
				max2[x] = max1[x];
				max1[x] = down[i];
			} else if (down[i] > max2[x]) {
				max2[x] = down[i];
			}
		}
	}
}
void dfs_up (int x, int p) {
	if (x == p) {
		up[x] = -1e8;
	} else {
		up[x] = up[p]+1;
		if (evil[p]) up[x] = max(1, up[x]);
		if (max1[p] == down[x]) {
			up[x] = max(up[x], max2[p]+2);
		} else {
			up[x] = max(up[x], max1[p]+2);
		}
	}
	for (auto i: adj[x]) {
		if (i != p) {
			dfs_up(i, x);
		}
	}
}
int dfs_total (int x, int p) {
	int o = 0;
	// cout << x << " " << down[x] << " " << up[x] << endl;
	if (down[x] <= d && up[x] <= d) o = 1;
	for (auto i: adj[x]) {
		if (i != p) {
			o += dfs_total(i, x);
		}
	}
	return o;
}
int main () {
	cin >> n >> m >> d;
	for (int i=1; i<=n; i++) {
		evil[i] = false;
	}
	int ei;
	for (int i=0; i<m; i++) {
		cin >> ei;
		evil[ei] = true;
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	dfs_down(1, 1);
	dfs_up(1, 1);
	cout << dfs_total(1, 1) << endl;
}