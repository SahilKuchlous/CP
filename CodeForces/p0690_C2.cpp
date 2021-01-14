#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
int n, m;
vector<int> adj[MAXN];
int dist[MAXN];
void dfs (int x, int p) {
	dist[x] = dist[p]+1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
	}
}
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dist[0] = 0;
	dfs(0, 0);
	int root = 0;
	for (int i=0; i<n; i++) {
		if (dist[i] > dist[root]) root = i;
	}
	dist[root] = 0;
	dfs(root, root);
	for (int i=0; i<n; i++) {
		if (dist[i] > dist[root]) root = i;
	}
	cout << dist[root]-1 << endl;
}