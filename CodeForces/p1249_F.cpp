#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> adj[210];
int dp[210][210];
int wts[210];
void dfs (int x, int p) {
	dp[x][0] = wts[x];
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x);
			dp[x][0] += dp[i][k];
		}
	}
	for (int i=1; i<=k/2; i++) {	
		int total = 0;
		for (auto j: adj[x]) {
			if (j != p) {
				total += dp[j][k-i];
			}
		}
		for (auto j: adj[x]) {
			if (j != p) {
				dp[x][i] = max(dp[x][i], total-dp[j][k-i]+dp[j][i-1]);
			}
		}
	}
	for (int i=(k/2)+1; i<=k; i++) {
		for (auto j: adj[x]) {
			if (j != p) {
				dp[x][i] += dp[j][i-1];
			}
		}
	}
	for (int i=k-1; i>=0; i--) {
		dp[x][i] = max(dp[x][i], dp[x][i+1]);
	}
}
int main () {
	cin >> n >> k;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> wts[i];
	}
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
	cout << dp[0][0] << endl;
}