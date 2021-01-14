#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int n, m;
vector< pair<int, int> > adj[100100];
bool vis[100100];
long long root_d[100100];
int in_t[100100];
int out_t[100100];
int timer = 0;
int bin[100100][20];
vector<int> extra;
void dfs (int x, int p) {
	vis[x] = true;
	in_t[x] = timer;
	timer++;
	bin[x][0] = p;
	for (int i=1; i<20; i++) {
		bin[x][i] = bin[bin[x][i-1]][i-1];
	}
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		if (vis[i.first]) {
			extra.push_back(x);
			extra.push_back(i.first);
			continue;
		}
		root_d[i.first] = root_d[x]+i.second;
		dfs(i.first, x);
	}
	out_t[x] = timer;
}
bool is_anc (int x, int y) {
	return (in_t[x] <= in_t[y] && out_t[y] <= out_t[x]);
}
int lca (int x, int y) {
	if (is_anc(x, y)) return x;
	if (is_anc(y, x)) return y;
	int o = x;
	for (int i=19; i>=0; i--) {
		if (!is_anc(bin[o][i], y)) {
			o = bin[o][i];
		}
	}
	return bin[o][0];
}
long long min_d[50][100100];
void dijk (int pos, int x) {
	for (int i=0; i<n; i++) {
		min_d[pos][i] = 1e16;
	}
	min_d[pos][x] = 0;
	set< pair<long long, int> > s;
	s.insert({0, x});
	while (s.size() > 0) {
		pair<long long, int> cur = *s.begin();
		s.erase(s.begin());
		for (auto i: adj[cur.second]) {
			if (cur.first+i.second < min_d[pos][i.first]) {
				s.erase({min_d[pos][i.first], i.first});
				min_d[pos][i.first] = cur.first+i.second;
				s.insert(make_pair(min_d[pos][i.first], i.first));
			}
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai].push_back({bi, ci});
		adj[bi].push_back({ai, ci});
	}
	dfs(0, 0);
	sort(extra.begin(), extra.end());
	extra.resize(unique(extra.begin(), extra.end())-extra.begin());
	for (int i=0; i<extra.size(); i++) {
		dijk(i, extra[i]);
	}
	int q;
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		long long ans = root_d[ai]+root_d[bi]-2*root_d[lca(ai, bi)];
		for (int j=0; j<extra.size(); j++) {
			ans = min(ans, min_d[j][ai]+min_d[j][bi]);
		}
		cout << ans << endl;
	}
}