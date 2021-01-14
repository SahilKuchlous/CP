#include <iostream>
#include <vector>
using namespace std;
int n, m;
int val[200100];
vector<int> adj[200100];
int s;
bool vis[200100];
bool cyc[200100];
long long ans = 0;
long long dfs (int x, int p) {
	vis[x] = true;
	long long best = 0;
	for (auto i: adj[x]) {
		if (i == p) continue;
		if (vis[i]) {
			cyc[x] = true;
			continue;
		}
		best = max(best, dfs(i, x));
		cyc[x] |= cyc[i];
	}
	if (!cyc[x]) best += val[x];
	return best;
}
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> val[i];
	}
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	cin >> s;
	s--;
	ans = dfs(s, s);
	for (int i=0; i<n; i++) {
		if (cyc[i]) ans += val[i];
	}
	cout << ans << endl;
}