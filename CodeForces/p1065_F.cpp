#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> adj[1000100];
pair<int, int> dp1[1000100];
int dp2[1000100];
void dfs1 (int x, int p, int d) {
	dp1[x] = make_pair(0, d);
	bool leaf = true;
	for (auto i: adj[x]) {
		if (i == p) continue;
		leaf = false;
		dfs1(i, x, d+1);
		if (dp1[i].second <= d) dp1[x].first += dp1[i].first;
		dp1[x].second = min(dp1[x].second, dp1[i].second);
	}
	if (leaf) {
		dp1[x] = make_pair(1, d-k);
	}
}
void dfs2 (int x, int p, int d) {
	int best = 0;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x, d+1);
		int score = 0;
		if (dp1[i].second <= d) score = -dp1[i].first;
		score += dp2[i];
		best = max(best, score);
	}
	dp2[x] = dp1[x].first+best;
}
int main () {
	cin >> n >> k;
	int ai;
	for (int i=1; i<n; i++) {
		cin >> ai;
		ai--;
		adj[i].push_back(ai);
		adj[ai].push_back(i);
	}
	dfs1(0, 0, 0);
	dfs2(0, 0, 0);
	cout << dp2[0] << endl;
}