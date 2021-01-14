#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int n;
set<int> adj[100100];
int o = 1e8;
void bfs (int x) {
	vector<int> dist(n, 1e8);
	vector<int> par(n, -1);
	dist[x] = 0;
	queue<int> cur;
	cur.push(x);
	while (cur.size() > 0) {
		int v = cur.front();
		cur.pop();
		for (auto i: adj[v]) {
			if (dist[i] == 1e8) {
				dist[i] = dist[v]+1;
				par[i] = v;
				cur.push(i);
			} else if (par[i] != v && par[v] != i) {
				o = min(o, dist[i]+dist[v]+1);
			}
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	long long a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<=60; i++) {
		vector<int> cur;
		for (int j=0; j<n; j++) {
			if ((a[j] & (1ll<<i)) > 0) {
				cur.push_back(j);
			}
		}
		if (cur.size() > 2) {
			cout << 3 << endl;
			return 0;
		}
		if (cur.size() == 2) {
			adj[cur[0]].insert(cur[1]);
			adj[cur[1]].insert(cur[0]);
		}
	}
	for (int i=0; i<n; i++) {
		if (adj[i].size() > 0) bfs(i);
	}
	cout << (o==1e8?-1:o) << endl;
}