#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> adj[1000005];
int depth[1000005];
int bin[1000005][25];
void dfs (int x, int p) {
	depth[x] = depth[p]+1;
	bin[x][0] = p;
	for (int i=1; i<25; i++) {
		bin[x][i] = bin[bin[x][i-1]][i-1];
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
}
bool marked[1000005];
vector<int> o;
int find (int x) {
	for (int i=24; i>=0; i--) {
		if (!marked[bin[x][i]]) x = bin[x][i];
	}
	return x;
}
void mark (int u, int v) {
	while (true) {
		marked[u] = true;
		if (u == v) break;
		u = bin[u][0];
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(n-1, n-1);
	int rem = n-k;
	for (int i=n-1; i>=0; i--) {
		if (marked[i]) continue;
		int lca = find(i);
		if (depth[i]-depth[lca]+1 <= rem) {
			mark(i, lca);
			rem -= depth[i]-depth[lca]+1;
		}
	}
	for (int i=0; i<n; i++) {
		if (!marked[i]) cout << i+1 << " ";
	}
	cout << endl;
}