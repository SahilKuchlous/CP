#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000
struct edge {
	int id;
	int x, y;
	int wt;
	bool operator < (const edge e) const {
		return wt > e.wt;
	}
};
int n, m, q;
edge edges[MAXN*MAXN];
int par[MAXN];
vector<int> grp[MAXN];
int col[MAXN];
int root (int x) {
	if (x == par[x]) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void merge (int x, int y) {
	int r1 = root(x), r2 = root(y);
	if (grp[r1].size() < grp[r2].size()) swap(r1, r2);
	bool flip = (col[x] == col[y]);
	for (auto i: grp[r2]) {
		grp[r1].push_back(i);
		if (flip) col[i] ^= 1;
	}
	par[r2] = r1;
}
void init () {
	for (int i=0; i<n; i++) {
		par[i] = i;
		grp[i] = {i};
		col[i] = 0;
	}
}
int solve (int l, int r) {
	for (int i=0; i<m; i++) {
		if (l <= edges[i].id && edges[i].id <= r) {
			int r1 = root(edges[i].x), r2 = root(edges[i].y);
			if (r1 != r2) {
				merge(edges[i].x, edges[i].y);
				continue;
			}
			if (col[edges[i].x] == col[edges[i].y]) return edges[i].wt;
		}
	}
	return -1;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for (int i=0; i<m; i++) {
		cin >> edges[i].x >> edges[i].y >> edges[i].wt;
		edges[i].x--; edges[i].y--;
		edges[i].id = i;
	}
	sort(edges, edges+m);
	int ai, bi;
	while (q--) {
		cin >> ai >> bi;
		ai--; bi--;
		init();
		cout << solve(ai, bi) << '\n';
	}
}