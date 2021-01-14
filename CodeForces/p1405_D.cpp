#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
int n, a, b, da, db;
vector<int> adj[MAXN];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
	}
}
int dist[MAXN];
void dfs (int x, int p) {
	dist[x] = dist[p]+1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b >> da >> db;
		a--; b--;
		reset();
		int ai, bi;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		if (2*da >= db) {
			cout << "Alice" << endl;
			continue;
		}
		dist[b] = -1;
		dfs(b, b);
		if (dist[a] <= da) {
			cout << "Alice" << endl;
			continue;
		}
		int rt = b;
		for (int i=0; i<n; i++) {
			if (dist[i] > dist[rt]) rt = i;
		}
		dist[rt] = -1;
		dfs(rt, rt);
		int diam = 0;
		for (int i=0; i<n; i++) {
			diam = max(diam, dist[i]);
		}
		if (diam <= 2*da) {
			cout << "Alice" << endl;
			continue;
		}
		cout << "Bob" << endl;
	}
}