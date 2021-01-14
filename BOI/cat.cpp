// Can't always pick all leaves
#include <iostream>
#include <vector>
using namespace std;
int n, d;
vector<int> adj[200100];
int depth[200100];
int cnt = 0;
int dfs (int x, int p) {
	depth[x] = depth[p]+1;
	int min_d = 1e8;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		min_d = min(min_d, depth[i]);
	}
	if (min_d-depth[x] >= d) {
		cnt++;
		return depth[x];
	}
	return min_d;
}
int main () {
	cin >> n >> d;
	int pi;
	for (int i=1; i<n; i++) {
		cin >> pi;
		adj[pi].push_back(i);
		adj[i].push_back(pi);
	}
	depth[0] = 0;
	dfs(0, 0);
	cout << cnt << endl;
}