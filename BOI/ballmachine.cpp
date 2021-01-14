#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, q;
int root;
vector<int> adj[100100];
int submin[100100];
void dfs1 (int x, int p) {
	submin[x] = x;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
		submin[x] = min(submin[x], submin[i]);
	}
}
bool comp (int a1, int a2) {
	return submin[a1] < submin[a2];
}
int timer = 0;
int in_t[100100], out_t[100100];
int kc = 0;
int key[100100];
int depth[100100];
int par[100100];
int ord[100100];
void dfs2 (int x, int p) {
	in_t[x] = timer;
	ord[timer] = x;
	timer++;
	if (x != p) depth[x] = depth[p]+1;
	par[x] = p;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x);
	}
	out_t[x] = timer;
	key[x] = kc;
	kc++;
}
int segtree[400100];
void update (int x, int l, int r, int a, int b, int v) {
	if (r < a || l > b) {
		return;
	}
	if (a <= l && r <= b) {
		segtree[x] += v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
}
int query (int x, int l, int r, int p) {
	if (p < l || p > r) {
		return 0;
	}
	int o = segtree[x];
	if (l == r) {
		return o;
	}
	int m = (l+r)/2;
	o += query(2*x+1, l, m, p);
	o += query(2*x+2, m+1, r, p);
	return o;
}
int bin[100100][20];
int find (int x, int d) {
	int cur = x;
	while (d > 0) {
		for (int i=0; i<20; i++) {
			if (d < (1<<i)) {
				cur = bin[cur][i-1];
				d -= (1<<(i-1));
				break;
			}
		}
	}
	return cur;
}
set< pair<int, int> > empty;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	int ai;
	for (int i=0; i<n; i++) {
		cin >> ai;
		ai--;
		if (ai == -1) {
			root = i;
			continue;
		}
		adj[ai].push_back(i);
		adj[i].push_back(ai);
	}
	dfs1(root, root);
	for (int i=0; i<n; i++) {
		sort(adj[i].begin(), adj[i].end(), comp);
	}
	depth[root] = 0;
	dfs2(root, root);
	for (int i=0; i<n; i++) {
		bin[ord[i]][0] = par[ord[i]];
		for (int j=1; j<20; j++) {
			bin[ord[i]][j] = bin[bin[ord[i]][j-1]][j-1];
		}
	}
	for (int i=0; i<n; i++) {
		empty.insert(make_pair(key[i], i));
	}
	int ti;
	int cur, last, k, anc;
	for (int i=0; i<q; i++) {
		cin >> ti >> ai;
		if (ti == 1) {
			for (int j=0; j<ai; j++) {
				cur = empty.begin()->second;
				update(0, 0, n-1, in_t[cur]+1, out_t[cur]-1, 1);
				empty.erase(empty.begin());
				last = cur;
			}
			cout << last+1 << endl;
		} else {
			ai--;
			k = query(0, 0, n-1, in_t[ai]);
			anc = find(ai, k);
			update(0, 0, n-1, in_t[anc]+1, out_t[anc]-1, -1);
			empty.insert(make_pair(key[anc], anc));
			cout << k << endl;
		}
	}
}