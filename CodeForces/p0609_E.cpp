#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct edge {
	int id;
	int a, b;
	int weight;
	bool in_mst;
	bool operator < (const edge &e) const {
		return weight < e.weight;
	}
};
int n, m;
edge edges[200100];

int dsu[200100];
int root (int x) {
	if (x == dsu[x]) return x;
	dsu[x] = dsu[dsu[x]];
	return root(dsu[x]);
}
void merge (int p1, int p2) {
	dsu[root(p1)] = root(p2);
}
bool query (int p1, int p2) {
	return root(p1) == root(p2);
}

long long mst_len = 0;
vector< pair<int, int> > adj[200100];
int timer = 0;
int tin[200100], tout[200100];
int up_id[200100][20], up_max[200100][20];
int l;
void dfs (int x, int p, int wt) {
	tin[x] = timer++;
	up_id[x][0] = p;
	up_max[x][0] = wt;
	for (int i=1; i<=l; i++) {
		up_id[x][i] = up_id[up_id[x][i-1]][i-1];
		up_max[x][i] = max(up_max[x][i-1], up_max[up_id[x][i-1]][i-1]);
	}
	for (auto i: adj[x]) {
		if (i.first != p) {
			dfs(i.first, x, i.second);
		}
	}
	tout[x] = timer++;
}
bool is_ancestor (int a, int b) {
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}
int query2 (int a, int b) {
	int o = 0;
	int cur_a = a;
	for (int i=l; i>=0; i--) {
		if (!is_ancestor(up_id[cur_a][i], b)) {
			o = max(o, up_max[cur_a][i]);
			cur_a = up_id[cur_a][i];
		}
	}
	if (!is_ancestor(a, b)) o = max(o, up_max[cur_a][0]);
	int cur_b = b;
	for (int i=l; i>=0; i--) {
		if (!is_ancestor(up_id[cur_b][i], a)) {
			o = max(o, up_max[cur_b][i]);
			cur_b = up_id[cur_b][i];
		}
	}
	if (!is_ancestor(b, a)) o = max(o, up_max[cur_b][0]);
	return o;
}

long long ans[200100];

int main () {
	cin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		edges[i].id = i;
		edges[i].a = ai;
		edges[i].b = bi;
		edges[i].weight = ci;
	}
	sort(edges, edges+m);
	for (int i=0; i<n; i++) {
		dsu[i] = i;
	}
	for (int i=0; i<m; i++) {
		if (!query(edges[i].a, edges[i].b)) {
			edges[i].in_mst = true;
			adj[edges[i].a].push_back(make_pair(edges[i].b, edges[i].weight));
			adj[edges[i].b].push_back(make_pair(edges[i].a, edges[i].weight));
			mst_len += edges[i].weight;
			merge(edges[i].a, edges[i].b);
		}
	}
	l = ceil(log2(n));
	dfs(0, 0, 0);
	for (int i=0; i<m; i++) {
		if (edges[i].in_mst) {
			ans[edges[i].id] = mst_len;
		} else {
			ans[edges[i].id] = mst_len+edges[i].weight-query2(edges[i].a, edges[i].b);
		}
	}
	for (int i=0; i<m; i++) {
		cout << ans[i] << endl;
	}
}