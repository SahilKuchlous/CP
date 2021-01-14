#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> adj[300100];
int dp[300100];
pair<int, int> m1[300100];
pair<int, int> m2[300100];
bool up[300100];
int o;
void init () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		up[i] = false;
	}
	o = 0;
}
void dfs1 (int x, int p) {
	dp[x] = 1;
	int cnt = 0;
	m1[x] = m2[x] = make_pair(-1, 0);
	for (auto i: adj[x]) {
		if (i == p) continue;
		cnt++;
		dfs1(i, x);
		if (dp[i] > m2[x].second) m2[x] = make_pair(i, dp[i]);
		if (m2[x].second > m1[x].second) swap(m1[x], m2[x]);
	}
	dp[x] += max(0, cnt-1);
	dp[x] += m1[x].second;
}
void dfs2 (int x, int p) {
	int extra = 0;
	if (p != -1) {
		extra = dp[p]-1;
		if (!up[p] && m1[p].first == x) {
			extra += m2[p].second-m1[p].second;
		}
		if (extra > m1[x].second) {
			dp[x] += extra-m1[x].second;
			up[x] = true;
		}
	}
	int score;
	if (up[x]) {
		score = dp[x]+m1[x].second;
	} else {
		score = dp[x]+max(extra, m2[x].second);
		if (p == -1 && adj[0].size() > 1) score--;
	}
	// cout << x << " " << extra << " " << score << endl;
	o = max(o, score);
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x);
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		init();
		int ai, bi;
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		dfs1(0, -1);
		dfs2(0, -1);
		cout << o << endl;
	}
}