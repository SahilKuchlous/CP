#include <iostream>
#include <vector>
using namespace std;
#define MAXN 200005
int n, m;
int val[MAXN];
pair<int, int> edges[MAXN];
vector< pair<int, int> > adj[MAXN];
bool inc[MAXN];
bool vis[MAXN];
int depth[MAXN];
int sub[MAXN];
void dfs (int x, int p) {
	if (p != -1) depth[x] = depth[p]+1;
	vis[x] = true;
	sub[x] = val[x];
	for (auto i: adj[x]) {
		if (i.first == p) continue;
		if (vis[i.first]) {
			inc[i.second] = false;
			continue;
		}
		inc[i.second] = true;
		dfs(i.first, x);
		sub[x] += sub[i.first];
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ttl = 0;
	for (int i=0; i<n; i++) {
		cin >> val[i];
		ttl += val[i];
	}
	if (ttl != 0) {
		cout << "Impossible" << endl;
		return 0;
	}
	cin >> m;
	for (int i=0; i<m; i++) {
		cin >> edges[i].first >> edges[i].second;
		edges[i].first--; edges[i].second--;
		adj[edges[i].first].push_back(make_pair(edges[i].second, i));
		adj[edges[i].second].push_back(make_pair(edges[i].first, i));
	}
	depth[0] = 0;
	dfs(0, -1);
	cout << "Possible" << endl;
	for (int i=0; i<m; i++) { 
		if (!inc[i]) {
			cout << 0 << endl;
			continue;
		}
		if (depth[edges[i].first] > depth[edges[i].second]) {
			cout << -sub[edges[i].first] << endl;
		} else {
			cout << sub[edges[i].second] << endl;
		}
	}
}