#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 200005
int n;
vector<int> adj[MAXN];
pair<int, int> p[MAXN];
int sz[MAXN];
void dfs1 (int x, int p) {
	sz[x] = 1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs1(i, x);
		sz[x] += sz[i];
	}
}
int root;
int centroid (int x, int p) {
	for (auto i: adj[x]) {
		if (i == p) continue;
		if (sz[i] > n/2) return centroid(i, x);
	}
	return x;
}
int timer = 0;
int in_t[MAXN], out_t[MAXN];
int anc[MAXN][25];
void dfs2 (int x, int p) {
	in_t[x] = timer++;
	anc[x][0] = p;
	for (int i=1; i<25; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x);
	}
	out_t[x] = timer;
}
bool is_anc (int x, int y) {
	return (in_t[x] <= in_t[y] && out_t[y] <= out_t[x]);
}
int lca (int a, int b) {
	if (is_anc(a, b)) return a;
	for (int i=24; i>=0; i--) {
		if (!is_anc(anc[a][i], b)) a = anc[a][i];
	}
	return anc[a][0];
}
int find (int a) {
	for (int i=24; i>=0; i--) {
		if (anc[a][i] != root) a = anc[a][i];
	}
	return a;
}
int cnt[MAXN];
vector<int> vals;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	for (int i=0; i<n/2; i++) {
		cin >> p[i].first >> p[i].second;
		p[i].first--; p[i].second--;
	}
	dfs1(0, 0);
	root = centroid(0, 0);
	dfs2(root, root);
	for (int i=0; i<n/2; i++) {
		int a = lca(p[i].first, p[i].second);
		if (a != root) cnt[find(a)]++;
	}
	for (int i=0; i<n; i++) {
		if (cnt[i] > 0) vals.push_back(cnt[i]);
	}
	if (vals.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	sort(vals.begin(), vals.end(), greater<int>());
	int ttl = 0;
	for (int i=1; i<vals.size(); i++) {
		ttl += vals[i];
	}
	if (ttl <= vals[0]) {
		cout << vals[0] << endl;
	} else {
		cout << (ttl+vals[0]+1)/2 << endl;
	}
}