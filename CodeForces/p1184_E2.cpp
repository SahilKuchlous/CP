#include <iostream>
#include <vector>
#include <algorithm>
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
int timer = 0;
int in_t[100100], out_t[100100];
int anc[100100][20];
int m_wt[100100][20];
void dfs (int x, int p) {
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
	int o[m];
	for (int i=0; i<m; i++) {
		if (!edges[i].mst) {
			o[edges[i].id] = query(edges[i].a, edges[i].b);
		} else {
			o[edges[i].id] = -1;
		}
	}
	for (int i=0; i<m; i++) {
		if (o[i] > -1) cout << o[i] << endl;
	}
}