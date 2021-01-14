#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
struct edge {
	int id;
	int a, b;
	int wt;
	bool mst;
	bool operator < (const edge e) const {
		return wt < e.wt;
	}
};
int n, m;
vector<edge> edges;
int par[100100];
int root (int x) {
	if (par[x] == x) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void merge (int x, int y) {
	par[root(y)] = root(x);
}
vector< pair<int, int> > tree[100100];
int depth[100100];
int timer = 0;
int in_t[100100], out_t[100100];
int anc[100100][20];
int m_wt[100100][20];
void dfs (int x, int p) {
	depth[x] = depth[p]+1;
	in_t[x] = timer;
	timer++;
	for (int i=1; i<20; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
		m_wt[x][i] = max(m_wt[x][i-1],  m_wt[anc[x][i-1]][i-1]);
	}
	for (auto i: tree[x]) {
		if (i.first == p) continue;
		anc[i.first][0] = x;
		m_wt[i.first][0] = i.second;
		dfs(i.first, x);
	}
	out_t[x] = timer;
}
bool is_anc (int x, int y) {
	return in_t[x] <= in_t[y] && out_t[y] <= out_t[x]; 
}
int query (int a, int b) {
	int o = 0;
	int cur_a = a, cur_b = b;
	for (int i=19; i>=0; i--) {
		if (!is_anc(anc[cur_a][i], b)) {
			o = max(o, m_wt[cur_a][i]);
			cur_a = anc[cur_a][i];
		}
		if (!is_anc(anc[cur_b][i], a)) {
			o = max(o, m_wt[cur_b][i]);
			cur_b = anc[cur_b][i];
		}
	}
	if (!is_anc(cur_a, b)) o = max(o, m_wt[cur_a][0]);
	if (!is_anc(cur_b, a)) o = max(o, m_wt[cur_b][0]);
	return o;
}
int lca (int a, int b) {
	if (is_anc(a, b)) return a;
	if (is_anc(b, a)) return b;
	int o = a;
	for (int i=19; i>=0; i--) {
		if (!is_anc(anc[o][i], b)) {
			o = anc[o][i];
		}
	}
	return anc[o][0];
}
int min_w[100100][20];
void process (int x, int t, int w) {
	int cur = x;
	for (int i=19; i>=0; i--) {
		if (depth[cur]-depth[t] >= (1ll<<i)) {
			min_w[cur][i] = min(min_w[cur][i], w);
			cur = anc[cur][i];
		}
	}
}
void update () {
	for (int j=19; j>0; j--) {
		for (int i=0; i<n; i++) {
			min_w[i][j-1] = min(min_w[i][j-1], min_w[i][j]);
			min_w[anc[i][j-1]][j-1] = min(min_w[anc[i][j-1]][j-1], min_w[i][j]);
		}
	}
}
int ans[1000100];
int main () {
	cin >> n >> m;
	edges.resize(m);
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		edges[i].id = i;
		edges[i].a = ai;
		edges[i].b = bi;
		edges[i].wt = ci;
		edges[i].mst = false;
	}
	sort(edges.begin(), edges.end());
	for (int i=0; i<n; i++) {
		par[i] = i;
		for (int j=0; j<20; j++) min_w[i][j] = 1e9;
	}
	for (int i=0; i<m; i++) {
		if (root(edges[i].a) != root(edges[i].b)) {
			merge(edges[i].a, edges[i].b);
			edges[i].mst = true;
			tree[edges[i].a].push_back(make_pair(edges[i].b, edges[i].wt));
			tree[edges[i].b].push_back(make_pair(edges[i].a, edges[i].wt));
		}
	}
	dfs(0, 0);
	for (int i=0; i<m; i++) {
		if (!edges[i].mst) {
			ans[edges[i].id] = query(edges[i].a, edges[i].b);
			int top = lca(edges[i].a, edges[i].b);
			process(edges[i].a, top, edges[i].wt);
			process(edges[i].b, top, edges[i].wt);
		}
	}
	update();
	for (int i=0; i<m; i++) {
		if (edges[i].mst) {
			if (depth[edges[i].a] > depth[edges[i].b]) {
				ans[edges[i].id] = min_w[edges[i].a][0];
			} else {
				ans[edges[i].id] = min_w[edges[i].b][0];
			}
		}
	}
	for (int i=0; i<m; i++) {
		cout << ans[i] << endl;
	}
}