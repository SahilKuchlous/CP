#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
int n;
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
	dist[0] = 0;
	dfs(0, 0);
	int root = 0;
	for (int i=0; i<n; i++) {
		if (dist[i] > dist[root]) root = i;
	}
	dist[root] = 0;
	dfs(root, root);
	int diam = 0;
	for (int i=0; i<n; i++) {
		diam = max(diam, dist[i]);
	}
	diam--;
	cout << 3*diam << endl;
}