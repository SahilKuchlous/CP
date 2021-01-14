#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 200005
int n;
int a[MAXN];
vector<int> adj[MAXN];
int depth[MAXN];
int in_t[MAXN];
vector<int> ord;
vector< pair<int, int> > euler;
void dfs (int x, int p) {
	depth[x] = depth[p]+1;
	in_t[x] = euler.size();
	euler.push_back(make_pair(depth[x], x));
	ord.push_back(x);
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		euler.push_back(make_pair(depth[x], x));
	}
}
pair<int, int> segtree[8*MAXN];
void build (int x, int l, int r) {
	if (l == r) {
		segtree[x] = euler[l];
		return;
	}
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return make_pair(1e9, 1e9);
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return min(query(2*x+1, l, m, a, b), query(2*x+2, m+1, r, a, b));
}
vector<int> opts;
map< int, vector<int> > pts;
int inc[MAXN], red[MAXN];
bool pos = true;
int sum = 0;
int o = 0;
void dfs2 (int x, int p) {
	sum += inc[x];
	if (sum == opts.size()) o++;
	sum -= red[x];
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x);
	}
	sum += red[x];
	sum -= inc[x];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	depth[0] = -1;
	dfs(0, 0);
	for (int i=0; i<n; i++) {
		pts[a[ord[i]]].push_back(ord[i]);
		opts.push_back(a[ord[i]]);
	}
	sort(opts.begin(), opts.end());
	opts.resize(unique(opts.begin(), opts.end())-opts.begin());
	build(0, 0, euler.size()-1);
	for (auto i: opts) {
		if (pts[i].size() == 1) continue;
		if (pts[i].size() == 2) {
			cout << pts[i][0] << " " << pts[i][1] << endl;
			int lca = query(0, 0, euler.size()-1, in_t[pts[i][0]], in_t[pts[i][1]]).second;
			inc[lca]++;
			red[pts[i][0]]++;
			red[pts[i][1]]++;
			continue;
		}
		int root = query(0, 0, euler.size()-1, in_t[pts[i][0]], in_t[pts[i][1]]).second;
		for (int j=2; j<pts[i].size(); j++) {
			int lca = query(0, 0, euler.size()-1, in_t[pts[i][j-1]], in_t[pts[i][j]]).second;
			if (lca != root) {
				pos = false;
				break;
			}
		}
		inc[root]++;
		red[root]++;
	}
	if (!pos) {
		cout << 0 << endl;
		return 0;
	}
	dfs2(0, 0);
	cout << o << endl;
}