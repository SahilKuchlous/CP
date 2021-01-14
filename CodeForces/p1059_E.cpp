#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100005
int n, l;
long long s;
int wt[MAXN];
vector<int> adj[MAXN];
int depth[MAXN];
int anc[MAXN][25];
long long cost[MAXN][25];
void dfs1 (int x, int p) {
	for (int i=1; i<25; i++) {
		anc[x][i] = anc[anc[x][i-1]][i-1];
		cost[x][i] = cost[x][i-1]+cost[anc[x][i-1]][i-1];
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		anc[i][0] = x;
		cost[i][0] = wt[x];
		depth[i] = depth[x]+1;
		dfs1(i, x);
	}
}
int ht[MAXN];
void calc (int x) {
	int cur_p = x;
	long long cur_c = wt[x];
	for (int i=24; i>=0; i--) {
		if (depth[x]-depth[cur_p]+(1<<i) < l && cur_c+cost[cur_p][i] <= s) {
			cur_c += cost[cur_p][i];
			cur_p = anc[cur_p][i];
		}
	}
	ht[x] = depth[cur_p];
}
int dp1[MAXN], dp2[MAXN];
void dfs2 (int x, int p) {
	dp1[x] = 0; dp2[x] = 1e9;
	bool leaf = true;
	for (auto i: adj[x]) {
		if (i == p) continue;
		leaf = false;
		dfs2(i, x);
		dp1[x] += dp1[i];
		dp2[x] = min(dp2[x], dp2[i]);
	}
	if (dp2[x] > depth[x]) {
		dp1[x]++;
		dp2[x] = ht[x];
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l >> s;
	for (int i=0; i<n; i++) {
		cin >> wt[i];
		if (wt[i] > s) {
			cout << -1 << endl;
			return 0;
		}
	}
	int ai;
	for (int i=1; i<n; i++) {
		cin >> ai;
		ai--;
		adj[i].push_back(ai);
		adj[ai].push_back(i);
	}
	depth[0] = 0;
	dfs1(0, 0);
	for (int i=0; i<n; i++) {
		calc(i);
	}
	dfs2(0, 0);
	cout << dp1[0] << endl;
}