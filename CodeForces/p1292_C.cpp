#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 3005
int n;
vector<int> adj[MAXN];
int par[MAXN];
int depth[MAXN];
int sz[MAXN];
vector<int> subtree[MAXN];
int dist[MAXN][MAXN];
vector< pair< int, pair<int, int> > > paths;
long long dp[MAXN][MAXN];
long long o = 0;
void dfs (int x, int p) {
	par[x] = p;
	depth[x] = depth[p]+1;
	sz[x] = 1;
	subtree[x].push_back(x);
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		sz[x] += sz[i];
		for (auto j: subtree[i]) {
			for (auto k: subtree[x]) {
				dist[j][k] = dist[k][j] = depth[j]+depth[k]-2*depth[x];
				paths.push_back(make_pair(-dist[j][k], make_pair(j, k)));
			}
		}
		for (auto j: subtree[i]) {
			subtree[x].push_back(j);
		}
	}
}
int main () {
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
	sort(paths.begin(), paths.end());
	for (auto i: paths) {
		int x = i.second.first, y = i.second.second;
		int sz_x = 1, sz_y = 1;
		for (auto i: adj[x]) {
			if (dist[i][y] < dist[x][y]) continue;
			if (i == par[x]) {
				sz_x += n-sz[x];
			} else {
				sz_x += sz[i];
			}
			dp[x][y] = max(dp[x][y], dp[i][y]);
		}
		for (auto i: adj[y]) {
			if (dist[i][x] < dist[x][y]) continue;
			if (i == par[y]) {
				sz_y += n-sz[y];
			} else {
				sz_y += sz[i];
			}
			dp[x][y] = max(dp[x][y], dp[x][i]);
		}
		dp[x][y] += 1ll*sz_x*sz_y;
		dp[y][x] = dp[x][y];
		o = max(o, dp[x][y]);
	}
	cout << o << endl;
}