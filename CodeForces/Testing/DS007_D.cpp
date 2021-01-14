#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
int n, m;
vector<int> adj[MAXN];
bool vis[MAXN];
int timer = 0;
int tin[MAXN];
int lo[MAXN];
int sz[MAXN];
long long o = 1e16;
void dfs (int x, int p) {
	vis[x] = true;
	tin[x] = lo[x] = timer++;
	sz[x] = 1;
	for (auto i: adj[x]) {
		if (i == p) continue;
		if (!vis[i]) {
			dfs(i, x);
			lo[x] = min(lo[x], lo[i]);
			sz[x] += sz[i];
			if (lo[i] > tin[x]) {
				o = min(o, 1ll*sz[i]*(sz[i]-1)/2+1ll*(n-sz[i])*(n-sz[i]-1)/2);
			}
		} else {
			lo[x] = min(lo[x], tin[i]);
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
	if (o == 1e16) {
		cout << -1 << endl;
	} else {
		cout << o-m+1 << endl;
	}
}