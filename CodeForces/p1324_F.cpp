#include <iostream>
#include <vector>
using namespace std;
int n;
int a[200100];
vector<int> adj[200100];
int dp[200100];
int ans[200100];
void dfs1 (int x, int p) {
	dp[x] = a[x];
	for (auto i: adj[x]) {
		if (i != p) {
			dfs1(i, x);
			dp[x] += max(0, dp[i]);
		}
	}
}
void dfs2 (int x, int p) {
	ans[x] = dp[x];
	for (auto i: adj[x]) {
		if (i != p) {
			dp[x] -= max(0, dp[i]);
			dp[i] += max(0, dp[x]);
			dfs2(i, x);
			dp[i] -= max(0, dp[x]);
			dp[x] += max(0, dp[i]);
		}
	}
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] == 0) a[i] = -1;
	}
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs1(0, 0);
	dfs2(0, 0);
	for (int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}