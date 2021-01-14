#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
#define MAXN 300005
int n, m, k, q;
vector< pair<int, long long> > adj[MAXN];
vector< pair< long long, pair<int, int> > > edges;
priority_queue< pair<long long, int> > ord;
long long dist[MAXN];
bool vis[MAXN];
int par[MAXN];
set<int> qry[MAXN];
long long o[MAXN];
int root (int x) {
	if (x == par[x]) return x;
	par[x] = par[par[x]];
	return root(par[x]);
}
void merge (int x, int y, long long wt) {
	int r1 = root(x), r2 = root(y);
	if (r1 == r2) return;
	if (qry[r1].size() < qry[r2].size()) swap(r1, r2);
	for (auto i: qry[r2]) {
		if (qry[r1].find(i) == qry[r1].end()) {
			qry[r1].insert(i);
		} else {
			o[i] = wt;
			qry[r1].erase(i);
		}
	}
	par[r2] = r1;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k >> q;
	int ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		ai--; bi--;
		adj[ai].push_back(make_pair(bi, ci));
		adj[bi].push_back(make_pair(ai, ci));
		edges.push_back(make_pair(ci, make_pair(ai, bi)));
	}
	for (int i=0; i<n; i++) {
		dist[i] = 1e16;
	}
	for (int i=0; i<k; i++) {
		ord.push(make_pair(0, i));
		dist[i] = 0;
	}
	while (ord.size() > 0) {
		int cur = ord.top().second;
		ord.pop();
		if (vis[cur]) continue;
		vis[cur] = true;
		for (auto i: adj[cur]) {
			if (dist[cur]+i.second < dist[i.first]) {
				dist[i.first] = dist[cur]+i.second;
			}
			ord.push(make_pair(-dist[i.first], i.first));
		}
	}
	for (int i=0; i<q; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		qry[ai].insert(i);
		qry[bi].insert(i);
	}
	for (int i=0; i<n; i++) {
		par[i] = i;
	}
	for (int i=0; i<m; i++) {
		edges[i].first += dist[edges[i].second.first] + dist[edges[i].second.second];
	}
	sort(edges.begin(), edges.end());
	for (auto i: edges) {
		merge(i.second.first, i.second.second, i.first);
	}
	for (int i=0; i<q; i++) {
		cout << o[i] << '\n';
	}
}